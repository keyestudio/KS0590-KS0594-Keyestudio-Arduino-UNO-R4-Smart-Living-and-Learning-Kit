/*  
 * File name: Mp3_Playing
 * Function: Mp3 play audio
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <SoftwareSerial.h>  //Soft serial port library

SoftwareSerial mySerial(10, 11); //MP3 TX pin to 10，RX pin to 11

void setup() {
  Serial.begin(9600); // initialize hard serial monitor
  mySerial.begin(9600); //initialize soft serial monitor
}

void loop() {
  int cmd1[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x01, 0xef}; //song 01 corresponding command, hexadecimal
  for(char i=0; i<8; i++){  
    mySerial.write(cmd1[i]); 
  }
  delay(3000);

  int cmd2[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x02, 0xef}; //song 02 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd2[i]);
  }
  delay(3000);

  int cmd3[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x03, 0xef}; //song 03 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd3[i]);
  }
  delay(3000);

  int cmd4[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x04, 0xef}; //song 04 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd4[i]);
  }
  delay(3000);

  int cmd5[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x05, 0xef}; //song 05 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd5[i]);
  }
  delay(3000);

  int cmd6[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x06, 0xef}; //song 06 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd6[i]);
  }
  delay(3000);

  int cmd7[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x07, 0xef}; //song 07 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd7[i]);
  }
  delay(3000);

  int cmd8[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x08, 0xef}; //song 08 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd8[i]);
  }
  delay(125000);

  int cmd9[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x09, 0xef}; //song 09 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd9[i]);
  }
  delay(205000);

  int cmd10[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x0A, 0xef}; //song 10 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd10[i]);
  }
  delay(88000);
}
