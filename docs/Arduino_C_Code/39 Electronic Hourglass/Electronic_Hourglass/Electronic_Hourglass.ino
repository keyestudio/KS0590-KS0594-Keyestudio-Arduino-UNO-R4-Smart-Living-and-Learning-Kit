/*  
 * File name: Electronic_Hourglass
 * Function: Tilt switch controls 4 LED to simulate electronic hourglasses
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
const byte SWITCH_PIN = 4; // set tilt switch pin to digital pin 4
int led1 = 8;  //set led1 pin to digital pin 8
int led2 = 9;  //set led2 pin to digital pin 9
int led3 = 10;  //set led3 pin to digital pin 10
int led4 = 11;  //set led4 pin to digital pin 11

byte switch_state = 0; //set variable switch_state with an initial value of 0

void setup(){
  Serial.begin(9600); //set baud rate to 9600
  pinMode(SWITCH_PIN, INPUT); //set tilt switch pin to input
  for(int i=8;i<12;i++){  //set 4 LED pin to output
    pinMode(i, OUTPUT);
  } 
  for(int i=8;i<12;i++){ //set 4 LED off
    digitalWrite(i,0);
  } 
}

void loop(){
  switch_state = digitalRead(SWITCH_PIN); //read tilt switch value and assign it to switch_state
  Serial.println(switch_state); //serial monitor prints tilt switch value 
  if (switch_state == 1) {  //if tilt switch tilts at a certain Angle (i.e., its value is 1)
    for(int i=8;i<12;i++){  //4 LED gradually turn on
      digitalWrite(i,1);
      delay(500);
    } 
  }
  if (switch_state == 0) {  //if tilt switch does not tilt (i.e., its value is 0)
    for(int i=11;i>7;i--){  //4 LED gradually turn off
      digitalWrite(i,0);
      delay(500);
    }
  }
}
