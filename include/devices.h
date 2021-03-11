#include "main.h"

// Vex devices
extern pros::Controller master;
extern pros::Controller partner;
extern pros::Motor leftMotorA;
extern pros::Motor leftMotorB;
extern pros::Motor rightMotorA;
extern pros::Motor rightMotorB;
extern pros::Motor leftArmMotor;
extern pros::Motor rightArmMotor;
extern pros::Motor leftUpwards;
extern pros::Motor rightUpwards;
extern pros::ADIAnalogIn leftBumper;
extern pros::ADIAnalogIn rightBumper;
extern pros::ADIAnalogIn limitSwitchC;
extern pros::ADIAccelerometer accel2G;

// outakeControl functions
void outakeControl(const std::int32_t velocity);
void outakeStop();

// intakeControl functions
void intakeControl(const std::int32_t velocity);
void intakeStop();

// drivetrainControl
void DrivetrainLateral(const std::int32_t velocity);
void DrivetrainTurn(const std::int32_t velocity);
void DrivetrainStop();

// PID
int drivePID();
void setPID(bool isTurning, double val1, double val2);
void setPID(bool isTurning, double val1);

// Autonomous functions
void skillsAdvancedAuto();
void pre_Auton();

// tasks to be run
int controllerDriveControl();
int OPcontrol();
int brainScreen();
int controllerScreen();
int customTimerWorker();

// PID variables
extern double kP;
extern double turnKP;
extern int desiredValue;
extern int desiredTurnValue;
extern bool startSlew;
extern bool turning;
extern bool resetDriveSensors;
extern bool enableDrivePID;
extern double slewPercent;
extern double slewTurnPercent;

// Display variables
extern int customTimer;
extern int customTimerStart;
extern double drivetrainTemp;
extern double batteryCapacity;
extern double customTimerArc;


// autonomous selector variables
extern int compAutoSelector;

// Display non-return funtions
void controllerShake();
void gui(void);

// more display stuff

#pragma once

#include <string>

//selector configuration
#define HUE 360
#define DEFAULT 1
#define AUTONS "Front", "Back", "Do Nothing"

namespace selector{

extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}
