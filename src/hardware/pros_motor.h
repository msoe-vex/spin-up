#pragma once
#include "constant/constants.h"
#include "interface/encoder.h"
#include "interface/motor.h"
#include "pros.h"

namespace hardware {

enum class ProsMotorCartridge {
  // equal to pros value to enable casting
  kBlueCartridge = pros::E_MOTOR_GEAR_BLUE,   // 600 rpm
  kGreenCartridge = pros::E_MOTOR_GEAR_GREEN  // 200 rpm
};

pros::motor_gearset_e_t ConvertProsMotorCartridge(ProsMotorCartridge);
ProsMotorCartridge ConvertProsGearset(pros::motor_gearset_e_t);

/**
 * A helper function for getting the max rpm of a motor.
 */
int GetMaxRpm(const ProsMotorCartridge);

/**
 * A class which wraps a single pros::Motor object.
 */
class ProsMotor : public interface::Motor, public interface::Encoder {
 public:
  ProsMotor(int port_number, bool reverse, ProsMotorCartridge cartridge)
      : motor_(
            port_number * (reverse ? -1 : 1), ConvertProsMotorCartridge(cartridge)) {
  }

  void Move(int) override;
  void MoveVoltage(int) override;
  void MoveVelocity(float) override;
  void MoveAbsolute(double position, int max_velocity) override;

  void ResetEncoder() override;
  double position() const override;
  float velocity() const override;

 private:
  ProsMotorCartridge cartridge() const;
  int max_rpm() const;

  inline const pros::Motor& motor() const { return motor_; }
  inline pros::Motor& motor() { return motor_; }

  pros::Motor motor_;
};
}  // namespace hardware