cmake_minimum_required(VERSION 3.5)
project(spin_up)

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(publisher 
src/minimal_publisher.cpp)
# add_executable(motor_test src/motor_test.cpp)
ament_target_dependencies(publisher
  rclcpp
  std_msgs
)

install(TARGETS
  publisher
  # motor_test
  DESTINATION lib/${PROJECT_NAME}
)

# install(
#   DIRECTORY config description launch
#   DESTINATION share/${PROJECT_NAME}
# )

ament_package()