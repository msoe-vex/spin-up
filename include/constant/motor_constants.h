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
  // declared in clockwise fashion
  Motor front_right_motor;
  Motor back_right_motor;
  Motor back_left_motor;
  Motor front_left_motor;
};

DrivetrainMotors GetDrivetrainMotors();
// interface::MotorAndEncoder GetShooterMotor();
// interface::Motor GetTransferMotor();

const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};
// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts = {1, 2};
const std::vector<int> kBackRightMotorPorts = {3, 4};
const std::vector<int> kBackLeftMotorPorts = {5, 6};
const std::vector<int> kFrontLeftMotorPorts = {7, 8};
}  // namespace constant