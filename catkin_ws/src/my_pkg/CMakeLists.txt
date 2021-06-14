cmake_minimum_required(VERSION 2.8.3)
project(my_pkg)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pubExe src/pub.cpp)
add_executable(subExe src/sub.cpp)
target_link_libraries(pubExe ${catkin_LIBRARIES})
target_link_libraries(subExe ${catkin_LIBRARIES})
