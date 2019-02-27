#ifndef _VISION_HPP_
#define _VISION_HPP_

#include "main.h"

class Vision
{
  public:

    explicit Vision();
    void visionCorrect(int sig);
    void lowFlag();
    void visionPivot(int power, int sig);
    void flagAlignment();
};

#endif
