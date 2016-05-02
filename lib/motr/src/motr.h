/*
  motr.h - Library for controlling DC motors
*/
#ifndef motr_h
#define motr_h

#include <arduino.h>
#include <string.h>

class motr
{
  public:
    motr(int pinA, int pinB);
    void GO(bool direction, int speed);
    void STOP();

  private:
    int pinA_, pinB_, direction_, speed_;
};

#endif
