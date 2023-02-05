#pragma once
#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {
/**
 * A class which wraps a single pros::Motor object.
 */
class ProsMotor : public interface::Motor, public interface::Encoder {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t gearset) : motor_(port_number * (reverse ? -1 : 1), gearset) {}

  void Move(int) override;
  void MoveVoltage(int) override;
  void MoveVelocity(float) override;
  void MoveAbsolute(double position, int max_velocity) override;

  void ResetEncoder() override;
  double GetPosition() override;
  float GetVelocity() override;

 private:
  int GetMaxRpm();
  inline pros::Motor& motor() { return motor_; }

  pros::Motor motor_;
};
}  // namespace hardware