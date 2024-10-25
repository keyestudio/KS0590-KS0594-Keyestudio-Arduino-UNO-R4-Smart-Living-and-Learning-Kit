/*  
 * File name: Home_Appliances
 * Function: Relays and button controls motor rotation to simulate a small home appliances
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int relayPin = 9;          // define relay pin to digital pin 9
int buttonPin = A0;         //define button pin to A0

int buttonState = HIGH;     // record button state and state initializes to high
int relayState = LOW;       //record relay state and state initializes to low
int lastButtonState = HIGH; // record last button state 
long lastChangeTime = 0;    // record button state change time 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // set button pin to input
  pinMode(relayPin, OUTPUT);          // set relay pin to output
  digitalWrite(relayPin, relayState); // set relay initial state to off
}
void loop() {
  int nowButtonState = digitalRead(buttonPin);// read button current state 
  // if button state changes, record the time
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // if button state changes and remains stable for a while, it should skip the rebound area
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {    // ensure button state is changed
      buttonState = nowButtonState;
      if (buttonState == LOW) {             // loe: button is pressed
        relayState = !relayState;           // reverse relay state 
        digitalWrite(relayPin, relayState); // update relay state 
      }
    }
  }
  lastButtonState = nowButtonState; // save the last button state 
}

