#include "interface/robot_motors.h"

namespace interface {

const DrivetrainMotors kDrivetrainMotors = GetDrivetrainMotors();

constexpr DrivetrainMotors GetDrivetrainMotors() {
  return {
      hardware::ProsMotor(
          constant::kFrontRightMotorPorts, constant::kDrivetrainReverse,
          constant::kDrivetrainGearset),
      hardware::ProsMotor(
          constant::kBackRightMotorPorts, constant::kDrivetrainReverse,
          constant::kDrivetrainGearset),
      hardware::ProsMotor(
          constant::kBackLeftMotorPorts, constant::kDrivetrainReverse,
          constant::kDrivetrainGearset),
      hardware::ProsMotor(
          constant::kFrontLeftMotorPorts, constant::kDrivetrainReverse,
          constant::kDrivetrainGearset)};
}
}  // namespace interface