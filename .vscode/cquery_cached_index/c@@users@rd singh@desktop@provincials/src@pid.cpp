#include "main.h"

pros::Motor backL(11, HIGHSPEED, FWD, DEGREES);
pros::Motor backR(12, HIGHSPEED, REV, DEGREES);
pros::Motor frontL(1, HIGHSPEED, FWD, DEGREES);
pros::Motor frontR(2, HIGHSPEED, REV, DEGREES);
pros::Motor flyWheel(10, HIGHSPEED, FWD, DEGREES);

pros::Motor tipper(9, HIGHSPEED, FWD, DEGREES);
pros::Motor intake(3, HIGHSPEED, REV, DEGREES);
pros::Motor indexer(4, HIGHSPEED, REV, DEGREES);
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
  backL.set_brake_mode(HOLD);
  frontL.set_brake_mode(BRAKE);
  frontR.set_brake_mode(BRAKE);
  backR.set_brake_mode(HOLD);
}



/*void PID::driveBrakeHold()
{
  PID::resetBrake();
  PID::drive(-5, 200);
}*/

void PID::resetBrake()
{
  backL.set_brake_mode(COAST);
  backR.set_brake_mode(COAST);
  frontL.set_brake_mode(COAST);
  frontR.set_brake_mode(COAST);

}

/*void PID::turnPID(int power)
{
  double kp = 0.6485;

  int main = 0;
  int secondary = 0;
  int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 1;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
 main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
 secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());

 error = main - secondary;

  if(main > secondary)
  {
      power = power - error * kp;
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
}*/

void PID::movePID(int power)
{
  double kp = 0.65;

 int main = 0;
 int secondary = 0;
 int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 10;
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

void PID::turn(int bearing, int speed)
{
  gyro.reset();

  float kp = 0;
	float ki = 0;
	float kd = 0;

	float integral = 0;
	float derivative = 0;

	float lastError = 0;
	float power = 0;
	int powerLeft = 0;
	int powerRight = 0;
  int MAX_POWER = 121;
  int MIN_POWER = 40;

	float error = 1;
	float currentBearing;
	float targetBearing = bearing * 10;

	while(error != 0)
	{
    currentBearing = gyro.get_value();

		error = targetBearing - currentBearing;

		power = speed - (error * kp);

		if(power > 0)
		{
			if(power > MAX_POWER)
			{
				power = MAX_POWER;
			}
			else if(power < MIN_POWER)
			{
				power = MIN_POWER;
			}
		}

		else if(power < 0)
		{
			if(power < -MAX_POWER)
			{
				power = -MAX_POWER;
			}
			else if(power > -MIN_POWER)
			{
				power = -MIN_POWER;
			}
		}
		powerLeft = (error >= 0) ? power : -power;
		powerRight = (error >= 0) ? -power : power;

		frontL.move(powerLeft);
    backL.move(powerLeft);
    frontR.move(powerRight);
    backR.move(powerRight);
	}

  gyro.reset();
}

void PID::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP)
{
  int currentDistance = 0;
  double error = 20;

  int targ = (targetDistance/12.566) * 360;

  int leftF, rightF;

  PID::resetPos();


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

    PID::movePID(maxPower);

    if(error < 10 && error > -10)
    {
      error = 0;
      PID::setZero();
      PID::driveBrakeHold();
      misc->flyCoast();
    }
  }
  PID::resetPos();

  intake.move(0);
}
