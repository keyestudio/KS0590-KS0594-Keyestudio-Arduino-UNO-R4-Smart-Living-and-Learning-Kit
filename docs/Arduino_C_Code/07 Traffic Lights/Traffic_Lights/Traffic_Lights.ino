/*

 * File name: Traffic_Lights
 * Function: simulate traffic lights
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int redled = 10;  // red LED to digital pin 10.
int yellowled = 7;  // yellow LED to digital pin 7.
int greenled = 4;  // green LED to digital pin 4.

void setup() {
  pinMode(redled, OUTPUT);  // red LED pin to output
  pinMode(yellowled, OUTPUT);  // yellow LED pin to output
  pinMode(greenled, OUTPUT);  // green LED pin to output
}

void loop(){
  digitalWrite(greenled, HIGH); // green LED on
  delay(5000); // delya 5s
  digitalWrite(greenled, LOW); // green LEDoff
  for(int i=0;i<3;i++){// blink for three times
    digitalWrite(yellowled, HIGH); //yellow LED on
    delay(500); // delay 0.5s
    digitalWrite(yellowled, LOW); // yellow LED off
    delay(500); // delay 0.5s
  } 
  digitalWrite(redled, HIGH); // red LED on 
  delay(5000); // delya 5s
  digitalWrite(redled, LOW); // red LED off
}
