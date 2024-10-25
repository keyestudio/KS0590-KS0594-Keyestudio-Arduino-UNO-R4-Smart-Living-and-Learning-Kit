/*
 * File name: Speed_Regulating_Waterfall_Lights
 * Function: Speed_Regulating_Waterfall_Lights
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
const int ledPins[] = {3, 4, 5};  //define red, yellow, green LED pin
const int potPin = A0;  //define potentiometer pin to analog A0   
int potValue = 0;  //potentiometer value   
int delayTime = 100;  //default delay time  
  
void setup() {  
  for (int i = 0; i < 3; i++) {  
    pinMode(ledPins[i], OUTPUT);  //set LED pin to output 
  }  
  pinMode(potPin, INPUT);  //set potentiometer pin to input 
}  
  
void loop() {  
  potValue = analogRead(potPin);  //read potentiometer value   
  delayTime = map(potValue, 0, 1023, 100, 1000);  //map potentiometer value to delay time 
  
  for (int i = 0; i < 3; i++) {  
    digitalWrite(ledPins[i], HIGH);  //turn on LED   
    delay(delayTime);  //delay   
    digitalWrite(ledPins[i], LOW);  //turn off LED   
  }  
}
