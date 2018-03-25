#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

const int CLK = D6; //Set the CLK pin connection to the display
const int DIO = D5; //Set the DIO pin connection to the display
const char* ssid     = "Police surveillance van";
const char* password = "evangelion00";

const IPAddress remote_ip(192, 168, 43, 1);
//const char* remote_host = "www.google.com";

const uint8 data[] = {
  0xff , 0xff , 0xff , 0xff,
};

const uint8_t NO[] = {
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F, //N
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_A | SEG_B | SEG_G | SEG_E | SEG_F, //N
  SEG_F | SEG_E | SEG_G | SEG_D | SEG_A,  //E
};

const uint8_t YES[] = {
  0x0,
  SEG_F | SEG_B | SEG_C | SEG_D | SEG_G, //Y,
  SEG_F | SEG_E | SEG_G | SEG_B | SEG_C | SEG_A, //E
  SEG_F | SEG_E | SEG_G | SEG_B | SEG_C,  // S
};

TM1637Display display(CLK, DIO); //set up the 4-Digit Display.

void setup()
{
  display.setBrightness(0x0a); //set the diplay to maximum brightness
  WiFi.begin(ssid, password);
  display.setSegments(data);

}


void loop()
{
  //  if(Ping.ping(remote_host)) {
  if (Ping.ping(remote_ip)) {
    display.setSegments(YES); //Display the YES
  }
  else {
    display.setSegments(NO); //Display the NO;
  }
}
