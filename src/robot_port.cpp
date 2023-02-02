#include "robot_port.h"

namespace robotport {
Port::Port(int port_number, bool reverse = false)
    : port_number(port_number), reverse(reverse) {}

DrivetrainMotorPort::DrivetrainMotorPort(
    int bottom_motor_port_number, int top_motor_port_number)
    : bottom_motor_port(bottom_motor_port_number),
      top_motor_port(top_motor_port_number, true) {}

ShooterMotorPort::ShooterMotorPort(
    int left_motor_port_number, int right_motor_port_number)
    : left_motor_port(left_motor_port_number),
      right_motor_port(right_motor_port_number, true) {}

TransferMotorPort::TransferMotorPort(
    int left_motor_port_number, int right_motor_port_number)
    : left_motor_port(left_motor_port_number),
      right_motor_port(right_motor_port_number, true) {}
}  // namespace robotport