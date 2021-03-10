#include "main.h"
#include "devices.h"

void pre_Auton() {
  // relase front hood section
  outakeControl(-200);
  pros::delay(400);
  outakeStop();
  // release base hood section
  intakeControl(-50);
  pros::delay(400);
  intakeStop();
}
