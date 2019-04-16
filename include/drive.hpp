#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

class Drive
{
  public:

    explicit Drive();
    void driveBrakeHold();
    void resetBrake();
    void resetPos();
    void ultrasonicPID (int power);
    void sonicReset(int power, int cm);
    void drive(int speed, int intake, int time);
    void setZero();
};


#endif
