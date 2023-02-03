#include "hardware/pros_motor.h"

namespace hardware {
ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : motor_(port_number * (reverse ? -1 : 1), gearset) {}

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

int ProsMotor::GetPosition() { return motor().get_position(); }
float ProsMotor::GetVelocity() {
  float rpm = motor().get_actual_velocity();
  return (rpm / GetMaxRpm()) * constant::kMaxVelocity;
}

int ProsMotor::GetMaxRpm() {
  // assume all gearing is the same
  switch (motor().get_gearing()) {
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
}  // namespace hardware