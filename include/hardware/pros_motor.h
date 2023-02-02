#pragma once
#include <cstdint>
#include <vector>

#include "constants/constants.h"
#include "interface/motor.h"
#include "main.h"

namespace hardware {
class ProsMotor : virtual private interface::Motor {
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
  pros::MotorGroup motor_;

 private:
  std::vector<std::int8_t> FlipPortNumbers(std::vector<int>, std::vector<bool>);
};

class ProsMotorAndEncoder : protected ProsMotor,
                            virtual private interface::MotorAndEncoder {
 public:
  void ResetEncoder();
  int GetPosition();
  float GetVelocity();
};
}  // namespace hardware