#ifndef _PID_HPP_
#define _PID_HPP_

#include "main.h"

class PID
{
  public:

    explicit PID();

    void turn(double degrees, int speed);
    double checkPower(double power);
    void powerDrive(int powerLeft, int powerRight);
    void turnPID(int power);
    void backPID(int power);
    void movePID(int power);
    void move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP);
};

#endif
