#include "main.h"


pros::Motor leftB(11, HIGHSPEED, FWD, DEGREES);
pros::Motor rightB(13, HIGHSPEED, REV, DEGREES);
pros::Motor leftF(1, HIGHSPEED, FWD, DEGREES);
pros::Motor rightF(2, HIGHSPEED, REV, DEGREES);
pros::Motor ball(9, HIGHSPEED, REV, DEGREES);

Drive::Drive()
{

}

void Drive::sonicReset(int power, int cm)
{
  pros::ADIUltrasonic leftW ('C', 'D');
  pros::ADIUltrasonic rightW ('E', 'F');
  pros::ADIUltrasonic front ('G', 'H');

  int left;
  int right;
  int diff;
  int tp;
  int error = 1;

  driveBrakeHold();

  while(error != 0)
  {
    left = leftW.get_value();
    right = rightW.get_value();

    error = ((left + right)/2) - (cm * 10);

    pros::lcd::set_text(4, "left = " + std::to_string(left));
    pros::lcd::set_text(5, "right = " + std::to_string(right));

    leftF.move(power);
    leftB.move(power);
    rightB.move(power);
    rightF.move(power);

    if(error < 15 && error > -15)
    {
      error = 0;
      setZero();
    }
  }
}

void Drive::drive(int speed, int intake, int time)
{
  leftF.move(speed);
  leftB.move(speed);
  rightB.move(speed);
  rightF.move(speed);
  ball.move(intake);

  pros::delay(time);

  leftF.move(0);
  leftB.move(0);
  rightB.move(0);
  rightF.move(0);
  ball.move(0);
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
