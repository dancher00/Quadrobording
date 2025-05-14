// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__STATES__BUILDER_HPP_
#define UNITREE_MSGS__MSG__DETAIL__STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_msgs/msg/detail/states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_msgs
{

namespace msg
{

namespace builder
{

class Init_States_foot_force_sensor
{
public:
  explicit Init_States_foot_force_sensor(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  ::unitree_msgs::msg::States foot_force_sensor(::unitree_msgs::msg::States::_foot_force_sensor_type arg)
  {
    msg_.foot_force_sensor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_imu_linear_acceleration
{
public:
  explicit Init_States_imu_linear_acceleration(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_foot_force_sensor imu_linear_acceleration(::unitree_msgs::msg::States::_imu_linear_acceleration_type arg)
  {
    msg_.imu_linear_acceleration = std::move(arg);
    return Init_States_foot_force_sensor(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_imu_angular_velocity
{
public:
  explicit Init_States_imu_angular_velocity(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_imu_linear_acceleration imu_angular_velocity(::unitree_msgs::msg::States::_imu_angular_velocity_type arg)
  {
    msg_.imu_angular_velocity = std::move(arg);
    return Init_States_imu_linear_acceleration(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_imu_orientation
{
public:
  explicit Init_States_imu_orientation(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_imu_angular_velocity imu_orientation(::unitree_msgs::msg::States::_imu_orientation_type arg)
  {
    msg_.imu_orientation = std::move(arg);
    return Init_States_imu_angular_velocity(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_tauj
{
public:
  explicit Init_States_tauj(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_imu_orientation tauj(::unitree_msgs::msg::States::_tauj_type arg)
  {
    msg_.tauj = std::move(arg);
    return Init_States_imu_orientation(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_vj
{
public:
  explicit Init_States_vj(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_tauj vj(::unitree_msgs::msg::States::_vj_type arg)
  {
    msg_.vj = std::move(arg);
    return Init_States_tauj(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_qj
{
public:
  explicit Init_States_qj(::unitree_msgs::msg::States & msg)
  : msg_(msg)
  {}
  Init_States_vj qj(::unitree_msgs::msg::States::_qj_type arg)
  {
    msg_.qj = std::move(arg);
    return Init_States_vj(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

class Init_States_t
{
public:
  Init_States_t()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_States_qj t(::unitree_msgs::msg::States::_t_type arg)
  {
    msg_.t = std::move(arg);
    return Init_States_qj(msg_);
  }

private:
  ::unitree_msgs::msg::States msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_msgs::msg::States>()
{
  return unitree_msgs::msg::builder::Init_States_t();
}

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__MSG__DETAIL__STATES__BUILDER_HPP_
