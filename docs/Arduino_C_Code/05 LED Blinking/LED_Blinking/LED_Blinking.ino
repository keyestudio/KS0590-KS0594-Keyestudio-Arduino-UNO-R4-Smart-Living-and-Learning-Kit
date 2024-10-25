/*
 * File name: LED_Blinking
 * Function: LED blinks 1s
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int ledPin = 10; // Define LED pin to 10.

void setup(){
  pinMode(ledPin, OUTPUT);// Set LED pin to output
}

void loop(){
  digitalWrite(ledPin, HIGH); // LED on.
  delay(1000); // Delay 1s.
  digitalWrite(ledPin, LOW); // LED off.
  delay(1000); // Delay 1s.
}
