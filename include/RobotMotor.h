#pragma once
#include <vector>

#include "Motor.h"
#include "RobotPort.h"

/**
 * Factory functions for retriving Motors on the robot.
 */
namespace RobotMotor {
struct DrivetrainMotors {
  Motor front_right;
  Motor back_right;
  Motor back_left;
  Motor front_left;
};
DrivetrainMotors get_drivetrain_motors();

MotorAndEncoder get_shooter_motor();
Motor get_transfer_motor();
}  // namespace RobotMotor