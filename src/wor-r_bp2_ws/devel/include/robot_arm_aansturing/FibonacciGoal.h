// Generated by gencpp from file robot_arm_aansturing/FibonacciGoal.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_FIBONACCIGOAL_H
#define ROBOT_ARM_AANSTURING_MESSAGE_FIBONACCIGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robot_arm_aansturing
{
template <class ContainerAllocator>
struct FibonacciGoal_
{
  typedef FibonacciGoal_<ContainerAllocator> Type;

  FibonacciGoal_()
    : order(0)  {
    }
  FibonacciGoal_(const ContainerAllocator& _alloc)
    : order(0)  {
  (void)_alloc;
    }



   typedef int32_t _order_type;
  _order_type order;




  typedef boost::shared_ptr< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> const> ConstPtr;

}; // struct FibonacciGoal_

typedef ::robot_arm_aansturing::FibonacciGoal_<std::allocator<void> > FibonacciGoal;

typedef boost::shared_ptr< ::robot_arm_aansturing::FibonacciGoal > FibonacciGoalPtr;
typedef boost::shared_ptr< ::robot_arm_aansturing::FibonacciGoal const> FibonacciGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robot_arm_aansturing

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robot_arm_aansturing': ['/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6889063349a00b249bd1661df429d822";
  }

  static const char* value(const ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6889063349a00b24ULL;
  static const uint64_t static_value2 = 0x9bd1661df429d822ULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_arm_aansturing/FibonacciGoal";
  }

  static const char* value(const ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definition\n\
int32 order\n\
";
  }

  static const char* value(const ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.order);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct FibonacciGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_arm_aansturing::FibonacciGoal_<ContainerAllocator>& v)
  {
    s << indent << "order: ";
    Printer<int32_t>::stream(s, indent + "  ", v.order);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_FIBONACCIGOAL_H
