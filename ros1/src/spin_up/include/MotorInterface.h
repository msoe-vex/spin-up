#pragma once

class MotorInterface {
 public:
  virtual void ResetEncoder();

  virtual void Move(int);
  virtual void MoveVoltage(int);
  virtual void MoveVelocity(int);
  virtual void MoveAbsolute(double position, int max_velocity);

  // pretend getter
  virtual int _position();
};
