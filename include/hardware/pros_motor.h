#pragma once
#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {

enum class ProsMotorCartridge {
  kBlueCartridge = pros::E_MOTOR_GEAR_BLUE,   // 600 rpm
  kGreenCartridge = pros::E_MOTOR_GEAR_GREEN  // 200 rpm
};

int GetMaxRpm(pros::motor_gearset_e gearset);

/**
 * A class which wraps a single pros::Motor object.
 */
class ProsMotor : public interface::Motor, public interface::Encoder {
 public:
  ProsMotor(int port_number, bool reverse, ProsMotorCartridge motor_cartridge)
      : motor_(
            port_number * (reverse ? -1 : 1),
            static_cast<pros::motor_gearset_e_t>(motor_cartridge)) {}

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