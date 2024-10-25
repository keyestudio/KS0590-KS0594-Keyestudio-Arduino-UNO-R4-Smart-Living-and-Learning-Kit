/*  
 * File name: IR Control a digital tube and LED
 * Function: IR Control a digital tube and LED
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN  2   // Defines the infrared reception and the pin is connected to the number 2
IRrecv irrecv(IR_RECEIVE_PIN);     // Creates a class object that receives the class
decode_results results;     // Create a decoded result class object
// set IO pins of each segments
int a=7;  // set a segment to digital pin 7
int b=6;  // set b segment to digital pin 6
int c=5;  // set c segment to digital pin 5
int d=10;  // set d segment to digital pin 10
int e=11;  // set e segment to digital pin 11
int f=8;  // set f segment to digital pin 8
int g=9;  // set g segment to digital pin 9
int dp=4;  // set dp segment to digital pin 4
int LED_L = 12;  //Define the external LED light pin to connect to the digital pin 12

boolean flag = true;  //LED marker bit

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start receiver
  int i;  // set variable i
  for(i=4;i<=11;i++)
  pinMode(i,OUTPUT);  // set pins 4-11 to output
  pinMode(LED_L,OUTPUT);  // set UNO R4 board L pin to output
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
      IrReceiver.printIRResultShort(&Serial); // Print the complete received data in one line
      IrReceiver.printIRSendUsage(&Serial);  // Print the statement needed to send this data
      handleControl(IrReceiver.decodedIRData.decodedRawData);      // Handle commands from remote control
      IrReceiver.resume(); // Enable receiving the next value
  }
}

void handleControl(unsigned long value){
  if (value == 0xBF40FF00 && flag == true){ // press button “OK” on the remote control and receive “OK” 
    digitalWrite(LED_L, HIGH);
    flag = false;
  } 
  else if (value == 0xBF40FF00 && flag == false){ // press button “OK” on the remote control and receive “OK”
    digitalWrite(LED_L, LOW);
    flag = true;
  } 
  else if(value == 0xE916FF00){ // press button “1” on the remote control
    digital_1();// display number 1
  } 
  else if(value == 0xE619FF00){ // press button “2” on the remote control
    digital_2();// display number  2
  } 
  else if(value == 0xF20DFF00){ // press button “3” on the remote control
    digital_3();// display number  3
  }
  else if(value == 0xF30CFF00){ // press button “4” on the remote control
    digital_4();// display number  4
  }
  else if(value == 0xE718FF00){ // press button “5” on the remote control
    digital_5();// display number  5
  }
  else if(value == 0xA15EFF00){ // press button “6” on the remote control
    digital_6();// display number  6
  }
  else if(value == 0xF708FF00){ // press button “7” on the remote control
    digital_7();// display number  7
  }
  else if(value == 0xE31CFF00){ // press button “8” on the remote control
    digital_8();// display number  8
  }
  else if(value == 0xA55AFF00){ // press button “9” on the remote control
    digital_9();// display number  9
  }
  else if(value == 0xAD52FF00){ // press button “0” on the remote control
    digital_0();// display number  0
  }
  else if(value == 0xBD42FF00){ // press button “*” on the remote control
    // turn off
    digitalWrite(c,LOW);
    digitalWrite(b,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
    digitalWrite(a,LOW);
    digitalWrite(e,LOW);
    digitalWrite(d,LOW);
  }
}

void digital_0(void) { // display number 0
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) { // display number  1
  unsigned char j;
  digitalWrite(c,HIGH);// Set the level of pin 5 to "High", turn on c
  digitalWrite(b,HIGH);// turn on b
  for(j=7;j<=11;j++)// turn off other segments
  digitalWrite(j,LOW);
  digitalWrite(dp,LOW);// turn off dp
}
void digital_2(void) { // display number  2
  unsigned char j;
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  for(j=9;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void digital_3(void) { // display number  3
  digitalWrite(g,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(f,LOW);
  digitalWrite(e,LOW);
}
void digital_4(void) { // display number  4
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}
void digital_5(void) { // display number  5
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void digital_6(void) { // display number  6
  unsigned char j;
  for(j=7;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
}
void digital_7(void) { // display number  7
  unsigned char j;
  for(j=5;j<=7;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  for(j=8;j<=11;j++)
  digitalWrite(j,LOW);
}
void digital_8(void) { // display number  8
  unsigned char j;
  for(j=5;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
}
void digital_9(void) { // display number  9
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}