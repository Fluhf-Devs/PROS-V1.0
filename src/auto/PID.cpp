#include "main.h"
#include "devices.h"

// settings
double kP = 0.09;
double kI = 0.0;
double kD = 0.09;

double turnKP = 0.046;
double turnKI = 0.0;
double turnKD = 0.05;

int error; // sensorValues - desiredValue = Position
int prevError = 0; // Position 20 milliseconds ago
int derivative; // error - prevError = speed
int totalError = 0; // totalError = totalError + error

int turnError; // sensorValues - desiredValue = Position
int turnPrevError = 0; // Position 20 milliseconds ago
int turnDerivative; // error - prevError = speed
int turnTotalError = 0; // totalError = totalError + error

//Autonomous settings
int desiredValue = 0; // motor ticks I think, bot 200rpm about 900 ticks / rev,
int desiredTurnValue = 0; // should work same as above

// variables used in slew
bool startSlew = false;
bool turning = false;

// variables that are part of stopping the PID
bool resetDriveSensors = false;
bool enableDrivePID = true;

// variables that have to be created outside thread
double lateralMotorPower = 0.0;
double turnMotorPower = 0.0;
double slew = 0.0;
double turnSlew = 0.0;
double slewPercent = 0.0;
double slewTurnPercent = 0.0;

int drivePID() {
  while (enableDrivePID) {
    if (resetDriveSensors) {
      resetDriveSensors = false;
      leftMotorA.tare_position();
      leftMotorB.tare_position();
      rightMotorA.tare_position();
      rightMotorB.tare_position();
    }

    // get the position of the motors
    int leftMotorAPosition = leftMotorA.get_position();
    int leftMotorBPosition = leftMotorB.get_position();
    int rightMotorAPosition = rightMotorA.get_position();
    int rightMotorBPosition = rightMotorB.get_position();

    ///////////////////////////////////////////////////
    /// Lateral movement PID
    /////////////////////////////////

    // get average of the four motors
    int averagePosition = (leftMotorAPosition + leftMotorBPosition + rightMotorAPosition + rightMotorAPosition)/4;
    // potential
    error = desiredValue - averagePosition;
    // derivative
    derivative = error - prevError;
    // velocity
    totalError += error;
    // calculate motor power
    lateralMotorPower = error * kP + derivative * kD;

    /////////////////////////////////////////////////////////
    // Turning Movement PID
    //////////////////////////////////////

    // get average of the four motors
    int turnDifference = ((leftMotorAPosition + leftMotorBPosition)/2) - ((rightMotorAPosition + rightMotorBPosition)/2);

    // Potential
    turnError = desiredTurnValue - turnDifference;

    // Derivative
    turnDerivative = turnError - turnPrevError;

    // velocity
    turnTotalError += turnError;

    // calculate power for turning
    turnMotorPower = turnError * turnKP + turnDerivative * turnKD;

    /////////////////////////////////////////////////////////////////////////////////
    // slew
    ////////////////////////////////////

    if(startSlew) {
      // lateral Slew
      if (turning == false) {
          slew = (lateralMotorPower / 100) * slewPercent;
          if(slewPercent < 100) {
             slewPercent += 10;
          }
      } else if (turning) {
          turnSlew = (turnMotorPower / 100) * slewTurnPercent;
          if(slewTurnPercent < 100) {
              slewTurnPercent += 10;
          }
      }
    }

    leftMotorA.move_voltage(slew + turnSlew);
    leftMotorB.move_voltage(slew + turnSlew);
    rightMotorA.move_voltage(((slew - turnSlew)/100)*96);
    rightMotorB.move_voltage(((slew - turnSlew)/100)*96);

    // set errors
    prevError = error;
    turnPrevError = turnError;

    pros::delay(20);
  }
  return 0;
}
