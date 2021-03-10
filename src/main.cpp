#include "main.h"
#include "devices.h"


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */

void competition_initialize() {

}

void autonomous() {
  switch (auton_sel) {
  // red right auton
  case 1:

    break;
  // red left auton
  case 2:

    break;
  // blue right auton
  case 3:

    break;
  // blue left auton
  case 4:

    break;
  // SkillsAuton1
  case 5:
    skillsAdvancedAuto();
    break;
  // SkillsAuton2
  case 6:

    break;
  }
}
