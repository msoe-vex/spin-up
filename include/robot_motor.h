#pragma once
#include <vector>

#include "main.h"
#include "motor.h"
#include "pros_motor.h"

/**
 * Factory functions for retriving Motors on the robot.
 */
namespace robot {
struct DrivetrainMotors {
  interface::Motor front_right_motor;
  interface::Motor back_right_motor;
  interface::Motor back_left_motor;
  interface::Motor front_left_motor;
};
DrivetrainMotors GetDrivetrainMotors();

interface::MotorAndEncoder GetShooterMotor();
interface::Motor GetTransferMotor();
}  // namespace robot