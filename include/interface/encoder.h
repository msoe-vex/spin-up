#pragma once

namespace interface {
class Encoder {
 public:
  virtual void ResetEncoder();
  virtual double GetPosition();
  virtual float GetVelocity();
};
}  // namespace interface