// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice
#include "unitree_msgs/msg/detail/states__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
unitree_msgs__msg__States__init(unitree_msgs__msg__States * msg)
{
  if (!msg) {
    return false;
  }
  // t
  // qj
  // vj
  // tauj
  // imu_orientation
  // imu_angular_velocity
  // imu_linear_acceleration
  // foot_force_sensor
  return true;
}

void
unitree_msgs__msg__States__fini(unitree_msgs__msg__States * msg)
{
  if (!msg) {
    return;
  }
  // t
  // qj
  // vj
  // tauj
  // imu_orientation
  // imu_angular_velocity
  // imu_linear_acceleration
  // foot_force_sensor
}

bool
unitree_msgs__msg__States__are_equal(const unitree_msgs__msg__States * lhs, const unitree_msgs__msg__States * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // t
  if (lhs->t != rhs->t) {
    return false;
  }
  // qj
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->qj[i] != rhs->qj[i]) {
      return false;
    }
  }
  // vj
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->vj[i] != rhs->vj[i]) {
      return false;
    }
  }
  // tauj
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->tauj[i] != rhs->tauj[i]) {
      return false;
    }
  }
  // imu_orientation
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->imu_orientation[i] != rhs->imu_orientation[i]) {
      return false;
    }
  }
  // imu_angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->imu_angular_velocity[i] != rhs->imu_angular_velocity[i]) {
      return false;
    }
  }
  // imu_linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->imu_linear_acceleration[i] != rhs->imu_linear_acceleration[i]) {
      return false;
    }
  }
  // foot_force_sensor
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force_sensor[i] != rhs->foot_force_sensor[i]) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__msg__States__copy(
  const unitree_msgs__msg__States * input,
  unitree_msgs__msg__States * output)
{
  if (!input || !output) {
    return false;
  }
  // t
  output->t = input->t;
  // qj
  for (size_t i = 0; i < 12; ++i) {
    output->qj[i] = input->qj[i];
  }
  // vj
  for (size_t i = 0; i < 12; ++i) {
    output->vj[i] = input->vj[i];
  }
  // tauj
  for (size_t i = 0; i < 12; ++i) {
    output->tauj[i] = input->tauj[i];
  }
  // imu_orientation
  for (size_t i = 0; i < 4; ++i) {
    output->imu_orientation[i] = input->imu_orientation[i];
  }
  // imu_angular_velocity
  for (size_t i = 0; i < 3; ++i) {
    output->imu_angular_velocity[i] = input->imu_angular_velocity[i];
  }
  // imu_linear_acceleration
  for (size_t i = 0; i < 3; ++i) {
    output->imu_linear_acceleration[i] = input->imu_linear_acceleration[i];
  }
  // foot_force_sensor
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force_sensor[i] = input->foot_force_sensor[i];
  }
  return true;
}

unitree_msgs__msg__States *
unitree_msgs__msg__States__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__States * msg = (unitree_msgs__msg__States *)allocator.allocate(sizeof(unitree_msgs__msg__States), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_msgs__msg__States));
  bool success = unitree_msgs__msg__States__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_msgs__msg__States__destroy(unitree_msgs__msg__States * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_msgs__msg__States__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_msgs__msg__States__Sequence__init(unitree_msgs__msg__States__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__States * data = NULL;

  if (size) {
    data = (unitree_msgs__msg__States *)allocator.zero_allocate(size, sizeof(unitree_msgs__msg__States), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_msgs__msg__States__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_msgs__msg__States__fini(&data[i - 1]);
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
unitree_msgs__msg__States__Sequence__fini(unitree_msgs__msg__States__Sequence * array)
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
      unitree_msgs__msg__States__fini(&array->data[i]);
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

unitree_msgs__msg__States__Sequence *
unitree_msgs__msg__States__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__States__Sequence * array = (unitree_msgs__msg__States__Sequence *)allocator.allocate(sizeof(unitree_msgs__msg__States__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_msgs__msg__States__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_msgs__msg__States__Sequence__destroy(unitree_msgs__msg__States__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_msgs__msg__States__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_msgs__msg__States__Sequence__are_equal(const unitree_msgs__msg__States__Sequence * lhs, const unitree_msgs__msg__States__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_msgs__msg__States__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__msg__States__Sequence__copy(
  const unitree_msgs__msg__States__Sequence * input,
  unitree_msgs__msg__States__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_msgs__msg__States);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_msgs__msg__States * data =
      (unitree_msgs__msg__States *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_msgs__msg__States__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_msgs__msg__States__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_msgs__msg__States__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
