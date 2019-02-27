#include "main.h"


pros::Motor leftB(11, HIGHSPEED, FWD, DEGREES);
pros::Motor rightB(12, HIGHSPEED, REV, DEGREES);
pros::Motor leftF(1, HIGHSPEED, FWD, DEGREES);
pros::Motor rightF(2, HIGHSPEED, REV, DEGREES);


Drive::Drive()
{

}

void Drive::drive(int speed, int time)
{
  leftF.move(speed);
  leftB.move(speed);
  rightB.move(speed);
  rightF.move(speed);

  pros::delay(time);
}

void Drive::resetPos()
{
  leftB.tare_position();
  rightB.tare_position();
  rightF.tare_position();
  leftF.tare_position();
}

void Drive::driveBrakeHold()
{
  leftB.set_brake_mode(BRAKE);
  leftF.set_brake_mode(BRAKE);
  rightF.set_brake_mode(BRAKE);
  rightB.set_brake_mode(BRAKE);
}

void Drive::resetBrake()
{
  leftB.set_brake_mode(COAST);
  rightB.set_brake_mode(COAST);
  leftF.set_brake_mode(COAST);
  rightF.set_brake_mode(COAST);

}

void Drive::setZero()
{
  leftF.move(0);
  leftB.move(0);
  rightB.move(0);
  rightF.move(0);
}
