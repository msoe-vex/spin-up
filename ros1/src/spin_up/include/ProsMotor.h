#pragma once
#include <string>

#include "Motor.h"

class ProsMotor : Motor {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t gearset);

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity);

 private:
  pros::Motor _motor;
};

class ProsMotorAndEncoder : ProsMotor {
 public:
  void ResetEncoder();
  int _position();
};
