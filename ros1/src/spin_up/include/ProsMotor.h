#pragma once
#include <string>

#include "main.h"
#include "Motor.h"

class ProsMotor : private Motor {
 public:
  ProsMotor(int port_number, bool reverse, pros::motor_gearset_e_t gearset);

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity);

  int GetMaxRpm();

 protected:
  pros::Motor _motor;
  pros::motor_gearset_e_t _gearset;
};

class ProsMotorAndEncoder : protected ProsMotor {
 public:
  void ResetEncoder();
  int _position();
};
