/*
 * File name: 74HC595N_control_7_LEDS
 * Function: 74HC595N_control_7_LEDS
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int data = 4;    // set 74hc595 pin 4 to data input pin SI 
int clock = 6;   // set 74hc595 pin 6 to clock pin SCK
int latch = 5;   // set 74hc595 pin 5 to output latch RCK
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup(){
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

void loop(){
  for(int i = 0; i < 256; i++){  //
    updateLEDs(i);
    delay(500);
  }
}

void updateLEDs(int value){
  digitalWrite(latch, LOW);  //
  shiftOut(data, clock, MSBFIRST, ~value);  // serial data output, high first
  digitalWrite(latch, HIGH);  // latch
}
