
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#include "RCWController.h"

RCWController::RCWController(const char *ssid, const char *password,
                             uint16_t localPort) {
  _ssid = ssid;
  _password = password;
  _localPort = localPort;
};

uint8_t RCWController::RCWBuf[BUFFER_LENGTH];

void RCWController::begin(WiFiUDP *udp) {
  Serial.begin(115200);
  Serial.println("Connecting to");
  WiFi.softAP(_ssid, _password);
  IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  _udp = udp;
  _udp->begin(_localPort);
  Serial.print("Local port: ");
  Serial.println(_udp->localPort());
  delay(2000);
  _udp->flush();
};

uint8_t RCWController::GetData() {
  uint16_t DataIn;
  while (1) {
    DataIn = _udp->parsePacket();
    if (DataIn < 10) {
      delay(1);
      break;
    }
    _udp->read(RCWBuf, (DataIn > BUFFER_LENGTH) ? BUFFER_LENGTH : DataIn);
    _udp->flush();
    break;
  }
  delay(8);
  return 0;
};