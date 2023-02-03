#include "hardware/pros_motor_group.h"

namespace hardware {
ProsMotorGroup::ProsMotorGroup(
    std::vector<int> port_numbers, std::vector<bool> reverse,
    pros::motor_gearset_e_t gearset)
    : motors_(ProsMotorGroup::FlipPortNumbers(port_numbers, reverse)) {
  motors().set_gearing(gearset);
}

void ProsMotorGroup::Move(int value) { motors().move(value); }
void ProsMotorGroup::MoveVoltage(int voltage) {
  motors().move_voltage(voltage);
}
void ProsMotorGroup::MoveVelocity(float velocity) {
  float rpm = (velocity / constant::kMaxVelocity) * GetMaxRpm();
  motors().move_velocity(rpm);
}
void ProsMotorGroup::MoveAbsolute(double position, int max_velocity) {
  motors().move_absolute(position, max_velocity);
}

void ProsMotorGroup::ResetEncoder() { motors().tare_position(); }

int ProsMotorGroup::GetPosition() {
  std::vector<int> positions = motors().get_positions();
  return std::reduce(positions.begin(), positions.end()) / positions.size();
}
float ProsMotorGroup::GetVelocity() {
  std::vector<double> motor_rpms = motors().get_actual_velocities();
  float rpm =
      std::reduce(motor_rpms.cbegin(), motor_rpms.cend()) / motor_rpms.size();
  return (rpm / GetMaxRpm()) * constant::kMaxVelocity;
}

std::vector<std::int8_t> ProsMotorGroup::FlipPortNumbers(
    std::vector<int> port_numbers, std::vector<bool> reverse) {
  std::vector<std::int8_t> result;
  for (int i = 0; i < port_numbers.size(); ++i) {
    result.push_back(port_numbers[i] * (reverse[i] ? -1 : 1));
  }
  return result;
}

int ProsMotorGroup::GetMaxRpm() {
  // assume all gearing is the same
  switch (motors()[0].get_gearing()) {
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