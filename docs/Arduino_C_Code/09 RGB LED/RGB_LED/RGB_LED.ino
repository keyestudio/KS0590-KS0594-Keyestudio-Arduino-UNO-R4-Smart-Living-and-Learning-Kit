/*
 * File name: RGB_LED
 * Function: RGB LED lights up in various colors
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int redpin = 11; //red LED pin to 11.
int greenpin = 10; // green LED pin to 10.
int bluepin = 9; // blue LED pin to 9.

int val = 0; //define a variable named val

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,LOW);
}

void loop() {
  for(val=255; val>0; val--){
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
  for(val=0; val<255; val++){
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
}
