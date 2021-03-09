#include "main.h"
#include "devices.h"

// initialize Controller
pros::Controller master (CONTROLLER_MASTER);
pros::Controller partner (CONTROLLER_PARTNER);

// initialize drivetrain motors
pros::Motor leftMotorA (21, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
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

// variables for remote control code
bool RemoteControlCodeEnabled = true;
bool DrivetrainLNeedsToBeStopped_Master = true;
bool DrivetrainRNeedsToBeStopped_Master = true;

// loop for controller code
int controllerDriveControl() {
	while(true) {
		// arcade control
		int power = master.get_analog(ANALOG_RIGHT_X);
		int turn = master.get_analog(ANALOG_LEFT_Y);
		int left = power + turn;
		int right = power - turn;
		leftMotorA.move(left);
		leftMotorB.move(left);
		rightMotorA.move(right);
		rightMotorB.move(right);

		pros::delay(20);
	}
	return 0;
}
