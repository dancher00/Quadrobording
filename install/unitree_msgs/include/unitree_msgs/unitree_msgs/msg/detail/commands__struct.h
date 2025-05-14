// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_H_
#define UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Commands in the package unitree_msgs.
typedef struct unitree_msgs__msg__Commands
{
  /// Time
  double t;
  /// float64[12] qJ                     # Joint position commands
  /// float64[12] vJ                     # Joint velocity commands
  /// float64[12] tauJ                   # Joint torque commands
  ///  Joint position commands
  double qj[12];
  /// Joint velocity commands
  double vj[12];
  /// Joint torque commands
  double tauj[12];
  /// float64[12] Kp                     # Joint position gain commands
  /// float64[12] Kd                     # Joint velocity gain commands
  ///  Joint position gain commands
  double kp[12];
  /// Joint velocity gain commands
  double kd[12];
} unitree_msgs__msg__Commands;

// Struct for a sequence of unitree_msgs__msg__Commands.
typedef struct unitree_msgs__msg__Commands__Sequence
{
  unitree_msgs__msg__Commands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_msgs__msg__Commands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_H_
