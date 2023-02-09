#pragma once
#include <memory>

#include "interface/controller.h"
#include "pros.h"

namespace hardware {
pros::controller_analog_e_t ConvertProsJoystick(
    interface::ControllerJoystick joystick);

class ProsController : public interface::Controller {
 public:
  ProsController(pros::controller_id_e_t id) : controller_(id) {}

  static std::unique_ptr<ProsController> MakeDriverController();
  static std::unique_ptr<ProsController> MakeOperatorController();

  int analog(interface::ControllerJoystick) const override;
  float voltage(interface::ControllerJoystick) const override;

 private:
  inline pros::Controller& controller() { return controller_; }
  inline const pros::Controller& controller() const { return controller_; }
  // mutable to enable usage from const methods
  mutable pros::Controller controller_;
};
}  // namespace hardware