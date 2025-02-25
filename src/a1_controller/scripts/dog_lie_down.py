#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Float64

def main():
    rospy.init_node("dog_lie_down", anonymous=False)
    
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
    
    angle_hip   = 0.5
    angle_thigh = 1.1
    angle_calf  = -2.65

    rospy.loginfo("[hip, thigh, calf] = [%.2f, %.2f, %.2f]", 
                  angle_hip, angle_thigh, angle_calf)
    
    rate = rospy.Rate(10)  # Hz
    while not rospy.is_shutdown():
        pub_FR_hip.publish(Float64(data=-angle_hip))
        pub_FR_thigh.publish(Float64(data=angle_thigh))
        pub_FR_calf.publish(Float64(data=angle_calf))
        
        pub_FL_hip.publish(Float64(data=angle_hip))
        pub_FL_thigh.publish(Float64(data=angle_thigh))
        pub_FL_calf.publish(Float64(data=angle_calf))
        
        pub_RR_hip.publish(Float64(data=-angle_hip))
        pub_RR_thigh.publish(Float64(data=angle_thigh))
        pub_RR_calf.publish(Float64(data=angle_calf))
        
        pub_RL_hip.publish(Float64(data=angle_hip))
        pub_RL_thigh.publish(Float64(data=angle_thigh))
        pub_RL_calf.publish(Float64(data=angle_calf))
        
        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
