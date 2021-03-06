cmake_minimum_required(VERSION 2.8.3)
project(robot_arm_aansturing)
## Add support for C++11, supported in ROS Kinetic and newer
add_definitions(-std=c++11)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  rospy
  std_msgs
  actionlib
  message_generation
  actionlib_msgs
)

find_package( OpenCV REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system thread regex date_time)

 
## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   Test.srv
   position.srv
   command.srv
#   Service1.srv
#   Service2.srv
 )

## Generate actions in the 'action' folder
 add_action_files(
 	DIRECTORY action
	FILES position.action Fibonacci.action Averaging.action
#   FILES
#   Action1.action
#   Action2.action
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   actionlib_msgs
 )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS
    serial
    std_msgs
    actionlib_msgs
#  INCLUDE_DIRS include
#  LIBRARIES robot_arm_aansturing
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
 # ${BOOST_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(robot_arm_aansturing
#   src/${PROJECT_NAME}/robot_arm_aansturing.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(robot_arm_aansturing ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(robot_arm_aansturing_node src/robot_arm_aansturing_node.cpp)

#add_executable(serialcomm_server src/serial_node.cpp src/Server.cpp)
add_executable(serial_server_node src/serial_node src/Server.cpp src/Servo.cpp src/RobotArm.cpp)
#add_executable(tutorial_client src/Client.cpp)

add_executable(tutorial_client 
	src/client/main.cpp 
	src/client/ArmContol.cpp
	src/client/ConcreteStates.cpp
	src/client/Context.cpp
	src/client/Event.cpp
	src/client/RobotArm.cpp
	src/client/RobotArmContext.cpp
	src/client/Servo.cpp
	src/client/Client.cpp
)

#add_executable(kinematic_node
#	src/kinematics/main.cpp
#	src/kinematics/Kinematic.cpp
#	src/kinematics/Matrix.hpp
#	)
	
add_executable(vision_node
	src/vision/main.cpp
	src/vision/colourrange.cpp
	src/vision/Configuration.cpp
	src/vision/figurenfilter.cpp
	src/vision/findGoals.cpp
	src/vision/kleurenfilter.cpp
	src/vision/searchAruco.cpp
	src/vision/SearchQuery.cpp
	src/kinematics/Kinematic.cpp
 	src/kinematics/Matrix.hpp
 	src/kinematics/motion_controller.cpp
	)
## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(robot_arm_aansturing_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#add_dependencies(serialcomm_server robot_arm_aansturing_gencpp)
add_dependencies(serial_server_node robot_arm_aansturing_gencpp)
add_dependencies(tutorial_client robot_arm_aansturing_gencpp)
#add_dependencies(kinematic_node robot_arm_aansturing_gencpp)
add_dependencies(vision_node robot_arm_aansturing_gencpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(robot_arm_aansturing_node
#  ${catkin_LIBRARIES}
#)

#target_link_libraries(serialcomm_server ${catkin_LIBRARIES})
target_link_libraries(serial_server_node ${catkin_LIBRARIES})
target_link_libraries(tutorial_client ${catkin_LIBRARIES})
#target_link_libraries(kinematic_node ${catkin_LIBRARIES})
target_link_libraries(vision_node ${catkin_LIBRARIES}
                                    ${OpenCV_LIBS})

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS robot_arm_aansturing robot_arm_aansturing_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_robot_arm_aansturing.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

add_executable(test_client src/client_test/client_test.cpp)
target_link_libraries(test_client ${catkin_LIBRARIES})
add_dependencies(test_client robot_arm_aansturing_gencpp)
