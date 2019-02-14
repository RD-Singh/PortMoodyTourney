#ifndef _MISCELL_HPP_
#define _MISCELL_HPP_

#include "main.h"

class miscell
{
  public:

    explicit miscell();

    void misc(int intakeP, int indexerP, int tipperP, int time);
    void capTip();
    void stop(int time);
    void flyCoast();
    void flywheelAccel(int speed);
};

#endif
