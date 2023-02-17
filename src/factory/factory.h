#pragma once

#include <utility>

#include "drivetrain/holonomic_drive.h"
#include "drivetrain/holonomic_motors.h"
#include "hardware/pros_motor.h"

namespace factory {
struct HolonomicDrivetrainPorts {
  std::pair<int, int> front_left;
  std::pair<int, int> front_right;
  std::pair<int, int> back_right;
  std::pair<int, int> back_left;
};

[[nodiscard]] drivetrain::HolonomicDrivetrain MakeHolonomicDrivetrain(
    HolonomicDrivetrainPorts ports, bool reverse,
    hardware::ProsMotorCartridge cartridge);

// [[nodiscard]] MakeProsMotor();
}  // namespace factory