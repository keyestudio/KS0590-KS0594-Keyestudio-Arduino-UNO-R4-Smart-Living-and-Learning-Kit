/*  
 * File name: IR Receiver
 * Function: Decode infrared remote control, print it on serial monitor
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <IRremote.hpp>

#define IR_RECEIVE_PIN   3   // Defines infrared receiver module pin
IRrecv irrecv(IR_RECEIVE_PIN);     // Creates a class object that receives the class
decode_results results;     // Create a decoded result class object

void setup() {
  Serial.begin(9600);       // set baud rate to 9600
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // start receiver
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
      IrReceiver.printIRResultShort(&Serial); // Print the complete received data in one line
      IrReceiver.printIRSendUsage(&Serial);  // Print the statement needed to send this data
      IrReceiver.resume(); // Enable receiving the next value
  }
  delay(100);
}