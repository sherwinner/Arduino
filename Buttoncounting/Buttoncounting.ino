//radio setup
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

//Joystick and button
const int buttonPin = 2;     // the number of the pushbutton pin
const int pot0 = A0;//U/D
const int pot1 = A1;//L/R
const int pot2 = A2;//wrist_turn
const int pot3 = A3;//claw

// variables to check button state:
int buttonPushCounter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

//variables to check joystick position
int valPot0;// base_turn
int valPot1;//base_tilt
int valPot2;//elbow
int valPot3;//wrist_tilt
int valPot4;//wrist_turn
int valPot5;//claw

//default positions of servos
int baseTurnCur = 250;
int baseTiltCur = 200;
int elbCur = 200;
int wristCur = 140;

void setup() 
{
   Serial.begin(9600);
   pinMode(buttonPin, INPUT_PULLUP); //define button state

//radio initialisation
   radio.begin();
   radio.openWritingPipe(address);
   radio.setPALevel(RF24_PA_MIN);
   radio.stopListening();
}

void loop() 
{ 
   radio.stopListening();

   // read the pushbutton input pin:
   buttonState = digitalRead(buttonPin);

   // compare the buttonState to its previous state
   if (buttonState != lastButtonState) 
   {
      if (buttonState == LOW) 
      {
         if (buttonPushCounter < 3)
         {
            buttonPushCounter++;
         }
         else 
         {
            buttonPushCounter = 1;
         }
      }
   }
   // Delay a little bit to avoid bouncing
   delay(50);

   // save the current state as the last state, for next time through the loop
   lastButtonState = buttonState;




   //check pots and send over radio
   //base_turn
   sendSignal(pot0, valPot0, 400, 480, "base_turn", baseTurnCur, 70, 520);
   
   //base_tilt
   if (buttonPushCounter == 1) // counter defaults to 1
   {
   valPot1 = analogRead(pot1); // set 'valPot1' to be the value read in from a joystick
   if(valPot1 < 405) // if the it's less than 405, then assume the joystick is moved down
      {
         if (baseTiltCur < 80)  // if the servo is already at it's minumum don't do shit
         {
         }
         else  // but otherwise
         {
            baseTiltCur = baseTiltCur-20; //decrement the servo by 20
            //radio.write(&servCur, sizeof(servCur));
            Serial.println("baseTilt"); //print the servo you're moving
            Serial.println(baseTiltCur); // and its new position
            delay (100); //wait a bit
         }
      }
      if(valPot1 > 450) //if the value from the joystick is more than 450, assume the joystick is moved up
      {
         if(baseTiltCur > 470) //if the servo is already at the maximum, dno't do shit
         {
         }
         else  //but otherwise
         {
            baseTiltCur = baseTiltCur+20; //increment the servo by 20
            //radio.write(&servCur, sizeof(servCur));
            Serial.println("baseTilt"); //print the servo you're moving
            Serial.println(baseTiltCur); // and its new position
            delay (100); //wait a bit
        }        
     }
   }
  
   //elbow
   else if(buttonPushCounter == 2) // if the count of button pushes is 2 execute this crap
   {
      sendSignal(pot1, valPot2, 405, 445, "elbow", elbCur, 80, 450);    
   }
   
   //wrist
   else if(buttonPushCounter == 3)
   {
      sendSignal(pot1, valPot3, 405, 445, "wrist_tilt", wristCur, 110, 440);    
   }
}

/*
   ******TO DO *********
   
   sendSignal(pot2, valPot4, "wrist_turn", 100, 510);
   sendSignal(pot3, valPot5, "claw", 35, 95);
*/

int sendSignal(int potread, int potsend, int dbLow, int dbHigh, String joint, int &servCur, int servMin, int servMax)
{
   potsend = analogRead(potread);
   if(potsend < dbLow)
   {
      if (!(servCur < servMin))
      {
         doMove(-20, servCur, joint);
      }
   }
   if(potsend > dbHigh)
   {
      if(!(servCur > servMax))
      {
         doMove(20, servCur, joint);
      }        
   }
return servCur;
}
int doMove(int move, int &subServCur, String subJoint)
{
  subServCur = subServCur + move;
  //radio.write(&servCur, sizeof(servCur));
  Serial.println(subJoint);
  Serial.println(subServCur);
  delay (100);
}
 
