#pragma once
#include <vector>

#include "motor.h"
#include "robot_constant.h"

/**
 * Factory functions for retriving Motors on the robot.
 */
namespace robotmotor {
struct DrivetrainMotors {
  Motor front_right_motor;
  Motor back_right_motor;
  Motor back_left_motor;
  Motor front_left_motor;
};
DrivetrainMotors GetDrivetrainMotors();

MotorAndEncoder GetShooterMotor();
Motor GetTransferMotor();
}  // namespace robotmotor