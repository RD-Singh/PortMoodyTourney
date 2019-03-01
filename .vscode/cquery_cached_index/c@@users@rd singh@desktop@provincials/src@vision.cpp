#include "main.h"

pros::Motor leftBDrive(11, HIGHSPEED, FWD, DEGREES);
pros::Motor rightBDrive(13, HIGHSPEED, REV, DEGREES);
pros::Motor leftFDrive(1, HIGHSPEED, FWD, DEGREES);
pros::Motor rightFDrive(2, HIGHSPEED, REV, DEGREES);
pros::Motor flywhl(10, HIGHSPEED, REV, DEGREES);

pros::Controller master(MAIN);

pros::Vision vision (8);

static PID * pid = new PID();
static Drive * DRIVE = new Drive();

Vision::Vision()
{

}

/*void Vision::lowFlag()
{
  int midx = 158;

  bool lowFlag = true;

  int x;

  while(lowFlag)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, 2);
    x = obj.x_middle_coord;

    if(x < (midx))
    {
      leftBDrive.move(-40);
      leftFDrive.move(-40);
      rightFDrive.move(40);
      rightBDrive.move(40);
    }
    if (x > (midx + 1))
    {
      leftBDrive.move(40);
      leftFDrive.move(40);
      rightFDrive.move(-40);
      rightBDrive.move(-40);
    }
    else
    {
      lowFlag = false;
      DRIVE->setZero();
    }
  }
}

void Vision::visionPivot(int power, int sig)
{
  int x;
  bool linedUp = true;
  int midX = 158;

  while(linedUp)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, sig);
    x = obj.x_middle_coord;

    if(x != (midX - 1))
    {
      pid->turnPID(power);
    }
    else
    {
      linedUp = false;
      DRIVE->setZero();
    }

    pros::lcd::set_text(5, "The Current Number is: " + std::to_string(x));

  }
}*/

void Vision::visionCorrect(int sig)
{
  int midX = 158;

  bool linedUp = true;

  int x;

  while(linedUp)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, sig);
    x = obj.x_middle_coord;

    if(x < (midX - 1))
    {
      leftBDrive.move(-20);
      leftFDrive.move(-20);
      rightFDrive.move(20);
      rightBDrive.move(20);
    }
    else if(x > (midX + 1))
    {
      leftBDrive.move(20);
      leftFDrive.move(20);
      rightFDrive.move(-20);
      rightBDrive.move(-20);
    }
    else
    {
      linedUp = false;
      DRIVE->setZero();
    }

    pros::lcd::set_text(5, "The Current Number is: " + std::to_string(x));

  }
}


void Vision::flagAlignment()
{
  int midX = 158;

  int x;

    pros::vision_object_s_t obj = vision.get_by_sig(0, 1);
    x = obj.x_middle_coord;

    if(x < (midX - 3))
    {
      master.rumble("-");
    }
    else if(x > (midX + 3))
    {
      master.rumble("-");
    }

}
