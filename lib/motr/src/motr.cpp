#include <arduino.h>
#include <motr.h>

Amotor::Amotor(uint8_t pinA, uint8_t pinB) {
  pinA_ = pinA;
  pinB_ = pinB;
};
void Amotor::begin() {
  pinMode(pinA_, OUTPUT);
  pinMode(pinB_, OUTPUT);
  digitalWrite(pinA_, 1);
  digitalWrite(pinB_, 1);
}

void Amotor::Go(uint8_t direction, uint16_t speed) {

  direction_ = direction;
  speed_ = speed;

  if (direction_ == FORWARDS) {
    digitalWrite(pinA_, 0);
    analogWrite(pinB_, speed_);
  }
  if (direction_ == BACKWARDS) {

    digitalWrite(pinB_, 0);
    analogWrite(pinA_, speed_);
  }
};

void Amotor::Stop() {
  digitalWrite(pinA_, 1);
  analogWrite(pinB_, 1);
};

Dmotor::Dmotor(uint8_t pinA, uint8_t pinB) {
  pinA_ = pinA;
  pinB_ = pinB;
};

void Dmotor::begin() {
  pinMode(pinA_, OUTPUT);
  pinMode(pinB_, OUTPUT);
  digitalWrite(pinA_, 1);
  digitalWrite(pinB_, 1);
};

void Dmotor::Go(uint8_t direction) {
  direction_ = direction;
  switch (direction_) {
  case FORWARDS: {
    digitalWrite(pinA_, 1);
    digitalWrite(pinB_, 0);
  } break;
  case BACKWARDS: {
    digitalWrite(pinA_, 0);
    digitalWrite(pinB_, 1);
  } break;
  case STOP: {
    digitalWrite(pinA_, 1);
    digitalWrite(pinB_, 1);
  } break;
  default: {
    digitalWrite(pinA_, 1);
    digitalWrite(pinB_, 1);
  } break;
  }
};
