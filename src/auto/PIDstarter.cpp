#include "main.h"
#include "devices.h"

void setPID(bool isTurning, double val1, double val2) {
  resetDriveSensors = true;
  startSlew = true;
  slewPercent = 0;
  slewTurnPercent = 0;

  if (isTurning) {
    turning = true;
    turnKP = val2;
    desiredValue = 0;
    desiredTurnValue = val1;
  } else if (isTurning == false) {
      turning = false;
      kP = val2;
      desiredTurnValue = 0;
      desiredValue = val1;
    }
}

void setPID(bool isTurning, double val1) {
  resetDriveSensors = true;
  startSlew = true;
  slewPercent = 0;
  slewTurnPercent = 0;

  if (isTurning) {
    turning = true;
    desiredValue = 0;
    desiredTurnValue = val1;
  } else if (isTurning == false) {
      turning = false;
      desiredTurnValue = 0;
      desiredValue = val1;
    }
}
