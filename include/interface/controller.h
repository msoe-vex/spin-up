#pragma once
namespace interface {
enum class ControllerJoystick { kLeftX = 0, kLeftY, kRightX, kRightY };

class Controller {
 public:
  virtual int GetAnalog(ControllerJoystick joystick) = 0;
  virtual float GetVoltage(ControllerJoystick joystick) = 0;
};
}  // namespace interface