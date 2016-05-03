#ifndef RCWController_h
#define RCWController_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#define BUFFER_LENGTH 256

#define XDirection 0
#define YDirection 1
#define FORWARDS 1
#define BACKWARDS 2
#define RIGHT 4
#define LEFT 8
#define AA 32
#define BB 64
#define YY 16
#define XX 256

class RCWController {

public:
  RCWController(const char *ssid, const char *password, uint16_t localPort);
  void begin(WiFiUDP *udp);
  uint8_t GetData();
  uint8_t Button();
  uint8_t joyStick1(boolean whatdirection);
  uint8_t joyStick2(boolean whatdirection);
  uint8_t Accelerometer(boolean whatdirection);

private:
  WiFiUDP *_udp;
  const char *_ssid;
  const char *_password;
  uint16_t _localPort;
  static uint8_t RCWBuf[];
  IPAddress IP;
};

#endif
