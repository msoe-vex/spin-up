#include "drivetrain/holonomic_drive.h"

namespace drivetrain {
void HolonomicDirectDrivetrain::Drive(const interface::Controller& controller) {
  const std::vector<float> voltages = {
      controller.voltage(interface::ControllerJoystick::kLeftX),
      controller.voltage(interface::ControllerJoystick::kLeftY),
      controller.voltage(interface::ControllerJoystick::kRightX),
      controller.voltage(interface::ControllerJoystick::kRightY)};
  holonomic_motors().SetVoltages(voltages);
}
}  // namespace drivetrain