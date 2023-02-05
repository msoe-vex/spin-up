#pragma once

namespace interface {
class Encoder {
 public:
  virtual void ResetEncoder() = 0;
  virtual double GetPosition() = 0;
  virtual float GetVelocity() = 0;

  virtual ~Encoder() = default;
};
}  // namespace interface