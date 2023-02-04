#include "hardware/pros_controller.h"

#include "constant/constants.h"

namespace hardware {
pros::controller_analog_e_t GetProsJoystick(
    enum interface::ControllerJoystick joystick) {
  switch (joystick) {
    case interface::ControllerJoystick::kLeftX:
      return pros::E_CONTROLLER_ANALOG_LEFT_X;
    case interface::ControllerJoystick::kLeftY:
      return pros::E_CONTROLLER_ANALOG_LEFT_Y;
    case interface::ControllerJoystick::kRightX:
      return pros::E_CONTROLLER_ANALOG_RIGHT_X;
    case interface::ControllerJoystick::kRightY:
      return pros::E_CONTROLLER_ANALOG_RIGHT_Y;
  }
  throw std::invalid_argument("Expected a convertible joystick.");
}

int ProsController::GetAnalog(enum interface::ControllerJoystick joystick) {
  return controller().get_analog(GetProsJoystick(joystick));
}

float ProsController::GetVoltage(enum interface::ControllerJoystick joystick) {
  return controller().get_analog(GetProsJoystick(joystick)) /
         static_cast<float>(constant::kProsMaxJoystickAnalog) *
         constant::kProsMaxMotorVoltage;
}
}  // namespace hardware