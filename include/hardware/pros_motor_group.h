#pragma once
#include <cstdint>
#include <numeric>
#include <vector>

#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {
class ProsMotorGroup : public interface::Motor, public interface::Encoder {
 public:
  ProsMotorGroup(
      std::vector<int> port_numbers, std::vector<bool> reverse,
      pros::motor_gearset_e_t);

  void Move(int) override;
  void MoveVoltage(int) override;
  void MoveVelocity(float) override;
  void MoveAbsolute(double position, int max_velocity) override;

  void ResetEncoder() override;
  double GetPosition() override;
  float GetVelocity() override;

 private:
  inline pros::MotorGroup& motors() { return motors_; }
  int GetMaxRpm();

  std::vector<std::int8_t> FlipPortNumbers(
      std::vector<int> port_numbers, std::vector<bool> reverse);

  pros::MotorGroup motors_;
};
}  // namespace hardware