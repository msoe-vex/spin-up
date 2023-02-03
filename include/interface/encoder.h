#pragma once

namespace interface {
class Encoder {
 public:
  virtual void ResetEncoder();
  virtual int GetPosition();
  virtual float GetVelocity();
};
}  // namespace interface