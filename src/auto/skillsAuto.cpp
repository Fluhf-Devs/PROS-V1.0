#include "main.h"
#include "devices.h"

void skillsAdvancedAuto() {
  customTimer = 60;

  // autonomous
  leftArmMotor.move_velocity(200);
  rightArmMotor.move_velocity(200);
  setPID(false, 800);

  pros::delay(1000);

  intakeStop();
  setPID(true, -250);

  pros::delay(500);

  outakeControl(600);
  pros::delay(200);
  outakeStop();
  setPID(false, 1300);

  pros::delay(1500);

  setPID(true, -800);

  pros::delay(750);

  setPID(false, 500, 0.02);

  pros::delay(500);

  setPID(false, 0, 0.09);
  outakeControl(600);
  pros::delay(500);
  outakeStop();

  pros::delay(100);

  setPID(false, -250);

  pros::delay(500);

  setPID(true, 750);

  pros::delay(500);

  intakeControl(200);
  setPID(false, 1900);

  pros::delay(1500);

  intakeStop();
  setPID(true, -625);

  pros::delay(500);

  setPID(false, 600, 0.02);
  pros::delay(400);
  outakeControl(600);
  pros::delay(700);
  outakeStop();

  pros::delay(900);

  setPID(false, -600, 0.09);

  pros::delay(1000);

  setPID(true, 1300);

  pros::delay(750);

  intakeControl(200);
  setPID(false, 1750);

  pros::delay(2000);

  intakeStop();
  setPID(true, -950);

  pros::delay(750);

  setPID(false, 600, 0.02);

  pros::delay(750);

  setPID(false, 0, 0.09);
  outakeControl(600);
  pros::delay(600);;
  outakeStop();

  pros::delay(1000);



/////////////////////////////////////////////////////////////////////////////
// experimental 5th goal, not tested
///////////////////////////////////////////////






  setPID(false, -800);

  pros::delay(750);

  setPID(true, 900);

  pros::delay(750);

  intakeControl(200);
  setPID(false, 1900);

  pros::delay(2000);

  intakeStop();
  setPID(false, 0);

  pros::delay(500);

  setPID(true, -700);

  pros::delay(750);

  setPID(false, 1500);

  pros::delay(1500);

  setPID(false, 0);
  outakeControl(600);

  pros::delay(2000);

  outakeStop();
}
