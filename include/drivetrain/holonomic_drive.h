#pragma once
#include <vector>

#include "hardware/pros_motor_group.h"
#include "interface/controller.h"
#include "interface/motor.h"

namespace drivetrain {
class HolonomicDrivetrainMotors {
 public:
  HolonomicDrivetrainMotors(
      interface::Motor front_right_motor, interface::Motor back_right_motor,
      interface::Motor back_left_motor, interface::Motor front_left_motor)
      : drivetrain_motors_(
            {front_right_motor, back_right_motor, back_left_motor,
             front_left_motor}) {}

 public:
  inline void SetVoltages(const std::vector<int>& voltages) {
    for (int i = 0; i < voltages.size(); ++i) {
      drivetrain_motors()[i].MoveVoltage(voltages[i]);
    }
  };

 private:
  inline std::vector<interface::Motor>& drivetrain_motors() {
    return drivetrain_motors_;
  }
  std::vector<interface::Motor> drivetrain_motors_;
};

class HolonomicDrive {
 public:
  HolonomicDrive(HolonomicDrivetrainMotors drivetrain_motors)
      : drivetrain_motors_(drivetrain_motors) {}

 protected:
  inline HolonomicDrivetrainMotors& drivetrain_motors() {
    return drivetrain_motors_;
  }

 private:
  HolonomicDrivetrainMotors drivetrain_motors_;
};

/**
 * Implements a holonomic drive system.
 */
class FieldOrientedHolonomicDrive : public HolonomicDrive {};

class HolonomicDirectDrive : virtual public HolonomicDrive {
 public:
 using HolonomicDrive::HolonomicDrive; // constructor inheritance

  void Drive(interface::Controller);
};
}  // namespace drivetrain