/*  
 * File name: Temperature-humidity meter
 * Function: IIC 1602 LCD displays temperature and humidity analog temperature and humidity meter
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
 */
#include "DHT.h"  //DHT Library 
#include <Wire.h>  //Wire Library 
#include <LiquidCrystal_I2C.h>  //IIC 1602 LCD display Library 
LiquidCrystal_I2C lcd(0x27,16,2);  // Set the LCD address to 0x27 and display it in 16 characters and 2 lines

#define DHTPIN  3    //define XHT11 to the digital pin 3
DHT dht(DHTPIN, DHT11);  //initialize

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  lcd.init();   // initialize LCD
  lcd.clear();   // clear the LCD display
  lcd.backlight(); //turn on LCD backlight
  dht.begin();  //dht works
}

void loop() {
  lcd.setCursor(0,0);  //LCD display location
  lcd.print("Humidity: ");  //LCD display strings Humidity:
  lcd.print((const int)dht.readHumidity());  //The LCD displays the humidity measured by XHT11
  lcd.print("%"); //LCD shows %
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print((const int)dht.readTemperature()); //LCD displays the temperature measured by XHT11
  lcd.print("C");
  delay(100);
}

