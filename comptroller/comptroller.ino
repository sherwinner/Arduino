#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

//define our potentiometers
int pot1 = A1;//claw
int pot2 = A2;//clawturn
/*
int pot3 = A3;//claw_wrist
int pot4 = A4;//elbow
int pot5 = A5;//base_angle
int pot6 = A6;//base_turn
*/
//variable to read the values from the analog pin (potentiometers)
int valPot1;// claw
int valPot2;//clawturn
/*
int valPot3;//claw_wrist
int valPot4;//elbow
int valPot5;//base_angle
int valPot6;//base_turn
*/

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 2; // send once per second

void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop()
{
  radio.stopListening();
/*
currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        send();
        prevMillis = millis();
    }
}

void send(){
*/
  //claw
  valPot1 = analogRead(pot1);
  valPot1 = map (valPot1, 0, 1023, 35, 95); //scale it to use it with the servo (value between 190 and 330)
  radio.write(&valPot1, sizeof(valPot1));
/*  
  //clawturn
  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 100, 510); //scale it to use it with the servo (value between 0 and 180)
  radio.write(&valPot2, sizeof(valPot2));
  Serial.println(valPot2);

  //claw_wrist
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 110, 440); //scale it to use it with the servo (value between 0 and 180)
  radio.write(&valPot3, sizeof(valPot3));
  Serial.println(valPot3);

  //elbow
  valPot4 = analogRead(pot4);
  valPot4 = map (valPot4, 0, 1023, 80, 450); //scale it to use it with the servo (value between 0 and 180)
  radio.write(&valPot4, sizeof(valPot4));
  Serial.println(valPot4);

  //base_angle
  valPot5 = analogRead(pot5);
  valPot5 = map (valPot5, 0, 1023, 470, 80); //scale it to use it with the servo (value between 0 and 180)
  radio.write(&valPot5, sizeof(valPot5));
  Serial.println(valPot5);

  //base_turn
  valPot6 = analogRead(pot6);
  valPot6 = map (valPot6, 0, 1023, 520, 70); //scale it to use it with the servo (value between 0 and 180)
  radio.write(&valPot6, sizeof(valPot6));
  Serial.println(valPot6);
*/
}
