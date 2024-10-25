/*
 * File name: Tilt_Switch
 * Function: read the value of Tilt_Switch
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int SWITCH_PIN = 7; // connect the tilt switch to pin D7
int val = 0;       //store the value of the tilt switch

void setup(){
  Serial.begin(9600); //start the serial monitor and set baud rate to 9600
  pinMode(SWITCH_PIN, INPUT); //set the sensor to input
} 

void loop(){
  val = digitalRead(SWITCH_PIN); //read sensor value and assign it to val
  Serial.print(val);  //print val
  if (val == 1) { //read high and print related messages
    Serial.print("    ");  
    Serial.println("Tilt"); 
    delay(100); 
  }
  else {               //when it is not tilt, read low
    Serial.print("    ");
    Serial.println("No tilt");
    delay(100);
  }
}
