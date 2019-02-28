#include "main.h"

PID * pid = new PID();
Vision * look = new Vision();
miscell * extra = new miscell();
Drive * drive = new Drive();

Auton::Auton()
{

}

/*void Auton::skillsAuton() //With resets and no vision sensor
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
    drive->drive(-47, 150);

    //moves a bit forward
    pid->move(5, 87, 127, 0, 0, 0);

    extra->stop(150);

    //turns towards flags
    pid->turn(90, -90);

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
    pid->move(30.7, -87, 127, 0, 0, 0);

    extra->stop(300);

    pid->turn(90, 90);

    drive->drive(-47, 500);

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

    //look->visionCorrect();

    extra->misc(20, 127, 0, 820);

    pid->move(17, 87, 127, 0, 0, 20);

    extra->stop(200);

    //look->visionCorrect();

    extra->misc(127, 127, 0, 1000);

    //toggles low flag and resets against wall
    pid->turn(-13, -90);

    pid->move(15, 87, 127, 0, -40, 0);

    drive->drive(57, 850);

    //backs up and turns on an angle towards the front starting blue tile
    pid->move(20, -87, 127, 0, -40, 0);

    extra->stop(200);

    pid->turn(-70, -90);

    pid->move(61.1, -87, 127, 0, 0, 0);

    extra->stop(150);

    //straightens, resets and flips the blue side anlged cap
    pid->turn(-28, -90);

    drive->drive(-50, 980);

    drive->setZero();

    extra->capTip();

    pid->move(44, 87, 127, 0, 0, 0);

    extra->misc(60, 0, 0, 600);

    pid->move(44, -87, 127, 0, 60, 0);

    drive->drive(-37, 100);

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

    drive->drive(47, 800);

    //moves back and turns on an angle to align in front of the blue alliance platform
    pid->move(22, -87, 127, 0, 0, 0);

    pid->turn(-40, -90);

    pid->move(53, -87, 127, 0, 0, 0);

    //turns towards the aliance platform and resets
    pid->turn(-70, -90);

    drive->drive(47, 700);

    //gets on the center platform
    pid->move(67, 87, 127, 127, 127, 0);
}*/

//Without as many resets and with vision sensor
void Auton::skillsAuton()
{
  //pid->move(distance, power, flywheel, indexer, intake, tipper);
  //pid->miscell(tipper, intake, indexer, time);

    int sig = 1;

    extra->flyCoast();

    //gets back cap

    extra->flywheelAccel(127);

    extra->capTip();

    //get angled cap
    pid->move(40, 90, 127, 0, 0, 0);

    extra->misc(127, 0, 0, 500);

    pid->move(40.25, -90, 127, 0, 0, 0);

    extra->stop(600);

    //turns towards flags
    pid->turn(90, 90);

    extra->stop(600);

    //look->visionCorrect(sig);

    //moves forawrd a bit and toggles top high flag

    pid->move(3, 90, 127, 0, 0, 30);

    extra->misc(0, 127, 0, 800);

    //moves forward and toggles the middle high flag
    pid->move(19, 90, 127, 0, 0, 27);

    extra->stop(500);

    extra->misc(127, 127, 0, 1000);

    //toggles low flag

    pid->turn(15, 90);

    extra->stop(300);

    pid->move(9, 70, 127, 0, -90, 0);

    extra->stop(500);

    pid->move(4, -70, 127, 0, -90, 0);

    extra->stop(500);

    pid->turn(15, -90);

    extra->stop(500);

    //moves back and turns towards the front cap
    pid->move(27.25, -90, 127, 0, 0, 0);

    extra->stop(500);

    pid->turn(87.5, -90);

    extra->stop(500);

    drive->drive(-45, 340);

    extra->stop(500);

    pid->move(7.5, 70, 127, 0, 0, 0);

    extra->stop(500);

    pid->turn(45, 90);

    extra->stop(500);

    //moves towards the front cap and tilts it so the balls roll into the intake
    pid->move(7.5, 80, 127, 0, 0, 0);

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

    pid->move(18, 90, 127, 0, 0, 20);

    extra->stop(500);

    //look->visionCorrect(sig);

    extra->misc(127, 127, 0, 1000);

    //toggles low flag and resets against wall
    pid->turn(16, 90);

    extra->stop(500);

    pid->move(16, 90, 127, 0, -40, 0);

    drive->drive(60, 800);

    //backs up and turns on an angle towards the front starting blue tile
    pid->move(23, -90, 127, 0, -40, 0);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(350);

    pid->move(50, 90, 127, 0, -70, 20);

    extra->stop(550);

    pid->move(5, -90, 127, 0, -50, 0);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(500);

    pid->move(16, -90, 127, 0, 0, 0);

    drive->drive(-50, 150);

    extra->stop(500);

    pid->move(50, 90, 127, 0, 0, 0);

    extra->platBall();

    pid->move(3, -60, 127, 0, 0, 10);

    extra->misc(127, 10, 38, 1600);

    extra->stop(650);

    pid->turn(85, -90);

    extra->stop(650);

    pid->move(4, -90, 127, 0, 0, 0);

    extra->stop(600);

    extra->capTip();

    pid->move(22, 90, 127, 0, 20, 0);

    extra->misc(127, 0, 0, 1000);

    pid->move(22.5, -90, 127, 0, 60, 0);

    extra->stop(500);

    pid->turn(90, -90);

    extra->stop(500);

    pid->move(4, 70, 127, 0, 0, 0);

    look->visionCorrect(sig);

    extra->stop(500);

    extra->misc(0, 127, 0, 600);

    //moves forward and toggles the middle high flag
    pid->move(16, 70, 127, 0, 0, 30);

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

    pid->turn(25, 90);

    extra->stop(500);

    pid->move(54, -90, 60, 0, 0, 0);

    extra->stop(500);

    //turns towards the aliance platform and resets
    pid->turn(65, 90);

    extra->stop(400);

    drive->drive(50, 700);

    //gets on the center platform
    pid->move(68, 90, 40, 127, 127, 0);
}

/*void skillsAuton2()
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
    pid->drive(-47, 440);

    extra->stop(200);

    //moves a bit forward
    pid->move(4.8, 87, 127, 0, 0, 0);

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
    pid->move(7.1, 47, 127, 0, -90, 0);

    extra->misc(0, 0, -45, 600);

    //moves back and turns towards the front cap
    pid->move(31, -87, 127, 0, 0, 0);

    extra->stop(300);

    pid->turn(90, 90);

    pid->drive(-47, 390);

    pid->move(6.5, 67, 127, 0, 0, 10);

    extra->stop(200);

    pid->turn(-45, -90);

    //moves towards the front cap and tilts it so the balls roll into the intake
    pid->move(9.25, 77, 127, 0, 0, 7);

    extra->misc(100, 0, -60, 800);

    extra->misc(100, 0, -5, 200);

    //flips the cap
    pid->move(3, -87, 127, 0, 50, 0);

    extra->stop(200);

    pid->move(5, 67, 127, 0, 60, 0);

    pid->move(6, 67, 127, 0, 60, 90);

    extra->stop(150);

    //turns towards the other side of the field in order to go towards the middle flags
    pid->turn(48, 90);

    pid->move(31.7, 87, 127, 0, 60, 0);

    extra->stop(150);

    extra->misc(-15, -15, 0, 70);

    extra->misc(10, 15, 0, 70);

    //turns towards flags and shoots them
    pid->turn(-90, -90);

    pid->move(7.4, -87, 127, 0, 80, 0);

    extra->stop(200);

    //look->visionCorrect();

    extra->misc(20, 127, 0, 820);

    pid->move(17, 87, 127, 0, 0, 20);

    extra->stop(200);

    //look->visionCorrect();

    extra->misc(127, 127, 0, 1000);

    //toggles low flag and resets against wall
    pid->turn(-25, -90);

    pid->move(15, 87, 127, 0, -40, 0);

    pid->drive(57, 850);

    //backs up and turns on an angle towards the front starting blue tile
    pid->move(20, -87, 127, 0, -40, 0);

    extra->stop(200);

    pid->turn(-70, -90);

    pid->move(63.3, -87, 127, 0, 0, 0);

    extra->stop(150);

    //straightens, resets and flips the blue side anlged cap
    pid->turn(-28, -90);

    pid->drive(-50, 500);

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
    pid->move(11.5, 77, 127, 0, 0, 0);

    extra->misc(100, 0, -60, 800);

    extra->misc(120, 0, -5, 200);

    //flips the cap
    pid->move(3, -87, 127, 0, 0, 0);

    extra->stop(200);

    pid->move(8, 67, 127, 0, 70, 0);

    pid->move(10, 67, 127, 0, 70, 97);

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
}*/

void Auton::blueFAuton()
{
  extra->flyCoast();

  //gets back cap

  extra->flywheelAccel(127);

  //get angled cap
  pid->move(40, 87, 127, 0, 0, 0);

  extra->misc(127, 0, 0, 500);

  pid->move(40, -87, 127, 0, 40, 0);

  //moves a bit forward
  pid->move(5.9, 87, 127, 0, 0, 0);

  extra->stop(150);

  //turns towards flags
  pid->turn(90, -90);

  extra->stop(200);

  //moves forawrd a bit and toggles top high flag
  pid->move(4, 87, 127, 0, 0, 0);

  extra->stop(250);

  extra->misc(0, 127, 0, 600);

  //moves forward and toggles the middle high flag
  pid->move(22.7, 87, 127, 0, 0, 0);

  extra->stop(150);

  extra->misc(127, 127, 0, 1000);

  //toggles low flag
  pid->move(7.4, 87, 90, 0, 0, 0);

  extra->misc(0, 0, -90, 350);

  //moves back and turns towards the front cap
  pid->move(31.25, -87, 90, 0, 0, 5);

  extra->stop(300);

  pid->turn(90, 90);

  drive->drive(-47, 500);

  pid->move(6.6, 67, 90, 0, 0, 0);

  extra->stop(200);

  pid->turn(45, -90);

  extra->stop(150);

  pid->move(10, 67, 94, 0, 0, 0);

  extra->misc(100, 0, -62, 800);

  extra->misc(127, 0, 5, 100);

  pid->move(3, -67, 94, 0, 0, -20);

  extra->stop(100);

  pid->move(3, 87, 94, 0, 50, 0);

  pid->move(7, 87, 94, 0, 40, 100);

  extra->misc(127, 127, 5, 1600);

/*   extra->stop(150);

  pid->move(12, 87, 82, 0, 0, 20);

  extra->stop(200);

  extra->misc(127, 127, 0, 1000);

  pid->move(9, -87, 0, 0, 0, 0);*/
}

void Auton::blueBAuton()
{
  extra->flyCoast();

  extra->flywheelAccel(110);

  //get angled cap
  pid->move(37, 90, 110, 0, 0, 0);

  extra->misc(70, 0, 0, 600);

  extra->stop(300);

  pid->move(32, -90, 113, 0, 60, 0);

  extra->stop(400);

  pid->turn(60, -90);

  extra->misc(127, 127, 0, 1250);

  pid->turn(161, 90);

  extra->stop(350);

  pid->move(18, 90, 115, 0, 0, 0);

  extra->stop(450);

  pid->turn(85, -90);

  extra->stop(350);

  pid->move(15.5, 90, 120, 0, 0, 0);

  extra->misc(90, 0, -60, 1200);

  extra->misc(90, 0, -15, 500);

  pid->move(2, -90, 120, 0, 0, 0);

  extra->stop(200);

  pid->move(10, 90, 120, 0, 0, 80);

  extra->stop(350);

  pid->move(7, -90, 110, 0, 0, 0);

  extra->stop(350);

  pid->turn(54, -90);

  extra->misc(127, 127, 20, 1000);

  pid->move(10, 90, 90, 0, 0, 0);

  extra->stop(350);

  pid->turn(28, -90);

  extra->stop(350);

  pid->move(40, 90, 76, 0, 0, 0);
}

/*void*+ redAuton()
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

  extra->misc(100, 0, -127, 400);

  extra->misc(120, 0, 10, 100);

  pid->move(3, -67, 95, 127, 127, -20);

  extra->stop(100);

  pid->move(3, 87, 95, 0, 90, 0);

  pid->move(7, 87, 95, 0, 90, 100);

  pid->turn(3, 90);

  extra->misc(127, 127, 10, 1600);
}*/

void Auton::redFAuton()
{
 extra->flyCoast();

 //gets back cap

 extra->flywheelAccel(127);

 //get angled cap
 pid->move(40, 87, 127, 0, 0, 0);

 extra->misc(127, 0, 0, 500);

 pid->move(40, -87, 127, 0, 0, 0);

 //resets
 drive->drive(-47, 440);

 extra->stop(200);

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
 pid->move(22, 67, 127, 0, 0, 30);

 extra->stop(150);

 extra->misc(127, 127, 0, 1000);

 //toggles low flag
 pid->move(7.6, 47, 127, 0, -90, 0);

 extra->misc(0, 0, -100, 350);

 //moves back and turns towards the front cap
 pid->move(31.5, -87, 127, 0, 0, 0);

 extra->stop(300);

 pid->turn(90, 90);

 drive->drive(-47, 390);

 pid->move(6.5, 67, 127, 0, 0, 10);

 extra->stop(200);

 pid->turn(-45, -90);

 //moves towards the front cap and tilts it so the balls roll into the intake
 pid->move(9.25, 77, 127, 0, 0, 7);

 extra->misc(100, 0, -60, 800);

 extra->misc(100, 0, -5, 200);

 //flips the cap
 pid->move(3, -87, 127, 0, 50, 0);

 extra->stop(200);

 pid->move(5, 67, 127, 0, 60, 0);

 pid->move(6, 67, 127, 0, 60, 90);

 extra->stop(150);

 extra->misc(127, 127, 20, 1600);
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
}
