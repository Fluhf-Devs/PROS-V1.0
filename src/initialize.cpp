#include "main.h"
#include "devices.h"
#include "selection.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	// display stuff
	selector::init();
	// run all necessary tasks
	pros::Task controllerDrive(controllerDriveControl);
	pros::Task PID(drivePID);
	pros::Task brainDisplay(brainScreen);
	pros::Task controllerDisplay(controllerScreen);
	pros::Task customTime(customTimerWorker);
	// set motor brake types
	leftMotorA.set_brake_mode(MOTOR_BRAKE_COAST);
	leftMotorB.set_brake_mode(MOTOR_BRAKE_COAST);
	rightMotorA.set_brake_mode(MOTOR_BRAKE_COAST);
	rightMotorB.set_brake_mode(MOTOR_BRAKE_COAST);
	leftUpwards.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightUpwards.set_brake_mode(MOTOR_BRAKE_BRAKE);
	leftArmMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightArmMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
}
