#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

static PID * pid = new PID();
static Vision * vis = new Vision();

void opcontrol() {

  pros::Motor leftBDrive_mtr(11, HIGHSPEED, FWD, DEGREES);
  pros::Motor rightBDrive_mtr(12, HIGHSPEED, REV, DEGREES);
  pros::Motor leftFDrive_mtr(1, HIGHSPEED, FWD, DEGREES);
  pros::Motor rightFDrive_mtr(2, HIGHSPEED, REV, DEGREES);

  pros::Motor flyWheel_mtr(10, HIGHSPEED, FWD, DEGREES);
  pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
  pros::Motor ballIntake_mtr(3, HIGHSPEED, REV, DEGREES);
  pros::Motor indexer(4, HIGHSPEED, REV, DEGREES);

  pros::Controller master(MAIN);

	int speed = 0;

	while (true) {

		leftBDrive_mtr.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		leftFDrive_mtr.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		rightFDrive_mtr.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));
		rightBDrive_mtr.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));

		flyWheel_mtr.set_brake_mode(COAST);

		pid->driveBrakeHold();

    //vis->flagAlignment();

    tipper.move(master.get_analog(RIGHT_Y));

		if(master.get_digital(BTN_R1))
		{
      for(int i = 1; i <= 127; i++)
			{
				speed++;
			}
		}
		else if(master.get_digital(BTN_R2))
		{
			speed = 0;
		}

    flyWheel_mtr.move(speed);

    /*if(master.get_digital(pros::BTN_A))
    {
      tipper.move_relative(95, 100);
    }*/

    if(master.get_digital(BTN_L1))
		{
			indexer.move(100);
		}
		else if(master.get_digital(BTN_L2))
		{
			ballIntake_mtr.move(100);
		}
		else if(master.get_digital(BTN_A))
		{
			ballIntake_mtr.move(-87);
		}
		else
		{
			indexer.move(0);
			ballIntake_mtr.move(0);
		}


    pros::delay(20);
	}
}
