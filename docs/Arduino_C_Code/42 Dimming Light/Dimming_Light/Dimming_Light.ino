/*  
 * File name: Dimming_Light
 * Function: potentiometer control LED
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int potPin = A0; // initialize potentiometer analog pin A0
int ledPin = 6; // initialize digital pin 6
int val = 0; // define val with an initial value of 0

void setup(){
  Serial.begin(9600);// set baud rate to 9600
  pinMode(potPin,INPUT);// set potentiometer analog pin to intput
  pinMode(ledPin,OUTPUT);// set LED digital pin to output
}

void loop(){
  val = analogRead(potPin);// read A0 value and assign it to val 
  Serial.println(val);// print val
  analogWrite(ledPin,val/4);
  delay(100);
}
