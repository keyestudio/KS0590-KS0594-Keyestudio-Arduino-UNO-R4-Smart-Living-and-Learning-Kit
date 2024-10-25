/*  
 * File name: Small Table Lamp
 * Function: button control LED on and off to simulate small table lamp
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int buttonPin = 7;               //button pin to digital pin 7
int ledPin = 3;                 //LED pin to digital pin 3
int ledState = LOW;            // ledState record LED state
int buttonState;                 // buttonState record button state
int lastButtonState = HIGH;     // lastbuttonState record button last state
long lastDebounceTime = 0;
long debounceDelay = 50;        //Jitter removal time

void setup() {
  pinMode(buttonPin, INPUT); //set button pin to input
  pinMode(ledPin, OUTPUT);  //set LED pin to output
  digitalWrite(ledPin, ledState);  //set LED initial state to off
}

void loop() {
  int reading = digitalRead(buttonPin);  //reading is used to store buttonPin data
  if (reading != lastButtonState) {   // Once a change in data is detected, record the current time
    lastDebounceTime= millis();
  }
  // Wait for 50ms and check again whether the buttonstate is the same as the current ButtonState
  // If it is different from the current state, change buttonstate
  // At the same time, if the buttonstate is low (pressed), then change the state of the led
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
          ledState= !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;  // change buttonlast state value
}
