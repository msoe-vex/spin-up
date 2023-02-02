#include "constant/motor_constants.h"

namespace constant {
const DrivetrainMotors kDrivetrainMotors = GetDrivetrainMotors();

namespace {
const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};
// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts = {1, 2};
const std::vector<int> kBackRightMotorPorts = {3, 4};
const std::vector<int> kBackLeftMotorPorts = {5, 6};
const std::vector<int> kFrontLeftMotorPorts = {7, 8};

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