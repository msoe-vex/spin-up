#include "ProsMotor.h"

ProsMotor::ProsMotor(
    int port_number, bool reverse, pros::motor_gearset_e_t gearset)
    : _motor(port_number, gearset, reverse), _gearset(gearset) {}

void ProsMotor::Move(int value) { _motor.move(value); }
void ProsMotor::MoveVoltage(int voltage) { _motor.move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  // float rpm = (velocity / MAX_VELOCITY) * ProsMotor::GetMaxRpm();
  // _motor.move_velocity(rpm);
}

void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  _motor.move_absolute(position, max_velocity);
}

void ProsMotorAndEncoder::ResetEncoder() { _motor.tare_position(); }
int ProsMotorAndEncoder::GetPosition() { return _motor.get_position(); }
float ProsMotorAndEncoder::GetVelocity() { _motor.get_actual_velocity();}






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

//#define kMaxVelocity 50.0f  // in/s (I put this here bc idk how to call it from constants.h)

void ProsMotor::MoveVelocity(float velocity) {
    float rpm = (velocity / kMaxVelocity) * GetMaxRpm();
    _motor.move_velocity(rpm);
}

float ProsMotorAndEncoder::GetVelocity() {
    float rpm = _motor.get_actual_velocity();
    return (rpm / GetMaxRpm()) * kMaxVelocity;
}   