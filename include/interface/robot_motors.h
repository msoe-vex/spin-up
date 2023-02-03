#pragma once

#include "interface/motor.h"
#include "constant/motor_constants.h"
#include "hardware/pros_motor.h"

namespace interface {

struct DrivetrainMotors {
  // declared in clockwise fashion
  Motor front_right_motor;
  Motor back_right_motor;
  Motor back_left_motor;
  Motor front_left_motor;
};

DrivetrainMotors GetDrivetrainMotors();
} // namespace interface