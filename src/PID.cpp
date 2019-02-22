#include "main.h"

pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
pros::Motor backR(12, HIGHSPEED, REV, DEGREES);
pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);
pros::Motor flyWheel(10, HIGHSPEED, REV, DEGREES);

pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
pros::Motor intake(3, HIGHSPEED, REV, DEGREES);
pros::Motor indexer(4, HIGHSPEED, REV, DEGREES);
pros::adi_port_config_e_t E_ADI_LEGACY_GYRO;

pros::ADIGyro gyro ('A');

static miscell * misc = new miscell();
PID::PID()
{

}

void PID::drive(int speed, int time)
{
  frontL.move(speed);
  backL.move(speed);
  backR.move(speed);
  frontR.move(speed);

  pros::delay(time);
}

void PID::resetPos()
{
  backL.tare_position();
  backR.tare_position();
  frontR.tare_position();
  frontL.tare_position();
}

void PID::resetSensor(int target)
{
  frontL.set_zero_position(target);
  backR.set_zero_position(target);
  backL.set_zero_position(target);
  frontR.set_zero_position(target);
  gyro.reset();
}

void PID::driveBrakeHold()
{
  backL.set_brake_mode(BRAKE);
  frontL.set_brake_mode(BRAKE);
  frontR.set_brake_mode(BRAKE);
  backR.set_brake_mode(BRAKE);
}

void PID::resetBrake()
{
  backL.set_brake_mode(COAST);
  backR.set_brake_mode(COAST);
  frontL.set_brake_mode(COAST);
  frontR.set_brake_mode(COAST);

}

void PID::turnPID(int power)
{
  double kp = 0.6595;
  int main = 0;
  int secondary = 0;
  int error = 1;
  int powerLeft, powerRight;
  int maxPower = power;
  int MIN_POWER = maxPower - 1;

  main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
  secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());
  error = main - secondary;

  if(main > secondary)
  {
      power = (error * kp);
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
  double kp = 0.758;
  double kd = 0.535;

  int main = 0;
  int secondary = 0;
  int error = 300;
  int powerLeft, powerRight;
  int derivative;
  int lastError = 0;

  int maxPower = initPower;
  int MIN_POWER = maxPower - 4;
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
  frontR.move(powerRight - 4);
  backL.move(powerLeft);
  backR.move(powerRight - 4);
}

void PID::backPID(int power)
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

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);
}

void PID::setZero()
{
  frontL.move(0);
  backL.move(0);
  backR.move(0);
  frontR.move(0);
}

void PID::turn(int degrees, int speed)
{
  resetPos();

  double kw = 2.6;

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
      driveBrakeHold();
      setZero();
    }
  }
  setZero();
  resetPos();
}

void PID::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP)
{
  int currentDistance = 0;
  double error = 20;

  int targ = (targetDistance/12.566) * 360;

  int leftF, rightF;
  resetPos();

 while(error != 0)
 {
    leftF = abs(frontL.get_position());
    rightF = abs(frontR.get_position());

    currentDistance = (leftF + rightF)/2;

    error = targ - currentDistance;

    intake.move(intakeP);
    indexer.move(indexerP);

    flyWheel.move(flyWheelP);

    tipper.move(tipperP);

    if(maxPower > 0)
    {
      movePID(maxPower);
    }
    else if(maxPower < 0)
    {
      backPID(maxPower);
    }

    if(error < 40 && error > -40)
    {
      setZero();
      driveBrakeHold();
      misc->flyCoast();
      error = 0;
    }
  }
  resetPos();

  intake.move(0);
}
