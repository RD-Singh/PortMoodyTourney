#ifndef _VISION_HPP_
#define _VISION_HPP_

#include "main.h"

class Vision
{
  public:

    explicit Vision();
    void visionCorrect(int sig);
    void lowFlag();
    void collectCapBall();
    void collectPlatBall();
    void highLow(int sig);
    void visionPivot(int power, int sig);
    void highFlag(int sig);
    void middleFlag(int sig);
    void visionPID(int power, int e, int sig);
};

#endif
