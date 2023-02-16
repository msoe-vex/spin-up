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

  [[nodiscard]] static std::unique_ptr<ProsController> MakeDriverController();
  [[nodiscard]] static std::unique_ptr<ProsController> MakeOperatorController();

  [[nodicard]] int analog(interface::ControllerJoystick) const override;
  [[nodiscard]] float voltage(interface::ControllerJoystick) const override;

 private:
  [[nodiscard]] inline pros::Controller& controller() { return controller_; }
  [[nodiscard]] inline pros::Controller& controller() const {
    return controller_;
  }
  // mutable to enable usage from const methods
  mutable pros::Controller controller_;
};
}  // namespace hardware