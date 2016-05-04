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

Dmotor LeftMotor(5, 4);  // D1, D2
Dmotor RightMotor(0, 2); // D3, D4

void setup() {
  LeftMotor.begin();
  RightMotor.begin();

  Controller.begin(&udp);
}

void loop() {
  uint8_t data = Controller.GetData();
  uint8_t direction = Controller.Button();

  switch (direction) {
  case FORWARDS: {
    LeftMotor.Go(FORWARDS);
    RightMotor.Go(FORWARDS);
  } break;
  case BACKWARDS: {
    LeftMotor.Go(BACKWARDS);
    RightMotor.Go(BACKWARDS);
  } break;
  case LEFT: {
    LeftMotor.Go(STOP);
    RightMotor.Go(FORWARDS);
  } break;
  case RIGHT: {
    LeftMotor.Go(BACKWARDS);
    RightMotor.Go(BACKWARDS);
  } break;
  default: {
    LeftMotor.Go(STOP);
    RightMotor.Go(STOP);
  } break;
  }
}
