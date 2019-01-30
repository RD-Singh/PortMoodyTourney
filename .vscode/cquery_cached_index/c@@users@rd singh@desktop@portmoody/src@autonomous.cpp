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

     //moves a bit forward
     pid->move(5, 87, 127, 0, 0, 0);

     extra->stop(150);

     //turns towards flags
     pid->turn(-90, -90);

     //moves forawrd a bit and toggles top high flag
     pid->move(4, 67, 127, 0, 0, 0);

     extra->stop(250);

     extra->misc(0, 127, 0, 600);

     //moves forward and toggles the middle high flag
     pid->move(22, 67, 127, 0, 0, 25);

     extra->stop(150);

     extra->misc(127, 127, 0, 1000);

     //toggles low flag
     pid->move(9.5, 47, 127, 0, 0, 0);

     //moves back and turns towards the front cap
     pid->move(33, -87, 127, 0, 0, 0);

     extra->stop(300);

     pid->turn(90, 90);

     pid->drive(-57, 500);

     pid->move(7, 67, 127, 0, 0, 0);

     extra->stop(200);

     pid->turn(-45, -90);

     //moves towards the front cap and tilts it so the balls roll into the intake
     pid->move(10.5, 77, 127, 0, 0, 0);

     extra->misc(100, 0, -60, 800);

     extra->misc(120, 0, -5, 800);

     //flips the cap
     pid->move(3, -87, 127, 0, 0, 0);

     extra->stop(200);

     pid->move(5, 67, 127, 0, 50, 0);

     pid->move(5, 77, 127, 0, 40, 107);

     extra->stop(150);

     //turns towards the other side of the field in order to go towards the middle flags
     pid->turn(51, 90);

     pid->move(32, 87, 127, 0, 0, 0);

     extra->stop(150);

     //turns towards flags and shoots them
     pid->turn(-90, -90);

     pid->move(8, -87, 127, 0, 40, 0);

     extra->stop(200);

     //vision->visionCorrect();

     extra->misc(80, 127, 0, 750);

     pid->move(16, 87, 127, 0, 0, 20);

     extra->stop(200);

     //vision->visionCorrect();

     extra->misc(127, 127, 0, 1000);

     //toggles low flag and resets against wall
     pid->turn(-12, -90);

     pid->move(16, 87, 127, 0, 0, 0);

     pid->drive(57, 850);

     //backs up and turns on an angle towards the front starting blue tile
     pid->move(20, -87, 127, 0, 0, 0);

     extra->stop(200);

     pid->turn(-70, -90);

     pid->move(60, -87, 127, 0, 0, 0);

     extra->stop(150);

     //straightens, resets and flips the blue side anlged cap
     pid->turn(-20, -90);

     pid->drive(-47, 400);

     extra->capTip();

     pid->move(47, 87, 127, 0, 0, 0);

     extra->stop(550);

     pid->move(47, -87, 127, 0, 0, 0);

     pid->drive(-57, 400);

     //moves a bit foward and turns towards front cap
     pid->move(5, 87, 127, 0, 0, 0);

     extra->stop(150);

     pid->turn(45, 90);

     //move toward front cap and titls it so the balls roll into the intake
     pid->move(12, 77, 127, 0, 0, 0);

     extra->misc(100, 0, -60, 800);

     extra->misc(120, 0, -5, 1200);

     //flips the cap
     pid->move(3, -87, 127, 0, 0, 0);

     extra->stop(200);

     pid->move(5, 67, 127, 0, 50, 0);

     pid->move(10, 80, 127, 0, 40, 97);

     extra->stop(150);

     //turns towards the last set of flags and shoots them
     pid->turn(50, 90);

     pid->move(15, -87, 127, 0, 60, 0);

     extra->misc(80, 127, -15, 800);

     pid->move(12, 87, 127, 0, 0, 0);

     extra->misc(127, 127, -30, 600);

     //moves forward into the low flag
     pid->move(16, 67, 127, 0, 0, 0);

     //moves back and turns on an angle to align in front of the blue alliance platform
     pid->move(18, -87, 127, 0, 0, 0);

     pid->turn(-25, -90);

     pid->move(35, -87, 127, 0, 0, 0);

     //turns towards the aliance platform and resets
     pid->turn(-75, -90);

     pid->drive(-47, 500);

     //gets on the center platform
     pid->move(55, 87, 127, 127, 127, 0);
 }

 void blueAuton()
 {
   extra->flyCoast();

   //gets back cap

   extra->flywheelAccel(127);

   //get angled cap
   pid->move(40, 87, 127, 0, 0, 0);

   extra->misc(127, 0, 0, 500);

   pid->move(40, -87, 127, 0, 0, 0);

   //resets
   pid->drive(-57, 600);

   //moves a bit forward
   pid->move(5.75, 87, 127, 0, 0, 0);

   extra->stop(150);

   //turns towards flags
   pid->turn(90, 90);

   //moves forawrd a bit and toggles top high flag
   pid->move(4, 67, 127, 0, 0, 0);

   extra->stop(250);

   extra->misc(0, 127, 0, 600);

   //moves forward and toggles the middle high flag
   pid->move(22, 67, 127, 0, 0, -20);

   extra->stop(150);

   extra->misc(127, 127, 0, 1000);

   //toggles low flag
   pid->move(7, 67, 127, 0, 0, 0);

   //moves back and turns towards the front cap
   pid->move(31, -87, 127, 0, 0, 0);

   extra->stop(300);

   pid->turn(-90, -90);

   pid->drive(-57, 500);

   pid->move(7, 67, 127, 0, 0, 0);

   extra->stop(200);

   pid->turn(45, 90);

   pid->move(10, 77, 127, 0, 0, 0);

   extra->misc(100, 0, -60, 800);

   extra->misc(120, 0, -5, 1200);

   pid->move(3, -87, 127, 0, 0, 0);

   extra->stop(200);

   pid->move(5, 87, 127, 0, 50, 0);

   pid->move(5, 77, 127, 0, 40, 100);

   extra->stop(150);

   extra->misc(70, 127, 0, 450);

   pid->move(16, 87, 91, 0, 0, 20);

   extra->stop(200);

   extra->misc(127, 127, 0, 1000);

   pid->move(9, -87, 0, 0, 0, 0);
 }
/*
 void redAuton()
 {
   pid->flywheelAccel(127);
  //Moves forward
  pid->move(40, 87, 127, 0, 0);

  pid->miscell(60, 0, 600);
  //moves back

  pid->drive(-87);

  pid->stop(1000);

  pid->drive(-67);

  pid->stop(1000);

  //moves a bit forward
  pid->move(6, 67, 127, 0, 30);

  pid->stop(200);
  //turns
  pid->turn(-85, -90);

  pid->move(5, 67, 127, 0, 0);

  pid->miscell(0, 80, 1000);

  //moves forward to the low flag
  pid->move(20, 93, 127, 0, 0);

  pid->miscell(90, 90, 1400);

  pid->turn(-10, -67);

  //toggles low flag
  pid->move(14, 87, 90, 0, 0);

  pid->stop(150);

  //moves back towards cap
  pid->move(5, -77, 70, 0, 0);

  pid->stop(250);

  pid->turn(10, 67);

  pid->stop(250);

  pid->move(4, -90, 60, 0, 0);

  //turns towwards cap
  pid->turn(90, 90);

  pid->stop(250);

  //resets
  pid->drive(-67);

  pid->stop(600);

  //flips cap
  pid->move(23, 80, 40, 0, -55);

  pid->stop(250);

  pid->move(10, -87, 30, 0, 0);
}
*/



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
  skillsAuton();
  //redAuton();
 /*pid->move(30, 85, 0, 0, 0, 0);
    pid->stop(1000);
pid->move(30, -85, 0, 0, 0, 0);
*/
  //pid->turn(90, 90);
}
