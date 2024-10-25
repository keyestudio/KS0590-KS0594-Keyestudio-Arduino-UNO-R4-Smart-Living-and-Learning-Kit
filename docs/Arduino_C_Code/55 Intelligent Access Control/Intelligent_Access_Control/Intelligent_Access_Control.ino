/*  
 * File name: IR Control a digital tube and LED
 * Function: IR Control a digital tube and LED
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "MFRC522_I2C_SOFT.h"
//The IIC pins default to A4 and A5
// 0x28 is the i2c address on the SDA. If it doesn't match, check your address with i2cscanner.
MFRC522 mfrc522(0x28, A4, A5);   // Create an instance of MFRC522.

#include <Servo.h>
Servo myservo;  // Create a servo object to control the servo
int servoPin = 6; // Define servo pin D6

#include <SoftwareSerial.h>  //Soft serial port library file
SoftwareSerial mySerial(10, 11); //MP3 TX pin to 10，RX pin to 11

String rfid_str = "";

void setup() {
  Serial.begin(9600); // Initialize the hardware serial port
  mySerial.begin(9600); // Initialize the software serial port
  mfrc522.PCD_Init();
  ShowReaderDetails();           // Display the PCD-MFRC522 card reader
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));

  myservo.attach(servoPin);  //choose servo pin D6
  myservo.write(0); 
  delay(500);
}

void loop() {
   if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  //Select a key card whose UID and SAK are mfrc522.uid, respectively.
  
  // save UID
  rfid_str = "";  //clear string 
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //Convert strings to real numbers
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println(rfid_str);
  
  if (rfid_str == "cae07ebe") {
    int cmd1[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x0B, 0xef}; //song 01 corresponding command, hexadecimal
    for(char i=0; i<8; i++){  
      mySerial.write(cmd1[i]); 
    }
    delay(2000);
    myservo.write(180);
    delay(500);
  } 
  else if (rfid_str == "39b646c2") {
    int cmd2[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x0C, 0xef}; //song 02 corresponding command, hexadecimal
    for(char i=0; i<8; i++){  
      mySerial.write(cmd2[i]); 
    }
    delay(2000);
    myservo.write(0);
    delay(500);
  }
}

void ShowReaderDetails() {
  // Obtain MFRC522 software
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown)"));
  Serial.println("");
  // When 0x00 or 0xFF is returned, the communication signal may not be transmitted
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}