#include "main.h"
#include "devices.h"

int OPcontrol() {
  while (true) {
    if (master.get_digital(DIGITAL_R1)) {
      intakeControl(200);
    } else if (master.get_digital(DIGITAL_R2)) {
      intakeControl(-200);
    } else {
      intakeControl(0);
    }

    if (master.get_digital(DIGITAL_L1)) {
      outakeControl(600);
    } else if (master.get_digital(DIGITAL_L2)) {
      outakeControl(-400);
    } else {
      outakeControl(0);
    }
  }
  return 0;
}
