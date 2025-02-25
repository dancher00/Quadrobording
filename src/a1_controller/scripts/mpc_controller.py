#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Float64
import casadi as ca
import numpy as np
import xml.etree.ElementTree as ET
import math

# -------------------------------
# config
# -------------------------------
default_config = {
    "urdf_file": "/home/danya/thes/a1_sim_py/src/a1_description/urdf/a1.urdf",
    "standing_height": 0.0,   # doesn't use
    "step_length": 0.2,
    "swing_height": 0.09,     # Ampl in swing phase
    "trajectory_type": "two_phase",
    "N": 100,
    "dt": 0.01,
    "dq_max": 28.6,
    "fix_hip": False,         
    "q0": [0.0, 2.5, -1],
    "w_pos": 10000.0,
    "w_dq": 0.1,
    "w_smooth": 0.1,
    "w_y": 1000.0,
    "w_z": 10000.0,
    "joint_limits": {
         "q_min": [-0.80, -1.05, -2.70],
         "q_max": [ 0.80,  4.19, -0.92]
    }
}

lie_down_angles = np.array([0.5, 1.1, -2.65])

desired_deep_z = -0.15
desired_x = 0.0       
desired_y_local = 0.2  

def read_offset(urdf_file, joint_name):
    tree = ET.parse(urdf_file)
    root = tree.getroot()
    for joint in root.findall("joint"):
        if joint.get("name") == joint_name:
            origin = joint.find("origin")
            if origin is not None and "xyz" in origin.attrib:
                return np.array([float(v) for v in origin.attrib["xyz"].split()])
    return None

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
            rospy.logwarn("Error parsing")
            L1, L2, L3 = 0.085, 0.20, 0.20
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
        return trunk_dims

def R_y(angle):
    return np.array([[ca.cos(angle), 0, ca.sin(angle)],
                     [0, 1, 0],
                     [-ca.sin(angle), 0, ca.cos(angle)]])

def R_x(angle):
    return np.array([[1, 0, 0],
                     [0, ca.cos(angle), -ca.sin(angle)],
                     [0, ca.sin(angle), ca.cos(angle)]])

# -------------------------------
# q0 = 0:
#   x = L2*cos(q1)+L3*cos(q1+q2)
#   z = -L2*sin(q1)-L3*sin(q1+q2)
# -------------------------------
def forward_kinematics_relative(q, robot, fix_hip=False):
    q0, q1, q2 = q[0], q[1], q[2]
    x_local = robot.L2 * ca.cos(q1) + robot.L3 * ca.cos(q1+q2)
    z_local = - (robot.L2 * ca.sin(q1) + robot.L3 * ca.sin(q1+q2))
    p_local = ca.vertcat(x_local, 0, z_local)
    R_x_mat = ca.vertcat(
        ca.horzcat(1, 0, 0),
        ca.horzcat(0, ca.cos(q0), -ca.sin(q0)),
        ca.horzcat(0, ca.sin(q0), ca.cos(q0))
    )
    p_rel = R_x_mat @ p_local
    return p_rel

# -------------------------------
# p_abs = effective_hip_offset + p_rel
# -------------------------------
def forward_kinematics(q, robot, effective_hip_offset, fix_hip=False):
    p_rel = forward_kinematics_relative(q, robot, fix_hip)
    return effective_hip_offset + p_rel

# -------------------------------
# -------------------------------
def generate_trajectory(N, step_length, swing_height, robot, effective_hip_offset, p0_abs, desired_y, desired_x, trajectory_type="two_phase"):
    N1 = N // 2
    N2 = N - N1
    p_ref_list = []
    # dragging
    for k in range(N1+1):
        alpha = k / float(N1)
        x_val = desired_x - step_length * alpha
        y_val = 0
        z_val = desired_deep_z
        p_ref_list.append([x_val, y_val, z_val])
    # swing 
    for k in range(1, N2+1):
        alpha = k / float(N2)
        x_val = (desired_x - step_length) + step_length * alpha
        y_val = 0
        z_val = desired_deep_z + swing_height * math.sin(math.pi * alpha)
        p_ref_list.append([x_val, y_val, z_val])
    p_ref_arr = np.array(p_ref_list)
    p_ref_arr = effective_hip_offset + p_ref_arr
    return p_ref_arr

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
            cost += self.w_y * ca.sumsqr(p_foot[1] - desired_y)
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
# -------------------------------
def main():
    rospy.init_node("mpc_FR_controller", anonymous=False)
    
    pub_FR_hip   = rospy.Publisher("/a1_gazebo/FR_hip_joint/command",   Float64, queue_size=10)
    pub_FR_thigh = rospy.Publisher("/a1_gazebo/FR_thigh_joint/command", Float64, queue_size=10)
    pub_FR_calf  = rospy.Publisher("/a1_gazebo/FR_calf_joint/command",  Float64, queue_size=10)
    
    pub_FL_hip   = rospy.Publisher("/a1_gazebo/FL_hip_joint/command",   Float64, queue_size=10)
    pub_FL_thigh = rospy.Publisher("/a1_gazebo/FL_thigh_joint/command", Float64, queue_size=10)
    pub_FL_calf  = rospy.Publisher("/a1_gazebo/FL_calf_joint/command",  Float64, queue_size=10)
    
    pub_RR_hip   = rospy.Publisher("/a1_gazebo/RR_hip_joint/command",   Float64, queue_size=10)
    pub_RR_thigh = rospy.Publisher("/a1_gazebo/RR_thigh_joint/command", Float64, queue_size=10)
    pub_RR_calf  = rospy.Publisher("/a1_gazebo/RR_calf_joint/command",  Float64, queue_size=10)
    
    pub_RL_hip   = rospy.Publisher("/a1_gazebo/RL_hip_joint/command",   Float64, queue_size=10)
    pub_RL_thigh = rospy.Publisher("/a1_gazebo/RL_thigh_joint/command", Float64, queue_size=10)
    pub_RL_calf  = rospy.Publisher("/a1_gazebo/RL_calf_joint/command",  Float64, queue_size=10)
    
    rospy.sleep(1.0)
    
    q_static = lie_down_angles.copy()  # [0.5, 1.1, -2.65]
    
    trunk_center = np.array([0.0, 0.0, 0.0]) 
    
    robot = RobotModel(default_config["urdf_file"])
    
    effective_hip_offset_FR = trunk_center + (robot.hip_offset_FR + robot.hip_fixed_offset_FR)
    
    def fk_numeric(q, eff_offset, fix=False):
        p = forward_kinematics(q, robot, eff_offset, fix)
        return np.array(ca.DM(p)).flatten()
    p0_abs_static = fk_numeric(q_static, effective_hip_offset_FR, False)
    
    p_drag_local = np.array([desired_x, 0, desired_deep_z])
    p_drag = effective_hip_offset_FR + p_drag_local
    
    d_x = desired_x
    d_z = -desired_deep_z      r = math.hypot(d_x, d_z)
    cos_q2 = (r**2 - robot.L2**2 - robot.L3**2) / (2 * robot.L2 * robot.L3)
    if cos_q2 < -1 or cos_q2 > 1:
        rospy.logerr("dragging point is unreachable.")
        return
    q2_sol = -math.acos(cos_q2)
    q1_sol = math.atan2(d_z, d_x) - math.atan2(robot.L3 * math.sin(q2_sol), robot.L2 + robot.L3 * math.cos(q2_sol))
    q0_FR = np.array([0.0, q1_sol, q2_sol])
    
    p0_abs_FR = fk_numeric(q0_FR, effective_hip_offset_FR, False)
    rospy.loginfo("(base): [%.3f, %.3f, %.3f]",
                  p0_abs_FR[0], p0_abs_FR[1], p0_abs_FR[2])
    
    rate = rospy.Rate(1.0 / default_config["dt"])
    
    while not rospy.is_shutdown():
        p_ref_arr = generate_trajectory(default_config["N"], default_config["step_length"],
                                        default_config["swing_height"], robot,
                                        effective_hip_offset_FR, p0_abs_FR,
                                        effective_hip_offset_FR[1], desired_x, trajectory_type="two_phase")
        mpc = MPCController(robot, default_config, q0_FR)
        mpc.setup_problem(p_ref_arr, effective_hip_offset_FR, effective_hip_offset_FR[1])
        q_sol_FR = mpc.solve()  
        num_steps = q_sol_FR.shape[0]
        
        for step in range(num_steps):
            q_FR = q_sol_FR[step]
            pub_FR_hip.publish(Float64(data=q_FR[0]))
            pub_FR_thigh.publish(Float64(data=q_FR[1]))
            pub_FR_calf.publish(Float64(data=q_FR[2]))
            
            pub_FL_hip.publish(Float64(data=q_static[0]))
            pub_FL_thigh.publish(Float64(data=q_static[1]))
            pub_FL_calf.publish(Float64(data=q_static[2]))
            
            pub_RR_hip.publish(Float64(data=q_static[0]))
            pub_RR_thigh.publish(Float64(data=q_static[1]))
            pub_RR_calf.publish(Float64(data=q_static[2]))
            
            pub_RL_hip.publish(Float64(data=q_static[0]))
            pub_RL_thigh.publish(Float64(data=q_static[1]))
            pub_RL_calf.publish(Float64(data=q_static[2]))
            
            rate.sleep()
        q0_FR = q_sol_FR[-1]
        p0_abs_FR = fk_numeric(q0_FR, effective_hip_offset_FR, False)
        rospy.loginfo("FR: [%.3f, %.3f, %.3f]", q0_FR[0], q0_FR[1], q0_FR[2])
        rospy.loginfo("(base): [%.3f, %.3f, %.3f]",
                      p0_abs_FR[0], p0_abs_FR[1], p0_abs_FR[2])

if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass
