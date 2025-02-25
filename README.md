
## Setup
```
cd src && catkin_init_workspace
cd .. && catkin_make
source devel/setup.bash
roscd a1_controller/scripts && chmod +x robot_controller_gazebo.py
cp -r RoboticsUtilities ~/.local/lib/python3.8/site-packages
roscd a1_joystick/scripts && chmod +x ramped_joystick.py
```

## Run
```
source devel/setup.bash
roslaunch a1 run_robot_gazebo.launch
```
After all the nodes have started, you can start using your joystick to control the robot.

If the robot happens to be on its back when you start Gazebo, simply press CTRL + R. 


