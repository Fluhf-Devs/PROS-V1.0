#include "main.h"
#include "devices.h"

void intakeControl(const std::int32_t velocity) {
  rightArmMotor.move_velocity(velocity);
  leftArmMotor.move_velocity(velocity);
}

void intakeStop() {
  rightArmMotor.move_velocity(0);
  leftArmMotor.move_velocity(0);
}
