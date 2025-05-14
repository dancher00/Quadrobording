// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_
#define UNITREE_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "unitree_msgs/msg/detail/commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace unitree_msgs
{

namespace msg
{

namespace builder
{

class Init_Commands_kd
{
public:
  explicit Init_Commands_kd(::unitree_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  ::unitree_msgs::msg::Commands kd(::unitree_msgs::msg::Commands::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

class Init_Commands_kp
{
public:
  explicit Init_Commands_kp(::unitree_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_kd kp(::unitree_msgs::msg::Commands::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_Commands_kd(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

class Init_Commands_tauj
{
public:
  explicit Init_Commands_tauj(::unitree_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_kp tauj(::unitree_msgs::msg::Commands::_tauj_type arg)
  {
    msg_.tauj = std::move(arg);
    return Init_Commands_kp(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

class Init_Commands_vj
{
public:
  explicit Init_Commands_vj(::unitree_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_tauj vj(::unitree_msgs::msg::Commands::_vj_type arg)
  {
    msg_.vj = std::move(arg);
    return Init_Commands_tauj(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

class Init_Commands_qj
{
public:
  explicit Init_Commands_qj(::unitree_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_vj qj(::unitree_msgs::msg::Commands::_qj_type arg)
  {
    msg_.qj = std::move(arg);
    return Init_Commands_vj(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

class Init_Commands_t
{
public:
  Init_Commands_t()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Commands_qj t(::unitree_msgs::msg::Commands::_t_type arg)
  {
    msg_.t = std::move(arg);
    return Init_Commands_qj(msg_);
  }

private:
  ::unitree_msgs::msg::Commands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::unitree_msgs::msg::Commands>()
{
  return unitree_msgs::msg::builder::Init_Commands_t();
}

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_
