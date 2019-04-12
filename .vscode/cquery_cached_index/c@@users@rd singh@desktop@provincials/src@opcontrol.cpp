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

static miscell * m = new miscell();
static Drive * d = new Drive();
static PID * p = new PID();
void opcontrol() {

  pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
  pros::Motor backR(13, HIGHSPEED, REV, DEGREES);
  pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
  pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);

  pros::Motor flywheel(10, TURBO, REV, DEGREES);
  pros::Motor capIntake(3, HIGHSPEED, REV, DEGREES);
  pros::Motor intake(9, HIGHSPEED, REV, DEGREES);
  pros::Motor indexer(14, HIGHSPEED, REV, DEGREES);
  pros::ADILineSensor ballTrack('A');
  pros::Vision vision (6);

  pros::ADIGyro leftGyro ('A');
  pros::ADIGyro rightGyro ('B');

  pros::ADIUltrasonic leftW (3, 4);
  pros::ADIUltrasonic rightW ('E', 'F');
  pros::ADIUltrasonic front ('G', 'H');

  pros::Controller master(MAIN);

  int speed = 0;
  int deg;
  int sig = 0;
  int left, right, avg;
  int capSpeed = 0;

  m->setSpeed(0);

  capIntake.set_brake_mode(HOLD);
  capIntake.tare_position();

	while (true) {

    left = leftW.get_value();
    right = rightW.get_value();

    pros::lcd::set_text(4, "Left  = " + std::to_string(left));
    pros::lcd::set_text(5, "Right = " + std::to_string(right));


//    m->doubleShot();



		backL.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		frontL.move(((master.get_analog(LEFT_Y) + master.get_analog(LEFT_X)/2)*1.5));
		frontR.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));
		backR.move(((master.get_analog(LEFT_Y) - master.get_analog(LEFT_X)/2)*1.5));

    d->driveBrakeHold();


		flywheel.set_brake_mode(COAST);

    capIntake.move(master.get_analog(RIGHT_Y));


   if(master.get_analog(RIGHT_Y) == 0 && master.get_digital(BTN_Y))
    {
      deg = deg - 225;

      if(deg > 0)
      {
        capSpeed = -87;
      }
      else if (deg < 0)
      {
        capSpeed = 87;
      }
      capIntake.move_relative(deg, capSpeed);
    }

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

    if(master.get_digital(BTN_R1))
    {
      if(m->getSpeed() == 127)
      {
        m->setSpeed(127);
      }
      else if(m->getSpeed() == 0)
      {
        for(int i = 1; i <= 127; i++)
        {
            speed++;
        }
        m->setSpeed(speed);
      }
    }
    else if(master.get_digital(BTN_R2))
    {
      m->setSpeed(0);
    }

    flywheel.move(m->getSpeed());

    if(master.get_digital(BTN_LEFT))
    {
      p->move(45, 105, 0, 0, 0, 0, 0);

      m->stop(500);

      p->move(45, -105, 0, 0, 0, 0, 0);
    }

    pros::delay(20);
	}
}
