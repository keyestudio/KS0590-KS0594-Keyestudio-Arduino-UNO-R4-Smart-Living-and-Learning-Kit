/*  
 * File name: Night_Lamp
 * Function: photoresistor control LED
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ANALOG_IN = A0;   //photoresistor pin to analog A0
int LED_PIN = 3;   //LED pin to D3
int item = 0;  //set item to 0

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    //set photoresistor pin to input
  pinMode(LED_PIN, OUTPUT);  // set led pin to output
}

void loop() {
  item = analogRead(PIN_ANALOG_IN); //read photoresistor analog value
  Serial.println(item);  //print photoresistor analog value
  if (item > 600) {  //the value > 600
    digitalWrite(LED_PIN, HIGH);  //turn on LED   
  } else {  //the value < = 600
    digitalWrite(LED_PIN, LOW);  //turn off LED
  }
}