#include "RobotPort.h"

namespace RobotPort {
Port::Port(int port_number, bool reverse = false)
    : _port_number(port_number), _reverse(reverse) {}

DrivetrainMotorPort::DrivetrainMotorPort(
    int bottom_motor_port_number, int top_motor_port_number)
    : _bottom_motor_port(bottom_motor_port_number),
      _top_motor_port(top_motor_port_number, true) {}

ShooterMotorPort::ShooterMotorPort(
    int left_motor_port_number, int right_motor_port_number)
    : _left_motor_port(left_motor_port_number),
      _right_motor_port(right_motor_port_number, true) {}

TransferMotorPort::TransferMotorPort(
    int left_motor_port_number, int right_motor_port_number)
    : _left_motor_port(left_motor_port_number),
      _right_motor_port(right_motor_port_number, true) {}
}  // namespace RobotPort