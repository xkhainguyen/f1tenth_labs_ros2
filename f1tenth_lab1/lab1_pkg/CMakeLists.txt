cmake_minimum_required(VERSION 3.5)
project(lab1_pkg)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(ackermann_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Include Cpp "include" directory
include_directories(include)
# Create Cpp executable
add_executable(talker 
  src/talker.cpp 
  src/DrivePublisher.cpp)

ament_target_dependencies(
  talker rclcpp ackermann_msgs rcl_interfaces)
# Install Cpp executables
install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME}
)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})
# Install Python executables
install(PROGRAMS
  scripts/relay.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files from /launch folder to /share
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
) 

# Install .yaml (config) files from /config folder to /share
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
) 

ament_package()
