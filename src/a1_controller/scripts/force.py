#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
import sys, select, termios, tty
from gazebo_msgs.srv import ApplyBodyWrench, ApplyBodyWrenchRequest
from geometry_msgs.msg import Wrench, Vector3

def getKey(timeout=0.1):
    """Считывает одно нажатие клавиши (не блокируясь надолго)."""
    fd = sys.stdin.fileno()
    old_attr = termios.tcgetattr(fd)
    try:
        tty.setraw(fd)
        rlist, _, _ = select.select([sys.stdin], [], [], timeout)
        if rlist:
            key = sys.stdin.read(1)
        else:
            key = ''
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_attr)
    return key

def main():
    rospy.init_node("force_applier_local", anonymous=True)
    rospy.loginfo("Запуск ноды force_applier_local...")

    # Ждём, пока сервис будет доступен
    rospy.wait_for_service("/gazebo/apply_body_wrench")
    apply_wrench_service = rospy.ServiceProxy("/gazebo/apply_body_wrench", ApplyBodyWrench)

    rospy.loginfo("Сервис /gazebo/apply_body_wrench найден.")
    rospy.loginfo("Нажмите 'q' (латинскую) для применения силы в локальном X базовой ссылки. Ctrl+C для выхода.")

    rate = rospy.Rate(50)  # 50 Гц
    while not rospy.is_shutdown():
        key = getKey(timeout=0.1)
        if key == 'q':
            # Пример: сила 20 Н вдоль локальной оси X
            force_value = 20.0

            req = ApplyBodyWrenchRequest()
            # ВАЖНО: имя модели и ссылки. Если у вас реально "ski_0", меняйте здесь!
            req.body_name = "ski::base_link"
            req.reference_frame = "ski::base_link"

            # Формируем Wrench (сила + момент = 0)
            wrench = Wrench()
            # Сила 20 Н вдоль локальной X:
            wrench.force = Vector3(force_value, 0.0, 0.0)
            wrench.torque = Vector3(0.0, 0.0, 0.0)

            req.wrench = wrench

            # Применяем силу немедленно
            req.start_time = rospy.Time(0)
            # Применяем силу на 0.5 секунды
            req.duration = rospy.Duration(0.5)

            try:
                resp = apply_wrench_service(req)
                if resp.success:
                    rospy.loginfo("Успешно применили %.1f Н в локальной оси X к %s" %
                                  (force_value, req.body_name))
                else:
                    rospy.logwarn("Не удалось применить силу: %s" % resp.status_message)
            except rospy.ServiceException as e:
                rospy.logerr("Сбой при вызове /gazebo/apply_body_wrench: %s" % e)

        rate.sleep()

if __name__ == "__main__":
    main()
