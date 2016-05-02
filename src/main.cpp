#include <arduino.h>
#include <motr.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

const char* ssid     = "DG1670AB2"; // Name of WiFi network
const char* password = "DG1670A74A7B2"; // WiFi network password

WiFiUDP udp;  // Create a UDP object to receive messages

uint16_t localPort = 10000; // Port the app is connected to

const uint16_t BufferLength = 256;  // Size of the array to store the incoming data

uint8_t Buffer[BufferLength]; // Array to store the incoming data

IPAddress IP; // Stores the local IP Adress

motr LeftMotor(D1,D2);  // Motor object to control the left motor on D1, D2
motr RightMotor(D3,D4); // Motor object to control the RIGHT motor on D3, D4

void setup()
{
  LeftMotor.STOP();
  RightMotor.STOP();

  Serial.begin(115200);
  delay(100);
  Serial.println("this");
  WiFi.softAP(ssid, password);
  IP = WiFi.softAPIP();

  Serial.print("AP IP address: ");
  Serial.println(IP);

  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
  delay(2000);
  udp.flush();
}

void loop()
{
int DataIn;

uint8_t Data[10];

  while (1)
    {
      DataIn = udp.parsePacket();

      if(DataIn<10)
      {
        delay(1);
        break;
      }

      udp.read(Buffer, (DataIn > BufferLength) ? BufferLength : DataIn);
      break;
    }

    for(uint8_t i = 1; i < 8; i++)
    {
      Data[i] = Buffer[i];
    }

delay(8);
Serial.println();
Serial.println(Data[2]);
Serial.println(Data[3]);
Serial.println(Data[4]);
Serial.println(Data[5]);
Serial.println();


}
