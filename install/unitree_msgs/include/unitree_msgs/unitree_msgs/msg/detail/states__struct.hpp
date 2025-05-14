// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from unitree_msgs:msg/States.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_HPP_
#define UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__unitree_msgs__msg__States __attribute__((deprecated))
#else
# define DEPRECATED__unitree_msgs__msg__States __declspec(deprecated)
#endif

namespace unitree_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct States_
{
  using Type = States_<ContainerAllocator>;

  explicit States_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t = 0.0;
      std::fill<typename std::array<double, 12>::iterator, double>(this->qj.begin(), this->qj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->vj.begin(), this->vj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tauj.begin(), this->tauj.end(), 0.0);
      std::fill<typename std::array<double, 4>::iterator, double>(this->imu_orientation.begin(), this->imu_orientation.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->imu_angular_velocity.begin(), this->imu_angular_velocity.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->imu_linear_acceleration.begin(), this->imu_linear_acceleration.end(), 0.0);
      std::fill<typename std::array<double, 4>::iterator, double>(this->foot_force_sensor.begin(), this->foot_force_sensor.end(), 0.0);
    }
  }

  explicit States_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : qj(_alloc),
    vj(_alloc),
    tauj(_alloc),
    imu_orientation(_alloc),
    imu_angular_velocity(_alloc),
    imu_linear_acceleration(_alloc),
    foot_force_sensor(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t = 0.0;
      std::fill<typename std::array<double, 12>::iterator, double>(this->qj.begin(), this->qj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->vj.begin(), this->vj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tauj.begin(), this->tauj.end(), 0.0);
      std::fill<typename std::array<double, 4>::iterator, double>(this->imu_orientation.begin(), this->imu_orientation.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->imu_angular_velocity.begin(), this->imu_angular_velocity.end(), 0.0);
      std::fill<typename std::array<double, 3>::iterator, double>(this->imu_linear_acceleration.begin(), this->imu_linear_acceleration.end(), 0.0);
      std::fill<typename std::array<double, 4>::iterator, double>(this->foot_force_sensor.begin(), this->foot_force_sensor.end(), 0.0);
    }
  }

  // field types and members
  using _t_type =
    double;
  _t_type t;
  using _qj_type =
    std::array<double, 12>;
  _qj_type qj;
  using _vj_type =
    std::array<double, 12>;
  _vj_type vj;
  using _tauj_type =
    std::array<double, 12>;
  _tauj_type tauj;
  using _imu_orientation_type =
    std::array<double, 4>;
  _imu_orientation_type imu_orientation;
  using _imu_angular_velocity_type =
    std::array<double, 3>;
  _imu_angular_velocity_type imu_angular_velocity;
  using _imu_linear_acceleration_type =
    std::array<double, 3>;
  _imu_linear_acceleration_type imu_linear_acceleration;
  using _foot_force_sensor_type =
    std::array<double, 4>;
  _foot_force_sensor_type foot_force_sensor;

  // setters for named parameter idiom
  Type & set__t(
    const double & _arg)
  {
    this->t = _arg;
    return *this;
  }
  Type & set__qj(
    const std::array<double, 12> & _arg)
  {
    this->qj = _arg;
    return *this;
  }
  Type & set__vj(
    const std::array<double, 12> & _arg)
  {
    this->vj = _arg;
    return *this;
  }
  Type & set__tauj(
    const std::array<double, 12> & _arg)
  {
    this->tauj = _arg;
    return *this;
  }
  Type & set__imu_orientation(
    const std::array<double, 4> & _arg)
  {
    this->imu_orientation = _arg;
    return *this;
  }
  Type & set__imu_angular_velocity(
    const std::array<double, 3> & _arg)
  {
    this->imu_angular_velocity = _arg;
    return *this;
  }
  Type & set__imu_linear_acceleration(
    const std::array<double, 3> & _arg)
  {
    this->imu_linear_acceleration = _arg;
    return *this;
  }
  Type & set__foot_force_sensor(
    const std::array<double, 4> & _arg)
  {
    this->foot_force_sensor = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unitree_msgs::msg::States_<ContainerAllocator> *;
  using ConstRawPtr =
    const unitree_msgs::msg::States_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unitree_msgs::msg::States_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unitree_msgs::msg::States_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::msg::States_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::msg::States_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::msg::States_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::msg::States_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unitree_msgs::msg::States_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unitree_msgs::msg::States_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unitree_msgs__msg__States
    std::shared_ptr<unitree_msgs::msg::States_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unitree_msgs__msg__States
    std::shared_ptr<unitree_msgs::msg::States_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const States_ & other) const
  {
    if (this->t != other.t) {
      return false;
    }
    if (this->qj != other.qj) {
      return false;
    }
    if (this->vj != other.vj) {
      return false;
    }
    if (this->tauj != other.tauj) {
      return false;
    }
    if (this->imu_orientation != other.imu_orientation) {
      return false;
    }
    if (this->imu_angular_velocity != other.imu_angular_velocity) {
      return false;
    }
    if (this->imu_linear_acceleration != other.imu_linear_acceleration) {
      return false;
    }
    if (this->foot_force_sensor != other.foot_force_sensor) {
      return false;
    }
    return true;
  }
  bool operator!=(const States_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct States_

// alias to use template instance with default allocator
using States =
  unitree_msgs::msg::States_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__MSG__DETAIL__STATES__STRUCT_HPP_
