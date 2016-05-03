#include "RCWController.h"
#include "arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include <motr.h>

const char *ssid = "DG1670AB2";         // Name of WiFi network
const char *password = "DG1670A74A7B2"; // WiFi network password
const uint16_t localPort = 10000;       // Port that the app is connected to

WiFiUDP udp; // Create a UDP object to receive messages from app

RCWController Controller(ssid, password, localPort);

motr Lmotor(5, 4); // D1, D2
motr Rmotor(0, 2); // D3, D4

void setup() {
  Lmotor.STOP();
  Rmotor.STOP();

  Controller.begin(&udp);
}

void loop() {
  uint8_t data = Controller.GetData();

  switch (Controller.Button()) {
  case FORWARDS:
    Lmotor.GO(1, 200);
    Rmotor.GO(1, 200);
    break;
  case BACKWARDS:
    Lmotor.GO(0, 200);
    Rmotor.GO(0, 200);
    break;
  case LEFT:
    Lmotor.GO(1, 20);
    Rmotor.GO(1, 200);
    break;
  case RIGHT:
    Lmotor.GO(1, 200);
    Rmotor.GO(1, 20);
  default:
    Lmotor.STOP();
    Rmotor.STOP();
  }
}
