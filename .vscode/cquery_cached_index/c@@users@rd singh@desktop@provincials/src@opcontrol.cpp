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
static Drive * driv = new Drive();

void opcontrol() {

  pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
  pros::Motor backR(12, HIGHSPEED, REV, DEGREES);
  pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
  pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);

  pros::Motor flywheel(10, HIGHSPEED, REV, DEGREES);
  pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
  pros::Motor intake(3, HIGHSPEED, REV, DEGREES);
  pros::Motor indexer(4, HIGHSPEED, REV, DEGREES);

  pros::ADIGyro gyro ('A');

  pros::Controller master(MAIN);

	int speed = 0;

	while (true) {

		backL.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		frontL.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		frontR.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));
		backR.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));

		flywheel.set_brake_mode(COAST);

		driv->driveBrakeHold();

    //vis->flagAlignment();

    tipper.move(master.get_analog(RIGHT_Y));


		if(master.get_digital(BTN_R1))
		{
      if(speed == 127)
      {
        speed = 127;
      }
      else if(speed == 0)
      {
        for(int i = 1; i <= 127; i++)
			  {
				    speed++;
			  }
      }
		}
		else if(master.get_digital(BTN_R2))
		{
      speed = 0;
		}
    else if(master.get_digital(BTN_X))
    {
      if(speed == 0)
      {
        for(int i = 1; i <= 87; i++)
        {
          speed++;
        }
      }
      else if(speed == 127)
      {
        for (int i = 127; i >= 87; i--)
        {
          speed--;
        }
      }
    }

    flywheel.move(speed);


    if(master.get_digital(BTN_L1))
		{
			indexer.move(87);
		}
		else if(master.get_digital(BTN_L2))
		{
			intake.move(127);
		}
		else if(master.get_digital(BTN_A))
		{
			intake.move(-87);
		}
		else
		{
			indexer.move(0);
			intake.move(0);
		}


    /*if(master.get_digital(BTN_Y))
    {
      pid->turn(90, 90);
    }*/

    pros::lcd::set_text(3, "Left Wheel = " + std::to_string(frontL.get_position()));
    pros::lcd::set_text(4, "Right Wheel = " + std::to_string(frontR.get_position()));
    pros::lcd::set_text(5, "Left Wheel = " + std::to_string(frontL.get_actual_velocity()));
    pros::lcd::set_text(6, "Right Wheel = " + std::to_string(frontR.get_actual_velocity()));

    pros::delay(20);
	}
}
