// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_H_
#define UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/States in the package unitree_msgs.
typedef struct unitree_msgs__msg__States
{
  /// Time
  double t;
  /// float64[12] qJ                     # Joint position measurements
  /// float64[12] vJ                     # Joint velocity measurements
  /// float64[12] tauJ                   # Joint torque measurements
  ///  Joint position measurements
  double qj[12];
  /// Joint velocity measurements
  double vj[12];
  /// Joint torque measurements
  double tauj[12];
  /// Imu orientation estimation expressed as a quaternion (x, y, z, w)
  double imu_orientation[4];
  /// Imu angular velocity
  double imu_angular_velocity[3];
  /// Imu linear acceleration
  double imu_linear_acceleration[3];
  /// Force sensor measurements
  double foot_force_sensor[4];
} unitree_msgs__msg__States;

// Struct for a sequence of unitree_msgs__msg__States.
typedef struct unitree_msgs__msg__States__Sequence
{
  unitree_msgs__msg__States * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_msgs__msg__States__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_H_
