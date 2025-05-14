// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__TRAITS_HPP_
#define UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_msgs/srv/detail/set_control_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetControlMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetControlMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetControlMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace unitree_msgs

namespace rosidl_generator_traits
{

[[deprecated("use unitree_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_msgs::srv::SetControlMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_msgs::srv::SetControlMode_Request & msg)
{
  return unitree_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_msgs::srv::SetControlMode_Request>()
{
  return "unitree_msgs::srv::SetControlMode_Request";
}

template<>
inline const char * name<unitree_msgs::srv::SetControlMode_Request>()
{
  return "unitree_msgs/srv/SetControlMode_Request";
}

template<>
struct has_fixed_size<unitree_msgs::srv::SetControlMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<unitree_msgs::srv::SetControlMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<unitree_msgs::srv::SetControlMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace unitree_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetControlMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accept
  {
    out << "accept: ";
    rosidl_generator_traits::value_to_yaml(msg.accept, out);
    out << ", ";
  }

  // member: current_control_mode
  {
    out << "current_control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_control_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetControlMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accept
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accept: ";
    rosidl_generator_traits::value_to_yaml(msg.accept, out);
    out << "\n";
  }

  // member: current_control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_control_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetControlMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace unitree_msgs

namespace rosidl_generator_traits
{

[[deprecated("use unitree_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_msgs::srv::SetControlMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const unitree_msgs::srv::SetControlMode_Response & msg)
{
  return unitree_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_msgs::srv::SetControlMode_Response>()
{
  return "unitree_msgs::srv::SetControlMode_Response";
}

template<>
inline const char * name<unitree_msgs::srv::SetControlMode_Response>()
{
  return "unitree_msgs/srv/SetControlMode_Response";
}

template<>
struct has_fixed_size<unitree_msgs::srv::SetControlMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<unitree_msgs::srv::SetControlMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<unitree_msgs::srv::SetControlMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unitree_msgs::srv::SetControlMode>()
{
  return "unitree_msgs::srv::SetControlMode";
}

template<>
inline const char * name<unitree_msgs::srv::SetControlMode>()
{
  return "unitree_msgs/srv/SetControlMode";
}

template<>
struct has_fixed_size<unitree_msgs::srv::SetControlMode>
  : std::integral_constant<
    bool,
    has_fixed_size<unitree_msgs::srv::SetControlMode_Request>::value &&
    has_fixed_size<unitree_msgs::srv::SetControlMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<unitree_msgs::srv::SetControlMode>
  : std::integral_constant<
    bool,
    has_bounded_size<unitree_msgs::srv::SetControlMode_Request>::value &&
    has_bounded_size<unitree_msgs::srv::SetControlMode_Response>::value
  >
{
};

template<>
struct is_service<unitree_msgs::srv::SetControlMode>
  : std::true_type
{
};

template<>
struct is_service_request<unitree_msgs::srv::SetControlMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<unitree_msgs::srv::SetControlMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__TRAITS_HPP_
