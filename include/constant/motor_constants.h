#pragma once
#include <vector>

#include "main.h"

namespace constant {
const pros::motor_gearset_e_t kDrivetrainGearset = pros::E_MOTOR_GEAR_BLUE;
const std::vector<bool> kDrivetrainReverse = {false, true};

const std::vector<std::vector<int>> kDrivertainMotorPorts = {
    // {top motor, bottom motor}
    {1, 2},  // front right
    {3, 4},  // back right
    {5, 6},  // back left
    {7, 8}   // front left
};

}  // namespace constant