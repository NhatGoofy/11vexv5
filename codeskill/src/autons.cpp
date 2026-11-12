#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
   // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(7.8, 1.1, 0, 2.5, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 1500);
  chassis.set_turn_exit_conditions(1, 300, 1000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 12;
  chassis.drive_max_voltage = 10;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}
void testdrive(){
  odom_constants();
  chassis.set_coordinates(-0,0, 270);
  chassis.drive_to_point(34,-12);
  chassis.turn_to_point(34,-12,90);
}
void testdicode(){                    //code da fix thanh cong
  chassis.drive_to_point(5,-54.5);
  chassis.turn_to_point(0, -25,180);
  for (int i = 0; i < 2; i++) {
    chassis.drive_to_point(5, -65);
    chassis.drive_to_point(5, -60);
  }
  chassis.drive_to_point(5,-54);

}
void codedi(){                      //code chay co ban
  chassis.drive_distance(11);
  chassis.turn_to_angle(90,10);
  chassis.drive_distance(12);
  wait(1000, msec);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(45,10);
  chassis.drive_distance(17);
  chassis.turn_to_angle(135,10);
  chassis.drive_distance(30);
  chassis.turn_to_angle(90,10);
  for (int i = 0; i < 3; i++) {
    chassis.drive_distance(6);
    chassis.drive_distance(-6);
  }
}
void kep() {
  motorhut.spinFor(reverse,360,deg);
  wait(0.1,sec);
}
void nha() {
  motorhut.spinFor(forward,360,deg);
  wait(0.1, sec);
}
void drivepoint(){ 
  odom_constants();                 // code dat pin
  for (int i = 0; i < 2; i++) {
    chassis.drive_to_point(60,0);
    wait(0.1,sec);
    chassis.drive_to_point(65,0);
    wait(0.1,sec);  
  }
  chassis.drive_to_point(50.5,19);
  wait(0.1,sec);
  motorup.spinToPosition(0,deg); 
  wait(0.1,sec);
  chassis.drive_to_point(64,8);
  wait(0.1, sec); 
  chassis.drive_to_point(57,38);
  wait(0.1, sec);
  motorup.spinToPosition(340,deg,false);
  wait(0.1,sec);
  chassis.drive_to_point(51.5,58);
  wait(0.1, sec);
  chassis.turn_to_point(-62, 58);
  //wait(0.1,sec);
 // chassis.turn_to_point(-24,61);
//wait(0.1, sec);
  //chassis.drive_to_point(-24,-58);
 // wait(0.1, sec);
 //pin2
  motorhut.spin(reverse);
  chassis.drive_max_voltage = 8; //tốc độ giảm
  chassis.drive_to_point(61.5,62.5);
  wait(0.1, sec);             //nâng thang máy
   chassis.drive_max_voltage = 9.5;
  chassis.drive_to_point(51.428, 58.074);
   chassis.drive_max_voltage = 9;
  wait(0.1, sec);
  motornang.spinFor(reverse,800,deg,false); 
  wait(0.1, sec);
  chassis.turn_to_point(48.731, 80.518);
  motorhut.stop(hold);
  chassis.drive_to_point(48.731, 26.518);
  motornang.spinFor(forward,800,deg,false);        //code ha thang may
  //lenh lap lai
  wait(0.8, sec);
  chassis.drive_to_point(51.428, 58.074);
  wait(0.1, sec);
  chassis.turn_to_point(-62,58);
  motorhut.spin(reverse);
  chassis.drive_max_voltage = 8;
  chassis.drive_to_point(62,62.5);
   chassis.drive_max_voltage = 9.5;
  //pin3
  wait(0.3, sec);            
  chassis.drive_to_point(51.428, 58.074);
   chassis.drive_max_voltage = 9;
  wait(0.1, sec);
  motornang.spinFor(reverse,1100,deg,false);  //nâng thang máy
  wait(0.1, sec);
  chassis.turn_to_point(48.731, 80.518);
  wait(0.1, sec);
  motorhut.stop(hold);
  chassis.drive_to_point(48.731, 26.518);
  wait(0.1, sec);
  motornang.spinFor(forward,1100,deg,false);        //code ha thang may
  wait(0.8, sec);
double s= 0.3;
int i = 1500;
for (int lan = 0; lan < 2; lan++) {
   wait(s, sec);
  chassis.drive_to_point(51.428, 58.074);
  wait(0.1, sec);
  chassis.turn_to_point(-62,58);
  wait(0.1, sec);
  motorhut.spin(reverse);
  chassis.drive_to_point(62.5,62.5);
  wait(0.3, sec);            
  chassis.drive_to_point(51.428, 58.074);
   //motornang.spinFor(reverse,3600,deg,false);  //nâng thang máy
   motornang.spinFor(reverse,i,deg,false);
   wait(0.1, sec);
  chassis.turn_to_point(48.731, 80.518);
  motorhut.stop(hold);
  chassis.drive_to_point(48.731, 26.518);
   //motornang.spinFor(forward,3600,deg,false);        //code ha thang may
    motornang.spinFor(forward,i, deg,false);
    i += 300;
    s+=0.3;
}


}

bool Rotationcheck = false;

int my_event(){ 
 while (true) {
    if (Rotationcheck){
        double angle = rotation15.position(degrees);

        if (angle < 89) {
           motorup.spinFor(reverse, 12,deg,false);
        }
        else if (angle > 91) {
            motorup.spinFor(forward, 12,deg,false);
        }
        else {
           motorup.setMaxTorque(100, percent);
            motorup.stop(hold);
        }
      }
        wait(0.1, sec);
    }

    return 0;
}


void test(){

task rotationcheck(my_event);
Rotationcheck = true;
wait(1.5 ,sec);
Rotationcheck = false;
motorup.stop(hold);

}
void hienThiCamBien() {
    while (true) {
        Brain.Screen.clearScreen();

        double goc = rotation15.position(deg);

        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Goc Rotation: %.2f deg", goc);

        wait(50, msec);
    }
}
void point50(){  //chassic.set_coordiate(-59.4,63.2);
 
 chassis.drive_to_point(-50,27.8);
  wait(0.1,sec);
  motorup.spinToPosition(150,deg); 
  wait(0.3, sec);
  chassis.drive_to_point(-49.4, 57);  
  wait(0.1, sec);
  motorup.spinToPosition(283,deg,false);
  wait(0.1, sec);
  chassis.turn_to_point(62.21,57.6);
  wait(0.1, sec);

  motorhut.spin(reverse);
  wait(0.1, sec);
  chassis.drive_to_point(-62.9,54.5);    // chuẩn cmn r :>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  wait(0.5, sec);
  motornang.spinFor(reverse,800,deg,false);   // nâng 
  wait(0.1, sec);
  chassis.drive_to_point(-47.8,57.8);
  wait(0.1, sec);
  chassis.turn_to_point(-47.8, 67);
  motorhut.stop(hold);
  wait(0.1, sec);
  chassis.drive_to_point(-47.4,30); //lặp lại lần 2
  wait(0.1, sec);
  motornang.spinFor(forward,1000,deg,false);   // đặt cốc lần 2
  wait(1, sec);
  chassis.drive_to_point(-47.8,55.8);
  wait(0.1, sec);
  chassis.turn_to_point(63,60);
  wait(0.1, sec);

  motorhut.spin(reverse);
  wait(0.1, sec);
  chassis.drive_to_point(-62.5,55.5);   
  wait(0.3, sec);
  motornang.spinFor(reverse, 1300,deg,false);
  wait(0.1, sec);
  chassis.drive_to_point(-56,57);
  wait(0.1, sec);

  motorhut.stop(hold); 
  wait(0.1, sec);
  chassis.turn_to_point(-47.8, 67);
  wait(0.1, sec);
  chassis.drive_to_point(-47.4, 30); //lặp lại lần 3
  wait(0.15, sec);
  motornang.spinFor(forward,1300,deg,false);   // đặt cốc lần 3
  wait(1, sec);
  int gocnang = 300;
  for(int a=0 ;a<2;a ++){
    chassis.drive_to_point(-47.8,57.8);
    wait(0.1, sec);
    chassis.turn_to_point(47.8,57.8);
    wait(0.1, sec);
    motorhut.spin(reverse);
    wait(0.1, sec);
    chassis.drive_to_point(-62.5,54.5); // code lặp lại
   wait(0.3, sec);
    motornang.spinFor(reverse, 1200 +gocnang,deg,false);
    wait(0.1, sec);
    chassis.drive_to_point(-56,54.5);   
    wait(0.1, sec);
  chassis.turn_to_point(-47.8, 67);
  motorhut.stop(hold);
  wait(0.1, sec); 
  chassis.drive_to_point(-47.4,28);
   wait(0.15, sec);
   motornang.spinFor(forward,1200+ gocnang,deg,false);   
   wait(1, sec);
  gocnang=+400;
  }
  chassis.drive_to_point(-47.8,57.8);
    wait(0.1, sec);
    chassis.turn_to_point(47.8,57.8);
    wait(0.1, sec);
    motorhut.spin(reverse);
    wait(0.1, sec);
    chassis.drive_to_point(-62.5,54.5); // code lặp lại
   wait(0.3, sec);
    motornang.spinFor(reverse, 1500,deg,false);
    wait(0.1, sec);
    chassis.drive_to_point(-53.489, 54.5);
    wait(0.1,sec);
    chassis.turn_to_point(-61, 66.5);
    wait(0.1, sec);
    chassis.drive_to_point(-4.402, 3.323);
    wait(0.1, sec);
    motornang.spinFor(forward, 1500,deg,false);
    // thực hiện code nâng xuống
    wait(1, sec);
}
  
void point_70(){
  chassis.drive_to_point(-49.5,27);
  wait(0.1,sec);
  motorup.spinToPosition(150,deg);
  wait(0.1, sec);
  motorhut.spin(forward);
  wait(0.3, sec);
  chassis.drive_to_point(-49.4, 57);  
  motorhut.stop();
  wait(0.1, sec);
  motorup.spinToPosition(283,deg,false);
  wait(0.1, sec);
  chassis.turn_to_point(62.21,57);
  wait(0.1, sec);

  motorhut.spin(reverse);
  wait(0.1, sec);
  chassis.drive_to_point(-62,56.5);    // chuẩn cmn r :>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  wait(0.5, sec);
  motornang.spinFor(reverse,950,deg,false);   // nâng 
  wait(0.1, sec);
    chassis.drive_to_point(-53.489, 55.5,2,6,6);
    wait(0.1,sec);
    chassis.turn_to_point(-61, 66.5);
    chassis.drive_max_voltage=8;
    wait(0.1, sec);
    chassis.drive_timeout=3000;    //set timeout
    wait(0.1, sec);
    chassis.drive_to_point(-1, 2);
    wait(0.1, sec);
    motornang.spinFor(forward, 450,deg,false);  // nâng xog pin 1
    
    wait(0.5, sec);
    motorhut.spinToPosition(300,deg,false);
    wait(0.3, sec);
    chassis.drive_to_point(-50, 57.5);
    wait(0.1, sec);
    chassis.turn_to_point(-41, 57.5);
    wait(0.1, sec);
     motornang.spinFor(forward, 500,deg,false);  
    wait(0.1, sec);

    motorhut.spin(reverse);
    wait(0.1, sec);
    chassis.drive_to_point(-60.8,57,2,6,6);   
    wait(0.5, sec);
    motornang.spinFor(reverse, 1250, deg,false);  // nâng cốc 2
    wait(0.1, sec);
    chassis.drive_to_point(-54, 54.5,2,6,6);
    wait(0.1, sec);
    chassis.turn_to_point(-56, 64);
    wait(0.1, sec);
     chassis.drive_max_voltage=8;    // đổi tốc độ 
     wait(0.1, sec);
    motorhut.stop();
    chassis.drive_to_point(-1, 2);
    motornang.spinFor(forward, 750, deg,false);  
    wait(0.8, sec);
    motorhut.spinToPosition(300,deg,false);
    wait(0.1, sec);
     chassis.drive_to_point(-50, 57);
    wait(0.1, sec);
    chassis.turn_to_point(-41, 57);
     chassis.drive_max_voltage=8;    // đổi tốc độ 
     motornang.spinFor(forward, 500,deg,false);  
    wait(0.1, sec);

    motorhut.spin(reverse);
    motorup.spinToPosition(280, deg);
    wait(0.5, sec);
    chassis.drive_to_point(-61,57,2,6,6);   
    wait(0.1, sec);
     
    motornang.spinFor(reverse, 1700, deg,false);  // nâng cốc 3
    wait(0.1, sec);
    chassis.drive_to_point(-54, 54.5,2,6,6);
    wait(0.1, sec);
    chassis.turn_to_point(-56, 64);
    wait(0.1, sec);
     chassis.drive_max_voltage=8;    // đổi tốc độ 
    motorhut.stop();
    chassis.drive_to_point(-1, 1.5);
    wait(0.5, sec);
    motornang.spinFor(forward, 1200, deg,false);  
    wait(1, sec);
    motorhut.spinToPosition(300,deg,false);
    wait(0.1, sec);
     chassis.drive_to_point(-52, 58);
    wait(0.1, sec);

    chassis.turn_to_point(-41, 58);
    chassis.drive_max_voltage=8;    // đổi tốc độ 
     motornang.spinFor(forward, 500,deg,false);  
    wait(0.1, sec);

    motorhut.spin(reverse);
    wait(0.1, sec);
    chassis.drive_to_point(-60.25,57,2,6,6,1.5, 300, 1000);  
    wait(0.1, sec);
     
    motornang.spinFor(reverse, 2000, deg,false);  // nâng cốc 4
    wait(0.1, sec);
    chassis.drive_to_point(-54, 55,2,6,6);
    wait(0.1, sec);
    chassis.turn_to_point(-56, 64);
    wait(0.1, sec);
     chassis.drive_max_voltage=8;    // đổi tốc độ 
    motorhut.stop();
    chassis.drive_to_point(0, 1.5);
    wait(0.5, sec);
    motornang.spinFor(forward, 1500, deg,false);  
    wait(1.3, sec);
    motorhut.spinToPosition(300,deg,false);
    wait(0.1, sec);
     chassis.drive_to_point(-52, 57.5);
    wait(0.1, sec);
    chassis.turn_to_point(-41, 57.5);
    chassis.drive_max_voltage=8;    // đổi tốc độ 
     motornang.spinFor(forward, 500,deg,false);  
    wait(0.1, sec);
    
     motorhut.spin(reverse);
  wait(0.1, sec);
  chassis.drive_to_point(-62,57);    // chuẩn cmn r :>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  chassis.drive_timeout= 1000;
  wait(0.3, sec);
  motornang.spinFor(reverse,1000,deg,false);   // nâng 
  wait(0.1, sec);
  chassis.drive_to_point(-47.8,57.8);
  wait(0.1, sec);
  chassis.turn_to_point(-47.8, 67);
  motorhut.stop(hold);
  wait(0.1, sec);
  chassis.drive_to_point(-47.4,30,4,8,6); //lặp lại lần 1
  wait(0.1, sec);
  motornang.spinFor(forward,1000,deg,false);   // đặt cốc lần 1
  wait(0.8, sec);
  chassis.drive_to_point(-47.8,57.8);
  wait(0.1, sec);
  chassis.turn_to_point(63,60);
  wait(0.1, sec);

  motorhut.spin(reverse);
  wait(0.1, sec);
  chassis.drive_to_point(-62,57.5);   
  wait(0.3, sec);
  motornang.spinFor(reverse, 1300,deg,false);
  wait(0.1, sec);
  chassis.drive_to_point(-56,57);
  wait(0.1, sec);

  motorhut.stop(hold); 
  wait(0.1, sec);
  chassis.turn_to_point(-47.8, 67);
  wait(0.1, sec);
  chassis.drive_to_point(-47.4, 30); //lặp lại lần 2
  wait(0.15, sec);
  motornang.spinFor(forward,1300,deg,false);   // đặt cốc lần 2
  wait(1, sec);
  chassis.drive_to_point(20,10); /// chayj dden pin do


    
}
void testcasecade(){
  
    while (true) {
        Brain.Screen.clearScreen();

        double casecade = motornang.position(deg);

        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Goc Rotation: %.2f deg", casecade);

        wait(50, msec);
    }
}