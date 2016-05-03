#include <arduino.h>
#include <motr.h>

motr::motr(int pinA, int pinB) {
  pinA_ = pinA;
  pinB_ = pinB;
}

void motr::GO(bool direction, int speed) {
  pinMode(pinA_, OUTPUT);
  pinMode(pinB_, OUTPUT);
  direction_ = direction;
  speed_ = speed;

  if (direction_) {
    digitalWrite(pinA_, 0);
    analogWrite(pinB_, speed_);
  } else {
    digitalWrite(pinB_, 0);
    analogWrite(pinA_, speed_);
  }
}

void motr::STOP() {
  pinMode(pinA_, OUTPUT);
  pinMode(pinB_, OUTPUT);
  digitalWrite(pinA_, 1);
  analogWrite(pinB_, 1);
}
