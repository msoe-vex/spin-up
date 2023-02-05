#pragma once

namespace interface {
class Encoder {
 public:
  virtual void ResetEncoder() = 0;
  virtual double position() const = 0;
  virtual float velocity() const = 0;

  virtual ~Encoder() = default;
};
}  // namespace interface