#include "hardware/pros_motor.h"

namespace hardware {
int GetMaxRpm(pros::motor_gearset_e_t gearset) {
  auto cartridge = static_cast<ProsMotorCartridge>(gearset);
  switch (cartridge) {
    case ProsMotorCartridge::kBlueCartridge:
      return 600;
    case ProsMotorCartridge::kGreenCartridge:
      return 200;
  }
  throw std::invalid_argument("Specified gearset is not supported.");
}

void ProsMotor::Move(int value) { motor().move(value); }
void ProsMotor::MoveVoltage(int voltage) { motor().move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / constant::kMaxVelocity) * GetMaxRpm();
  motor().move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  motor().move_absolute(position, max_velocity);
}

void ProsMotor::ResetEncoder() { motor().tare_position(); }

double ProsMotor::GetPosition() { return motor().get_position(); }
float ProsMotor::GetVelocity() {
  float rpm = motor().get_actual_velocity();
  return (rpm / GetMaxRpm()) * constant::kMaxVelocity;
}

int ProsMotor::GetMaxRpm() {
  return hardware::GetMaxRpm(motor().get_gearing());
}
}  // namespace hardware