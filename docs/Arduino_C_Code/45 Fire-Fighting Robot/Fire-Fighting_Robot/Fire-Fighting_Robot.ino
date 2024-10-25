/*  
 * File name: Fire-fighting robot
 * Function: The flame sensor controls the motor and the LED to simulate fire-fighting robot
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ANALOG_IN = A0;   //define flame sensor pin to analgo A0
int motorPin = 6;   //define motor  pin to digital 6
int ledPin = 10;   //define led pin to digital 10
int item = 0; //define variable item with an initial value of 0

void setup() {
  Serial.begin(9600);  //set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT); //set flame sensor pin to input
  pinMode(motorPin, OUTPUT); //set motor pin to output
  pinMode(ledPin, OUTPUT); //set led pin to output
}

void loop() {
  item = analogRead(PIN_ANALOG_IN); //read flame sensor analog value and assign it to variable item
  Serial.print(item); //print item
  if (item > 100) { //item > 100, fan on, LED blink
    Serial.print("   "); 
    Serial.println("Put out a fire");
    digitalWrite(motorPin, HIGH); //turn on motor 
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);  
  } 
  else {//or else, fan off, LED off
    Serial.print("   "); 
    Serial.println("No flame detected");
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW); 
  } 
}
