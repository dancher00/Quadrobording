// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice
#include "unitree_msgs/msg/detail/commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
unitree_msgs__msg__Commands__init(unitree_msgs__msg__Commands * msg)
{
  if (!msg) {
    return false;
  }
  // t
  // qj
  // vj
  // tauj
  // kp
  // kd
  return true;
}

void
unitree_msgs__msg__Commands__fini(unitree_msgs__msg__Commands * msg)
{
  if (!msg) {
    return;
  }
  // t
  // qj
  // vj
  // tauj
  // kp
  // kd
}

bool
unitree_msgs__msg__Commands__are_equal(const unitree_msgs__msg__Commands * lhs, const unitree_msgs__msg__Commands * rhs)
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
  // kp
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->kp[i] != rhs->kp[i]) {
      return false;
    }
  }
  // kd
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->kd[i] != rhs->kd[i]) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__msg__Commands__copy(
  const unitree_msgs__msg__Commands * input,
  unitree_msgs__msg__Commands * output)
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
  // kp
  for (size_t i = 0; i < 12; ++i) {
    output->kp[i] = input->kp[i];
  }
  // kd
  for (size_t i = 0; i < 12; ++i) {
    output->kd[i] = input->kd[i];
  }
  return true;
}

unitree_msgs__msg__Commands *
unitree_msgs__msg__Commands__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__Commands * msg = (unitree_msgs__msg__Commands *)allocator.allocate(sizeof(unitree_msgs__msg__Commands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(unitree_msgs__msg__Commands));
  bool success = unitree_msgs__msg__Commands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
unitree_msgs__msg__Commands__destroy(unitree_msgs__msg__Commands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    unitree_msgs__msg__Commands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
unitree_msgs__msg__Commands__Sequence__init(unitree_msgs__msg__Commands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__Commands * data = NULL;

  if (size) {
    data = (unitree_msgs__msg__Commands *)allocator.zero_allocate(size, sizeof(unitree_msgs__msg__Commands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = unitree_msgs__msg__Commands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        unitree_msgs__msg__Commands__fini(&data[i - 1]);
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
unitree_msgs__msg__Commands__Sequence__fini(unitree_msgs__msg__Commands__Sequence * array)
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
      unitree_msgs__msg__Commands__fini(&array->data[i]);
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

unitree_msgs__msg__Commands__Sequence *
unitree_msgs__msg__Commands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  unitree_msgs__msg__Commands__Sequence * array = (unitree_msgs__msg__Commands__Sequence *)allocator.allocate(sizeof(unitree_msgs__msg__Commands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = unitree_msgs__msg__Commands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
unitree_msgs__msg__Commands__Sequence__destroy(unitree_msgs__msg__Commands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    unitree_msgs__msg__Commands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
unitree_msgs__msg__Commands__Sequence__are_equal(const unitree_msgs__msg__Commands__Sequence * lhs, const unitree_msgs__msg__Commands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!unitree_msgs__msg__Commands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
unitree_msgs__msg__Commands__Sequence__copy(
  const unitree_msgs__msg__Commands__Sequence * input,
  unitree_msgs__msg__Commands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(unitree_msgs__msg__Commands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    unitree_msgs__msg__Commands * data =
      (unitree_msgs__msg__Commands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!unitree_msgs__msg__Commands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          unitree_msgs__msg__Commands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!unitree_msgs__msg__Commands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
