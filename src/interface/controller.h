#pragma once
namespace interface {
enum class ControllerJoystick { kLeftX, kLeftY, kRightX, kRightY };

enum class ControllerButton { kA, kX, kY };

class Controller {
 public:
  [[nodiscard]] virtual int analog(ControllerJoystick joystick) const = 0;
  [[nodiscard]] virtual float voltage(ControllerJoystick joystick) const = 0;
  [[nodiscard]] virtual boolean button(ControllerButton button) const = 0;

  virtual ~Controller() = default;
};
}  // namespace interface