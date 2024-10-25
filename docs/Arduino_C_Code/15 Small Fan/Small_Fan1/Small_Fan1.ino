/*
 * File name: Small_Fan1
 * Function: Small_Fan rotates 1
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
void setup() {
  // initialize digital pin 9 to output
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);   // turn on motor (HIGH)
  delay(4000);              // delay 4s
  digitalWrite(9, LOW);    // Reduce the voltage and turn off the motor
  delay(3000);              // delay 3s
}

