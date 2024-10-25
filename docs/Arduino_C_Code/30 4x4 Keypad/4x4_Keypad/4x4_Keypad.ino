/*  
 * File name: 4x4_Keypad
 * Function: read 4x4_Keypad key value 
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "Adafruit_Keypad.h"  // Adafruit_Keypad library

// Define the number of rows and columns for the 4x4 keypad
const byte ROWS = 4;
const byte COLS = 4;

// Define characters that map to each button on the 4x4 keypad
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Define the Arduino pins connected to the 4x4 keypad row pins
byte rowPins[ROWS] = { 2, 3, 4, 5 };
// Define the Arduino pins connected to the column pins of the 4x4 keypad
byte colPins[COLS] = { 6, 7, 8, 9 };

// Initialize a custom 4x4 keypad instance
Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // set baud rate to 9600
  myKeypad.begin();   // Initialize the 4x4 keypad
}

void loop() {
  //Update button status of 4x4 keypad
  myKeypad.tick();

  //Check for new keypad status
  while (myKeypad.available()) {
    // Read keypad status
    keypadEvent e = myKeypad.read();
    // Print the key value of the triggered state
    Serial.print((char)e.bit.KEY);
    // Print Key status Type: Press or release
    if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
  }
  delay(10);
}
