/*
 * File name: Flowing_Water_Light
 * Function: Flowing_Water_Light
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
byte ledPins[] = {2, 3, 4, 5, 6}; //LED pins
int ledCounts; //set LED numbers

void setup() {
//set LED pins to output
  ledCounts = sizeof(ledPins); 
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCounts; i++) { //The five leds will turn on and off from right to left
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCounts - 1; i > -1; i--) { //The five leds will turn on and off from left to right
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

