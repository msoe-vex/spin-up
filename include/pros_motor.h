#pragma once
#include <string>

#include "main.h"
#include "motor.h"
#include "robot_constant.h"

namespace prosmotor {
class ProsMotor : private Motor {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t gearset);

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity);

 protected:
  int GetMaxRpm();

  pros::Motor motor_;
};

class ProsMotorAndEncoder : protected ProsMotor {
 public:
  void ResetEncoder();
  int GetPosition();
  float GetVelocity();
};
}  // namespace prosmotor