/*  
 * File name: Temperature_Instrument_Meter
 * Function: The OLED display displays the temperature measured by the thermistor
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN_ANALOG_IN   A0
float Rt=0;      //NTC thermistor
float R=10000;   //10K resistors with fixed resistance values
float T2=273.15+25; //Convert to Kelvin temperature
float B=3950;    //The B value is an important parameter of thermistor
float K=273.15;  //Degree Kelvin (K°)
float VR=0;

#define SCREEN_WIDTH 128 // Display width, in pixels
#define SCREEN_HEIGHT 64 // OLED Display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialization with I2C addr 0x3C (for 128x64)
  display.clearDisplay(); // clear display
}

void loop(){
  int AnalogValue = analogRead(PIN_ANALOG_IN);    //read analog value of A0
  VR = (float)(AnalogValue / 1023.0 * 5.0);  //Convert to a voltage value
  Rt = (5.0 - VR) / VR * 4700;    //calculate NTC thermistor
  float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;//calculate temperature
  display.clearDisplay();  //clear display
  display.setTextSize(1);  //set font size
  display.setTextColor(WHITE);  //set font color
  display.setCursor(15,0);   //set font position
  display.println("Temperature Meter");  //set displayed content 
  display.setCursor(0,25);   //set font position
  display.println("Voltage:");  //set displayed content
  display.setCursor(50,25);
  display.println(VR);
  display.setCursor(80,25);
  display.println("V");
  display.setCursor(0,50);
  display.println("Temperature:");
  display.setCursor(75,50);
  display.println(temp);
  display.setCursor(110,50);
  display.println("C");
  display.display();
  delay(150);
}
