/*
  motr.h - Library for controlling DC motors
*/
#ifndef motr_h
#define motr_h

#include <arduino.h>
#include <string.h>
#define STOP 0
#define FORWARDS 1
#define BACKWARDS 2

class Amotor {
public:
  Amotor(uint8_t pinA, uint8_t pinB);
  void begin();
  void Go(boolean direction, uint16_t speed);
  void Stop();

private:
  uint8_t pinA_, pinB_;
  boolean direction_;
  uint16_t speed_;
};

class Dmotor {
public:
  Dmotor(uint8_t pinA, uint8_t pinB);
  void begin();
  void Go(uint8_t direction);

private:
  uint8_t pinA_, pinB_;
  uint8_t direction_;
};

#endif
