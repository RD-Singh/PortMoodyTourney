#ifndef _MISCELL_HPP_
#define _MISCELL_HPP_

#include "main.h"

class miscell
{
  public:

    explicit miscell();

    void misc(int intakeP, int indexerP, int tipperP, int time);
    int getSpeed();
    void setSpeed(int speed);
    void capTip();
    void stop(int time);
    void platBall();
    void flywheelDrive();
    void flywheel(int x);
    void flyCoast();
    void doubleShot();
    void flywheelAccel(int speed);
};

#endif
