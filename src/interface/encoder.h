#pragma once

namespace interface {
class Encoder {
 public:
  virtual void ResetEncoder() = 0;
  virtual double GetPosition() const = 0;
  virtual float GetVelocity() const = 0;

  virtual ~Encoder() = default;
};
}  // namespace interface