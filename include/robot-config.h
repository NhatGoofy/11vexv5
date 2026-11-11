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
extern motor leftMotorB;  
extern motor leftMotorC;
extern motor_group LeftDriveSmart;     // banh xe ben trai 

extern motor rightMotorA;
extern motor rightMotorB;   
extern motor rightMotorC;
extern motor_group RightDriveSmart;      // banh xe ben phai 

extern rotation fwdtrack; 
extern motor toggle1;
extern motor intake;   // motor quay

extern digital_out intake1;
extern digital_out khop;
extern digital_out tay;
extern rotation rotation15;
extern motor thangP;
extern motor thangT;
extern motor_group thang;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );