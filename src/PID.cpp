#include "main.h"

pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
pros::Motor backR(13, HIGHSPEED, REV, DEGREES);
pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);
pros::Motor flyWheel(10, TURBO, REV, DEGREES);

pros::Motor tipper(3, HIGHSPEED, FWD, DEGREES);
pros::Motor intake(9, HIGHSPEED, REV, DEGREES);
pros::Motor indexer(14, HIGHSPEED, REV, DEGREES);

pros::ADIGyro leftGyro ('A');

static miscell * misc = new miscell();
static Drive * driveMtrs = new Drive();
static Vision * v = new Vision();

PID::PID()
{

}

void PID::turnPID(int power)
{
  double kp = 0.75;
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

void PID::movePID(int initPower)
{
  double kp = 0.387;
  double kd = 0.395;

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

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);
}

void PID::backPID(int power)
{
  double kp = 0.735;

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

    frontL.move(powerLeft);
    frontR.move(powerRight);
    backL.move(powerLeft);
    backR.move(powerRight);
}

void PID::turn(double degrees, int speed)
{
  driveMtrs->resetPos();

  double kw = 2.686;

  double currentBearing = 0;
  double error = 10;
  double targetBearing = degrees * kw;

  int left, right;

  while(error != 0)
  {
    left = abs(frontL.get_position());
    right = abs(frontR.get_position());

    currentBearing = (left + right)/2;

    error = targetBearing - currentBearing;

    turnPID(speed);

    if(error < 5 && error > -5)
    {
      error = 0;
      driveMtrs->driveBrakeHold();
      driveMtrs->setZero();
    }
  }
  driveMtrs->setZero();
  driveMtrs->resetPos();
}


void PID::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP)
{
  int currentDistance = 0;
  double error = 20, lastError = 0, derivative;

  int targ = (targetDistance/12.566) * 360;

  int leftF, rightF;

  int MAX_POWER = maxPower, MIN_POWER = 15;

  double kp = 0.365, kd = 0.385;

  driveMtrs->resetPos();

  int power = 0, paramPower;

  if(maxPower > 0)
  {
    power = 4;
    while(power < maxPower)
    {
      power*=1.575;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
      pros::delay(50);
    }
  }
  else if(maxPower < 0)
  {
    power = -4;
    while(power > -maxPower)
    {
      power*=1.325;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
      pros::delay(50);
    }
  }

 while(error != 0)
 {
    leftF = abs(frontL.get_position());
    rightF = abs(frontR.get_position());

    currentDistance = (leftF + rightF)/2;

    error = targ - currentDistance;
    derivative = error - lastError;
    lastError = error;


    paramPower = (error * kp) + (derivative * kd);

    if(maxPower < 0)
    {
      paramPower = -paramPower;
    }

    if(paramPower > 0)
    {
      if (paramPower > MAX_POWER)
      {
        paramPower = maxPower;
      }
      else if(paramPower < MIN_POWER)
      {
        paramPower = MIN_POWER;
      }
    }
    else if(paramPower < 0)
    {
      if (paramPower < MAX_POWER)
      {
        paramPower = maxPower;
      }
      else if(paramPower > -MIN_POWER)
      {
        paramPower = -MIN_POWER;
      }
    }

    intake.move(intakeP);
    indexer.move(indexerP);

    flyWheel.move(flyWheelP);

    tipper.move(tipperP);

    if(maxPower > 0)
    {
      movePID(paramPower);
    }
    else if(maxPower < 0)
    {
      backPID(paramPower);
    }

      if(error < 10 && error > -10)
      {
        driveMtrs->setZero();
        driveMtrs->driveBrakeHold();
        misc->flyCoast();
        error = 0;
      }

      pros::delay(5);
  }
  driveMtrs->resetPos();

  intake.move(0);
}
