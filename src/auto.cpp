#include "main.h"

PID * pid = new PID();
Vision * look = new Vision();
miscell * extra = new miscell();
Drive * drive = new Drive();

pros::Motor flyW(10, TURBO, REV, DEGREES);
pros::Motor capper(3, HIGHSPEED, FWD, DEGREES);
pros::Motor balls(9, HIGHSPEED, REV, DEGREES);
pros::Motor ind(14, HIGHSPEED, REV, DEGREES);

Auton::Auton()
{

}
/*
//Without as many resets and with vision sensor
void Auton::skillsAuton()
{
  //pid->move(distance, power, flywheel, indexer, intake, tipper);
  //pid->miscell(tipper, intake, indexer, time);

    int sig = 1;

    extra->flyCoast();

    //gets back cap

    extra->flywheelAccel(127);

    //get angled cap
    pid->move(39, 90, 127, 0, -50, 0);

    extra->misc(127, 0, 0, 800);

    pid->move(38.5, -90, 127, 0, 60, 0);

    extra->stop(700);

    //turns towards flags
    pid->turn(90, 90);

    extra->stop(700);

    look->visionCorrect(sig);

    extra->stop(400);

    //moves forawrd a bit and toggles top high flag

    pid->move(3, 90, 127, 0, 0, -25);

    extra->misc(0, 127, 0, 800);

    //moves forward and toggles the middle high flag
    pid->move(19, 90, 127, 0, 0, -18);

    extra->stop(500);

    extra->misc(127, 127, 0, 1000);

    //toggles low flag

    pid->turn(12, 90);

    extra->stop(200);

    pid->move(12, 70, 127, 0, -90, 0);

    extra->stop(500);

    pid->move(5, -70, 127, 0, -90, 0);

    extra->stop(500);

    pid->turn(12, -90);

    extra->stop(500);

    //moves back and turns towards the front cap
    pid->move(27, -90, 127, 0, 0, 0);

    extra->stop(500);

    pid->turn(87.5, -90);

    extra->stop(500);

    drive->drive(-45, 200);

    extra->stop(500);

    pid->move(7.5, 70, 127, 0, 0, 0);

    extra->stop(500);

    pid->turn(45, 90);

    extra->stop(500);

    //moves towards the front cap and tilts it so the balls roll into the intake
    pid->move(8.25, 80, 127, 0, 0, 0);

    extra->misc(100, 0, -60, 900);

    extra->misc(100, 0, -5, 600);

    //flips the cap
    pid->move(3, -90, 127, 0, 50, 0);

    extra->stop(500);

    pid->move(6, 70, 127, 0, 60, 0);

    pid->move(6, 70, 127, 0, 60, 90);

    extra->stop(800);

    //turns towards the other side of the field in order to go towards the middle flags
    pid->turn(45, -90);

    extra->stop(500);

    pid->move(31, 90, 127, 0, 60, 0);

    extra->stop(500);

    //turns towards flags and shoots them

    pid->turn(90, 90);

    extra->stop(350);

    pid->move(9.5, -90, 127, 0, 80, 0);

    extra->stop(500);

    look->visionCorrect(sig);

    extra->misc(5, 127, 0, 820);

    drive->drive(60, 900);

    drive->drive(0, 400);

    //look->visionCorrect(sig);

    extra->misc(127, 127, 0, 1000);

    //toggles low flag and resets against wall
    pid->turn(15.5, 90);

    extra->stop(500);

    pid->move(16, 90, 127, 0, -40, 0);

    drive->drive(60, 800);

    //backs up and turns on an angle towards the front starting blue tile
    pid->move(23, -90, 127, 0, -40, 0);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(350);

    pid->move(50, 90, 127, 0, -55, 20);

    extra->stop(550);

    pid->move(5, -90, 127, 0, -50, 0);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(500);

    pid->move(14, -90, 127, 0, 0, 0);

    drive->drive(-45, 200);

    extra->stop(500);

    pid->move(50, 90, 127, 0, 0, 0);

    extra->platBall();

    pid->move(3, -60, 127, 0, 0, 10);

    extra->misc(127, 18, 35, 1200);

    extra->stop(350);

    pid->turn(88, -90);

    extra->stop(550);

    pid->move(22, 90, 127, 0, -50, 0);

    extra->misc(127, 0, 0, 1000);

    pid->move(24, -90, 127, 0, 60, 30);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(500);

    pid->move(3.5, 70, 127, 0, 0, 0);

    look->visionCorrect(sig);

    extra->stop(500);

    extra->misc(0, 127, 0, 600);

    //moves forward and toggles the middle high flag
    pid->move(16.5, 70, 127, 0, 0, 30);

    extra->stop(550);

    //look->visionCorrect(sig);

    extra->misc(127, 127, 0, 1000);

    //toggles low flag

    pid->turn(18, 90);

    extra->stop(500);

    pid->move(14, 90, 100, 0, 0, 0);

    drive->drive(50, 600);

    extra->stop(500);

    pid->move(20, -90, 80, 0, 0, 0);

    extra->stop(400);

    pid->turn(25, 90);

    extra->stop(500);

    pid->move(52, -90, 60, 0, 0, 0);

    extra->stop(500);

    //turns towards the aliance platform and resets
    pid->turn(65, 90);

    extra->stop(400);

    drive->drive(40, 900);

    //gets on the center platform
    pid->move(68, 90, 40, 127, 127, 0);
}
*/
void Auton::blueFAuton()
{
  int sig = 2;

  extra->flywheelAccel(127);
  extra->flyCoast();

  extra->capTip();

  pid->move(23, 80, 127, 0, 40, 0);

  drive->drive(-50, 127, 400);
}

void Auton::blueFPAuton()
{
  int sig = 2;

  extra->flywheelAccel(127);
  extra->flyCoast();

  extra->capTip();

  pid->move(38, 105, 127, 0, 80, 0);

  extra->misc(90, 0, 0, 500);

  pid->move(36.5, -105, 127, 0, 60, 0);

  extra->stop(300);

  pid->turn(90, -90);

  capper.move(67);

  pros::delay(700);

  capper.move(0);

  look->visionCorrect(2);

  extra->misc(0, 127, 0, 400);

  pid->move(24.5, 105, 127, 0, 0, 0);

  extra->stop(200);

  extra->misc(127, 127, 0, 700);

  extra->capTip();

  extra->stop(300);

  drive->drive(60, 0, 300);

}

void Auton::redFPAuton()
{
  int sig = 1;

  extra->flywheelAccel(127);
  extra->flyCoast();

  extra->capTip();

  pid->move(38, 105, 127, 0, 80, 0);

  extra->misc(90, 0, 0, 500);

  pid->move(37.65, -105, 127, 0, 60, 0);

  extra->stop(300);

  pid->turn(90, 90);

  capper.move(67);

  pros::delay(700);

  capper.move(0);

  look->visionCorrect(sig);

  extra->misc(0, 127, 0, 400);

  pid->move(24.5, 105, 127, 0, 0, 0);

  extra->stop(200);

  extra->misc(127, 127, 0, 700);

  extra->capTip();

  extra->stop(300);

  capper.move(-50);

  extra->stop(250);

  capper.move(0);

  pid->turn(15, 90);

  extra->stop(200);

  drive->drive(60, 127, 400);

  extra->stop(200);

  drive->drive(-60, 127, 400);

  extra->stop(200);

  pid->turn(16.5, -90);

  extra->stop(200);

  pid->move(27, -105, 127, 0, 0, 0);

  extra->stop(250);

  pid->turn(90, -90);

  extra->stop(250);

  pid->move(32, 105, 127, 0, 0, 0);

  extra->stop(250);

  pid->turn(135, 90);

  extra->stop(250);

  look->collectCapBall();
}
