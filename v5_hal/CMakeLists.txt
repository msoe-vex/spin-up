cmake_minimum_required(VERSION 3.8)
project(v5_hal)

# find dependencies
find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CompetitionStatus.msg"
  "msg/RollPitchYaw.msg"
  "msg/V5Battery.msg"
  "msg/V5Controller.msg"
  "msg/V5InertialSensor.msg"
  "msg/V5Motor.msg"
  "msg/V5RotationSensor.msg"
)

install(FILES
  my_mapping_rules.yaml
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
