# Install script for directory: /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/srv" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/srv/Test.srv"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/srv/position.srv"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/srv/command.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/action" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/action/position.action"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/action/Fibonacci.action"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/action/Averaging.action"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/msg" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionAction.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionActionGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionActionResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionActionFeedback.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/positionFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/msg" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciAction.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciActionGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciActionResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciActionFeedback.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/FibonacciFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/msg" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingAction.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingActionGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingActionResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingActionFeedback.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingGoal.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingResult.msg"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/robot_arm_aansturing/msg/AveragingFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/cmake" TYPE FILE FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/catkin_generated/installspace/robot_arm_aansturing-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/include/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/roseus/ros/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/common-lisp/ros/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/share/gennodejs/ros/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/python2.7/dist-packages/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/python2.7/dist-packages/robot_arm_aansturing")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/catkin_generated/installspace/robot_arm_aansturing.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/cmake" TYPE FILE FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/catkin_generated/installspace/robot_arm_aansturing-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing/cmake" TYPE FILE FILES
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/catkin_generated/installspace/robot_arm_aansturingConfig.cmake"
    "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/catkin_generated/installspace/robot_arm_aansturingConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/robot_arm_aansturing" TYPE FILE FILES "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/package.xml")
endif()

