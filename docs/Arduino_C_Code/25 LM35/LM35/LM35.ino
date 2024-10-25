/*  
 * File name: LM35
 * Function: detect temperature via LM35
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int lm35Pin = A0;  //define lm35 pin
float temperature = 0; //define a variable temperature with an initial value of 0
long value = 0; //define a variable value with an initial value of 0

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  pinMode(lm35Pin, INPUT);  //set lm35Pin to input
}

void loop() {
  value = analogRead(lm35Pin); //read analog input

  //Voltage and Celsius conversion:
  //0.00488125=5/1024，0 ~ 5V corresponds to the analog port reading 1 ~ 1024, and every 10 millivolts corresponds to 1°C
  temperature = (value * 0.0048828125 * 100);
  
  Serial.print("Temper =  ");
  Serial.print(temperature);
  Serial.println("℃");
  delay(100);
}

