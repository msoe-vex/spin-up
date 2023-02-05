#pragma once
#include <memory>

#include "interface/controller.h"
#include "pros.h"

namespace hardware {
pros::controller_analog_e_t GetProsJoystick(
    interface::ControllerJoystick joystick);

class ProsController : public interface::Controller {
 public:
  ProsController(pros::controller_id_e_t id) : controller_(id) {}

  int GetAnalog(interface::ControllerJoystick) const override;
  float GetVoltage(interface::ControllerJoystick) const override;

  static std::unique_ptr<interface::Controller> GetMasterController();

 private:
  // inline pros::Controller& controller() { return controller_; }
  // mutable to enable usage from const methods
  mutable pros::Controller controller_;
};

}  // namespace hardware