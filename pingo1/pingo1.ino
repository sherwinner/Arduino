/*
 * With this library an ESP8266 can ping a remote machine and know if it's reachable. 
 * It provides some basic measurements on ping messages (avg response time).
 */
#include <TM1637Display.h>
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

// Module connection pins (Digital Pins)
#define CLK 0
#define DIO 1

const char* ssid     = "Police surveillance van";
const char* password = "evangelion00";
int relay = 3;
int allgood = 4;

const uint8_t NO[] = {
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
};

TM1637Display display(CLK, DIO);

const IPAddress remote_ip(192, 168, 43, 1);
//const char* remote_host = "www.google.com";

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(allgood, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("Connecting to WiFi");
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected with ip ");  
  Serial.println(WiFi.localIP());

  Serial.print("Pinging remote IP ");
  Serial.println(remote_ip);

//  Serial.print("Pinging Host ");
//  Serial.println(remote_host);

//  if(Ping.ping(remote_host)) {
  if(Ping.ping(remote_ip)) {
    Serial.println("Success!!");
  } else {
    Serial.println("Error :(");
  }
}

void loop() {
//  if(Ping.ping(remote_host)) {
  if(Ping.ping(remote_ip)) {
    digitalWrite(BUILTIN_LED, LOW);
    Serial.println("ZOMG_IT_WORKS");
      }
    else {
      Serial.println("OHNOES");
      digitalWrite(BUILTIN_LED, HIGH);
      
         
         display.setSegments(NO);
    }
delay(5000);
}
