/*
 * File name: PIR motion
 * Function: read PIR motion sensor value
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int val = 0;
int pirPin = 3;   //define PIR motion sensor pin to D3
void setup() {
  Serial.begin(9600);   //baud rate to 9600
  pinMode(pirPin, INPUT);    //set sensor to input
}

void loop() {
  val = digitalRead(pirPin);    //read sensr value
  Serial.print(val);    //print sensor value
  if (val == 1) {    //if someone moves around, output high
    Serial.print("        ");
    Serial.println("Some body is in this area!");
    delay(100);
  }
  else {    //if not, output low
    Serial.print("        ");
    Serial.println("No one!");
    delay(100);
  }
}