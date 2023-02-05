#include "drivetrain/holonomic_motors.h"

namespace drivetrain {
HolonomicMotors HolonomicMotors::GetHolonomicMotors() {
  std::vector<std::unique_ptr<interface::Motor>> motors;
  // emplace back constructs the ptr inside the vector instead of copying
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kFrontRightMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kBackRightMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kBackLeftMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  motors.emplace_back(std::make_unique<hardware::ProsMotorGroup>(
      constant::kFrontLeftMotorPorts, constant::kDrivetrainReverse,
      constant::kDrivetrainCartridge));
  return HolonomicMotors(std::move(motors));
}
}  // namespace drivetrain