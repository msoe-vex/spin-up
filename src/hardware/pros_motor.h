#pragma once
#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "pros.h"

namespace hardware {

enum class ProsMotorCartridge {
  kBlueCartridge = pros::E_MOTOR_GEAR_BLUE,   // 600 rpm
  kGreenCartridge = pros::E_MOTOR_GEAR_GREEN  // 200 rpm
};

pros::motor_gearset_e_t GetProsGearset(ProsMotorCartridge);

namespace {
ProsMotorCartridge GetProsMotorCartridge(pros::motor_gearset_e_t);
}  // namespace

/**
 * A helper function for getting the max rpm of a motor.
 */
int GetMaxRpm(const pros::Motor& motor);

/**
 * A class which wraps a single pros::Motor object.
 */
class ProsMotor : public interface::Motor, public interface::Encoder {
 public:
  ProsMotor(int port_number, bool reverse, ProsMotorCartridge motor_cartridge)
      : motor_(
            port_number * (reverse ? -1 : 1), GetProsGearset(motor_cartridge)) {
  }

  void Move(int) override;
  void MoveVoltage(int) override;
  void MoveVelocity(float) override;
  void MoveAbsolute(double position, int max_velocity) override;

  void ResetEncoder() override;
  double GetPosition() const override;
  float GetVelocity() const override;

 private:
  int GetMaxRpm() const;

  inline const pros::Motor& motor() const { return motor_; }
  inline pros::Motor& motor() { return motor_; }

  pros::Motor motor_;
};
}  // namespace hardware