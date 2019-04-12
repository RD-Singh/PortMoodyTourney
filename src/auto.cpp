#include "main.h"

PID * pid = new PID();
Vision * look = new Vision();
miscell * extra = new miscell();
Drive * drive = new Drive();

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

void Auton::blueFAuton()
{
  int sig = 3;

  extra->flyCoast();

  //gets back cap

  extra->flywheelAccel(127);

  //get angled cap
  pid->move(39, 90, 127, 0, 20, 0);

  extra->misc(127, 0, 0, 800);

  pid->move(39, -90, 127, 0, 60, 0);

  extra->stop(200);

  pid->turn(88, -90);

  //look->visionCorrect(sig);

  extra->stop(200);

  //moves forawrd a bit and toggles top high flag

  pid->move(2.5, 90, 127, 0, 0, 5);

  extra->stop(200);

  extra->misc(0, 127, 0, 800);

  //moves forward and toggles the middle high flag
  pid->move(19.5, 90, 127, 0, 0, -20);

  extra->stop(200);

  extra->misc(127, 127, -10, 1000);

  //toggles low flag

  pid->turn(12, -90);

  extra->stop(200);

  pid->move(9, 90, 127, 0, -90, 0);

  extra->stop(200);

  pid->move(4, -90, 127, 0, -90, 0);

  extra->stop(200);

  pid->turn(12, 90);

  extra->stop(200);

  //moves back and turns towards the front cap
  pid->move(26.5, -90, 127, 0, 0, 0);

  extra->stop(200);

  pid->turn(37.5, 90);

  extra->stop(200);

  //moves towards the front cap and tilts it so the balls roll into the intake
  pid->move(11.5, 90, 105, 0, 0, 0);

  extra->misc(100, 0, -60, 900);

  extra->misc(100, 0, -5, 600);

  //flips the cap
  pid->move(4, -90, 93, 0, 50, 0);

  extra->stop(200);

  pid->move(7, 90, 89, 0, 60, 0);

  pid->move(24, 90, 89, 80, 80, 90);
}

void Auton::blueFPAuton()
{
  int sig = 1;

  extra->flyCoast();

  //gets back cap

  extra->flywheelAccel(127);

  //get angled cap
  pid->move(39, 90, 127, 0, 20, 0);

  extra->misc(127, 0, 0, 800);

  pid->move(39, -90, 127, 0, 60, 0);

  extra->stop(200);

  pid->turn(88, -90);

  extra->stop(300);

  //look->visionCorrect(sig);

  //extra->stop(200);

  //moves forawrd a bit and toggles top high flag

  pid->move(2, 90, 127, 0, 0, 5);

  extra->stop(300);

  extra->misc(0, 127, 0, 800);

  //moves forward and toggles the middle high flag
  pid->move(21, 90, 127, 0, 0, -20);

  extra->stop(300);

  extra->misc(127, 127, -10, 1000);

  //toggles low flag

  pid->turn(11.8, -90);

  extra->stop(600);

  pid->move(9, 90, 127, 0, -90, 0);

  extra->stop(300);

  pid->move(4, -90, 127, 0, -90, 0);

  extra->stop(300);

  pid->turn(12, 90);

  extra->stop(300);

  //moves back and turns towards the front cap
  pid->move(50, -90, 127, 0, 0, 0);

  extra->stop(300);

  pid->turn(90, 90);

  extra->stop(300);

  drive->drive(50, 400);

  pid->move(40, 90, 127, 0, 127, 0);
}

void Auton::blueBAuton()
{
  extra->flyCoast();

  extra->flywheelAccel(110);

  //get angled cap
  pid->move(37, 90, 110, 0, 0, 0);

  extra->misc(70, 0, 0, 600);

  extra->stop(200);

  pid->move(32, -90, 113, 0, 60, 0);

  extra->stop(400);

  pid->turn(60, -90);

  extra->misc(127, 127, 0, 1250);

  pid->turn(161, 90);

  extra->stop(350);

  pid->move(20, 90, 115, 0, 0, 0);

  drive->drive(50, 600);

  extra->stop(450);

  pid->move(5, -90, 115, 0, 0, 0);

  extra->stop(350);

  pid->turn(89, -90);

  extra->stop(350);

  pid->move(16, 90, 120, 0, 0, 0);

  extra->misc(90, 0, -60, 1200);

  extra->misc(90, 0, -15, 500);

  pid->move(2, -90, 120, 0, 0, 0);

  extra->stop(200);

  pid->move(10, 90, 120, 0, 0, 80);

  extra->stop(350);

  pid->move(7, -90, 110, 0, 0, 0);

  extra->stop(350);

  pid->turn(56, -90);

  extra->misc(127, 127, 20, 1000);

  pid->move(10, 90, 90, 0, 0, 0);

  extra->stop(350);

  pid->turn(28, -90);

  extra->stop(350);

  pid->move(45, 90, 76, 0, 0, 0);
}

void Auton::redFAuton()
{
  int sig = 1;

  extra->flyCoast();

  //gets back cap

  extra->flywheelAccel(127);

  //get angled cap
  pid->move(39, 90, 127, 0, 20, 0);

  extra->misc(127, 0, 0, 800);

  pid->move(39, -90, 127, 0, 68, 0);

  extra->stop(200);

  pid->turn(90, 90);

  extra->stop(300);

  look->visionCorrect(sig);

  extra->stop(200);

  //moves forawrd a bit and toggles top high flag

  pid->move(2, 90, 127, 0, 0, 5);

  extra->stop(200);

  extra->misc(0, 127, 0, 800);

  //moves forward and toggles the middle high flag
  pid->move(21.5, 90, 127, 0, 0, -20);

  extra->stop(200);

  extra->misc(127, 127, -10, 1000);

  //toggles low flag

  pid->turn(12, 90);

  extra->stop(200);

  pid->move(9.25, 90, 127, -90, -90, 0);

  extra->stop(200);

  pid->move(4, -90, 127, -90, -90, 0);

  extra->stop(200);

  pid->turn(12, -90);

  extra->stop(200);

  //moves back and turns towards the front cap
  pid->move(26.75, -90, 127, 0, 0, 0);

  extra->stop(200);

  pid->turn(40, -90);

  extra->stop(200);

  //moves towards the front cap and tilts it so the balls roll into the intake
  pid->move(10.25, 90, 105, 0, 0, 0);

  extra->misc(100, 0, -60, 900);

  extra->misc(100, 0, -5, 600);

  //flips the cap
  pid->move(4, -90, 93, 0, 50, 0);

  extra->stop(200);

  pid->move(5, 90, 100, 0, 60, 0);

  pid->move(27, 90, 97, 80, 40, 90);
}

void Auton::redFPAuton()
{
  int sig = 1;

  extra->flyCoast();

  //gets back cap

  extra->flywheelAccel(127);

  //get angled cap
  pid->move(39, 90, 127, 0, 20, 0);

  extra->misc(127, 0, 0, 800);

  pid->move(39, -90, 127, 0, 60, 0);

  extra->stop(200);

  pid->turn(89, 90);

  extra->stop(300);

  look->visionCorrect(sig);

  extra->stop(200);

  //moves forawrd a bit and toggles top high flag

  pid->move(2, 90, 127, 0, 0, 5);

  extra->stop(200);

  extra->misc(0, 127, 0, 800);

  //moves forward and toggles the middle high flag
  pid->move(21, 90, 127, 0, 0, -20);

  extra->stop(200);

  extra->misc(127, 127, -10, 1000);

  //toggles low flag

  pid->turn(12, 90);

  extra->stop(200);

  pid->move(9, 90, 127, 0, -90, 0);

  extra->stop(200);

  pid->move(4, -90, 127, 0, -90, 0);

  extra->stop(200);

  pid->turn(12, -90);

  extra->stop(200);

  //moves back and turns towards the front cap
  pid->move(50, -90, 127, 0, 0, 0);

  extra->stop(200);

  pid->turn(90, -90);

  extra->stop(200);

  drive->drive(50, 400);

  pid->move(40, 90, 127, 0, 127, 0);
}

void Auton::redBAuton()
{
  extra->flyCoast();

  extra->flywheelAccel(117);

  //get angled cap
  pid->move(39, 90, 117, 0, 0, 0);

  extra->misc(80, 0, 0, 600);

  pid->move(34, -90, 117, 0, 60, 0);

  extra->stop(400);

  pid->turn(60, 90);

  extra->misc(0, 127, 0, 700);

  extra->flywheel(88);

  extra->stop(700);

  extra->misc(127, 127, 0, 900);

  pid->turn(11, -90);

  extra->stop(350);

  pid->move(8, 90, 105, 0, 127, 0);

  extra->platBall();

  pid->move(7, -70, 105, 0, 127, 0);

  extra->stop(350);

  pid->move(2, 70, 104, 0, 127, 0);

  extra->misc(127, 127, 0, 1000);
}*/
