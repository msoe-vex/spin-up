#include "drivetrain/holonomic_motors.h"

namespace drivetrain {
HolonomicMotors HolonomicMotors::MakeHolonomicMotors() {
  std::vector<std::unique_ptr<interface::Motor>> motor_ptrs;
  // emplace back constructs the ptr inside the vector instead of copying
  motor_ptrs.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kFrontRightMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motor_ptrs.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kBackRightMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motor_ptrs.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kBackLeftMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motor_ptrs.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kFrontLeftMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  return HolonomicMotors(std::move(motor_ptrs));
}
}  // namespace drivetrain