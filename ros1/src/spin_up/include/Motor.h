#pragma once
#include <string>

#include "MotorInterface.h"
#include "main.hpp"

class Motor : MotorInterface {
 public:
  Motor(int port_number, bool reverse, pros::motor_gearset_e_t gearset);

  void ResetEncoder();

  void Move(int);
  void MoveVoltage(int);
  void MoveVelocity(float);
  void MoveAbsolute(double position, int max_velocity) {

    _motor.ahh();
  }

  // pretend getter
  int _position();

 private:
  pros::Motor _motor;
};
