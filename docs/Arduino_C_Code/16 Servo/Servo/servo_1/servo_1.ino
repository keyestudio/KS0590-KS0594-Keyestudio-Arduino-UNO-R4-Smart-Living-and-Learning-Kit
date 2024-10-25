/*
 * File name: Servo_1
 * Function: servo rotates to angle 0 -> 90 -> 180 repeatedly
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <Servo.h>

Servo myservo;  //create a servo object to control servo

int servoPin = 3;  // define servo pin to 3

void setup() {
  myservo.attach(servoPin);  //choose servo pin 3
}

void loop() {
  myservo.write(0); //rotate to 0 degree
  delay(1000); //delay 1s
  myservo.write(90); //rotate to 90 degree
  delay(1000); //delay 1s
  myservo.write(180); //rotate to 180 degree
  delay(1000); //delay 1s
}