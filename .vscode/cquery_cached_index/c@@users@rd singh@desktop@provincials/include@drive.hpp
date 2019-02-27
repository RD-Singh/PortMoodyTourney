#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

class Drive
{
  public:

    explicit Drive();
    void driveBrakeHold();
    void resetBrake();
    void resetPos();
    void drive(int speed, int time);
    void setZero();
};


#endif
