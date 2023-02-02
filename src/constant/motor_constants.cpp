#include "constant/motor_constants.h"

namespace constant {
const DrivetrainMotors kDrivetrainMotors = GetDrivetrainMotors();
namespace {
constexpr DrivetrainMotors GetDrivetrainMotors() {
  return {
      hardware::ProsMotor(
          kFrontRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotor(
          kBackRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotor(
          kBackLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotor(
          kFrontLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset)};
}
}  // namespace
}  // namespace constant