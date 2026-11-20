#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT4, ratio6_1, true);
motor leftMotorB = motor(PORT5, ratio6_1, true);
motor leftMotorC = motor(PORT6,ratio6_1,true);

motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB,leftMotorC);  // banh ben trai


motor rightMotorA = motor(PORT1, ratio6_1, false);
motor rightMotorB = motor(PORT2, ratio6_1, false);
motor rightMotorC = motor(PORT3, ratio6_1, false);

motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB,rightMotorC); // banh ben phai


rotation fwdtrack= rotation(PORT12);       // tracking toa do


motor motornangT = motor(PORT8,false);
motor motornangP = motor(PORT9,true);
motor_group motornang = motor_group(motornangP,motornangT); // motor len xuong
digital_out gap = digital_out(Brain.ThreeWirePort.B);
motor khop = motor(PORT10,false);
motor toggle2 = motor(PORT11,true);
bool RemoteControlcodeEnabled = true;


drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);
inertial Inertial11 = inertial(PORT13);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}