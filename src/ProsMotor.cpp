#include "ProsMotor.h"

ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : _motor(port_number, gearset, reverse) {}

void ProsMotor::Move(int value) { _motor.move(value); }
void ProsMotor::MoveVoltage(int voltage) { _motor.move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / kMaxVelocity) * GetMaxRpm();
  _motor.move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  _motor.move_absolute(position, max_velocity);
}
int ProsMotor::GetMaxRpm() {
  switch (_motor.get_gearing()) {
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
void ProsMotorAndEncoder::ResetEncoder() { _motor.tare_position(); }
int ProsMotorAndEncoder::GetPosition() { return _motor.get_position(); }
float ProsMotorAndEncoder::GetVelocity() {
  float rpm = _motor.get_actual_velocity();
  return (rpm / GetMaxRpm()) * kMaxVelocity;
}