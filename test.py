import casadi as ca
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import xml.etree.ElementTree as ET
import scipy.optimize as opt
import math
import sys

# -------------------------------
# Конфигурация
# -------------------------------
default_config = {
    "urdf_file": "a1_sim_py/src/a1_description/urdf/a1.urdf",
    "standing_height": 0.35,      # ориентировочная высота стопы
    "step_length": 0.2,
    "swing_height": 0.07,
    "trajectory_type": "two_phase",
    "N": 100,
    "dt": 0.01,
    "dq_max": 28.6,
    "fix_hip": False,             # в режиме MPC фиксация hip; для ИК – не фиксируем q[0]
    "q0": [0.0, 2.5, -1],
    "w_pos": 10000.0,
    "w_dq": 0.1,
    "w_smooth": 0.1,
    "w_y": 1000.0,
    "joint_limits": {
         "q_min": [-0.80, -1.05, -2.70],
         "q_max": [ 0.80,  4.19, -0.92]
    },
    # Параметр для смещения центра масс (trunk) в режиме com_transfering
    "com_shifting": 0.08  
}

hip_target = np.deg2rad(0)  # начальное значение hip-roll (в радианах)

# -------------------------------
# Функция для чтения offset из URDF по имени joint
# -------------------------------
def read_offset(urdf_file, joint_name):
    tree = ET.parse(urdf_file)
    root = tree.getroot()
    for joint in root.findall("joint"):
        if joint.get("name") == joint_name:
            origin = joint.find("origin")
            if origin is not None and "xyz" in origin.attrib:
                return np.array([float(v) for v in origin.attrib["xyz"].split()])
    return None

# -------------------------------
# Класс для модели робота (чтение URDF и кинематика)
# -------------------------------
class RobotModel:
    def __init__(self, urdf_file):
        self.urdf_file = urdf_file
        self.L1, self.L2, self.L3 = self.read_link_lengths_from_urdf()
        self.trunk_dims = self.read_trunk_dimensions_from_urdf()
        self.hip_offset_FR = read_offset(urdf_file, "FR_hip_joint")
        self.hip_fixed_offset_FR = read_offset(urdf_file, "FR_hip_fixed")
        self.hip_offset_FL = read_offset(urdf_file, "FL_hip_joint")
        self.hip_fixed_offset_FL = read_offset(urdf_file, "FL_hip_fixed")
        self.hip_offset_RR = read_offset(urdf_file, "RR_hip_joint")
        self.hip_fixed_offset_RR = read_offset(urdf_file, "RR_hip_fixed")
        self.hip_offset_RL = read_offset(urdf_file, "RL_hip_joint")
        self.hip_fixed_offset_RL = read_offset(urdf_file, "RL_hip_fixed")
        self.link_masses = self.read_link_masses_from_urdf()

    def read_link_lengths_from_urdf(self):
        tree = ET.parse(self.urdf_file)
        root = tree.getroot()
        L1, L2, L3 = None, None, None
        for joint in root.findall("joint"):
            if joint.get("name") == "FR_hip_fixed":
                origin = joint.find("origin")
                if origin is not None and "xyz" in origin.attrib:
                    values = [float(v) for v in origin.attrib["xyz"].split()]
                    L1 = np.linalg.norm(values)
                break
        for link in root.findall("link"):
            if link.get("name") == "FR_thigh":
                collision = link.find("collision")
                if collision is not None:
                    geometry = collision.find("geometry")
                    if geometry is not None:
                        box = geometry.find("box")
                        if box is not None and "size" in box.attrib:
                            sizes = [float(v) for v in box.attrib["size"].split()]
                            L2 = max(sizes)
                break
        for link in root.findall("link"):
            if link.get("name") == "FR_calf":
                collision = link.find("collision")
                if collision is not None:
                    geometry = collision.find("geometry")
                    if geometry is not None:
                        box = geometry.find("box")
                        if box is not None and "size" in box.attrib:
                            sizes = [float(v) for v in box.attrib["size"].split()]
                            L3 = max(sizes)
                break
        if L1 is None or L2 is None or L3 is None:
            print("Ошибка чтения длин звеньев из URDF – используются значения по умолчанию.")
            L1, L2, L3 = 0.085, 0.20, 0.20
        print("Длины звеньев: L1 = {:.3f}, L2 = {:.3f}, L3 = {:.3f}".format(L1, L2, L3))
        return L1, L2, L3

    def read_trunk_dimensions_from_urdf(self):
        tree = ET.parse(self.urdf_file)
        root = tree.getroot()
        trunk_dims = None
        for link in root.findall("link"):
            if link.get("name") == "trunk":
                collision = link.find("collision")
                if collision is not None:
                    geometry = collision.find("geometry")
                    if geometry is not None:
                        box = geometry.find("box")
                        if box is not None and "size" in box.attrib:
                            trunk_dims = [float(v) for v in box.attrib["size"].split()]
                break
        if trunk_dims is None:
            trunk_dims = [0.267, 0.194, 0.114]
        print("Габариты trunk (x,y,z):", trunk_dims)
        return trunk_dims

    def read_link_masses_from_urdf(self):
        tree = ET.parse(self.urdf_file)
        root = tree.getroot()
        masses = {}
        for link in root.findall("link"):
            mass = None
            inertial = link.find("inertial")
            if inertial is not None:
                mass_elem = inertial.find("mass")
                if mass_elem is not None and "value" in mass_elem.attrib:
                    mass = float(mass_elem.attrib["value"])
            if mass is not None:
                masses[link.get("name")] = mass
        print("Массы звеньев из URDF:", masses)
        return masses

# -------------------------------
# Функции поворотных матриц
# -------------------------------
def R_y(angle):
    return np.array([[np.cos(angle), 0, np.sin(angle)],
                     [0, 1, 0],
                     [-np.sin(angle), 0, np.cos(angle)]])

def R_x(angle):
    return np.array([[1, 0, 0],
                     [0, np.cos(angle), -np.sin(angle)],
                     [0, np.sin(angle),  np.cos(angle)]])

# -------------------------------
# Функция прямой кинематики (с учетом hip-roll)
# -------------------------------
def forward_kinematics_relative(q, robot, fix_hip=True):
    if fix_hip:
        q1 = q[1]
        q2 = q[2]
        thigh_vector = R_y(q1) @ np.array([robot.L2, 0, 0])
        calf_vector  = R_y(q1+q2) @ np.array([robot.L3, 0, 0])
        return ca.vertcat(thigh_vector[0] + calf_vector[0],
                          0,
                          thigh_vector[2] + calf_vector[2])
    else:
        q0 = q[0]
        q1 = q[1]
        q2 = q[2]
        thigh_vector = R_y(q1) @ np.array([robot.L2, 0, 0])
        calf_vector  = R_y(q1+q2) @ np.array([robot.L3, 0, 0])
        p_local = thigh_vector + calf_vector
        p_rel = R_x(q0) @ p_local
        return ca.vertcat(p_rel[0], p_rel[1], p_rel[2])

# -------------------------------
# Абсолютная кинематика: p_abs = effective_hip_offset + p_rel
# -------------------------------
def forward_kinematics(q, robot, effective_hip_offset, fix_hip=True):
    p_rel = forward_kinematics_relative(q, robot, fix_hip)
    return effective_hip_offset + p_rel

# -------------------------------
# Функция вычисления положений звеньев для визуализации
# -------------------------------
def compute_leg_positions(q, effective_offset, robot, fix_hip=True):
    hip = effective_offset.copy()
    if fix_hip:
        knee = hip.copy()
        thigh = R_y(q[1]) @ np.array([robot.L2, 0, 0])
        ankle = knee + thigh
        calf  = R_y(q[1]+q[2]) @ np.array([robot.L3, 0, 0])
        foot  = ankle + calf
    else:
        q0, q1, q2 = q
        thigh_local = R_y(q1) @ np.array([robot.L2, 0, 0])
        thigh = R_x(q0) @ thigh_local
        knee = hip.copy()
        ankle = knee + thigh
        calf_local = R_y(q1+q2) @ np.array([robot.L3, 0, 0])
        calf = R_x(q0) @ calf_local
        foot = ankle + calf
    return hip, knee, ankle, foot

# -------------------------------
# Функция обратной кинематики для 3DoF ноги (аналітически через numpy)
# -------------------------------
def inverse_kinematics(desired, robot):
    # desired: 3-мерный вектор (d_x, d_y, d_z) – положение конечного эффектора относительно hip (effective)
    d_x, d_y, d_z = desired
    # Сначала находим угол hip-roll q0:
    R_val = np.hypot(d_y, d_z)
    # Если R_val очень мал, выбираем q0 = 0 (избегаем деления на ноль)
    if R_val < 1e-6:
        q0 = 0.0
    else:
        q0 = np.arctan2(d_y, -d_z)
    # Определяем скалярную величину R для плоского 2R манипулятора:
    R_des = R_val
    A = robot.L2
    B = robot.L3
    # Стандартное уравнение для 2 звеньев:
    D = (d_x**2 + R_des**2 - A**2 - B**2) / (2 * A * B)
    D = np.clip(D, -1.0, 1.0)
    # Выбираем решение "локтя вниз" (q2 отрицательный)
    q2 = -np.arccos(D)
    # Вычисляем q1:
    q1 = np.arctan2(R_des, d_x) - np.arctan2(B * np.sin(q2), A + B * np.cos(q2))
    return np.array([q0, q1, q2])

# -------------------------------
# Генерация траектории для FR ноги (относительно hip)
# -------------------------------
def generate_trajectory(N, step_length, swing_height,  effective_hip_offset, p0_abs, desired_y):
    N1 = N // 2
    N2 = N - N1
    p_ref_list = []
    # Фаза dragging: конечный эффектор движется по земле (z = 0)
    for k in range(N1+1):
        alpha = k / N1
        x_val = -step_length * alpha
        z_val = 0.0
        p_ref_list.append([x_val, desired_y, z_val])
    # Фаза подъёма: конечный эффектор поднимается и опускается
    for k in range(1, N2+1):
        alpha = k / N2
        x_val = -step_length + step_length * alpha
        z_val = swing_height * np.sin(np.pi * alpha)
        p_ref_list.append([x_val, desired_y, z_val])
    p_ref_arr = np.array(p_ref_list)
    ref_offset = p0_abs - effective_hip_offset
    p_ref_arr = p_ref_arr + effective_hip_offset + ref_offset - np.array([0, 0, p0_abs[2]])
    return p_ref_arr

# -------------------------------
# MPC-контроллер для FR ноги
# -------------------------------
class MPCController:
    def __init__(self, robot, config, q0):
        self.robot = robot
        self.N = config["N"]
        self.dt = config["dt"]
        self.fix_hip = config["fix_hip"]
        self.q0 = q0
        self.dq_max = config["dq_max"]
        self.w_pos = config["w_pos"]
        self.w_dq = config["w_dq"]
        self.w_smooth = config["w_smooth"]
        self.w_y = config["w_y"]
        self.q_min = np.array(config["joint_limits"]["q_min"])
        self.q_max = np.array(config["joint_limits"]["q_max"])
        self.opti = ca.Opti()
        self.q_vars  = [self.opti.variable(3) for _ in range(self.N+1)]
        self.dq_vars = [self.opti.variable(3) for _ in range(self.N)]
    
    def setup_problem(self, p_ref_arr, effective_hip_offset, desired_y):
        self.opti.subject_to(self.q_vars[0] == self.q0)
        for k in range(self.N):
            self.opti.subject_to(self.q_vars[k+1] == self.q_vars[k] + self.dq_vars[k]*self.dt)
            self.opti.subject_to(self.q_vars[k] >= self.q_min)
            self.opti.subject_to(self.q_vars[k] <= self.q_max)
            self.opti.subject_to(self.dq_vars[k] >= -self.dq_max)
            self.opti.subject_to(self.dq_vars[k] <= self.dq_max)
        self.opti.subject_to(self.q_vars[self.N] >= self.q_min)
        self.opti.subject_to(self.q_vars[self.N] <= self.q_max)

        cost = 0
        for k in range(self.N+1):
            p_foot = forward_kinematics(self.q_vars[k], self.robot, effective_hip_offset, self.fix_hip)
            p_ref_k = ca.DM(p_ref_arr[k])
            cost += self.w_pos * ca.sumsqr(p_foot - p_ref_k)
            cost += self.w_y * (p_foot[1] - desired_y)**2
        for k in range(self.N):
            cost += self.w_dq * ca.sumsqr(self.dq_vars[k])
        for k in range(1, self.N):
            cost += self.w_smooth * ca.sumsqr(self.dq_vars[k] - self.dq_vars[k-1])
        self.opti.minimize(cost)
    
    def solve(self):
        ipopt_opts = {"print_level": 0, "max_iter": 500, "tol": 1e-4}
        self.opti.solver('ipopt', {"expand": True}, ipopt_opts)
        for k in range(self.N):
            self.opti.set_initial(self.dq_vars[k], 0.0)
        sol = self.opti.solve()
        q_sol = np.array([sol.value(self.q_vars[k]) for k in range(self.N+1)])
        return q_sol

# -------------------------------
# Функция рисования поверхности земли
# -------------------------------
def draw_ground(ax, allX, allY, ground_z=0, color='lightgreen', alpha=0.3):
    x_min, x_max = np.min(allX), np.max(allX)
    y_min, y_max = np.min(allY), np.max(allY)
    vertices = np.array([
        [x_min, y_min, ground_z],
        [x_max, y_min, ground_z],
        [x_max, y_max, ground_z],
        [x_min, y_max, ground_z]
    ])
    ground = Poly3DCollection([vertices], color=color, alpha=alpha)
    ax.add_collection3d(ground)

# -------------------------------
# Функции рисования 3D объектов (туловище, скейтборд)
# -------------------------------
def draw_box(ax, lower_corner, width, depth, height, edgecolor='green', facecolor=(0,0,0,0), alpha=0.25):
    x, y, z = lower_corner
    vertices = np.array([
        [x, y, z],
        [x+width, y, z],
        [x+width, y+depth, z],
        [x, y+depth, z],
        [x, y, z+height],
        [x+width, y, z+height],
        [x+width, y+depth, z+height],
        [x, y+depth, z+height]
    ])
    faces = [
        [vertices[j] for j in [0,1,2,3]],
        [vertices[j] for j in [4,5,6,7]],
        [vertices[j] for j in [0,1,5,4]],
        [vertices[j] for j in [1,2,6,5]],
        [vertices[j] for j in [2,3,7,6]],
        [vertices[j] for j in [3,0,4,7]]
    ]
    box = Poly3DCollection(faces, linewidths=1, edgecolors=edgecolor, alpha=alpha)
    box.set_facecolor(facecolor)
    ax.add_collection3d(box)

def draw_skateboard(ax,
                    board_length=0.7,
                    board_width=0.4,
                    board_thickness=0.02,
                    wheel_diameter=0.056,
                    wheel_width=0.04,
                    wheel_gap=0.01):
    wheel_radius = wheel_diameter/2
    z_bottom_board = wheel_radius + wheel_gap
    lower_corner = np.array([-board_length/2, -board_width/2, z_bottom_board])
    # Скейтборд сделан прозрачным (alpha=0.3)
    draw_box(ax, lower_corner, board_length, board_width, board_thickness,
             edgecolor='black', facecolor=(0.5,0.3,0.1,0.3), alpha=0.3)
    x_wheels = [0.30, 0.30, -0.30, -0.30]
    y_wheels = [0.08, -0.08, 0.08, -0.08]
    for (xw, yw) in zip(x_wheels, y_wheels):
        center = (xw, yw, wheel_radius)
        theta = np.linspace(0, 2*np.pi, 24)
        xs = center[0] + wheel_radius*np.cos(theta)
        zs = center[2] + wheel_radius*np.sin(theta)
        ys = np.full_like(theta, center[1])
        ax.plot(xs, ys, zs, color='gray')

# -------------------------------
# Функция установки равных масштабов по осям
# -------------------------------
def set_axes_equal_3d(ax, X, Y, Z):
    x_min, x_max = np.min(X), np.max(X)
    y_min, y_max = np.min(Y), np.max(Y)
    z_min, z_max = np.min(Z), np.max(Z)
    if z_min < 0:
        z_min_new = 0
    else:
        z_min_new = z_min
    range_x = x_max - x_min
    range_y = y_max - y_min
    range_z = z_max - z_min_new
    max_range = max(range_x, range_y, range_z)
    mid_x = 0.5*(x_min + x_max)
    mid_y = 0.5*(y_min + y_max)
    ax.set_xlim3d(mid_x - max_range/2, mid_x + max_range/2)
    ax.set_ylim3d(mid_y - max_range/2, mid_y + max_range/2)
    ax.set_zlim3d(z_min_new, z_min_new + max_range)

# -------------------------------
# Функции для расчёта CoM робота
# -------------------------------
def compute_leg_com(positions, leg_prefix, link_masses):
    # positions: (hip, knee, ankle, foot)
    hip, knee, ankle, foot = positions
    mass_hip   = link_masses.get(f"{leg_prefix}_hip", 0)
    mass_thigh = link_masses.get(f"{leg_prefix}_thigh", 0)
    mass_calf  = link_masses.get(f"{leg_prefix}_calf", 0)
    mass_foot  = link_masses.get(f"{leg_prefix}_foot", 0)
    com_leg = mass_hip * hip + mass_thigh * ((hip + ankle) / 2) + mass_calf * ((ankle + foot) / 2) + mass_foot * foot
    total_mass_leg = mass_hip + mass_thigh + mass_calf + mass_foot
    return com_leg, total_mass_leg

def compute_robot_com(trunk_center, leg_positions, link_masses):
    mass_trunk = link_masses.get("trunk", 0)
    com_sum = trunk_center * mass_trunk
    total_mass = mass_trunk
    for leg in ['FR', 'FL', 'RR', 'RL']:
        com_leg, mass_leg = compute_leg_com(leg_positions[leg], leg, link_masses)
        com_sum = com_sum + com_leg
        total_mass += mass_leg
    return com_sum / total_mass if total_mass > 0 else trunk_center

# -------------------------------
# Анимация для режима MPC (mpc_pushing)
# -------------------------------
def animate_mpc(joint_positions_FR, foot_traj_FR, trunk_dims, trunk_center,
                static_positions_FL, static_positions_RR, static_positions_RL, board_top_z, link_masses):
    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111, projection='3d')
    
    ax.set_box_aspect([1, 1, 1])
    ax.set_xlabel('X (м)')
    ax.set_ylabel('Y (м)')
    ax.set_zlabel('Z (м)')
    ax.set_title("3D-анимация: MPC управления ногой и динамика CoM")
    
    draw_skateboard(ax)
    tw, td, th = trunk_dims
    lower_box = trunk_center - np.array([tw/2, td/2, th/2])
    draw_box(ax, lower_box, tw, td, th, edgecolor='green', facecolor=(0,1,0,0.3))
    
    colors_FR = ['skyblue', 'blue', 'navy']
    lines_FR = [ax.plot([], [], [], color=c, lw=3)[0] for c in colors_FR]
    colors_FL = ['lightcoral', 'red', 'darkred']
    lines_FL = [ax.plot([], [], [], color=c, lw=3)[0] for c in colors_FL]
    colors_RR = ['lightgreen', 'green', 'darkgreen']
    lines_RR = [ax.plot([], [], [], color=c, lw=3)[0] for c in colors_RR]
    colors_RL = ['plum', 'purple', 'indigo']
    lines_RL = [ax.plot([], [], [], color=c, lw=3)[0] for c in colors_RL]
    
    line_FR_traj, = ax.plot([], [], [], 'k--', lw=1, label='FR Foot Trajectory')
    com_marker, = ax.plot([], [], [], 'o', color='magenta', markersize=8, label='Проекция CoM')
    
    # Стабильностный треугольник для трёх статичных ног: FL, RR, RL
    tri_vertices = np.array([
        [static_positions_FL[3][0], static_positions_FL[3][1], board_top_z],
        [static_positions_RR[3][0], static_positions_RR[3][1], board_top_z],
        [static_positions_RL[3][0], static_positions_RL[3][1], board_top_z]
    ])
    stability_triangle = Poly3DCollection([tri_vertices], facecolor=(0, 0.8, 0, 0.3), edgecolor='k', lw=2, label='Треугольник устойчивости')
    ax.add_collection3d(stability_triangle)
    
    handles = []
    labels = []
    for i, c in enumerate(colors_FR):
        h, = ax.plot([], [], [], color=c, lw=3)
        handles.append(h)
        if i == 0:
            labels.append("FR Hip-Knee")
        elif i == 1:
            labels.append("FR Knee-Ankle")
        elif i == 2:
            labels.append("FR Ankle-Foot")
    for leg_name, color_set in zip(["FL", "RR", "RL"], [colors_FL, colors_RR, colors_RL]):
        for i, c in enumerate(color_set):
            h, = ax.plot([], [], [], color=c, lw=3)
            handles.append(h)
            if i == 0:
                labels.append(f"{leg_name} Hip-Knee")
            elif i == 1:
                labels.append(f"{leg_name} Knee-Ankle")
            elif i == 2:
                labels.append(f"{leg_name} Ankle-Foot")
    handles.append(line_FR_traj)
    labels.append("FR Foot Trajectory")
    handles.append(com_marker)
    labels.append("Проекция CoM")
    handles.append(stability_triangle)
    labels.append("Треугольник устойчивости")
    ax.legend(handles=handles, labels=labels, loc='upper right', fontsize=9)
    
    allX, allY, allZ = [], [], []
    for pos in joint_positions_FR:
        for pt in pos:
            allX.append(pt[0])
            allY.append(pt[1])
            allZ.append(pt[2])
    for pos in [static_positions_FL, static_positions_RR, static_positions_RL]:
        for pt in pos:
            allX.append(pt[0])
            allY.append(pt[1])
            allZ.append(pt[2])
    allX.extend([lower_box[0], lower_box[0]+tw, -0.35, 0.35])
    allY.extend([lower_box[1], lower_box[1]+td, -0.2, 0.2])
    allZ.extend([lower_box[2], lower_box[2]+th, 0.0, 0.15])
    set_axes_equal_3d(ax, np.array(allX), np.array(allY), np.array(allZ))
    
    zmin, zmax = ax.get_zlim3d()
    if zmin < 0:
        ax.set_zlim3d(0, zmax)
    
    def update(frame):
        hip, knee, ankle, foot = joint_positions_FR[frame]
        seg_FR = [(hip, knee), (knee, ankle), (ankle, foot)]
        for i, (p_start, p_end) in enumerate(seg_FR):
            xs = [p_start[0], p_end[0]]
            ys = [p_start[1], p_end[1]]
            zs = [p_start[2], p_end[2]]
            lines_FR[i].set_data(xs, ys)
            lines_FR[i].set_3d_properties(zs)
        xs_traj = foot_traj_FR[:frame+1, 0]
        ys_traj = foot_traj_FR[:frame+1, 1]
        zs_traj = foot_traj_FR[:frame+1, 2]
        line_FR_traj.set_data(xs_traj, ys_traj)
        line_FR_traj.set_3d_properties(zs_traj)
        def update_static(lines, pos):
            hip_s, knee_s, ankle_s, foot_s = pos
            seg = [(hip_s, knee_s), (knee_s, ankle_s), (ankle_s, foot_s)]
            for i, (p_start, p_end) in enumerate(seg):
                xs = [p_start[0], p_end[0]]
                ys = [p_start[1], p_end[1]]
                zs = [p_start[2], p_end[2]]
                lines[i].set_data(xs, ys)
                lines[i].set_3d_properties(zs)
        update_static(lines_FL, static_positions_FL)
        update_static(lines_RR, static_positions_RR)
        update_static(lines_RL, static_positions_RL)
        
        # Вычисляем динамику CoM
        leg_positions = {
            "FR": joint_positions_FR[frame],
            "FL": static_positions_FL,
            "RR": static_positions_RR,
            "RL": static_positions_RL
        }
        com = compute_robot_com(trunk_center, leg_positions, link_masses)
        com_proj = np.array([com[0], com[1], board_top_z])
        com_marker.set_data([com_proj[0]], [com_proj[1]])
        com_marker.set_3d_properties([com_proj[2]])
        return lines_FR + lines_FL + lines_RR + lines_RL + [line_FR_traj, com_marker]
    
    anim = FuncAnimation(fig, update, frames=len(joint_positions_FR), interval=50, blit=True)
    plt.show()

# -------------------------------
# Анимация для режима com_transfering (смещение trunk с фиксированными ногами)
# -------------------------------

def animate_com_transfering(trunk_traj, leg_trajs, com_traj, board_top_z, trunk_dims):
    # leg_trajs – словарь с ключами "FR", "FL", "RR", "RL": для каждой ноги массив положений (hip,knee,ankle,foot) по кадрам
    # trunk_traj – массив положений trunk по кадрам
    fig = plt.figure(figsize=(12,10))
    ax = fig.add_subplot(111, projection='3d')
    
    ax.set_box_aspect([1, 1, 1])
    ax.set_xlabel('X (м)')
    ax.set_ylabel('Y (м)')
    ax.set_zlabel('Z (м)')
    ax.set_title("3D-анимация: Перемещение trunk (смещение CoM) при фиксированных стопах ног")
    
    draw_skateboard(ax)
    tw, td, th = trunk_dims
    # Первоначальное положение trunk
    lower_box = trunk_traj[0] - np.array([tw/2, td/2, th/2])
    trunk_box = Poly3DCollection([], linewidths=1, edgecolors='green', alpha=0.3)
    trunk_box.set_facecolor((0,1,0,0.3))
    ax.add_collection3d(trunk_box)
    
    # Линии для ног для каждого набора цветов (одинаковые для всех ног, но будем рисовать отдельно)
    colors = {
        "FR": ['skyblue', 'blue', 'navy'],
        "FL": ['lightcoral', 'red', 'darkred'],
        "RR": ['lightgreen', 'green', 'darkgreen'],
        "RL": ['plum', 'purple', 'indigo']
    }
    lines = {leg: [ax.plot([], [], [], color=c, lw=3)[0] for c in colors[leg]] for leg in colors}
    
    # Проекция CoM
    com_marker, = ax.plot([], [], [], 'o', color='magenta', markersize=8, label='Проекция CoM')
    # Стабильностный треугольник (например, для ног FL, RR, RL)
    stability_polygon = Poly3DCollection([], facecolor=(0, 0.8, 0, 0.3),
                                         edgecolor='k', lw=2)
    ax.add_collection3d(stability_polygon)
    
    # Легенда
    handles = []
    labels = []
    for leg in ["FR", "FL", "RR", "RL"]:
        for i, c in enumerate(colors[leg]):
            h, = ax.plot([], [], [], color=c, lw=3)
            handles.append(h)
            if i == 0:
                labels.append(f"{leg} Hip-Knee")
            elif i == 1:
                labels.append(f"{leg} Knee-Ankle")
            elif i == 2:
                labels.append(f"{leg} Ankle-Foot")
    handles.append(com_marker)
    labels.append("Проекция CoM")
    handles.append(stability_polygon)
    labels.append("Треугольник устойчивости")
    ax.legend(handles=handles, labels=labels, loc='upper right', fontsize=9)
    
    allX, allY, allZ = [], [], []

    allX.extend([lower_box[0], lower_box[0]+tw, -0.35, 0.35])
    allY.extend([lower_box[1], lower_box[1]+td, -0.2, 0.2])
    allZ.extend([lower_box[2], lower_box[2]+th, 0.0, 0.15])
    set_axes_equal_3d(ax, np.array(allX), np.array(allY), np.array(allZ))
    
    zmin, zmax = ax.get_zlim3d()
    if zmin < 0:
        ax.set_zlim3d(0, zmax)
    
    def update(frame):
        # Туловище
        trunk_pos = trunk_traj[frame]
        lower_box = trunk_pos - np.array([tw/2, td/2, th/2])
        vertices = np.array([
            [lower_box[0],       lower_box[1],       lower_box[2]],
            [lower_box[0]+tw,    lower_box[1],       lower_box[2]],
            [lower_box[0]+tw,    lower_box[1]+td,    lower_box[2]],
            [lower_box[0],       lower_box[1]+td,    lower_box[2]],
            [lower_box[0],       lower_box[1],       lower_box[2]+th],
            [lower_box[0]+tw,    lower_box[1],       lower_box[2]+th],
            [lower_box[0]+tw,    lower_box[1]+td,    lower_box[2]+th],
            [lower_box[0],       lower_box[1]+td,    lower_box[2]+th]
        ])
        faces = [
            [vertices[j] for j in [0,1,2,3]],
            [vertices[j] for j in [4,5,6,7]],
            [vertices[j] for j in [0,1,5,4]],
            [vertices[j] for j in [1,2,6,5]],
            [vertices[j] for j in [2,3,7,6]],
            [vertices[j] for j in [3,0,4,7]]
        ]
        trunk_box.set_verts(faces)
        
        # Ноги
        for leg in leg_trajs:
            hip, knee, ankle, foot = leg_trajs[leg][frame]
            seg = [(hip,knee), (knee,ankle), (ankle,foot)]
            for i,(p1,p2) in enumerate(seg):
                lines[leg][i].set_data([p1[0],p2[0]],[p1[1],p2[1]])
                lines[leg][i].set_3d_properties([p1[2], p2[2]])
        
        # Полигон (четыре стопы)
        FR_foot = leg_trajs["FR"][frame][3]
        FL_foot = leg_trajs["FL"][frame][3]
        RL_foot = leg_trajs["RL"][frame][3]
        RR_foot = leg_trajs["RR"][frame][3]
        quad_vertices = np.array([
            [FR_foot[0], FR_foot[1], board_top_z],
            [FL_foot[0], FL_foot[1], board_top_z],
            [RL_foot[0], RL_foot[1], board_top_z],
            [RR_foot[0], RR_foot[1], board_top_z],
        ])
        stability_polygon.set_verts([quad_vertices])
        
        # CoM
        com = com_traj[frame]
        com_proj = np.array([com[0], com[1], board_top_z])
        com_marker.set_data([com_proj[0]], [com_proj[1]])
        com_marker.set_3d_properties([com_proj[2]])
        return sum(list(lines.values()), []) + [trunk_box, com_marker, stability_polygon]
    
    # Аналогично отключаем blit:
    anim = FuncAnimation(fig, update, frames=len(trunk_traj), interval=50, blit=False)
    plt.show()



# -------------------------------
# Режим MPC (mpc_pushing)
# -------------------------------
def run_mpc_pushing():
    config = default_config.copy()
    config["fix_hip"] = False  # FR нога с свободным hip, но для ИК MPC задаём q0 отдельно
    robot = RobotModel(config["urdf_file"])
    distance_between_skate_and_robot = 0.21
    board_top_z = 0.058
    standing_height = board_top_z + distance_between_skate_and_robot
    trunk_center = np.array([0.0, 0.0, standing_height])
    config["standing_height"] = standing_height

    q0_all = np.array(config["q0"])
    effective_hip_offset_FR = trunk_center + (robot.hip_offset_FR + robot.hip_fixed_offset_FR)
    effective_hip_offset_FL = trunk_center + (robot.hip_offset_FL + robot.hip_fixed_offset_FL)
    effective_hip_offset_RR = trunk_center + (robot.hip_offset_RR + robot.hip_fixed_offset_RR)
    effective_hip_offset_RL = trunk_center + (robot.hip_offset_RL + robot.hip_fixed_offset_RL)
    
    desired_y = effective_hip_offset_FR[1]
    
    # Конфигурация для статичных ног (FL, RR, RL) – вычисляем как в предыдущем коде
    q_static = q0_all.copy()
    def f_static(q2):
        p_foot_z = effective_hip_offset_FL[2] - (
            robot.L2 * np.sin(q_static[1]) +
            robot.L3 * np.sin(q_static[1] + q2)
        )
        return p_foot_z - board_top_z
    q_static[2] = opt.brentq(f_static, -2.7, -0.92)
    def fk_numeric(q):
        p = forward_kinematics(q, robot, effective_hip_offset_FR, config["fix_hip"])
        return np.array(ca.DM(p)).flatten()
    p0_abs_static = fk_numeric(q_static)
    
    # Для FR ноги решаем обратную кинематику аналитически
    d_x = p0_abs_static[0] - effective_hip_offset_FR[0]
    d_y = 0  # желаемо, стопа должна быть прямо под hip
    d_z = board_top_z - effective_hip_offset_FR[2]
    q0_FR = inverse_kinematics(np.array([d_x, d_y, d_z]), robot)
    print("Начальная конфигурация FR (для MPC):", q0_FR)
    p0_abs_FR = fk_numeric(q0_FR)
    
    p_ref_arr = generate_trajectory(config["N"], config["step_length"], config["swing_height"],
                                    robot, effective_hip_offset_FR, p0_abs_FR, desired_y, config["trajectory_type"])
    mpc = MPCController(robot, config, q0_FR)
    mpc.setup_problem(p_ref_arr, effective_hip_offset_FR, desired_y)
    q_sol_FR = mpc.solve()

    joint_positions_FR = []
    foot_traj_FR = []
    for q in q_sol_FR:
        pos = compute_leg_positions(q, effective_hip_offset_FR, robot, config["fix_hip"])
        joint_positions_FR.append(pos)
        foot_traj_FR.append(pos[3])
    joint_positions_FR = np.array(joint_positions_FR)
    foot_traj_FR = np.array(foot_traj_FR)

    static_positions_FL = compute_leg_positions(q_static, effective_hip_offset_FL, robot, fix_hip=True)
    static_positions_RR = compute_leg_positions(q_static, effective_hip_offset_RR, robot, fix_hip=True)
    static_positions_RL = compute_leg_positions(q_static, effective_hip_offset_RL, robot, fix_hip=True)

    print("Длины звеньев:")
    for leg, pos in zip(["FR", "FL", "RR", "RL"], [joint_positions_FR[0], static_positions_FL, static_positions_RR, static_positions_RL]):
        lk = np.linalg.norm(pos[1] - pos[0])
        la = np.linalg.norm(pos[2] - pos[1])
        lf = np.linalg.norm(pos[3] - pos[2])
        print(f"{leg}: Hip-Knee: {lk:.3f}, Knee-Ankle: {la:.3f}, Ankle-Foot: {lf:.3f}")

    animate_mpc(joint_positions_FR, foot_traj_FR, robot.trunk_dims, trunk_center,
                static_positions_FL, static_positions_RR, static_positions_RL, board_top_z, robot.link_masses)

# -------------------------------
# Режим com_transfering (перемещение trunk с фиксированными стопами ног)
# -------------------------------
def run_com_transfering():
    config = default_config.copy()
    robot = RobotModel(config["urdf_file"])

    distance_between_skate_and_robot = 0.12
    board_top_z = 0.058
    standing_height = board_top_z + distance_between_skate_and_robot
    trunk_center = np.array([0.0, 0.0, standing_height])
    config["standing_height"] = standing_height
    com_shift = config["com_shifting"]

    # Эффективные оффсеты
    effective_offsets = {
        "FR": trunk_center + (robot.hip_offset_FR + robot.hip_fixed_offset_FR),
        "FL": trunk_center + (robot.hip_offset_FL + robot.hip_fixed_offset_FL),
        "RR": trunk_center + (robot.hip_offset_RR + robot.hip_fixed_offset_RR),
        "RL": trunk_center + (robot.hip_offset_RL + robot.hip_fixed_offset_RL)
    }
    # ИК для статичной позы ног (каждая стопа на доске)
    q_static = {}
    foot_static = {}
    for leg in effective_offsets:
        d0 = np.array([0.0, 0.0, board_top_z - effective_offsets[leg][2]])
        q_static[leg] = inverse_kinematics(d0, robot)
        foot_static[leg] = effective_offsets[leg] + np.array(
            forward_kinematics_relative(q_static[leg], robot, fix_hip=False)
        ).flatten()

    # Создаём ЦИКЛ: 0 -> +com_shift -> 0 -> -com_shift -> 0
    cycle_points = [0.0, +com_shift, 0.0, -com_shift, 0.0]
    num_frames = config["N"]
    # Для равномерности разбиваем общее число кадров между этими участками
    segment_len = num_frames // (len(cycle_points) - 1)

    trunk_ys = []
    for i in range(len(cycle_points)-1):
        startY = trunk_center[1] + cycle_points[i]
        endY   = trunk_center[1] + cycle_points[i+1]
        for j in range(segment_len):
            alpha = j / (segment_len - 1)
            y_val = (1-alpha)*startY + alpha*endY
            trunk_ys.append(y_val)

    # Если кадров чуть меньше/больше, можно усечь/дополнить
    trunk_traj = []
    for y in trunk_ys:
        trunk_traj.append([trunk_center[0], y, trunk_center[2]])
    trunk_traj = np.array(trunk_traj)

    # Накопим траектории ног и CoM
    leg_trajs = {leg: [] for leg in effective_offsets}
    com_traj = []
    for i in range(len(trunk_traj)):
        new_trunk = trunk_traj[i]
        current_leg_positions = {}
        for leg in effective_offsets:
            # "динамический" offset
            if leg == "FR":
                hip_off = robot.hip_offset_FR + robot.hip_fixed_offset_FR
            elif leg == "FL":
                hip_off = robot.hip_offset_FL + robot.hip_fixed_offset_FL
            elif leg == "RR":
                hip_off = robot.hip_offset_RR + robot.hip_fixed_offset_RR
            else:
                hip_off = robot.hip_offset_RL + robot.hip_fixed_offset_RL
            new_eff = new_trunk + hip_off

            # стопа должна оставаться на месте foot_static[leg]
            desired_foot_world = foot_static[leg]
            d_new = desired_foot_world - new_eff
            q_new = inverse_kinematics(d_new, robot)
            pos = compute_leg_positions(q_new, new_eff, robot, fix_hip=False)
            current_leg_positions[leg] = pos
        for leg in current_leg_positions:
            leg_trajs[leg].append(current_leg_positions[leg])

        c = compute_robot_com(new_trunk, current_leg_positions, robot.link_masses)
        com_traj.append(c)

    for leg in leg_trajs:
        leg_trajs[leg] = np.array(leg_trajs[leg])
    com_traj = np.array(com_traj)

    animate_com_transfering(trunk_traj, leg_trajs, com_traj, board_top_z, robot.trunk_dims)

# -------------------------------
# Основная программа
# -------------------------------
def main():
    # Если в командной строке указан аргумент, выбираем режим:
    # "mpc_pushing" – исходный функционал с MPC,
    # "com_transfering" – смещение trunk (перемещение CoM) с фиксацией стоп ног.
    mode = "mpc_pushing"
    if len(sys.argv) > 1:
        mode = sys.argv[1]
    if mode == "com_transfering":
        run_com_transfering()
    else:
        run_mpc_pushing()

if __name__ == "__main__":
    main()
