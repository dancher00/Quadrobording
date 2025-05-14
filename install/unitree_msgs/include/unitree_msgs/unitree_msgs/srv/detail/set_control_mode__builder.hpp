// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__BUILDER_HPP_
#define UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_msgs/srv/detail/set_control_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_msgs
{

namespace srv
{

namespace builder
{

class Init_SetControlMode_Request_control_mode
{
public:
  Init_SetControlMode_Request_control_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::unitree_msgs::srv::SetControlMode_Request control_mode(::unitree_msgs::srv::SetControlMode_Request::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_msgs::srv::SetControlMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_msgs::srv::SetControlMode_Request>()
{
  return unitree_msgs::srv::builder::Init_SetControlMode_Request_control_mode();
}

}  // namespace unitree_msgs


namespace unitree_msgs
{

namespace srv
{

namespace builder
{

class Init_SetControlMode_Response_current_control_mode
{
public:
  explicit Init_SetControlMode_Response_current_control_mode(::unitree_msgs::srv::SetControlMode_Response & msg)
  : msg_(msg)
  {}
  ::unitree_msgs::srv::SetControlMode_Response current_control_mode(::unitree_msgs::srv::SetControlMode_Response::_current_control_mode_type arg)
  {
    msg_.current_control_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_msgs::srv::SetControlMode_Response msg_;
};

class Init_SetControlMode_Response_accept
{
public:
  Init_SetControlMode_Response_accept()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetControlMode_Response_current_control_mode accept(::unitree_msgs::srv::SetControlMode_Response::_accept_type arg)
  {
    msg_.accept = std::move(arg);
    return Init_SetControlMode_Response_current_control_mode(msg_);
  }

private:
  ::unitree_msgs::srv::SetControlMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_msgs::srv::SetControlMode_Response>()
{
  return unitree_msgs::srv::builder::Init_SetControlMode_Response_accept();
}

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__BUILDER_HPP_
