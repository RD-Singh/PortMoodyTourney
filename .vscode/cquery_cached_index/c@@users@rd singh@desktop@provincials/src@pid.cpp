#include "main.h"

pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
pros::Motor backR(13, HIGHSPEED, REV, DEGREES);
pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);
pros::Motor flyWheel(10, TURBO, REV, DEGREES);

pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
pros::Motor intake(3, HIGHSPEED, REV, DEGREES);
pros::Motor indexer(14, HIGHSPEED, REV, DEGREES);

pros::ADIGyro leftGyro ('B');
pros::ADIGyro rightGyro ('C');

static miscell * misc = new miscell();
static Drive * driveMtrs = new Drive();
static Vision * v = new Vision();

PID::PID()
{

}

void PID::turnPID(int power)
{
  double kp = 0.78;
  int main = 0;
  int secondary = 0;
  int error = 1;
  int powerLeft, powerRight;
  int maxPower = power;
  int MIN_POWER = maxPower - 4;

  main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
  secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());
  error = main - secondary;

  if(main > secondary)
  {
      power = power - (error * kp);
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

  if(abs(frontR.get_position()) > abs(frontL.get_position()))
  {
    powerLeft = -maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = -power;
    powerRight = maxPower;
  }

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);

}

void PID::movePID(int initPower, int e)
{
  double kp = 0.9;
  double kd = 0;//615;

  int main = 0;
  int secondary = 0;
  int error = 0;
  int powerLeft, powerRight;
  int derivative;
  int lastError = 0;

  int maxPower = initPower;
  int MIN_POWER = maxPower - 2;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
  main = ((frontR.get_position()) >= (frontL.get_position())) ? (frontR.get_position()) : (frontL.get_position());
  secondary = ((frontR.get_position()) >= (frontL.get_position())) ? (frontL.get_position()) : (frontR.get_position());

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

  if(frontR.get_position() > frontL.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }

  if(e < 300)
  {
    frontL.move(powerLeft - 30);
    frontR.move(powerRight - 30);
    backL.move(powerLeft - 30);
    backR.move(powerRight - 30);

    if(e < 250)
    {
      frontL.move(powerLeft - 60);
      frontR.move(powerRight - 60);
      backL.move(powerLeft - 60);
      backR.move(powerRight - 60);

      if(e < 200)
      {
        frontL.move(powerLeft - 90);
        frontR.move(powerRight - 90);
        backL.move(powerLeft - 90);
        backR.move(powerRight - 90);
      }
    }
  }

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);
}

void PID::backPID(int power, int e)
{
  double kp = 0.6775;

 int main = 0;
 int secondary = 0;
 int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 5;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
 main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
 secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());

 error = main - secondary;

  if(main > secondary)
  {
     power = power - (error * kp);
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

  if(frontR.get_position() > frontL.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }

  if(e < 300)
  {
    frontL.move(powerLeft + 30);
    frontR.move(powerRight + 30);
    backL.move(powerLeft + 30);
    backR.move(powerRight + 30);

    if(e < 250)
    {
      frontL.move(powerLeft + 60);
      frontR.move(powerRight + 60);
      backL.move(powerLeft + 60);
      backR.move(powerRight + 60);

      if(e < 200)
      {
        frontL.move(powerLeft + 90);
        frontR.move(powerRight + 90);
        backL.move(powerLeft + 90);
        backR.move(powerRight + 90);
      }
    }
  }
  else
  {
    frontL.move(powerLeft);
    frontR.move(powerRight);
    backL.move(powerLeft);
    backR.move(powerRight);
  }
}

void PID::turn(char direction, double degrees, int speed)
{
  driveMtrs->resetPos();

  double currentBearing = 0;
  double error = 10;
  double targetBearing = degrees * 10;

  int left, right;

  while(error != 0)
  {
    left = leftGyro.get_value();
    right = rightGyro.get_value();

    currentBearing = (left + right)/2;

    error = targetBearing - currentBearing;

    if(direction == 'L')
    {

    }
    else if(direction == 'R')
    {

    }
    turnPID(speed);

    if(error < 5 && error > -5)
    {
      error = 0;
      driveMtrs->driveBrakeHold();
      driveMtrs->setZero();
    }
  }
  driveMtrs->setZero();
  leftGyro.reset();
  rightGyro.reset();
  driveMtrs->resetPos();
}

void PID::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP, int sig)
{
  int currentDistance = 0;
  double error = 20;

  int targ = (targetDistance/12.566) * 360;

  int leftF, rightF;

  int MAX_POWER = maxPower;

  double kp = 0.95;

  driveMtrs->resetPos();

  int power = 5, paramPower;

  if(maxPower > 0)
  {
    while(power < 105)
    {
      power*=1.36;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
      pros::delay(50);
    }
  }
  else if(maxPower < 0)
  {
    for(int i = 0; i>=(maxPower + 40); i--)
    {
      power*=1.0475;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
    }
  }

 while(error != 0)
 {
    leftF = abs(frontL.get_position());
    rightF = abs(frontR.get_position());

    currentDistance = (leftF + rightF)/2;

    error = targ - currentDistance;

    paramPower = error * kp;

    if (paramPower > MAX_POWER)
    {
      paramPower = maxPower;
    }
    
    intake.move(intakeP);
    indexer.move(indexerP);

    flyWheel.move(flyWheelP);

    tipper.move(tipperP);

    if(maxPower > 0)
    {
      movePID(paramPower, error);
    }
    else if(maxPower < 0)
    {
      backPID(paramPower, error);
    }

      if(error < 10 && error > -10)
      {
        driveMtrs->setZero();
        driveMtrs->driveBrakeHold();
        misc->flyCoast();
        error = 0;
      }

  }
  driveMtrs->resetPos();

  intake.move(0);
}
