/*
 * File name: Small_Fan2
 * Function: Small_Fan rotates 2
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
void setup() {
  // Initialize digital pin 9 to output
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(9, LOW);   // turn on motor (LOW)
  delay(4000);              // Delay 4s
  digitalWrite(9, HIGH);    // Turn the voltage up and turn off the motor
  delay(3000);              // Delay 3s
}
