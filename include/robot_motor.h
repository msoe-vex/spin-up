#pragma once
#include <vector>

#include "motor.h"
#include "robot_port.h"

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
DrivetrainMotors get_drivetrain_motors();

MotorAndEncoder get_shooter_motor();
Motor get_transfer_motor();
}  // namespace robotmotor