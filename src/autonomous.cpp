#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 int auton = 0;

 PID * pid = new PID();
 static Vision * vision = new Vision();
 miscell * extra = new miscell();

 void skillsAuton()
 {
   //pid->move(distance, power, flywheel, indexer, intake, tipper);
   //pid->miscell(tipper, intake, indexer, time);

     extra->flyCoast();

     //gets back cap

     extra->flywheelAccel(127);

     extra->capTip();

     //get angled cap
     pid->move(40, 87, 127, 0, 0, 0);

     extra->misc(127, 0, 0, 500);

     pid->move(40, -87, 127, 0, 0, 0);

     //resets
     pid->drive(-47, 650);

     extra->stop(200);

     //moves a bit forward
     pid->move(4.7, 87, 127, 0, 0, 0);

     extra->stop(150);

     //turns towards flags
     pid->turn(-90, -90);

     //moves forawrd a bit and toggles top high flag
     pid->move(4, 67, 127, 0, 0, 0);

     extra->stop(250);

     extra->misc(0, 127, 0, 600);

     //moves forward and toggles the middle high flag
     pid->move(22, 67, 127, 0, 0, 30);

     extra->stop(150);

     extra->misc(127, 127, 0, 1000);

     //toggles low flag
     pid->move(6.5, 47, 127, 0, -90, 0);

     extra->misc(0, 0, -45, 600);

     //moves back and turns towards the front cap
     pid->move(30.5, -87, 127, 0, 0, 0);

     extra->stop(300);

     pid->turn(90, 90);

     pid->drive(-47, 500);

     pid->move(7, 67, 127, 0, 0, 10);

     extra->stop(200);

     pid->turn(-45, -90);

     //moves towards the front cap and tilts it so the balls roll into the intake
     pid->move(9, 77, 127, 0, 0, 7);

     extra->misc(100, 0, -60, 800);

     extra->misc(100, 0, -5, 200);

     //flips the cap
     pid->move(3, -87, 127, 0, 50, 0);

     extra->stop(200);

     pid->move(5, 67, 127, 0, 60, 0);

     pid->move(5, 67, 127, 0, 60, 90);

     extra->stop(150);

     //turns towards the other side of the field in order to go towards the middle flags
     pid->turn(48, 90);

     pid->move(32, 87, 127, 0, 60, 0);

     extra->stop(150);

     extra->misc(-15, -15, 0, 70);

     extra->misc(10, 15, 0, 70);

     //turns towards flags and shoots them
     pid->turn(-90, -90);

     pid->move(8, -87, 127, 0, 80, 0);

     extra->stop(200);

     //vision->visionCorrect();

     extra->misc(20, 127, 0, 820);

     pid->move(17, 87, 127, 0, 0, 20);

     extra->stop(200);

     //vision->visionCorrect();

     extra->misc(127, 127, 0, 1000);

     //toggles low flag and resets against wall
     pid->turn(-13, -90);

     pid->move(15, 87, 127, 0, -40, 0);

     pid->drive(57, 850);

     //backs up and turns on an angle towards the front starting blue tile
     pid->move(20, -87, 127, 0, -40, 0);

     extra->stop(200);

     pid->turn(-70, -90);

     pid->move(61.1, -87, 127, 0, 0, 0);

     extra->stop(150);

     //straightens, resets and flips the blue side anlged cap
     pid->turn(-28, -90);

     pid->drive(-50, 980);

     pid->setZero();

     extra->capTip();

     pid->move(44, 87, 127, 0, 0, 0);

     extra->misc(60, 0, 0, 600);

     pid->move(44, -87, 127, 0, 60, 0);

     pid->drive(-37, 100);

     extra->stop(200);

     //moves a bit foward and turns towards front cap
     pid->move(5, 87, 127, 0, 0, 0);

     extra->stop(150);

     pid->turn(45, 90);

     //move toward front cap and titls it so the balls roll into the intake
     pid->move(11.85, 77, 127, 0, 0, 0);

     extra->misc(100, 0, -60, 800);

     extra->misc(120, 0, -5, 200);

     //flips the cap
     pid->move(3, -87, 127, 0, 0, 0);

     extra->stop(200);

     pid->move(8, 67, 127, 0, 70, 0);

     pid->move(11, 67, 127, 0, 70, 97);

     extra->stop(150);

     //turns towards the last set of flags and shoots them
     pid->turn(51, 90);

     pid->move(16.7, -87, 127, 0, 60, 0);

     extra->misc(20, 127, 15, 800);

     pid->move(14, 87, 127, 0, 0, 0);

     extra->misc(127, 127, 10, 600);

     //moves forward into the low flag
     pid->move(17, 67, 127, 0, 0, 30);

     pid->turn(-17, -90);

     pid->move(9, 67, 127, 0, 0, 0);

     pid->drive(47, 800);

     //moves back and turns on an angle to align in front of the blue alliance platform
     pid->move(22, -87, 127, 0, 0, 0);

     pid->turn(-40, -90);

     pid->move(53, -87, 127, 0, 0, 0);

     //turns towards the aliance platform and resets
     pid->turn(-70, -90);

     pid->drive(47, 700);

     //gets on the center platform
     pid->move(67, 87, 127, 127, 127, 0);
 }

 void blueAuton()
 {
   extra->flyCoast();

   //gets back cap

   extra->flywheelAccel(127);

   //get angled cap
   pid->move(40, 87, 127, 0, 0, 0);

   extra->misc(127, 0, 0, 500);

   pid->move(40, -87, 127, 0, 40, 0);

   //resets
   pid->drive(-57, 500);

   //moves a bit forward
   pid->move(5.5, 87, 127, 0, 0, 0);

   extra->stop(150);

   //turns towards flags
   pid->turn(90, 90);

   //moves forawrd a bit and toggles top high flag
   pid->move(4, 87, 127, 0, 0, 0);

   extra->stop(250);

   extra->misc(0, 127, 0, 600);

   //moves forward and toggles the middle high flag
   pid->move(22, 87, 127, 0, 0, 0);

   extra->stop(150);

   extra->misc(127, 127, 0, 1000);

   //toggles low flag
   pid->move(7, 87, 90, 0, 0, 0);

   extra->misc(0, 0, -40, 650);

   //moves back and turns towards the front cap
   pid->move(31, -87, 90, 0, 0, 5);

   extra->stop(300);

   pid->turn(-90, -90);

   pid->drive(-57, 500);

   pid->move(7, 67, 90, 0, 0, 0);

   extra->stop(200);

   pid->turn(45, 90);

   pid->move(10, 67, 88, 0, 0, 0);

   extra->misc(100, 0, -62, 800);

   extra->misc(120, 0, -5, 100);

   extra->misc(127, 127, 5, 1200);

   pid->move(2, -67, 85, 0, 0, -20);

   extra->stop(100);

   pid->move(2, 87, 85, 0, 50, 0);

   pid->move(7, 87, 85, 0, 40, 100);

/*   extra->stop(150);

   pid->move(12, 87, 82, 0, 0, 20);

   extra->stop(200);

   extra->misc(127, 127, 0, 1000);

   pid->move(9, -87, 0, 0, 0, 0);*/
 }

 void redAuton()
 {
   extra->flyCoast();

   //gets back cap

   extra->flywheelAccel(127);

   //get angled cap
   pid->move(40, 87, 127, 0, 0, 0);

   extra->misc(127, 0, 0, 500);

   pid->move(40, -87, 127, 0, 40, 0);

   //resets
   pid->drive(-47, 490);

   //moves a bit forward
   pid->move(6, 87, 127, 0, 0, 0);

   extra->stop(150);

   //turns towards flags
   pid->turn(-94, -90);

   //moves forawrd a bit and toggles top high flag
   pid->move(4, 87, 127, 0, 0, 0);

   extra->stop(250);

   extra->misc(0, 127, 0, 600);

   //moves forward and toggles the middle high flag
   pid->move(22, 87, 127, 0, 0, 0);

   extra->stop(150);

   extra->misc(127, 127, 0, 1000);

   //toggles low flag
   pid->move(7, 87, 90, 0, 0, 0);

   extra->misc(0, 0, -40, 650);

   //moves back and turns towards the front cap
   pid->move(30.5, -87, 90, 0, 0, 5);

   extra->stop(300);

   pid->turn(90, 90);

   pid->drive(-57, 420);

   pid->move(7.5, 67, 90, 0, 0, 0);

   extra->stop(200);

   pid->turn(-44, -90);

   pid->move(9, 67, 95, 0, 0, 0);

   extra->misc(100, 0, -62, 800);

   extra->misc(120, 0, 5, 100);

   pid->move(3, -67, 95, 127, 127, -20);

   extra->stop(100);

   pid->move(3, 87, 95, 0, 90, 0);

   pid->move(7, 87, 95, 0, 90, 100);

   pid->turn(3, 90);

   extra->misc(127, 127, 10, 1600);
}




void autonomous()
{
  /*if(auton == 0)
  {
    blueAuton();
  }
  else if(auton == 1)
  {
    redAuton();
  }
  else if(auton == 2)
  {
    skillsAuton();
  }*/
  //blueAuton();
  //skillsAuton();
  skillsAuton();
 /*pid->move(30, 85, 0, 0, 0, 0);
    pid->stop(1000);
pid->move(30, -85, 0, 0, 0, 0);
*/
  //pid->turn(90, 90);
  //vision->visionCorrect();
}
