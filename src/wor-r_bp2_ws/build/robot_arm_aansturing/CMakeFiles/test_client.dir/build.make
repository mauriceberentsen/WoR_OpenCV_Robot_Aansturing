# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build

# Include any dependencies generated for this target.
include robot_arm_aansturing/CMakeFiles/test_client.dir/depend.make

# Include the progress variables for this target.
include robot_arm_aansturing/CMakeFiles/test_client.dir/progress.make

# Include the compile flags for this target's objects.
include robot_arm_aansturing/CMakeFiles/test_client.dir/flags.make

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o: robot_arm_aansturing/CMakeFiles/test_client.dir/flags.make
robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o: /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/src/client_test/client_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o"
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o -c /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/src/client_test/client_test.cpp

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_client.dir/src/client_test/client_test.cpp.i"
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/src/client_test/client_test.cpp > CMakeFiles/test_client.dir/src/client_test/client_test.cpp.i

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_client.dir/src/client_test/client_test.cpp.s"
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/src/client_test/client_test.cpp -o CMakeFiles/test_client.dir/src/client_test/client_test.cpp.s

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.requires:

.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.requires

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.provides: robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.requires
	$(MAKE) -f robot_arm_aansturing/CMakeFiles/test_client.dir/build.make robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.provides.build
.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.provides

robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.provides.build: robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o


# Object files for target test_client
test_client_OBJECTS = \
"CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o"

# External object files for target test_client
test_client_EXTERNAL_OBJECTS =

/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: robot_arm_aansturing/CMakeFiles/test_client.dir/build.make
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libserial.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libactionlib.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libroscpp.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/librosconsole.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/librostime.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /opt/ros/kinetic/lib/libcpp_common.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client: robot_arm_aansturing/CMakeFiles/test_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client"
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
robot_arm_aansturing/CMakeFiles/test_client.dir/build: /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/devel/lib/robot_arm_aansturing/test_client

.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/build

robot_arm_aansturing/CMakeFiles/test_client.dir/requires: robot_arm_aansturing/CMakeFiles/test_client.dir/src/client_test/client_test.cpp.o.requires

.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/requires

robot_arm_aansturing/CMakeFiles/test_client.dir/clean:
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing && $(CMAKE_COMMAND) -P CMakeFiles/test_client.dir/cmake_clean.cmake
.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/clean

robot_arm_aansturing/CMakeFiles/test_client.dir/depend:
	cd /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing /home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/build/robot_arm_aansturing/CMakeFiles/test_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : robot_arm_aansturing/CMakeFiles/test_client.dir/depend

