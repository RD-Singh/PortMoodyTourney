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

 PID * Pid = new PID();
 static Vision * visi = new Vision();
 Auton * Auto = new Auton();


void autonomous()
{
  /*if(auton == 0)
  {
    Auto->blueAuton();
  }
  else if(auton == 1)
  {
    Auto->edAuton();
  }
  else if(auton == 2)
  {
    Auto->skillsAuton();
  }*/
  //Auto->blueAuton();
  //Auto->skillsAuton();
  Auto->redBAuton();
    //Pid->turn(90, 90);
  //Pid->move(40, 90, 0, 0, 0, 0);


}
