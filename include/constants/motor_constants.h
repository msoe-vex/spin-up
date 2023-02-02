#pragma once
#include <vector>

#include "hardware/pros_motor.h"
#include "interface/motor.h"
#include "main.h"

/**
 * Factory functions for retriving Motors on the robot.
 */
namespace constants {
struct DrivetrainMotors {
  interface::Motor front_right_motor;
  interface::Motor back_right_motor;
  interface::Motor back_left_motor;
  interface::Motor front_left_motor;
};
DrivetrainMotors GetDrivetrainMotors();

interface::MotorAndEncoder GetShooterMotor();
interface::Motor GetTransferMotor();
}  // namespace constants