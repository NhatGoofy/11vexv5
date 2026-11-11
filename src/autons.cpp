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
  chassis.set_drive_constants(5, 0.5, 0, 1.8, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 1000);
  chassis.set_turn_exit_conditions(1, 300, 1200);
  chassis.set_swing_exit_conditions(1, 300, 3000);
  
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 6;
  chassis.drive_max_voltage = 5;
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

void point_70(){

    // Bánh trái chạy nhanh
    LeftDriveSmart.spin(reverse, 7.2, volt);

    // Bánh phải chạy chậm
    RightDriveSmart.spin(reverse, 2, volt);

    // Duy trì chuyển động trong 1.2 giây
    wait(1000, msec);

    // Dừng robot
    LeftDriveSmart.stop();
    RightDriveSmart.stop();  
    
}

void point_80(){

    // Bánh trái chạy nhanh
    RightDriveSmart.spin(reverse, 7.2, volt);

    // Bánh phải chạy chậm
    LeftDriveSmart.spin(reverse, 2, volt);

    // Duy trì chuyển động trong 1.2 giây
    wait(400, msec);

    // Dừng robot
    LeftDriveSmart.stop();
    RightDriveSmart.stop();  
    
}
void point_90(){
    // Bánh trái chạy nhanh
    RightDriveSmart.spin(fwd, 8, volt);

    // Bánh phải chạy chậm
    LeftDriveSmart.spin(fwd, 1, volt);

    // Duy trì chuyển động trong 1.2 giây
    wait(1000, msec);

    // Dừng robot
    LeftDriveSmart.stop();
    RightDriveSmart.stop();  
}
void point_100(){
    // Bánh trái chạy nhanh
    LeftDriveSmart.spin(fwd, 8, volt);

    // Bánh phải chạy chậm
    RightDriveSmart.spin(fwd, 1, volt);

    // Duy trì chuyển động trong 1.2 giây
    wait(1000, msec);

    // Dừng robot
    LeftDriveSmart.stop();
    RightDriveSmart.stop();  
}
void taymo(){
  tay.set(true);
}
void taydong(){
  tay.set(false);
}
void taymo1(){
  wait(0.05, sec);
 tay.set(true); 
}
void intakemo(){
  intake1.set(true);
}
void intakedong(){
  intake1.set(false);
}
void intakedong1(){
  wait(0.3, sec);
  intake1.set(false);
}
void hut(){
  toggle1.spin(reverse);
}

void dat_pin(){
  tay.set(true);
  thang.spinFor (fwd,60,deg);
  khop.set(false);
  thang.spinFor (reverse,60,deg);

}
void nang(){
  thang.spinFor(fwd, 1000, deg);
}
void point50(){
  odom_constants(); 
  toggle1.spinFor(forward,700,deg);
  wait(0.2, sec);
  thang.spinFor(fwd, 1600,deg,false);
  wait(0.1, sec);
  chassis.drive_to_point(-47, 0);
  chassis.turn_to_angle(0);
  chassis.drive_to_point(-47, 19);
  wait(0.3, sec);
  
  thang.spinFor(reverse, 1300,deg);
  wait(0.1,sec);
  taymo();

  wait(0.2, sec);
  thang.spinFor(reverse, 300,deg,false);  // đặt pin 1 
  wait(0.2, sec);
  chassis.drive_to_point(-47, -6);
  wait(0.2, sec);
}
void dedo(){
  chassis.turn_to_point(-67, 7);
  chassis.drive_to_point(-26, -22.4);
  taydong();
  wait(0.3, sec);
  thang.spinFor(forward,2500,deg,false);
  chassis.turn_to_point(-11, -18);
  wait(0.1, sec);
  chassis.drive_to_point(-41.5, -23);
  wait(0.1, sec);
  thang.spinFor(reverse,2000,deg);
  taymo();
  thang.spinFor(reverse, 500, deg,false);
  wait(0.15, sec);
}





            

