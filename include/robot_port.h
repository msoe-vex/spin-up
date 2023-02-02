#pragma once

/**
 * Defines the ports sensors and motors are hooked up to on the robot.
 */
namespace robotport {
struct Port {
  int port_number;
  bool reverse;
  Port(int port_number, bool reverse = false);
};

struct DrivetrainMotorPort {
  Port bottom_motor_port;
  Port top_motor_port;
  // handles reversing
  DrivetrainMotorPort(int bottom_motor_port_number, int top_motor_port_number);
};

// clockwise around the robot
DrivetrainMotorPort kDrivertrainFrontRightPort{1, 2};
DrivetrainMotorPort kDrivetrainBackRight{3, 4};
DrivetrainMotorPort kDrivetrainBackLeft{5, 6};
DrivetrainMotorPort kDrivetrainFrontLeftPort{7, 8};

struct ShooterMotorPort {
  Port left_motor_port;
  Port right_motor_port;
  ShooterMotorPort(int left_motor_port_number, int right_motor_port_number);
};
ShooterMotorPort kShooterPort{9, 10};

struct TransferMotorPort {
  Port left_motor_port;
  Port right_motor_port;
  TransferMotorPort(int left_motor_port_number, int right_motor_port_number);
};
TransferMotorPort kTransferPort{11, 12};
}  // namespace robotport