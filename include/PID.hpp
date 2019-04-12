#ifndef _PID_HPP_
#define _PID_HPP_

#include "main.h"

class PID
{
  public:

    explicit PID();
    void turn(char direction, double degrees, int speed);
    void turnPID(int power);
    void backPID(int power, int error);
    void movePID(int power, int error);
    void move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP, int sig);
};

#endif
