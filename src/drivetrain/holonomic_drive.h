#pragma once
#include <vector>

#include "drivetrain/holonomic_motors.h"
#include "interface/controller.h"
#include "interface/motor.h"

namespace drivetrain {
class HolonomicDrive {
 public:
  HolonomicDrive(HolonomicMotors holonomic_motors)
      : holonomic_motors_(std::move(holonomic_motors)) {}

 protected:
  [[nodiscard]] inline HolonomicMotors& holonomic_motors() {
    return holonomic_motors_;
  }

 private:
  HolonomicMotors holonomic_motors_;
};

/**
 * Implements a holonomic drive system.
 */
class FieldOrientedHolonomicDrive : public HolonomicDrive {
 public:
  using HolonomicDrive::HolonomicDrive;
};

class HolonomicDirectDrive : virtual public HolonomicDrive {
 public:
  using HolonomicDrive::HolonomicDrive;  // constructor inheritance

  void Drive(const interface::Controller&);
};
}  // namespace drivetrain