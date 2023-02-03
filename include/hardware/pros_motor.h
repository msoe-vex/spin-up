#pragma once
#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {
/**
 * A class which wraps a single pros::Motor object.
 */
class ProsMotor : virtual public interface::Motor,
                  virtual public interface::Encoder {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t);

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity);

  void ResetEncoder();
  int GetPosition();
  float GetVelocity();

 private:
  int GetMaxRpm();
  inline pros::Motor& motor() { return motor_; }

  pros::Motor motor_;
};
}  // namespace hardware