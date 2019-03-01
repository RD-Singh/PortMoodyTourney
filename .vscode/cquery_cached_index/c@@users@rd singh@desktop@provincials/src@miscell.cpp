#include "main.h"

pros::Motor fly_Wheel(10, HIGHSPEED, REV, DEGREES);
pros::Motor flipper(9, HIGHSPEED, FWD, DEGREES);
pros::Motor ballIntake(3, HIGHSPEED, REV, DEGREES);
pros::Motor indexerMtr(4, HIGHSPEED, REV, DEGREES);


miscell::miscell()
{

}



void miscell::capTip()
{
  flipper.tare_position();

  flipper.set_brake_mode(HOLD);

  flipper.move_relative(-410, -127);

  while (!((flipper.get_position() < -400) && (flipper.get_position() > -420)))
  {
   pros::delay(2);
  }
}

void miscell::flywheel(int x)
{
  fly_Wheel.move(x);
}

void miscell::platBall()
{
  flipper.tare_position();

  flipper.set_brake_mode(HOLD);

  flipper.move_relative(-540, -127);

  while (!((flipper.get_position() < -530) && (flipper.get_position() > -550)))
  {
   pros::delay(2);
  }
}

void miscell::stop(int x)
{
  pros::delay(x);
}

void miscell::flyCoast()
{
  fly_Wheel.set_brake_mode(COAST);
}

void miscell::misc(int intakeP, int indexerP, int tipperP, int x)
{
  flipper.set_brake_mode(HOLD);
  ballIntake.move(intakeP);
  indexerMtr.move(indexerP);
  flipper.move(tipperP);

  pros::delay(x);
}

void miscell::flywheelAccel(int x)
{
 int speed = 0;

 for(int i = 1; i <= x; i++)
 {
   speed++;
 }

 fly_Wheel.move(speed);
}
