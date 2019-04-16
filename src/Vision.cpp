#include "main.h"

pros::Motor leftBDrive(11, HIGHSPEED, FWD, DEGREES);
pros::Motor rightBDrive(13, HIGHSPEED, REV, DEGREES);
pros::Motor leftFDrive(1, HIGHSPEED, FWD, DEGREES);
pros::Motor rightFDrive(2, HIGHSPEED, REV, DEGREES);
pros::Motor flywhl(10, HIGHSPEED, REV, DEGREES);
pros::Motor intak(9, HIGHSPEED, REV, DEGREES);


pros::Controller master(MAIN);

pros::Vision vision (8);
pros::Vision vision2 (6);

static PID * pid = new PID();
static Drive * dr = new Drive();

Vision::Vision()
{

}

void Vision::lowFlag()
{
  int midx = 158;

  bool lowFlag = true;

  int x;

  while(lowFlag)
  {
    pros::vision_object_s_t obj = vision2.get_by_sig(0, 3);
    x = obj.x_middle_coord;

    if(x < (midx - 3))
    {
      leftBDrive.move(-40);
      leftFDrive.move(-40);
      rightFDrive.move(40);
      rightBDrive.move(40);
    }
    if (x > (midx + 3))
    {
      leftBDrive.move(40);
      leftFDrive.move(40);
      rightFDrive.move(-40);
      rightBDrive.move(-40);
    }
    else
    {
      lowFlag = false;
      dr->setZero();
    }
  }
}

void Vision::visionPID(int initPower, int e, int sig)
{
  double kp = 0.675;
  double kd = 0;//0.5;

  pros::vision_object_s_t obj = vision.get_by_sig(0, sig);

  int x = obj.x_middle_coord;

  int main = 0, secondary = 0, error = 0, lastError = 0;
  int powerLeft, powerRight;
  int derivative;
  int midx = 158;

  int maxPower = initPower;
  int MIN_POWER = maxPower - 4;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
  main = ((rightFDrive.get_position()) >= (leftFDrive.get_position())) ? (rightFDrive.get_position()) : (leftFDrive.get_position());
  secondary = ((rightFDrive.get_position()) >= (leftFDrive.get_position())) ? (leftFDrive.get_position()) : (rightFDrive.get_position());

  error = (main - secondary);
  derivative = error - lastError;
  lastError = error;
  int power = 0;


    if(main > secondary)
    {
       power = (error * kp) + (derivative * kd);
    }

    if(power > 0)
    {
      if(power < MIN_POWER)
      {
        power = MIN_POWER;
      }
    }
    else if(power < 0)
    {
      if(power > -MIN_POWER)
      {
        power = -MIN_POWER;
      }
    }

    if(midx > x)
    {
      powerLeft = maxPower;
      powerRight = power;
    }
    else if (midx < x)
    {
      powerLeft = power;
      powerRight = maxPower;
    }

      leftFDrive.move(powerLeft);
      rightFDrive.move(powerRight);
      leftBDrive.move(powerLeft);
      rightBDrive.move(powerRight);

}

void Vision::visionCorrect(int sig)
{
  int midX = 158;

  bool linedUp = true;

  int x;

  while(linedUp)
  {
    pros::vision_object_s_t obj = vision2.get_by_sig(0, sig);
    x = obj.x_middle_coord;

    if(x < (midX - 4))
    {
      leftBDrive.move(-20);
      leftFDrive.move(-20);
      rightFDrive.move(20);
      rightBDrive.move(20);
    }
    else if(x > (midX + 4))
    {
      leftBDrive.move(20);
      leftFDrive.move(20);
      rightFDrive.move(-20);
      rightBDrive.move(-20);
    }
    else
    {
      linedUp = false;
      dr->setZero();
    }

    pros::lcd::set_text(5, "The Current Number is: " + std::to_string(x));

  }
}

void Vision::highFlag(int sig)
{

  bool inPosition = true;
  dr->driveBrakeHold();
  while(inPosition)
  {
    pros::vision_object_s_t obj = vision2.get_by_sig(0, sig);

    int y = obj.top_coord;

    if(y > 119)
    {
      leftBDrive.move(50);
      leftFDrive.move(50);
      rightFDrive.move(50);
      rightBDrive.move(50);
    }
    else if(y < 115)
    {
      leftBDrive.move(-50);
      leftFDrive.move(-50);
      rightFDrive.move(-50);
      rightBDrive.move(-50);
    }
    else
    {
      inPosition = false;
      dr->setZero();
    }
  }
}

void Vision::middleFlag(int sig)
{

  bool inPosition = true;
  dr->driveBrakeHold();

  while(inPosition)
  {
    pros::vision_object_s_t obj = vision2.get_by_sig(0, sig);

    int y = obj.top_coord;

    if(y > 71)
    {
      leftBDrive.move(50);
      leftFDrive.move(50);
      rightFDrive.move(50);
      rightBDrive.move(50);
    }
    else if(y < 65)
    {
      leftBDrive.move(-50);
      leftFDrive.move(-50);
      rightFDrive.move(-50);
      rightBDrive.move(-50);
    }
    else
    {
      inPosition = false;
      dr->setZero();
    }
  }
}

void Vision::collectCapBall()
{

  bool inPosition = true;
  dr->driveBrakeHold();

  int midX = 158;

  int x;

  while(inPosition)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, 3);
    x = obj.x_middle_coord;

    if(x < (midX - 3))
    {
      leftBDrive.move(-30);
      leftFDrive.move(-30);
      rightFDrive.move(30);
      rightBDrive.move(30);
    }
    else if(x > (midX + 3))
    {
      leftBDrive.move(30);
      leftFDrive.move(30);
      rightFDrive.move(-30);
      rightBDrive.move(-30);
    }
    else
    {
      inPosition = false;
      dr->setZero();
    }
  }

  pros::delay(300);

  while(inPosition)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, 3);

    int y = obj.top_coord;

    if(y < 180)
    {
      leftBDrive.move(50);
      leftFDrive.move(50);
      rightFDrive.move(50);
      rightBDrive.move(50);
    }
    else
    {
      inPosition = false;
      dr->setZero();
    }
  }

  leftBDrive.move(40);
  leftFDrive.move(40);
  rightFDrive.move(40);
  rightBDrive.move(40);
  intak.move(95);

  pros::delay(1200);

  leftBDrive.move(0);
  leftFDrive.move(0);
  rightFDrive.move(0);
  rightBDrive.move(0);
  intak.move(65);

  pros::delay(300);

  leftBDrive.move(-50);
  leftFDrive.move(-50);
  rightFDrive.move(-50);
  rightBDrive.move(-50);
  intak.move(95);

  pros::delay(500);

  leftBDrive.move(0);
  leftFDrive.move(0);
  rightFDrive.move(0);
  intak.move(0);
  rightBDrive.move(0);

}
