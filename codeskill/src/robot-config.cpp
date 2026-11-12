#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT1, ratio6_1, true);
motor leftMotorB = motor(PORT2, ratio6_1, true);

motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);  // banh ben trai


motor rightMotorA = motor(PORT3, ratio6_1, false);
motor rightMotorB = motor(PORT4, ratio6_1, false);

motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB); // banh ben phai


rotation fwdtrack= rotation(PORT12,true);       // tracking toa do


motor motornangT = motor(PORT5,false);
motor motornangP = motor(PORT6,true);
motor motornangT1=motor(PORT13,false);
motor motornangP1=motor(PORT7,true);
motor_group motornang = motor_group(motornangP,motornangT,motornangT1,motornangP1); // motor len xuong

motor motorhut = motor(PORT9,false);
motor motorup = motor(PORT8,false);
bool RemoteControlcodeEnabled = true;


drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);
inertial Inertial11 = inertial(PORT11);
rotation rotation15 = rotation(PORT14);

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