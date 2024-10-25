/*  
 * File name: Ultrasonic radar monitoring
 * Function: Ultrasonic control IIC 1602 LCD screen and MP3 module to simulate ultrasonic radar
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include <SoftwareSerial.h> //Soft serial port library
#include <LiquidCrystal_I2C.h> //i2c 1602 LCD library

const int TrigPin = 3; // ultrasonic trig pin to 3
const int EchoPin = 4; // ultrasonic echo pin to 4
SoftwareSerial mySerial(10, 11); // MP3 TX pin to 10，RX pin to 11
LiquidCrystal_I2C lcd(0x27, 16, 2); // initialize I2C LCD
int distance; // Define global variables and save distances.

void setup() {
  Serial.begin(9600);  // set hardware serial baud rate to 9600
  mySerial.begin(9600);  // set software serial baud rate to 9600
  pinMode(TrigPin, OUTPUT);  //set TrigPin to output
  pinMode(EchoPin, INPUT);  //set EchoPin to input
  lcd.clear(); // clear the LCD display
  lcd.init(); // initialize LCD
  lcd.backlight(); // turn on LCD backlight
}

void loop() {
  static int currentTrack = 1;
  playTrack(currentTrack);
  currentTrack++;
  if (currentTrack > 31) {
    currentTrack = 1;
  }

  // Detect the distance and broadcast it, 1602LCD shows 
  distance = getDistance();
  Serial.print(distance);
  Serial.println("cm");
  if (distance > 0 && distance <= 30) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm");
    playDistanceTrack(distance);
  }
  else{
    int cmd[] = {0x7e, 0xff, 0x06, 0x16, 0x00, 0x00, 0x00, 0xef};
    for (char i = 0; i < 8; i++) {
      mySerial.write(cmd[i]);
    }
    delay(2000);
  } 
  delay(5000);
}

void playTrack(int trackNumber) { // LCD shows MP3 broadcast ultrasonic detection distance 
  int cmd[] = {0x7e, 0xff, 0x06, 0x0f, 0x00, 0x02, trackNumber, 0xef};
  for (char i = 0; i < 8; i++) {
    mySerial.write(cmd[i]);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Playing Track: ");
  lcd.print(trackNumber);
}

void playDistanceTrack(int distance) { // LCD shows MP3 broadcast ultrasonic detection distance and “Playing Distance”
  int cmd[] = {0x7e, 0xff, 0x06, 0x0f, 0x00, 0x02, distance, 0xef};
  for (char i = 0; i < 8; i++) {
    mySerial.write(cmd[i]);
  }
  lcd.setCursor(0, 1);
  lcd.print("Playing Distance");
}

float getDistance() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW);
  float distance = pulseIn(EchoPin, HIGH) / 58.0; 
  delay(300);
  return distance;
}