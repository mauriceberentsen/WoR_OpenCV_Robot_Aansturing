// Generated by gencpp from file robot_arm_aansturing/Test.msg
// DO NOT EDIT!


#ifndef ROBOT_ARM_AANSTURING_MESSAGE_TEST_H
#define ROBOT_ARM_AANSTURING_MESSAGE_TEST_H

#include <ros/service_traits.h>


#include <robot_arm_aansturing/TestRequest.h>
#include <robot_arm_aansturing/TestResponse.h>


namespace robot_arm_aansturing
{

struct Test
{

typedef TestRequest Request;
typedef TestResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Test
} // namespace robot_arm_aansturing


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::robot_arm_aansturing::Test > {
  static const char* value()
  {
    return "6a2e34150c00229791cc89ff309fff21";
  }

  static const char* value(const ::robot_arm_aansturing::Test&) { return value(); }
};

template<>
struct DataType< ::robot_arm_aansturing::Test > {
  static const char* value()
  {
    return "robot_arm_aansturing/Test";
  }

  static const char* value(const ::robot_arm_aansturing::Test&) { return value(); }
};


// service_traits::MD5Sum< ::robot_arm_aansturing::TestRequest> should match 
// service_traits::MD5Sum< ::robot_arm_aansturing::Test > 
template<>
struct MD5Sum< ::robot_arm_aansturing::TestRequest>
{
  static const char* value()
  {
    return MD5Sum< ::robot_arm_aansturing::Test >::value();
  }
  static const char* value(const ::robot_arm_aansturing::TestRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::robot_arm_aansturing::TestRequest> should match 
// service_traits::DataType< ::robot_arm_aansturing::Test > 
template<>
struct DataType< ::robot_arm_aansturing::TestRequest>
{
  static const char* value()
  {
    return DataType< ::robot_arm_aansturing::Test >::value();
  }
  static const char* value(const ::robot_arm_aansturing::TestRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::robot_arm_aansturing::TestResponse> should match 
// service_traits::MD5Sum< ::robot_arm_aansturing::Test > 
template<>
struct MD5Sum< ::robot_arm_aansturing::TestResponse>
{
  static const char* value()
  {
    return MD5Sum< ::robot_arm_aansturing::Test >::value();
  }
  static const char* value(const ::robot_arm_aansturing::TestResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::robot_arm_aansturing::TestResponse> should match 
// service_traits::DataType< ::robot_arm_aansturing::Test > 
template<>
struct DataType< ::robot_arm_aansturing::TestResponse>
{
  static const char* value()
  {
    return DataType< ::robot_arm_aansturing::Test >::value();
  }
  static const char* value(const ::robot_arm_aansturing::TestResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROBOT_ARM_AANSTURING_MESSAGE_TEST_H
