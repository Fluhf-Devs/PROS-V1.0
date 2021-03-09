#include "main.h"
#include "devices.h"

void DrivetrainLateral(const std::int32_t velocity) {
  leftMotorA.move_velocity(velocity);
  leftMotorB.move_velocity(velocity);
  rightMotorA.move_velocity(velocity);
  rightMotorB.move_velocity(velocity);
}

void DrivetrainTurn(const std::int32_t velocity) {
  leftMotorA.move_velocity(-velocity);
  leftMotorB.move_velocity(-velocity);
  rightMotorA.move_velocity(velocity);
  rightMotorB.move_velocity(velocity);
}

void DrivetrainStop() {
  leftMotorA.move_velocity(0);
  leftMotorB.move_velocity(0);
  rightMotorA.move_velocity(0);
  rightMotorB.move_velocity(0);
}
