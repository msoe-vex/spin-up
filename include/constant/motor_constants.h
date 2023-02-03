#pragma once
#include <vector>

#include "drivetrain/holonomic_drive.h"
#include "main.h"

namespace constant {
const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};

// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts = {1, 2};
const std::vector<int> kBackRightMotorPorts = {1, 2};
const std::vector<int> kBackLeftMotorPorts = {1, 2};
const std::vector<int> kFrontLeftMotorPorts = {1, 2};

drivetrain::HolonomicDrivetrainMotors GetHolonomicDrivetrainMotors() {
  return drivetrain::HolonomicDrivetrainMotors(
      hardware::ProsMotorGroup(
          kFrontRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotorGroup(
          kBackRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotorGroup(
          kBackLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset),
      hardware::ProsMotorGroup(
          kFrontLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset));
}
}  // namespace constant