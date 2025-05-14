// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "unitree_msgs/srv/detail/set_control_mode__rosidl_typesupport_introspection_c.h"
#include "unitree_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "unitree_msgs/srv/detail/set_control_mode__functions.h"
#include "unitree_msgs/srv/detail/set_control_mode__struct.h"


// Include directives for member types
// Member `control_mode`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  unitree_msgs__srv__SetControlMode_Request__init(message_memory);
}

void unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_fini_function(void * message_memory)
{
  unitree_msgs__srv__SetControlMode_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_member_array[1] = {
  {
    "control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs__srv__SetControlMode_Request, control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_members = {
  "unitree_msgs__srv",  // message namespace
  "SetControlMode_Request",  // message name
  1,  // number of fields
  sizeof(unitree_msgs__srv__SetControlMode_Request),
  unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_member_array,  // message members
  unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_type_support_handle = {
  0,
  &unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unitree_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Request)() {
  if (!unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_type_support_handle.typesupport_identifier) {
    unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &unitree_msgs__srv__SetControlMode_Request__rosidl_typesupport_introspection_c__SetControlMode_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "unitree_msgs/srv/detail/set_control_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "unitree_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "unitree_msgs/srv/detail/set_control_mode__functions.h"
// already included above
// #include "unitree_msgs/srv/detail/set_control_mode__struct.h"


// Include directives for member types
// Member `current_control_mode`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  unitree_msgs__srv__SetControlMode_Response__init(message_memory);
}

void unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_fini_function(void * message_memory)
{
  unitree_msgs__srv__SetControlMode_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_member_array[2] = {
  {
    "accept",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs__srv__SetControlMode_Response, accept),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unitree_msgs__srv__SetControlMode_Response, current_control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_members = {
  "unitree_msgs__srv",  // message namespace
  "SetControlMode_Response",  // message name
  2,  // number of fields
  sizeof(unitree_msgs__srv__SetControlMode_Response),
  unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_member_array,  // message members
  unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_type_support_handle = {
  0,
  &unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unitree_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Response)() {
  if (!unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_type_support_handle.typesupport_identifier) {
    unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &unitree_msgs__srv__SetControlMode_Response__rosidl_typesupport_introspection_c__SetControlMode_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "unitree_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "unitree_msgs/srv/detail/set_control_mode__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_members = {
  "unitree_msgs__srv",  // service namespace
  "SetControlMode",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_Request_message_type_support_handle,
  NULL  // response message
  // unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_Response_message_type_support_handle
};

static rosidl_service_type_support_t unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_type_support_handle = {
  0,
  &unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unitree_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode)() {
  if (!unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_type_support_handle.typesupport_identifier) {
    unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unitree_msgs, srv, SetControlMode_Response)()->data;
  }

  return &unitree_msgs__srv__detail__set_control_mode__rosidl_typesupport_introspection_c__SetControlMode_service_type_support_handle;
}
