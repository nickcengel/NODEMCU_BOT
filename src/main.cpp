#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <RCWController.h>
#include <WiFiUDP.h>
#include <motr.h>

#define D1 5
#define D2 4
#define D3 0
#define D4 2

void ButtonMove(); // Prototype for button control function

const char *ssid = "DG1670AB2";         // Name of WiFi network
const char *password = "DG1670A74A7B2"; // WiFi network password
const uint16_t localPort = 4242;        // Port that the app is connected to

uint8_t previous = 0; // Previous command value from controller app

WiFiUDP udp; // Create a UDP object to receive messages from app

RCWController Controller(ssid, password,
                         localPort); // Create an object to connect to wifi

Dmotor LeftMotor(D1, D2); // Create motor objects
Dmotor RightMotor(D3, D4);

void setup() {
  RightMotor.begin();
  LeftMotor.begin();

  Controller.begin(&udp);
}

void loop() {
  Controller.GetData();
  delay(5);
  ButtonMove();
}

void ButtonMove() {
  uint8_t direction = Controller.Button();

  if (direction != previous) {
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
      LeftMotor.Go(FORWARDS);
      RightMotor.Go(STOP);
    } break;
    default: {
      LeftMotor.Go(STOP);
      RightMotor.Go(STOP);
    } break;
    }
    previous = direction;
  }
}
