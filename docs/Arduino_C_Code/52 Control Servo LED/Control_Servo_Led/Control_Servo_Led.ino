/*  
 * File name: Control_Servo_Led
 * Function: Control_Servo_Led
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <Servo.h>

Servo myservo;  //Create a servo object to control the servo
int servoPin = 3;  // define servo pin to D3

int ledPin = 11; // define LED to pin D11

#define PIN_BUTTON  6  //Connect the pin of the self-locking key to the D6
#define PIN_ANALOG_IN  A0  //set potentiometer to pin A0

int val1 = 0;   //store button value
int val2 = 0;   //set val2 to 0

void setup() {
  pinMode(PIN_ANALOG_IN, INPUT);    //Set the potentiometer pin to input mode
  pinMode(PIN_BUTTON, INPUT);    //Set the pin of the button to input mode
  pinMode(ledPin, OUTPUT);// Set the led pin to output mode
  myservo.attach(servoPin);  //set servo pin to D3
  myservo.write(0); // servo rotates 0°
  delay(200); // delay 200ms
}

void loop() {
  val1 = digitalRead(PIN_BUTTON);  //Read the value of button and assign it to the variable val1
  if (val1 == 0) {       //press button to read high
    digitalWrite(ledPin, HIGH); // LED on
  }
  else {
    digitalWrite(ledPin, LOW); // LED off
  }  
  val2 = analogRead(PIN_ANALOG_IN);    //The analog value of the potentiometer
  myservo.write((map(val2, 0, 1023, 0, 180)));   // The analog value of the potentiometer is mapped to the position of the servo
  delay(5);   // Wait 10ms for the servo to reach the corresponding position
}
