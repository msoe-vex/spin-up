#pragma once
#include <memory>
#include <vector>

#include "interface/controller.h"
#include "interface/motor.h"

namespace drivetrain {
class HolonomicMotors {
 public:
  HolonomicMotors(std::vector<std::unique_ptr<interface::Motor>> motors)
      : motors_(std::move(motors)) {}

  // Delete copy constructor and assignment operator to prevent issues with
  // wrapped unique_ptrs
  HolonomicMotors(const HolonomicMotors&) = delete;
  HolonomicMotors& operator=(const HolonomicMotors&) = delete;

  // Add move operators
  HolonomicMotors(HolonomicMotors&&) = default;
  HolonomicMotors& operator=(HolonomicMotors&&) = default;
  ~HolonomicMotors() = default;

  inline void SetVoltages(const std::vector<float>& voltages) {
    for (int i = 0; i < voltages.size(); ++i) {
      motors()[i]->MoveVoltage(voltages[i]);
    }
  };

 private:
  inline std::vector<std::unique_ptr<interface::Motor>>& motors() {
    return motors_;
  }
  std::vector<std::unique_ptr<interface::Motor>> motors_;
};

class HolonomicDrive {
 public:
  HolonomicDrive(HolonomicMotors holonomic_motors)
      : holonomic_motors_(std::move(holonomic_motors)) {}

  //  protected:
  inline HolonomicMotors& holonomic_motors() { return holonomic_motors_; }

 private:
  HolonomicMotors holonomic_motors_;
};

/**
 * Implements a holonomic drive system.
 */
class FieldOrientedHolonomicDrive : public HolonomicDrive {};

class HolonomicDirectDrive : virtual public HolonomicDrive {
 public:
  using HolonomicDrive::HolonomicDrive;  // constructor inheritance

  void Drive(const interface::Controller&);
};
}  // namespace drivetrain