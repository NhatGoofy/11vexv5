#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT1, ratio6_1, true);
motor leftMotorB = motor(PORT2, ratio6_1, true);
motor leftMotorC = motor(PORT3,ratio6_1,true);

motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);  // banh ben trai


motor rightMotorA = motor(PORT4, ratio6_1, false);
motor rightMotorB = motor(PORT5, ratio6_1, false);
motor rightMotorC = motor(PORT6, ratio6_1, false);


motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB,rightMotorC); // banh ben phai

motor thangP = motor(PORT8,ratio6_1,true);
motor thangT = motor(PORT9,ratio6_1,false);
motor_group thang = motor_group(thangP, thangT);

rotation fwdtrack= rotation(PORT11,false);       // tracking toa do

motor toggle1 = motor(PORT10, ratio18_1, false);

drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller(primary);
inertial Inertial11 = inertial(PORT12);
rotation rotation15 = rotation(PORT14);
digital_out intake1 = digital_out(Brain.ThreeWirePort.C);
digital_out khop = digital_out(Brain.ThreeWirePort.A);
digital_out tay = digital_out(Brain.ThreeWirePort.B);
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