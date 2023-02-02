#pragma once

namespace interface {
class Motor {
 public:
  virtual void Move(int);
  virtual void MoveVoltage(int);
  virtual void MoveVelocity(int);
  virtual void MoveAbsolute(double position, int max_velocity);
};

class MotorAndEncoder : Motor {
 public:
  virtual void ResetEncoder();
  virtual int GetPosition();
  virtual float GetVelocity();
};
}  // namespace interface