#pragma once
#include <cstdint>
#include <vector>

#include "main.h"
#include "motor.h"
#include "robot_constant.h"

namespace {}  // namespace

namespace hardware {
class ProsMotor : private interface::Motor {
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

class ProsMotorAndEncoder : private interface::MotorAndEncoder,
                            protected ProsMotor {
 public:
  void ResetEncoder();
  int GetPosition();
  float GetVelocity();
};
}  // namespace hardware