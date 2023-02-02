#include "constants/motor_constants.h"

namespace constants {
const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};
// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts = {1, 2};
const std::vector<int> kBackRightMotorPorts = {4, 5};
const std::vector<int> kBackLeftMotorPorts = {6, 7};
const std::vector<int> kFrontLeftMotorPorts = {3, 4};

DrivetrainMotors GetDrivetrainMotors() {
  //   return {
  //   hardware::ProsMotor(
  //       kFrontRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
  //   hardware::ProsMotor(
  //       kBackRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
  //   hardware::ProsMotor(
  //       kBackLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
  //   hardware::ProsMotor(
  //       kFrontLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset)};
  //   };
}

interface::MotorAndEncoder GetShooterMotor() {}

interface::Motor GetTransferMotor() {}
}  // namespace constants