#include "main.h"
#include <stdio.h>

pros::Motor fly_Wheel(10, TURBO, REV, DEGREES);
pros::Motor flipper(3, HIGHSPEED, FWD, DEGREES);
pros::Motor ballIntake(9, HIGHSPEED, REV, DEGREES);
pros::Motor indexerMtr(14, HIGHSPEED, REV, DEGREES);
pros::ADILineSensor ballTrack('A');

int speed;

miscell::miscell()
{

}

void miscell::setSpeed(int s)
{
    speed = s;
}

int miscell::getSpeed()
{
  return speed;
}

void miscell::capTip()
{
  flipper.tare_position();

  flipper.set_brake_mode(HOLD);

  flipper.move_relative(-200, 127);

  while (!((flipper.get_position() < -180) && (flipper.get_position() > -220)))
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

/*void miscell::doubleShot()
{
  int speedVal = fly_Wheel.get_actual_velocity();
  int threshold = 582;

  if(speedVal < threshold)
  {
    setSpeed(77);
  }
  else
  {
    setSpeed(127);
  }

}*/

void miscell::flywheelAccel(int x)
{
 int speed = 0;

 for(int i = 1; i <= x; i++)
 {
   speed++;
 }

 fly_Wheel.move(speed);
}
