/*  
 * File name: RFID
 * Function: RFID read UID
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "MFRC522_I2C_SOFT.h"

// 0x28 is the i2c address on the SDA. If it doesn't match, check your address with i2cscanner.
MFRC522 mfrc522(0x28, A4, A5);   // Create an instance of MFRC522.

void setup() {
  Serial.begin(115200);           // Initialize serial communication with the PC
  mfrc522.PCD_Init();             // Initialize MFRC522
  ShowReaderDetails();            // Display detailed PCD-MFRC522 card reader details
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop() {
  // Look for new cards and choose one if available
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // Select a key card whose UID and SAK are mfrc522.uid, respectively
  // save UID
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();
}

void ShowReaderDetails() {
  //attain MFRC522 software
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
  // return 0x00 or 0xFF: The communication signal may have failed to transmit
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}
