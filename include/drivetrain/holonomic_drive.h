#pragma once
#include "interface/holonomic_drivetrain_motors.h"

namespace drivetrain {
interface::HolonomicDrivetrainMotors GetHolonomicDrivetrainMotors();

class HolonomicDrive {
 public:
  HolonomicDrive(interface::HolonomicDrivetrainMotors drivetrain_motors)
      : drivetrain_motors_(drivetrain_motors) {}

 protected:
  inline interface::HolonomicDrivetrainMotors& drivetrain_motors() {
    return drivetrain_motors_;
  }

 private:
  interface::HolonomicDrivetrainMotors drivetrain_motors_;
};

/**
 * Implements a holonomic drive system.
 */
class FieldOrientedHolonomicDrive : public HolonomicDrive {};

class HolonomicDirectDrive : public HolonomicDrive {};

class TankDrive {};

}  // namespace drivetrain