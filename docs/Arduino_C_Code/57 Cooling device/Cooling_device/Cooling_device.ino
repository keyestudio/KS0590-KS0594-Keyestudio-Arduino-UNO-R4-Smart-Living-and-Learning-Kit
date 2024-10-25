/*  
 * File name: Cooling_device
 * Function: temperature sensor controls four-bit digital tube and motor to simulate cooling device
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <SoftwareSerial.h> //Soft serial port library
#include <LiquidCrystal_I2C.h> //i2c 1602 LCD library

int lm35Pin = A0;   // define LM35 to pin A0
int motorPin = 5;  // define DC motor to pin D5
SoftwareSerial mySerial(10, 11); // MP3 TX to pin 10, RX to pin 11
LiquidCrystal_I2C lcd(0x27, 16, 2); // initialize I2C LCD

void setup() {
  Serial.begin(9600);  // hardware serial baud rate to 9600
  mySerial.begin(9600);  // software serial baud rate to 9600
  pinMode(lm35Pin, INPUT); // set lm35Pin to input
  pinMode(motorPin, OUTPUT); // set motorPin to output
  lcd.init(); // initialize LCD
  lcd.clear(); // clear the LCD display
  lcd.backlight(); // turn on LCD bakclight
}

void loop() {
  int reading = analogRead(lm35Pin);  // read LM35 pin analog value
  int temperC = (reading * 0.0048828125 * 100); //Voltage and Celsius conversion :0.00488125=5/1024, 0~5V corresponds to analog port reading 1~1024, every 10 millivolts corresponds to 1℃, calculate the Celsius temperature.
  int temperF = (temperC * 1.8) + 32.0; // Celsius to Fahrenheit conversion: Fahrenheit = Celsius x 1.8 + 32, calculate the temperature in Fahrenheit
  Serial.print("C: ");
  Serial.print(temperC);
  Serial.print(" C");
  Serial.print("  | F: ");
  Serial.print(temperF);
  Serial.println(" F");
  lcd.setCursor(0,0);
  lcd.print("C: ");
  lcd.print(temperC);
  lcd.print(" C");
  lcd.setCursor(8,0);
  lcd.print("F: ");
  lcd.print(temperF);
  lcd.print(" F");
  delay(10);
  if (temperC > 30) { // When the temperature exceeds 30 ° C, the small speaker on the MP3 module announces the voice and the fan turns on
    lcd.setCursor(0,1);
    lcd.print("Turn on the fan");
    int cmd1[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x0D, 0xef}; //song 1 corresponding command, hexadecimal
    for(char i=0; i<8; i++){
      mySerial.write(cmd1[i]);
    }
    delay(2000);
    digitalWrite(motorPin, HIGH);
  } 
  else { // Otherwise, the MP3 module on the small speaker voice broadcast, fan off
    lcd.setCursor(0,1);
    lcd.print("Turn off the fan"); 
    int cmd2[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x0E, 0xef}; //song 2 corresponding command, hexadecimal
    for(char i=0; i<8; i++){
      mySerial.write(cmd2[i]);
    }
    delay(2000);
    digitalWrite(motorPin, LOW);
  }
}
