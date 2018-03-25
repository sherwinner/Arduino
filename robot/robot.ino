//add servo library
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//define our potentiometers
int pot1 = A1;//claw
int pot2 = A2;//clawturn
int pot3 = A3;//claw_wrist
// int pot4 = A4;//elbow
// int pot5 = A5;//base_angle
// int pot6 = A6;//base_turn

//variable to read the values from the analog pin (potentiometers)
int valPot1;// claw
int valPot2;//clawturn
int valPot3;//claw_wrist
int valPot4;//elbow
int valPot5;//base_angle
int valPot6;//base_turn

void setup()
{
 Serial.begin(9600);

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}


void loop()
{
  //claw
  valPot1 = analogRead(pot1);
  valPot1 = map (valPot1, 0, 1023, 170, 360); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(0, 0, valPot1);
  
  //clawturn
  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 100, 510); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(1, 0, valPot2);
  Serial.println(valPot2);

  //claw_wrist
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 110, 440); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(2, 0, valPot3);
  Serial.println(valPot3);

    //elbow
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 80, 450); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(3, 0, valPot3);
  Serial.println(valPot3);

   //base_angle
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 470, 80); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(4, 0, valPot3);
  Serial.println(valPot3);

   //base_turn
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 520, 70); //scale it to use it with the servo (value between 0 and 180)
  pwm.setPWM(5, 0, valPot3);
  Serial.println(valPot3);

}
