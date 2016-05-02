#include <arduino.h>
#include <motr.h>

motr::motr(int pinA, int pinB)
{
  pinA_ = pinA;
  pinB_ = pinB;
}

void motr::GO(bool direction, int speed)
{
  direction_ = direction;
  speed_ =768 - 3*speed +20;

  if(direction_)
  {
    digitalWrite(pinA_, 0);
    analogWrite(pinB_, speed_);
  }
  else
  {
    digitalWrite(pinB_, 0);
    analogWrite(pinA_, speed_);

  }

}

void motr::STOP()
{
  digitalWrite(pinA_, 1);
  analogWrite(pinB_, 1);
}
