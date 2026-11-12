using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:
// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;
extern inertial Inertial11;
extern motor leftMotorA;
extern motor leftMotorB;        // banh xe ben trai 

extern motor rightMotorA;
extern motor rightMotorB;      // banh xe ben phai

extern motor motornangT;
extern motor motornangP;  // motor nang ha
extern motor motornangT1;
extern motor motornangP1;
extern motor_group motornang;  

extern rotation fwdtrack; 

extern motor intake;   // motor quay

extern motor motorhut;
extern motor motorup;    // piston giu lai
extern rotation rotation15;



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );