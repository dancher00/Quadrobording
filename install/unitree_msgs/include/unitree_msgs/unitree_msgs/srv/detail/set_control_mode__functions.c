// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice
#include "unitree_msgs/srv/detail/set_control_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `control_mode`
#include "rosidl_runtime_c/string_functions.h"

bool
unitree_msgs__srv__SetControlMode_Request__init(unitree_msgs__srv__SetControlMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__init(&msg->control_mode)) {
    unitree_msgs__srv__SetControlMode_Request__fini(msg);
    return false;
  }
  return true;
}

void
unitree_msgs__srv__SetControlMode_Request__fini(unitree_msgs__srv__SetControlMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // control_mode
  rosidl_runtime_c__String__fini(&msg->control_mode);
}

bool
unitree_msgs__srv__SetControlMode_Request__are_equal(const unitree_msgs__srv__SetControlMode_Request * lhs, const unitree_msgs__srv__SetControlMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->control_mode), &(rhs->control_mode)))
  {
    return false;
  }
  return true;
}

bool
unitree_msgs__srv__SetControlMode_Request__copy(
  const unitree_msgs__srv__SetControlMode_Request * input,
  unitree_msgs__srv__SetControlMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // control_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->control_mode), &(output->control_mode)))
  {
    return false;
  }
  return true;
}

unitree_msgs__srv__SetControlMode_Request *
unitree_msgs__srv__SetControlMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Request * msg = (unitree_msgs__srv__SetControlMode_Request *)allocator.allocate(sizeof(unitree_msgs__srv__SetControlMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_msgs__srv__SetControlMode_Request));
  bool success = unitree_msgs__srv__SetControlMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_msgs__srv__SetControlMode_Request__destroy(unitree_msgs__srv__SetControlMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_msgs__srv__SetControlMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_msgs__srv__SetControlMode_Request__Sequence__init(unitree_msgs__srv__SetControlMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Request * data = NULL;

  if (size) {
    data = (unitree_msgs__srv__SetControlMode_Request *)allocator.zero_allocate(size, sizeof(unitree_msgs__srv__SetControlMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_msgs__srv__SetControlMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_msgs__srv__SetControlMode_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
unitree_msgs__srv__SetControlMode_Request__Sequence__fini(unitree_msgs__srv__SetControlMode_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      unitree_msgs__srv__SetControlMode_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

unitree_msgs__srv__SetControlMode_Request__Sequence *
unitree_msgs__srv__SetControlMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Request__Sequence * array = (unitree_msgs__srv__SetControlMode_Request__Sequence *)allocator.allocate(sizeof(unitree_msgs__srv__SetControlMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_msgs__srv__SetControlMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_msgs__srv__SetControlMode_Request__Sequence__destroy(unitree_msgs__srv__SetControlMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_msgs__srv__SetControlMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_msgs__srv__SetControlMode_Request__Sequence__are_equal(const unitree_msgs__srv__SetControlMode_Request__Sequence * lhs, const unitree_msgs__srv__SetControlMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_msgs__srv__SetControlMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__srv__SetControlMode_Request__Sequence__copy(
  const unitree_msgs__srv__SetControlMode_Request__Sequence * input,
  unitree_msgs__srv__SetControlMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_msgs__srv__SetControlMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_msgs__srv__SetControlMode_Request * data =
      (unitree_msgs__srv__SetControlMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_msgs__srv__SetControlMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_msgs__srv__SetControlMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_msgs__srv__SetControlMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_control_mode`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
unitree_msgs__srv__SetControlMode_Response__init(unitree_msgs__srv__SetControlMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accept
  // current_control_mode
  if (!rosidl_runtime_c__String__init(&msg->current_control_mode)) {
    unitree_msgs__srv__SetControlMode_Response__fini(msg);
    return false;
  }
  return true;
}

void
unitree_msgs__srv__SetControlMode_Response__fini(unitree_msgs__srv__SetControlMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // accept
  // current_control_mode
  rosidl_runtime_c__String__fini(&msg->current_control_mode);
}

bool
unitree_msgs__srv__SetControlMode_Response__are_equal(const unitree_msgs__srv__SetControlMode_Response * lhs, const unitree_msgs__srv__SetControlMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accept
  if (lhs->accept != rhs->accept) {
    return false;
  }
  // current_control_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_control_mode), &(rhs->current_control_mode)))
  {
    return false;
  }
  return true;
}

bool
unitree_msgs__srv__SetControlMode_Response__copy(
  const unitree_msgs__srv__SetControlMode_Response * input,
  unitree_msgs__srv__SetControlMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accept
  output->accept = input->accept;
  // current_control_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->current_control_mode), &(output->current_control_mode)))
  {
    return false;
  }
  return true;
}

unitree_msgs__srv__SetControlMode_Response *
unitree_msgs__srv__SetControlMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Response * msg = (unitree_msgs__srv__SetControlMode_Response *)allocator.allocate(sizeof(unitree_msgs__srv__SetControlMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_msgs__srv__SetControlMode_Response));
  bool success = unitree_msgs__srv__SetControlMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_msgs__srv__SetControlMode_Response__destroy(unitree_msgs__srv__SetControlMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_msgs__srv__SetControlMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_msgs__srv__SetControlMode_Response__Sequence__init(unitree_msgs__srv__SetControlMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Response * data = NULL;

  if (size) {
    data = (unitree_msgs__srv__SetControlMode_Response *)allocator.zero_allocate(size, sizeof(unitree_msgs__srv__SetControlMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_msgs__srv__SetControlMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_msgs__srv__SetControlMode_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
unitree_msgs__srv__SetControlMode_Response__Sequence__fini(unitree_msgs__srv__SetControlMode_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      unitree_msgs__srv__SetControlMode_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

unitree_msgs__srv__SetControlMode_Response__Sequence *
unitree_msgs__srv__SetControlMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__srv__SetControlMode_Response__Sequence * array = (unitree_msgs__srv__SetControlMode_Response__Sequence *)allocator.allocate(sizeof(unitree_msgs__srv__SetControlMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_msgs__srv__SetControlMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_msgs__srv__SetControlMode_Response__Sequence__destroy(unitree_msgs__srv__SetControlMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_msgs__srv__SetControlMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_msgs__srv__SetControlMode_Response__Sequence__are_equal(const unitree_msgs__srv__SetControlMode_Response__Sequence * lhs, const unitree_msgs__srv__SetControlMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_msgs__srv__SetControlMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__srv__SetControlMode_Response__Sequence__copy(
  const unitree_msgs__srv__SetControlMode_Response__Sequence * input,
  unitree_msgs__srv__SetControlMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_msgs__srv__SetControlMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_msgs__srv__SetControlMode_Response * data =
      (unitree_msgs__srv__SetControlMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_msgs__srv__SetControlMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_msgs__srv__SetControlMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_msgs__srv__SetControlMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
