/*  
 * File name: OLED
 * Function: OLED display
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Bitmap data
static const unsigned char PROGMEM sunfounderIcon[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x01, 0x00, 0x07, 0xff, 0xff, 
	0xff, 0xff, 0xc0, 0x07, 0xc0, 0x01, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xe0, 0x00, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x1f, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xf8, 0x00, 0x3f, 0xff, 
	0xff, 0xfc, 0x00, 0x7f, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0xfe, 0xff, 0x00, 0x07, 0xff, 
	0xff, 0xf8, 0x01, 0xfc, 0x7f, 0x80, 0x03, 0xff, 0xff, 0xf0, 0x03, 0xf8, 0x3f, 0xc0, 0x01, 0xff, 
	0xff, 0xe0, 0x07, 0xf0, 0x0f, 0xe0, 0x00, 0xff, 0xff, 0xc0, 0x0f, 0xe0, 0x07, 0xf8, 0x00, 0x3f, 
	0xff, 0x80, 0x0f, 0xc0, 0x03, 0xfc, 0x00, 0x7f, 0xff, 0x00, 0x1f, 0xc0, 0x01, 0xfe, 0x00, 0xff, 
	0xff, 0x00, 0x0f, 0xe0, 0x00, 0x7f, 0x81, 0xff, 0xff, 0x00, 0x0f, 0xf0, 0x00, 0x3f, 0xc3, 0xff, 
	0xff, 0x80, 0x03, 0xfc, 0x00, 0x1f, 0xe7, 0xff, 0xff, 0xc0, 0x01, 0xfe, 0x00, 0x0f, 0xff, 0xff, 
	0xff, 0xe0, 0x00, 0xff, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0x80, 0x01, 0xff, 0xff, 
	0xff, 0xf8, 0x00, 0x1f, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x0f, 0xf0, 0x00, 0x7f, 0xff, 
	0xff, 0xff, 0x00, 0x07, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x80, 0x03, 0xfc, 0x00, 0x0f, 0xff, 
	0xff, 0xff, 0xc0, 0x00, 0xff, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0x80, 0x03, 0xff, 
	0xff, 0xff, 0xf8, 0x00, 0x3f, 0xc0, 0x01, 0xff, 0xff, 0xf3, 0xfc, 0x00, 0x1f, 0xe0, 0x00, 0xff, 
	0xff, 0xe1, 0xfe, 0x00, 0x07, 0xf8, 0x00, 0x7f, 0xff, 0xc0, 0x7f, 0x00, 0x03, 0xf8, 0x00, 0x7f, 
	0xff, 0x80, 0x3f, 0xc0, 0x01, 0xfc, 0x00, 0xff, 0xff, 0x00, 0x1f, 0xe0, 0x03, 0xf8, 0x00, 0xff, 
	0xfe, 0x00, 0x0f, 0xf0, 0x03, 0xf0, 0x01, 0xff, 0xff, 0x80, 0x07, 0xf8, 0x07, 0xe0, 0x03, 0xff, 
	0xff, 0xc0, 0x01, 0xfc, 0x0f, 0xc0, 0x07, 0xff, 0xff, 0xe0, 0x00, 0xff, 0x1f, 0xc0, 0x0f, 0xff, 
	0xff, 0xf0, 0x00, 0x7f, 0xbf, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0x00, 0x3f, 0xff, 
	0xff, 0xfe, 0x00, 0x0f, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x00, 0x07, 0xfc, 0x00, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x03, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xf0, 0x03, 0xff, 0xff, 
	0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void setup() {
  Serial.begin(9600);

  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);       // Set text size
  display.setTextColor(WHITE);  // Set text color
  display.setCursor(0, 28);     // Set cursor position
  display.println("Hello world!");
  display.display();  // Display the content on the screen
  delay(2000);
  display.clearDisplay();  // Clear the screen

  // Display Inverted Text
  display.setTextColor(BLACK, WHITE);  // 'inverted' text
  display.setCursor(0, 28);
  display.println("Hello world!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0, 24);
  display.setTextSize(2);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display Numbers
  display.setTextSize(1);
  display.setCursor(0, 28);
  display.println(123456789);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display ASCII Characters
  display.setCursor(0, 24);
  display.setTextSize(2);
  for (int i = 1; i < 8; i++) {
    display.write(i);
  }
  display.display();
  delay(2000);
  display.clearDisplay();

  // Scroll full screen
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Full");
  display.println("screen");
  display.println("scrolling!");
  display.display();
  display.startscrollright(0x00, 0x07);  // Scroll the screen to the right
  delay(5000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);  // Scroll the screen to the left
  delay(5000);
  display.stopscroll();
  delay(1000);
  display.clearDisplay();

  // Scroll part of the screen
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Scroll");
  display.println("some part");
  display.println("of the screen.");
  display.display();
  display.startscrollright(0x00, 0x00);  // Scroll the first column of the screen to the right
  delay(4000);
  display.stopscroll();
  display.clearDisplay();

  // Display bitmap
  display.drawBitmap(32, 0, sunfounderIcon, 64, 64, WHITE);
  display.display();
}

void loop() {
}