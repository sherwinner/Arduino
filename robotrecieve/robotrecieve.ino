#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

//define our servos
Servo servo1;

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//variable to read the values from the analog pin (potentiometers)
int valPot1;// claw
int valPot2;//clawturn
/*
int valPot3 = 0;//claw_wrist
int valPot4;//elbow
int valPot5;//base_angle
int valPot6;//base_turn
*/
void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  //pwm.begin();
  //pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
  servo1.attach(3);// claw grab
  servo1.write(70); //define servo start position
}


void loop()
{
  radio.startListening();
  if (radio.available()) {
//     while (radio.available()) {

        //claw
        radio.read(&valPot1, sizeof(valPot1));
        servo1.write(valPot1);

 /*       
        pwm.setPWM(0, 0, valPot1);
        Serial.println(valPot1);

        //claw_turn
        radio.read(&valPot2, sizeof(valPot2));
        pwm.setPWM(1, 0, valPot2);
        Serial.println(valPot2);

        //claw_wrist
        radio.read(&valPot3, sizeof(valPot3));
        pwm.setPWM(2, 0, valPot3);
        Serial.println(valPot3);

        //elbow
        radio.read(&valPot4, sizeof(valPot4));
        pwm.setPWM(3, 0, valPot4);
        Serial.println(valPot4);
        
        //base_angle
        radio.read(&valPot5, sizeof(valPot5));
        pwm.setPWM(4, 0, valPot5);
        Serial.println(valPot5);
        
        //base_turn
        radio.read(&valPot6, sizeof(valPot6));
        pwm.setPWM(5, 0, valPot6);
        Serial.println(valPot6);        
//     }
*/  }
}
