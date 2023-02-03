#pragma once
#include <cstdint>
#include <vector>

#include "constant/constants.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {
struct ProsMotorDefinition {
  int port_number;
  bool reverse;
  ProsMotorDefinition(int port_number, bool reverse = false);
};

class ProsMotor : virtual public interface::Motor {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t);
  ProsMotor(
      std::vector<int> port_numbers, std::vector<bool> reverse,
      pros::motor_gearset_e_t);

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity);

 protected:
  int GetMaxRpm();
  inline pros::MotorGroup& motor() { return motor_; }

 private:
  std::vector<std::int8_t> FlipPortNumbers(std::vector<int>, std::vector<bool>);

  pros::MotorGroup motor_;
};

class ProsMotorAndEncoder : protected ProsMotor,
                            virtual public interface::MotorAndEncoder {
 public:
  void ResetEncoder();
  int GetPosition();
  float GetVelocity();
};
}  // namespace hardware