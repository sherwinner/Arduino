//add servo library
#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

//define our potentiometers
int pot1 = A1;
int pot2 = A2;
int pot3 = A3;
int pot4 = A4;
int pot5 = A5;
int pot6 = A6;


//variable to read the values from the analog pin (potentiometers)
int valPot1;
int valPot2;
int valPot3;
int valPot4;
int valPot5;
int valPot6;

void setup()
{
  //attaches our servos on pins PWM 3-5-6-9 to the servos
  servo1.attach(3);// base turn
  servo1.write(-10);  //define servo1 start position
  
  servo2.attach(5);// base tilt
  servo2.write(-10); //define servo2 start position
  
  servo3.attach(6);//elbow bend
  servo3.write(90); //define servo3 start position
  
  servo4.attach(9);// wrist bend
  servo4.write(70); //define servo4 start position
  
  servo5.attach(10);// claw turn
  servo5.write(70); //define servo4 start position

  servo6.attach(11);// claw grab
  servo6.write(70); //define servo4 start position
 
  Serial.begin(9600);
}

void loop()
{
  //reads the value of potentiometers (value between 0 and 1023)

  valPot1 = analogRead(pot1);
  valPot1 = map (valPot1, 0, 1023, 0, 260); //scale it to use it with the servo (value between 0 and 180)
  servo1.write(valPot1); //set the servo position according to the scaled value
  Serial.println(valPot1);


  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 150, 0);
  servo2.write(valPot2);
  Serial.println(valPot2);
  
  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 0, 180);
  servo3.write(valPot3);

  valPot4 = analogRead(pot4);
  valPot4 = map (valPot4, 0, 1023, 0, 145);
  servo4.write(valPot4);

  valPot5 = analogRead(pot5);
  valPot5 = map (valPot5, 0, 1023, 180, 0);
  servo5.write(valPot5);

  valPot6 = analogRead(pot6);
  valPot6 = map (valPot6, 0, 1023, 25, 105);
  servo6.write(valPot6);
  
}
