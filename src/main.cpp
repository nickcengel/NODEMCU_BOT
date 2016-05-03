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

void setup() { Controller.begin(&udp); }

void loop() { uint8_t data = Controller.GetData(); }
