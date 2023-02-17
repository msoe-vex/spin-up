#pragma once
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <vector>

#include "constant/constants.h"
#include "hardware/pros_motor.h"
#include "hardware/pros_motor_cartridge.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "pros.h"

namespace hardware {
class ProsMotorGroup : public interface::Motor, public interface::Encoder {
 public:
  ProsMotorGroup(
      std::vector<int> port_numbers, std::vector<bool> reverse,
      ProsMotorCartridge cartridge)
      : motors_(FlipPortNumbers(port_numbers, reverse)) {
    motors().set_gearing(static_cast<pros::motor_gearset_e_t>(cartridge));
  }

  ProsMotorGroup(const ProsMotorGroup&) = delete;
  ProsMotorGroup& operator=(const ProsMotorGroup&) = delete;

  ProsMotorGroup(ProsMotorGroup&&) = default;
  ProsMotorGroup& operator=(ProsMotorGroup&&) = default;
  ~ProsMotorGroup() = default;

  void Move(int) override;
  void MoveVoltage(int) override;
  void MoveVelocity(float) override;
  void MoveAbsolute(double position, int max_velocity) override;

  void ResetEncoder() override;
  [[nodiscard]] double position() const override;
  [[nodiscard]] float velocity() const override;

 private:
  [[nodiscard]] ProsMotorCartridge cartridge() const;
  [[nodiscard]] int max_rpm() const;

  [[nodiscard]] std::vector<std::int8_t> FlipPortNumbers(
      std::vector<int> port_numbers, std::vector<bool> reverse);

  [[nodiscard]] inline pros::MotorGroup& motors() const { return motors_; }
  [[nodiscard]] inline pros::MotorGroup& motors() { return motors_; }

  // mutable to prevent issues with const methods
  // Some pros methods are missing const annotations
  mutable pros::MotorGroup motors_;
};
}  // namespace hardware