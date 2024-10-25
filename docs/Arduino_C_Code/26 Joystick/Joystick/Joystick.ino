/*  
 * File name: Joystick
 * Function: read Joystick value
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int VRx = A0;  //define axis-X pin
int VRy = A1;  //define axis-Y pin
int SW = 7;    //define axis-Z pin
int xPosition = 0;  //set variable xPosition with an initial value of 0
int yPosition = 0;  //set variable yPosition with an initial value of 0
int SW_state = 0;  //set variable SW_state with an initial value of 0

void setup() {
Serial.begin(9600); 
pinMode(VRx, INPUT);  //axis-X pin  to output
pinMode(VRy, INPUT);  //axis-Y pin  to output
pinMode(SW, INPUT_PULLUP);   //axis-Z pin to pull-up
}

// In loop(), use analogRead() to read the values for the X and Y axes
// And use digitalRead() to read the z-axis values and then display them
void loop() {
  xPosition = analogRead(VRx); 
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  delay(100);
}