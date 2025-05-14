// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "unitree_msgs/msg/detail/commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace unitree_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Commands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) unitree_msgs::msg::Commands(_init);
}

void Commands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<unitree_msgs::msg::Commands *>(message_memory);
  typed_message->~Commands();
}

size_t size_function__Commands__qj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__Commands__qj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__Commands__qj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__Commands__qj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Commands__qj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Commands__qj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Commands__qj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__Commands__vj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__Commands__vj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__Commands__vj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__Commands__vj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Commands__vj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Commands__vj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Commands__vj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__Commands__tauj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__Commands__tauj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__Commands__tauj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__Commands__tauj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Commands__tauj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Commands__tauj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Commands__tauj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__Commands__kp(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__Commands__kp(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__Commands__kp(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__Commands__kp(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Commands__kp(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Commands__kp(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Commands__kp(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__Commands__kd(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__Commands__kd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__Commands__kd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__Commands__kd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Commands__kd(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Commands__kd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Commands__kd(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Commands_message_member_array[6] = {
  {
    "t",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, t),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "qj",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, qj),  // bytes offset in struct
    nullptr,  // default value
    size_function__Commands__qj,  // size() function pointer
    get_const_function__Commands__qj,  // get_const(index) function pointer
    get_function__Commands__qj,  // get(index) function pointer
    fetch_function__Commands__qj,  // fetch(index, &value) function pointer
    assign_function__Commands__qj,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vj",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, vj),  // bytes offset in struct
    nullptr,  // default value
    size_function__Commands__vj,  // size() function pointer
    get_const_function__Commands__vj,  // get_const(index) function pointer
    get_function__Commands__vj,  // get(index) function pointer
    fetch_function__Commands__vj,  // fetch(index, &value) function pointer
    assign_function__Commands__vj,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tauj",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, tauj),  // bytes offset in struct
    nullptr,  // default value
    size_function__Commands__tauj,  // size() function pointer
    get_const_function__Commands__tauj,  // get_const(index) function pointer
    get_function__Commands__tauj,  // get(index) function pointer
    fetch_function__Commands__tauj,  // fetch(index, &value) function pointer
    assign_function__Commands__tauj,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, kp),  // bytes offset in struct
    nullptr,  // default value
    size_function__Commands__kp,  // size() function pointer
    get_const_function__Commands__kp,  // get_const(index) function pointer
    get_function__Commands__kp,  // get(index) function pointer
    fetch_function__Commands__kp,  // fetch(index, &value) function pointer
    assign_function__Commands__kp,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "kd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    12,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::Commands, kd),  // bytes offset in struct
    nullptr,  // default value
    size_function__Commands__kd,  // size() function pointer
    get_const_function__Commands__kd,  // get_const(index) function pointer
    get_function__Commands__kd,  // get(index) function pointer
    fetch_function__Commands__kd,  // fetch(index, &value) function pointer
    assign_function__Commands__kd,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Commands_message_members = {
  "unitree_msgs::msg",  // message namespace
  "Commands",  // message name
  6,  // number of fields
  sizeof(unitree_msgs::msg::Commands),
  Commands_message_member_array,  // message members
  Commands_init_function,  // function to initialize message memory (memory has to be allocated)
  Commands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Commands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Commands_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace unitree_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<unitree_msgs::msg::Commands>()
{
  return &::unitree_msgs::msg::rosidl_typesupport_introspection_cpp::Commands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, unitree_msgs, msg, Commands)() {
  return &::unitree_msgs::msg::rosidl_typesupport_introspection_cpp::Commands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
