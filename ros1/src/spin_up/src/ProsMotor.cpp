#include "../include/ProsMotor.h"

ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : _motor(port_number, gearset, reverse) {}

void ProsMotor::Move(int value) { _motor.move(value); }
void ProsMotor::MoveVoltage(int voltage) { _motor.move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / MAX_VELOCITY) * GetMaxRpm();
  _motor.move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  _motor.move_absolute(position, max_velocity);
}

void ProsMotorAndEncoder::ResetEncoder() { _motor.tare_encoder(); }
int ProsMotorAndEncoder::_position() { return _motor.get_position(); }