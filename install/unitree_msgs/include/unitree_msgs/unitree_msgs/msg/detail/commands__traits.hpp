// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__COMMANDS__TRAITS_HPP_
#define UNITREE_MSGS__MSG__DETAIL__COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "unitree_msgs/msg/detail/commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace unitree_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Commands & msg,
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

  // member: kp
  {
    if (msg.kp.size() == 0) {
      out << "kp: []";
    } else {
      out << "kp: [";
      size_t pending_items = msg.kp.size();
      for (auto item : msg.kp) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: kd
  {
    if (msg.kd.size() == 0) {
      out << "kd: []";
    } else {
      out << "kd: [";
      size_t pending_items = msg.kd.size();
      for (auto item : msg.kd) {
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
  const Commands & msg,
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

  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kp.size() == 0) {
      out << "kp: []\n";
    } else {
      out << "kp:\n";
      for (auto item : msg.kp) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.kd.size() == 0) {
      out << "kd: []\n";
    } else {
      out << "kd:\n";
      for (auto item : msg.kd) {
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

inline std::string to_yaml(const Commands & msg, bool use_flow_style = false)
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
  const unitree_msgs::msg::Commands & msg,
  std::ostream & out, size_t indentation = 0)
{
  unitree_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use unitree_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const unitree_msgs::msg::Commands & msg)
{
  return unitree_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<unitree_msgs::msg::Commands>()
{
  return "unitree_msgs::msg::Commands";
}

template<>
inline const char * name<unitree_msgs::msg::Commands>()
{
  return "unitree_msgs/msg/Commands";
}

template<>
struct has_fixed_size<unitree_msgs::msg::Commands>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unitree_msgs::msg::Commands>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unitree_msgs::msg::Commands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UNITREE_MSGS__MSG__DETAIL__COMMANDS__TRAITS_HPP_
