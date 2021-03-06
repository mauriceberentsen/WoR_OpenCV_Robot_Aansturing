// Generated by gencpp from file robot_arm_aansturing/commandRequest.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_COMMANDREQUEST_H
#define ROBOT_ARM_AANSTURING_MESSAGE_COMMANDREQUEST_H


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
struct commandRequest_
{
  typedef commandRequest_<ContainerAllocator> Type;

  commandRequest_()
    : time(0)
    , command()  {
    }
  commandRequest_(const ContainerAllocator& _alloc)
    : time(0)
    , command(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _time_type;
  _time_type time;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _command_type;
  _command_type command;




  typedef boost::shared_ptr< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> const> ConstPtr;

}; // struct commandRequest_

typedef ::robot_arm_aansturing::commandRequest_<std::allocator<void> > commandRequest;

typedef boost::shared_ptr< ::robot_arm_aansturing::commandRequest > commandRequestPtr;
typedef boost::shared_ptr< ::robot_arm_aansturing::commandRequest const> commandRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_arm_aansturing::commandRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robot_arm_aansturing

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'robot_arm_aansturing': ['/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e910f6b13df2ebbf25f3d3309811088e";
  }

  static const char* value(const ::robot_arm_aansturing::commandRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe910f6b13df2ebbfULL;
  static const uint64_t static_value2 = 0x25f3d3309811088eULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_arm_aansturing/commandRequest";
  }

  static const char* value(const ::robot_arm_aansturing::commandRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 time\n\
string command\n\
";
  }

  static const char* value(const ::robot_arm_aansturing::commandRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct commandRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_arm_aansturing::commandRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_arm_aansturing::commandRequest_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    Printer<int32_t>::stream(s, indent + "  ", v.time);
    s << indent << "command: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_COMMANDREQUEST_H
