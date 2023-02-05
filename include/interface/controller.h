#pragma once
namespace interface {
enum class ControllerJoystick { kLeftX = 0, kLeftY, kRightX, kRightY };

class Controller {
 public:
  virtual int GetAnalog(ControllerJoystick joystick) const = 0;
  virtual float GetVoltage(ControllerJoystick joystick) const = 0;

  virtual ~Controller() = default;
};
}  // namespace interface