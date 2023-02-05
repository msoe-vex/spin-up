#pragma once
namespace interface {
enum class ControllerJoystick { kLeftX, kLeftY, kRightX, kRightY };

class Controller {
 public:
  virtual int analog(ControllerJoystick joystick) const = 0;
  virtual float voltage(ControllerJoystick joystick) const = 0;

  virtual ~Controller() = default;
};
}  // namespace interface