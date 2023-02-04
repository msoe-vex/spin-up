#include "drivetrain/holonomic_drive.h"

namespace drivetrain {
void HolonomicDirectDrive::Drive(interface::Controller& controller) {
  //   const std::vector<float> voltages = {
  //       controller->GetVoltage(interface::ControllerJoystick::kLeftX),
  //       controller->GetVoltage(interface::ControllerJoystick::kLeftY),
  //       controller->GetVoltage(interface::ControllerJoystick::kRightX),
  //       controller->GetVoltage(interface::ControllerJoystick::kRightY)};
  //   drivetrain_motors().SetVoltages(voltages);
}

}  // namespace drivetrain