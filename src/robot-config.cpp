#include "main.h"
#include "devices.h"

void initialize() {
	// initialize Controller
	pros::Controller master (CONTROLLER_MASTER);
	pros::Controller partner (CONTROLLER_PARTNER);

	// initialize drivetrain motors
	pros::Motor leftMotorA_initializer (21, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	pros::Motor leftMotorB (9, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	pros::Motor rightMotorA (1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	pros::Motor rightMotorB (8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	// intake motors
	pros::Motor leftArmMotor (2, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
	pros::Motor rightArmMotor (20, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	// outake motors
	pros::Motor leftUpwards (4, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
	pros::Motor rightUpwards (5, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
	// initialize sensors
  pros::ADIAnalogIn leftBumper ('A');
  pros::ADIAnalogIn rightBumper ('B');
  pros::ADIAnalogIn limitSwitchC ('C');
  pros::ADIAccelerometer accel2G ('D');
}
