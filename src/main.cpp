#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
TANK_ONE_FORWARD_ROTATION,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(leftMotorA, leftMotorB,leftMotorC),

//Right Motors:
motor_group(rightMotorA, rightMotorB,rightMotorC),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT12,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
0,     0,

//LB:      //RB: 
0,     0,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT11,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-1,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
0,

//Sideways tracker diameter (reverse to make the direction switch):
0,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
0

);

int current_auton_selection = 0;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
    
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Inertial11.calibrate();
    while (Inertial11.isCalibrating()) {
    wait(100, msec);} 
    
  chassis.set_coordinates(-62,0,270); // code tọa độ
  rotation15.setPosition(90, degrees);  // đặt góc đo góc quay
  Drivetrain.setDriveVelocity(200, percent);
  toggle1.setVelocity(200, percent);
  thang.setVelocity(90,percent);
  thang.stop(hold);


  while(!auto_started){

  while(1){
    double goc = rotation15.position(deg);
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(1,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(1,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(1,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(1,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(1,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    Brain.Screen.printAt(1,120,"Goc Rotation: %.2f deg", goc);
  }
    task::sleep(200);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      point50();
      break;
    case 1:         

      break;
    case 2:
   
      break;
    case 3:

      break;
    case 4:

      break;
    case 5:

      break;
    case 6:

      break;
    case 7:

      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  int buttonCount = 0;
  Drivetrain.setDriveVelocity(150, percent);

  bool buttonPressed = false;
  // User control code here, inside the loop
  while (1) {
    
    if (Controller1.ButtonLeft.pressing()){
      point50();
    }
    if (Controller1.ButtonX.pressing()){
      if(!buttonPressed) {
        buttonCount++;
        buttonPressed = true;
        if (buttonCount == 1){
          intake1.set(true);
        }
        else if (buttonCount == 2){
          intake1.set(false);
          buttonCount = 0;
        }
      }
    }
    else {
      buttonPressed = false;
    }
    if (Controller1.ButtonUp.pressing()) {
      khop.set(true);
    }
    if(Controller1.ButtonDown.pressing()){
      khop.set(false);
    }
    if (Controller1.ButtonL2.pressing()) {
      tay.set(false);
    }
    if(Controller1.ButtonB.pressing()){
      tay.set(true);
    }
    if(Controller1.ButtonL1.pressing()){
      toggle1.spin(reverse);
    }
    else if(Controller1.ButtonA.pressing()){
      toggle1.spin(forward);
    }
    else {
      toggle1.stop(hold);
    }
    if(Controller1.ButtonR1.pressing()){
      thang.spin(fwd);
    }
    else if(Controller1.ButtonR2.pressing()){
      thang.spin(reverse);
    }
    else  {
      thang.stop();
    }
    
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................   

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
    chassis.control_arcade();

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
