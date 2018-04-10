#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

//define our servos
Servo servo1;

RF24 radio(7, 10); // CE, CSN
const byte address[6] = "00001";

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//variable to read the values from the analog pin (potentiometers)
int valPot0;// base_turn
int valPot1;//base_tilt
int valPot2;//elbow
int valPot3;//wrist_tilt
int valPot4;//wrist_turn
int valPot5;//claw

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
  servo1.attach(3);// claw grab
  servo1.write(70); //define servo start position
}


void loop()
{
  radio.startListening();
  if (radio.available()) {
//     while (radio.available()) {

        //base_turn
        radio.read(&valPot1, sizeof(valPot1));
        pwm.setPWM(0, 0, valPot1);
        Serial.println(valPot1);

 /*       
         //base_tilt
        radio.read(&valPot2, sizeof(valPot2));
        pwm.setPWM(1, 0, valPot2);
        Serial.println(valPot2);

        //elbow
        radio.read(&valPot3, sizeof(valPot3));
        pwm.setPWM(2, 0, valPot3);
        Serial.println(valPot3);

        //wrist_tilt
        radio.read(&valPot4, sizeof(valPot4));
        pwm.setPWM(3, 0, valPot4);
        Serial.println(valPot4);
        
        //wrist_turn
        radio.read(&valPot5, sizeof(valPot5));
        pwm.setPWM(4, 0, valPot5);
        Serial.println(valPot5);
        
        //claw
        radio.read(&valPot6, sizeof(valPot6));
        pwm.setPWM(5, 0, valPot6);
        Serial.println(valPot6);        
//     }
*/  }
}
