#pragma once
namespace interface {
enum ControllerJoystick { kLeftX = 0, kLeftY, kRightX, kRightY };

class Controller {
 public:
  virtual int GetAnalog(ControllerJoystick joystick);
  virtual float GetVoltage(ControllerJoystick joystick);
};
}  // namespace interface