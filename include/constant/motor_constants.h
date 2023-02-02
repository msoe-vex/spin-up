#pragma once
#include <vector>

#include "hardware/pros_motor.h"
#include "interface/motor.h"
#include "main.h"

/**
 * Factory functions for retriving Motors on the robot.
 */
namespace constant {
struct DrivetrainMotors {
  interface::Motor front_right_motor;
  interface::Motor back_right_motor;
  interface::Motor back_left_motor;
  interface::Motor front_left_motor;
};
const DrivetrainMotors kDrivetrainMotors;

namespace {
const pros::motor_gearset_e_t kDrivetrainGearset;
const std::vector<bool> kDrivetrainReverse;
// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts;
const std::vector<int> kBackRightMotorPorts;
const std::vector<int> kBackLeftMotorPorts;
const std::vector<int> kFrontLeftMotorPorts;

constexpr constant::DrivetrainMotors GetDrivetrainMotors();

// constexpr interface::MotorAndEncoder GetShooterMotor();
// constexpr interface::Motor GetTransferMotor();
}  // namespace
}  // namespace constant