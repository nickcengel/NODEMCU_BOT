#ifndef RCWController_h
#define RCWController_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#define BUFFER_LENGTH 32

class RCWController {

public:
  RCWController(const char *ssid, const char *password, uint16_t localPort);
  void begin(WiFiUDP *udp);
  uint8_t GetData();

private:
  WiFiUDP *_udp;
  const char *_ssid;
  const char *_password;
  uint16_t _localPort;
  static uint8_t RCWBuf[];
  IPAddress IP;
};

#endif
