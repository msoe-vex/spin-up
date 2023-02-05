#pragma once
#include "interface/controller.h"
#include "main.h"

namespace hardware {
pros::controller_analog_e_t GetProsJoystick(
    interface::ControllerJoystick joystick);

class ProsController : public interface::Controller {
 public:
  ProsController(pros::controller_id_e_t id) : controller_(id) {}

  int GetAnalog(interface::ControllerJoystick) override;
  float GetVoltage(interface::ControllerJoystick) override;

 private:
  inline pros::Controller& controller() { return controller_; }

  pros::Controller controller_;
};

}  // namespace hardware