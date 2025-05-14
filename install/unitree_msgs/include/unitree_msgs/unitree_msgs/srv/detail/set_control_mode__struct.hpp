// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from unitree_msgs:srv/SetControlMode.idl
// generated code does not contain a copyright notice

#ifndef UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_HPP_
#define UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__unitree_msgs__srv__SetControlMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__unitree_msgs__srv__SetControlMode_Request __declspec(deprecated)
#endif

namespace unitree_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetControlMode_Request_
{
  using Type = SetControlMode_Request_<ContainerAllocator>;

  explicit SetControlMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_mode = "";
    }
  }

  explicit SetControlMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : control_mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_mode = "";
    }
  }

  // field types and members
  using _control_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _control_mode_type control_mode;

  // setters for named parameter idiom
  Type & set__control_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unitree_msgs__srv__SetControlMode_Request
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unitree_msgs__srv__SetControlMode_Request
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetControlMode_Request_ & other) const
  {
    if (this->control_mode != other.control_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetControlMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetControlMode_Request_

// alias to use template instance with default allocator
using SetControlMode_Request =
  unitree_msgs::srv::SetControlMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace unitree_msgs


#ifndef _WIN32
# define DEPRECATED__unitree_msgs__srv__SetControlMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__unitree_msgs__srv__SetControlMode_Response __declspec(deprecated)
#endif

namespace unitree_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetControlMode_Response_
{
  using Type = SetControlMode_Response_<ContainerAllocator>;

  explicit SetControlMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accept = false;
      this->current_control_mode = "";
    }
  }

  explicit SetControlMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_control_mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accept = false;
      this->current_control_mode = "";
    }
  }

  // field types and members
  using _accept_type =
    bool;
  _accept_type accept;
  using _current_control_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_control_mode_type current_control_mode;

  // setters for named parameter idiom
  Type & set__accept(
    const bool & _arg)
  {
    this->accept = _arg;
    return *this;
  }
  Type & set__current_control_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_control_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unitree_msgs__srv__SetControlMode_Response
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unitree_msgs__srv__SetControlMode_Response
    std::shared_ptr<unitree_msgs::srv::SetControlMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetControlMode_Response_ & other) const
  {
    if (this->accept != other.accept) {
      return false;
    }
    if (this->current_control_mode != other.current_control_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetControlMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetControlMode_Response_

// alias to use template instance with default allocator
using SetControlMode_Response =
  unitree_msgs::srv::SetControlMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace unitree_msgs

namespace unitree_msgs
{

namespace srv
{

struct SetControlMode
{
  using Request = unitree_msgs::srv::SetControlMode_Request;
  using Response = unitree_msgs::srv::SetControlMode_Response;
};

}  // namespace srv

}  // namespace unitree_msgs

#endif  // UNITREE_MSGS__SRV__DETAIL__SET_CONTROL_MODE__STRUCT_HPP_
