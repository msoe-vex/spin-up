#include "hardware/pros_motor.h"

namespace hardware {
pros::motor_gearset_e_t GetProsGearset(ProsMotorCartridge cartridge) {
  switch (cartridge) {
    case ProsMotorCartridge::kBlueCartridge:
      return pros::E_MOTOR_GEARSET_06;
    case ProsMotorCartridge::kGreenCartridge:
      return pros::E_MOTOR_GEARSET_18;
    default:
      throw std::invalid_argument(
          "Failed to convert cartridge to pros gearset.");
  }
}

namespace {
ProsMotorCartridge GetProsMotorCartridge(pros::motor_gearset_e_t gearset) {
  switch (gearset) {
    case pros::E_MOTOR_GEARSET_06:
      return ProsMotorCartridge::kBlueCartridge;
    case pros::E_MOTOR_GEARSET_18:
      return ProsMotorCartridge::kGreenCartridge;
    default:
      throw std::invalid_argument(
          "Failed to convert pros gearset to cartridge.");
  }
}
}  // namespace

int get_max_rpm(const pros::Motor& motor) {
  switch (GetProsMotorCartridge(motor.get_gearing())) {
    case ProsMotorCartridge::kBlueCartridge:
      return 600;
    case ProsMotorCartridge::kGreenCartridge:
      return 200;
    default:
      throw std::invalid_argument("Failed to convert cartridge to max rpm.");
  }
}

void ProsMotor::Move(int value) { motor().move(value); }
void ProsMotor::MoveVoltage(int voltage) { motor().move_voltage(voltage); }
void ProsMotor::MoveVelocity(float velocity) {
  float rpm = (velocity / constant::kMaxVelocity) * get_max_rpm();
  motor().move_velocity(rpm);
}
void ProsMotor::MoveAbsolute(double position, int max_velocity) {
  motor().move_absolute(position, max_velocity);
}

void ProsMotor::ResetEncoder() { motor().tare_position(); }

double ProsMotor::position() const { return motor().get_position(); }
float ProsMotor::velocity() const {
  float rpm = motor().get_actual_velocity();
  return (rpm / get_max_rpm()) * constant::kMaxVelocity;
}

int ProsMotor::get_max_rpm() const { return hardware::get_max_rpm(motor()); }
}  // namespace hardware