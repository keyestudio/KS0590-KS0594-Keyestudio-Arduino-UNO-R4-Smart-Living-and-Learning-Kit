/*
 * File name: Breathing_LED
 * Function: with PWM, LED dims and lights up, like breathe
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int ledPin = 10;  // Define LED pin to 10.

void setup() {
  pinMode(ledPin,OUTPUT); // Set LED pin to output 
}

void loop(){
  for (int value = 0 ; value < 255; value=value+1) {  //gradually lighting
    analogWrite(ledPin, value);
    delay(10);
  }
  for (int value = 255; value >0; value=value-1) {  //dimming
    analogWrite(ledPin, value);
    delay(10);
  } 
} 
