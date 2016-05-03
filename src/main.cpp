#include "RCWController.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include <motr.h>

const char *ssid = "DG1670AB2";         // Name of WiFi network
const char *password = "DG1670A74A7B2"; // WiFi network password
const uint16_t localPort = 10000;       // Port that the app is connected to

WiFiUDP udp; // Create a UDP object to receive messages from app

RCWController Controller(ssid, password, localPort);

// motr Lmotor(5, 4); // D1, D2
// motr Rmotor(0, 2); // D3, D4

void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(5, 1);
  digitalWrite(4, 1);
  digitalWrite(0, 1);
  digitalWrite(2, 1);
  // Lmotor.STOP();
  // Rmotor.STOP();

  Controller.begin(&udp);
}

void loop() {

  uint8_t data = Controller.GetData();

  uint8_t direction = Controller.Button();

  //  Serial.println(direction);

  switch (direction) {
  case 0: {
    digitalWrite(5, 1);
    digitalWrite(4, 1);

    digitalWrite(0, 1);
    digitalWrite(2, 1);
  }

  break;
  case 1: {
    digitalWrite(5, 1);
    digitalWrite(4, 0);

    digitalWrite(0, 1);
    digitalWrite(2, 0);
  } break;
  case 2: {
    digitalWrite(5, 0);
    digitalWrite(4, 1);

    digitalWrite(0, 0);
    digitalWrite(2, 1);
  } break;
  case 8: {
    digitalWrite(5, 1);
    digitalWrite(4, 1);

    digitalWrite(0, 1);
    digitalWrite(2, 0);
  } break;
  case 4: {
    digitalWrite(5, 1);
    digitalWrite(4, 0);

    digitalWrite(0, 1);
    digitalWrite(2, 1);
  } break;

  default: {
    digitalWrite(5, 1);
    digitalWrite(4, 1);

    digitalWrite(0, 1);
    digitalWrite(2, 1);
  } break;
  }
}
