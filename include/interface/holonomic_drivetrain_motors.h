#pragma once
#include <vector>

#include "interface/motor.h"

namespace interface {
class HolonomicDrivetrainMotors {
 public:
  HolonomicDrivetrainMotors(
      Motor front_right_motor, Motor back_right_motor, Motor back_left_motor,
      Motor front_left_motor)
      : drivetrain_motors_(
            {front_right_motor, back_right_motor, back_left_motor,
             front_left_motor}) {}

 private:
  std::vector<interface::Motor> drivetrain_motors_;
};

}  // namespace interface