#include "drivetrain/holonomic_drive.h"

namespace drivetrain {

void HolonomicDirectDrive::Drive(interface::Controller controller) {
  const std::vector<int> voltages = {
      controller.GetAnalog(interface::ControllerJoystick::kLeftX),
      controller.GetAnalog(interface::ControllerJoystick::kLeftY),
      controller.GetAnalog(interface::ControllerJoystick::kRightX),
      controller.GetAnalog(interface::ControllerJoystick::kRightY)};
  drivetrain_motors().SetVoltages(voltages);
}

}  // namespace drivetrain