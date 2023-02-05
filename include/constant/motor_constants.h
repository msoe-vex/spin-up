#pragma once
#include <memory>
#include <vector>

#include "drivetrain/holonomic_drive.h"
#include "hardware/pros_controller.h"
#include "hardware/pros_motor_group.h"
#include "interface/controller.h"
#include "main.h"

namespace constant {
const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};

// {top motor, bottom motor}
const std::vector<int> kFrontRightMotorPorts = {1, 2};
const std::vector<int> kBackRightMotorPorts = {1, 2};
const std::vector<int> kBackLeftMotorPorts = {1, 2};
const std::vector<int> kFrontLeftMotorPorts = {1, 2};

drivetrain::HolonomicMotors GetHolonomicMotors() {
  std::vector<std::unique_ptr<interface::Motor>> motors;
  // emplace back constructs the ptr inside the vector instead of copying
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      kFrontRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      kBackRightMotorPorts, kDrivetrainReverse, kDrivetrainGearset));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      kBackLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      kFrontLeftMotorPorts, kDrivetrainReverse, kDrivetrainGearset));
  return drivetrain::HolonomicMotors(std::move(motors));
}

std::unique_ptr<interface::Controller> GetMasterController() {
  return std::make_unique<hardware::ProsController>(pros::E_CONTROLLER_MASTER);
}
}  // namespace constant