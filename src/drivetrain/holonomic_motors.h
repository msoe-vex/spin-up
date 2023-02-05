#pragma once
#include <memory>

#include "constant/motor_constants.h"
#include "hardware/pros_motor_group.h"

namespace drivetrain {
class HolonomicMotors {
 public:
  HolonomicMotors(std::vector<std::unique_ptr<interface::Motor>> motors)
      : motors_(std::move(motors)) {}

  static drivetrain::HolonomicMotors GetHolonomicMotors();

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
}  // namespace drivetrain