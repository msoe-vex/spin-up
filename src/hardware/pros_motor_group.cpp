#include "hardware/pros_motor_group.h"

namespace hardware {
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

double ProsMotorGroup::GetPosition() const {
  // manual member access to avoid automatically calling const motors()
  std::vector<double> positions = motors_.get_positions();
  return std::reduce(positions.begin(), positions.end()) / positions.size();
}
float ProsMotorGroup::GetVelocity() const {
  std::vector<double> motor_rpms = motors_.get_actual_velocities();
  float rpm =
      std::reduce(motor_rpms.cbegin(), motor_rpms.cend()) / motor_rpms.size();
  return (rpm / GetMaxRpm()) * constant::kMaxVelocity;
}

std::vector<std::int8_t> ProsMotorGroup::FlipPortNumbers(
    std::vector<int> port_numbers, std::vector<bool> reverse) {
  if (port_numbers.size() != reverse.size()) {
    throw std::invalid_argument(
        "Expected port_numbers to be the same size as reverse.");
  }

  std::vector<std::int8_t> result;
  for (int i = 0; i < port_numbers.size(); ++i) {
    result.push_back(port_numbers[i] * (reverse[i] ? -1 : 1));
  }
  return result;
}

int ProsMotorGroup::GetMaxRpm() const {
  return hardware::GetMaxRpm(motors_[0]);
}
}  // namespace hardware