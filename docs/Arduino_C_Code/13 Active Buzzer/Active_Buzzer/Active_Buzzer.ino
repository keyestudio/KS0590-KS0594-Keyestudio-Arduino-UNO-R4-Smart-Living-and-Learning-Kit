/*
 * File name: Active buzzer
 * Function: Active buzzer emit sound
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int buzzer = 3;   //define buzzer pin to D3
void setup() {
  pinMode(buzzer, OUTPUT);    //set to output
}

void loop() {
  digitalWrite(buzzer, HIGH); //emit sound
  delay(1000);
  digitalWrite(buzzer, LOW);  //stop emitting sound
  delay(1000);
}