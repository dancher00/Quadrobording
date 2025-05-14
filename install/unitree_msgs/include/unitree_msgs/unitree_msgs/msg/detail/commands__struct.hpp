// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from unitree_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_
#define UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__unitree_msgs__msg__Commands __attribute__((deprecated))
#else
# define DEPRECATED__unitree_msgs__msg__Commands __declspec(deprecated)
#endif

namespace unitree_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Commands_
{
  using Type = Commands_<ContainerAllocator>;

  explicit Commands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t = 0.0;
      std::fill<typename std::array<double, 12>::iterator, double>(this->qj.begin(), this->qj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->vj.begin(), this->vj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tauj.begin(), this->tauj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kp.begin(), this->kp.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kd.begin(), this->kd.end(), 0.0);
    }
  }

  explicit Commands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : qj(_alloc),
    vj(_alloc),
    tauj(_alloc),
    kp(_alloc),
    kd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t = 0.0;
      std::fill<typename std::array<double, 12>::iterator, double>(this->qj.begin(), this->qj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->vj.begin(), this->vj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->tauj.begin(), this->tauj.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kp.begin(), this->kp.end(), 0.0);
      std::fill<typename std::array<double, 12>::iterator, double>(this->kd.begin(), this->kd.end(), 0.0);
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
  using _kp_type =
    std::array<double, 12>;
  _kp_type kp;
  using _kd_type =
    std::array<double, 12>;
  _kd_type kd;

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
  Type & set__kp(
    const std::array<double, 12> & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const std::array<double, 12> & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unitree_msgs::msg::Commands_<ContainerAllocator> *;
  using ConstRawPtr =
    const unitree_msgs::msg::Commands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unitree_msgs::msg::Commands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unitree_msgs::msg::Commands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::msg::Commands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::msg::Commands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::msg::Commands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::msg::Commands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unitree_msgs::msg::Commands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unitree_msgs::msg::Commands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unitree_msgs__msg__Commands
    std::shared_ptr<unitree_msgs::msg::Commands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unitree_msgs__msg__Commands
    std::shared_ptr<unitree_msgs::msg::Commands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Commands_ & other) const
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
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    return true;
  }
  bool operator!=(const Commands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Commands_

// alias to use template instance with default allocator
using Commands =
  unitree_msgs::msg::Commands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_
