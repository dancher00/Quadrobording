// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__STATES__TRAITS_HPP_
#define UNITREE_MSGS__MSG__DETAIL__STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_msgs/msg/detail/states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const States & msg,
  std::ostream & out)
{
  out << "{";
  // member: t
  {
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
    out << ", ";
  }

  // member: qj
  {
    if (msg.qj.size() == 0) {
      out << "qj: []";
    } else {
      out << "qj: [";
      size_t pending_items = msg.qj.size();
      for (auto item : msg.qj) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: vj
  {
    if (msg.vj.size() == 0) {
      out << "vj: []";
    } else {
      out << "vj: [";
      size_t pending_items = msg.vj.size();
      for (auto item : msg.vj) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tauj
  {
    if (msg.tauj.size() == 0) {
      out << "tauj: []";
    } else {
      out << "tauj: [";
      size_t pending_items = msg.tauj.size();
      for (auto item : msg.tauj) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: imu_orientation
  {
    if (msg.imu_orientation.size() == 0) {
      out << "imu_orientation: []";
    } else {
      out << "imu_orientation: [";
      size_t pending_items = msg.imu_orientation.size();
      for (auto item : msg.imu_orientation) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: imu_angular_velocity
  {
    if (msg.imu_angular_velocity.size() == 0) {
      out << "imu_angular_velocity: []";
    } else {
      out << "imu_angular_velocity: [";
      size_t pending_items = msg.imu_angular_velocity.size();
      for (auto item : msg.imu_angular_velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: imu_linear_acceleration
  {
    if (msg.imu_linear_acceleration.size() == 0) {
      out << "imu_linear_acceleration: []";
    } else {
      out << "imu_linear_acceleration: [";
      size_t pending_items = msg.imu_linear_acceleration.size();
      for (auto item : msg.imu_linear_acceleration) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: foot_force_sensor
  {
    if (msg.foot_force_sensor.size() == 0) {
      out << "foot_force_sensor: []";
    } else {
      out << "foot_force_sensor: [";
      size_t pending_items = msg.foot_force_sensor.size();
      for (auto item : msg.foot_force_sensor) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const States & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
    out << "\n";
  }

  // member: qj
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.qj.size() == 0) {
      out << "qj: []\n";
    } else {
      out << "qj:\n";
      for (auto item : msg.qj) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: vj
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vj.size() == 0) {
      out << "vj: []\n";
    } else {
      out << "vj:\n";
      for (auto item : msg.vj) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tauj
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tauj.size() == 0) {
      out << "tauj: []\n";
    } else {
      out << "tauj:\n";
      for (auto item : msg.tauj) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: imu_orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu_orientation.size() == 0) {
      out << "imu_orientation: []\n";
    } else {
      out << "imu_orientation:\n";
      for (auto item : msg.imu_orientation) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: imu_angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu_angular_velocity.size() == 0) {
      out << "imu_angular_velocity: []\n";
    } else {
      out << "imu_angular_velocity:\n";
      for (auto item : msg.imu_angular_velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: imu_linear_acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imu_linear_acceleration.size() == 0) {
      out << "imu_linear_acceleration: []\n";
    } else {
      out << "imu_linear_acceleration:\n";
      for (auto item : msg.imu_linear_acceleration) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: foot_force_sensor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.foot_force_sensor.size() == 0) {
      out << "foot_force_sensor: []\n";
    } else {
      out << "foot_force_sensor:\n";
      for (auto item : msg.foot_force_sensor) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const States & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace unitree_msgs

namespace rosidl_generator_traits
{

[[deprecated("use unitree_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const unitree_msgs::msg::States & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const unitree_msgs::msg::States & msg)
{
  return unitree_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_msgs::msg::States>()
{
  return "unitree_msgs::msg::States";
}

template<>
inline const char * name<unitree_msgs::msg::States>()
{
  return "unitree_msgs/msg/States";
}

template<>
struct has_fixed_size<unitree_msgs::msg::States>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_msgs::msg::States>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_msgs::msg::States>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_MSGS__MSG__DETAIL__STATES__TRAITS_HPP_
