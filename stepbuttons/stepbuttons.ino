#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

const int upbuttonPin = 3;     // the ID of the up pushbutton pin
const int downbuttonPin = 7;     // the ID of the down pushbutton pin

int upbuttonState = 1;         // current state of the button
int lastupButtonState = 1;     // previous state of the button
int downbuttonState = 1;         // current state of the button
int lastdownButtonState = 1;     // previous state of the button

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
// initialize the stepper library on pins 8 through 11:

int count;
int stepstotake;

void setup() {
  // initialize the button pin as a input:
  pinMode(upbuttonPin, INPUT_PULLUP);
  pinMode(downbuttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

// read the pushbutton input pin:
   upbuttonState = digitalRead(upbuttonPin);
   downbuttonState = digitalRead(downbuttonPin);


// compare the buttonState to its previous state
  if (upbuttonState != lastupButtonState){
      // if the state has changed, increment the counter
      if (upbuttonState == 0)  {
      // if the current state is HIGH then the button
      // went from off to on:
      count++;
      Serial.print("number of rotations:  ");
      Serial.println(count);
     }
   }
 if (downbuttonState != lastdownButtonState){
      // if the state has changed, decrement the counter
      if (downbuttonState == 0)  {
      // if the current state is HIGH then the button
      // went from off to on:
      while (count > 0){
      count--;}
      Serial.print("number of rotations:  ");
      Serial.println(count);
    }
   }

  while (count > 0){
  myStepper.setSpeed(10);
  stepstotake = stepsPerRevolution * count;  
  myStepper.step(stepstotake);
  Serial.print("number of rotations:  ");
  Serial.println(count);
  count--;
  }
}

