#include "pros_motor.h"

namespace prosmotor {
ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : motor_(port_number, gearset, reverse) {}

void ProsMotor::Move(int value) { motor_.move(value); }
void ProsMotor::MoveVoltage(int voltage) { motor_.move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / robotconstant::kMaxVelocity) * GetMaxRpm();
  motor_.move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  motor_.move_absolute(position, max_velocity);
}
int ProsMotor::GetMaxRpm() const {
  switch (motor_.get_gearing()) {
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

void ProsMotorAndEncoder::ResetEncoder() { motor_.tare_position(); }
int ProsMotorAndEncoder::GetPosition() const { return motor_.get_position(); }
float ProsMotorAndEncoder::GetVelocity() const {
  float rpm = motor_.get_actual_velocity();
  return (rpm / ProsMotorAndEncoder::GetMaxRpm()) * robotconstant::kMaxVelocity;
}
}  // namespace prosmotor