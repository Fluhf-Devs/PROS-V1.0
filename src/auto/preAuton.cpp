#include "main.h"
#include "devices.h"

void pre_Auton() {
  // release hood
  intakeControl(-50);
  pros::delay(400);
  intakeStop();
}
