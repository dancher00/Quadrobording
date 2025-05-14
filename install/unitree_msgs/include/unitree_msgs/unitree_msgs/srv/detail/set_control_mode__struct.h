// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_H_
#define UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'control_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetControlMode in the package unitree_msgs.
typedef struct unitree_msgs__srv__SetControlMode_Request
{
  rosidl_runtime_c__String control_mode;
} unitree_msgs__srv__SetControlMode_Request;

// Struct for a sequence of unitree_msgs__srv__SetControlMode_Request.
typedef struct unitree_msgs__srv__SetControlMode_Request__Sequence
{
  unitree_msgs__srv__SetControlMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_msgs__srv__SetControlMode_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_control_mode'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetControlMode in the package unitree_msgs.
typedef struct unitree_msgs__srv__SetControlMode_Response
{
  bool accept;
  rosidl_runtime_c__String current_control_mode;
} unitree_msgs__srv__SetControlMode_Response;

// Struct for a sequence of unitree_msgs__srv__SetControlMode_Response.
typedef struct unitree_msgs__srv__SetControlMode_Response__Sequence
{
  unitree_msgs__srv__SetControlMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unitree_msgs__srv__SetControlMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_H_
