/*
 * File name: Servo_2
 * Function: Control servo for sweeping
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <Servo.h>

Servo myservo;  //create a servo object to control servo

int posVal = 0;    // define a variable to store the position of the servo
int servoPin = 3;  // define servp pin to 3

void setup() {
  myservo.attach(servoPin);  //choose servo pin 3
}

void loop() {
  
  for (posVal = 0; posVal <= 180; posVal += 1) { // Attach the servo on the servoPin to the servo object
    // set step to 1 degree
    myservo.write(posVal);       // Tell the servo to the position of the variable "pos"
    delay(15);                   // Wait 15ms for the servo to arrive
  }
  for (posVal = 180; posVal >= 0; posVal -= 1) { // from 180° to 0°
    myservo.write(posVal);       // Tell the servo to the position of the variable "pos"
    delay(15);                   // Wait 15ms for the servo to arrive
  }
}