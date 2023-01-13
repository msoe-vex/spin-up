#include "../include/Motor.h"

Motor::Motor(int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : _motor(port_number, gearset, reverse) {}

void Motor::ResetEncoder() { _motor.tare_position(); }

void Motor::Move(int value) { _motor.move(value); }
void Motor::MoveVoltage(int voltage) { _motor.move_voltage(voltage); }
void Motor::MoveVelocity(float velocity) {
  float rpm = (velocity / MAX_VELOCITY) * GetMaxRpm();
  _motor.move_velocity(rpm);
}
void Motor::MoveAbsolute(double position, int max_velocity) {
  _motor.move_absolute(position, max_velocity);
}

int Motor::_position() { return _motor.get_position(); }