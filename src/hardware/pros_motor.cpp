#include "hardware/pros_motor.h"

namespace hardware {
ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : ProsMotor({port_number}, {reverse}, gearset) {}

ProsMotor::ProsMotor(
    std::vector<int> port_numbers, std::vector<bool> reverse,
    pros::motor_gearset_e_t gearset)
    : motor_(ProsMotor::FlipPortNumbers(port_numbers, reverse)) {
  motor().set_gearing(gearset);
}

std::vector<std::int8_t> ProsMotor::FlipPortNumbers(
    std::vector<int> port_numbers, std::vector<bool> reverse) {
  std::vector<std::int8_t> result;
  for (int i = 0; i < port_numbers.size(); ++i) {
    result.push_back(port_numbers[i] * (reverse[i] ? -1 : 1));
  }
  return result;
}

void ProsMotor::Move(int value) { ProsMotor::motor().move(value); }
void ProsMotor::MoveVoltage(int voltage) { motor().move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / constant::kMaxVelocity) * GetMaxRpm();
  motor().move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  motor().move_absolute(position, max_velocity);
}

int ProsMotor::GetMaxRpm() {
  // assume all gearing is the same
  switch (motor().get_gearing()[0]) {
    case pros::E_MOTOR_GEARSET_06:
      return 600;
    case pros::E_MOTOR_GEARSET_18:
      return 200;
    case pros::E_MOTOR_GEARSET_36:
      return 100;
    default:
      return 200;
  }
}

void ProsMotorAndEncoder::ResetEncoder() { motor().tare_position(); }
int ProsMotorAndEncoder::GetPosition() { return motor().get_positions()[0]; }
float ProsMotorAndEncoder::GetVelocity() {
  float rpm = motor().get_actual_velocities()[0];
  return (rpm / ProsMotorAndEncoder::GetMaxRpm()) * constant::kMaxVelocity;
}
}  // namespace hardware