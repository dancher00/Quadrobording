// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "unitree_msgs/msg/detail/states__struct.hpp"
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

void States_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) unitree_msgs::msg::States(_init);
}

void States_fini_function(void * message_memory)
{
  auto typed_message = static_cast<unitree_msgs::msg::States *>(message_memory);
  typed_message->~States();
}

size_t size_function__States__qj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__States__qj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__States__qj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__qj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__qj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__qj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__qj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__vj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__States__vj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__States__vj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__vj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__vj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__vj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__vj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__tauj(const void * untyped_member)
{
  (void)untyped_member;
  return 12;
}

const void * get_const_function__States__tauj(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void * get_function__States__tauj(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 12> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__tauj(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__tauj(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__tauj(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__tauj(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__imu_orientation(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__States__imu_orientation(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__States__imu_orientation(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__imu_orientation(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__imu_orientation(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__imu_orientation(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__imu_orientation(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__imu_angular_velocity(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__States__imu_angular_velocity(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__States__imu_angular_velocity(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__imu_angular_velocity(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__imu_angular_velocity(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__imu_angular_velocity(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__imu_angular_velocity(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__imu_linear_acceleration(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__States__imu_linear_acceleration(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__States__imu_linear_acceleration(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__imu_linear_acceleration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__imu_linear_acceleration(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__imu_linear_acceleration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__imu_linear_acceleration(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__States__foot_force_sensor(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__States__foot_force_sensor(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__States__foot_force_sensor(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__States__foot_force_sensor(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__States__foot_force_sensor(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__States__foot_force_sensor(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__States__foot_force_sensor(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember States_message_member_array[8] = {
  {
    "t",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::States, t),  // bytes offset in struct
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
    offsetof(unitree_msgs::msg::States, qj),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__qj,  // size() function pointer
    get_const_function__States__qj,  // get_const(index) function pointer
    get_function__States__qj,  // get(index) function pointer
    fetch_function__States__qj,  // fetch(index, &value) function pointer
    assign_function__States__qj,  // assign(index, value) function pointer
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
    offsetof(unitree_msgs::msg::States, vj),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__vj,  // size() function pointer
    get_const_function__States__vj,  // get_const(index) function pointer
    get_function__States__vj,  // get(index) function pointer
    fetch_function__States__vj,  // fetch(index, &value) function pointer
    assign_function__States__vj,  // assign(index, value) function pointer
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
    offsetof(unitree_msgs::msg::States, tauj),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__tauj,  // size() function pointer
    get_const_function__States__tauj,  // get_const(index) function pointer
    get_function__States__tauj,  // get(index) function pointer
    fetch_function__States__tauj,  // fetch(index, &value) function pointer
    assign_function__States__tauj,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu_orientation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::States, imu_orientation),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__imu_orientation,  // size() function pointer
    get_const_function__States__imu_orientation,  // get_const(index) function pointer
    get_function__States__imu_orientation,  // get(index) function pointer
    fetch_function__States__imu_orientation,  // fetch(index, &value) function pointer
    assign_function__States__imu_orientation,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu_angular_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::States, imu_angular_velocity),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__imu_angular_velocity,  // size() function pointer
    get_const_function__States__imu_angular_velocity,  // get_const(index) function pointer
    get_function__States__imu_angular_velocity,  // get(index) function pointer
    fetch_function__States__imu_angular_velocity,  // fetch(index, &value) function pointer
    assign_function__States__imu_angular_velocity,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu_linear_acceleration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::States, imu_linear_acceleration),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__imu_linear_acceleration,  // size() function pointer
    get_const_function__States__imu_linear_acceleration,  // get_const(index) function pointer
    get_function__States__imu_linear_acceleration,  // get(index) function pointer
    fetch_function__States__imu_linear_acceleration,  // fetch(index, &value) function pointer
    assign_function__States__imu_linear_acceleration,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "foot_force_sensor",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs::msg::States, foot_force_sensor),  // bytes offset in struct
    nullptr,  // default value
    size_function__States__foot_force_sensor,  // size() function pointer
    get_const_function__States__foot_force_sensor,  // get_const(index) function pointer
    get_function__States__foot_force_sensor,  // get(index) function pointer
    fetch_function__States__foot_force_sensor,  // fetch(index, &value) function pointer
    assign_function__States__foot_force_sensor,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers States_message_members = {
  "unitree_msgs::msg",  // message namespace
  "States",  // message name
  8,  // number of fields
  sizeof(unitree_msgs::msg::States),
  States_message_member_array,  // message members
  States_init_function,  // function to initialize message memory (memory has to be allocated)
  States_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t States_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &States_message_members,
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
get_message_type_support_handle<unitree_msgs::msg::States>()
{
  return &::unitree_msgs::msg::rosidl_typesupport_introspection_cpp::States_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, unitree_msgs, msg, States)() {
  return &::unitree_msgs::msg::rosidl_typesupport_introspection_cpp::States_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
