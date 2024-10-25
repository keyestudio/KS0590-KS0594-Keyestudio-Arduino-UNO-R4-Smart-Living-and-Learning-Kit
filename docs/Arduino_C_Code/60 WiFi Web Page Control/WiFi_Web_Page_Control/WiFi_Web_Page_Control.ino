/*
 * File name: WiFi Web Page Control 
 * Function: WiFi Web Page Control multiple modules to simulate WiFi smart life
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "WiFiS3.h"
#include "arduino_secrets.h" 
#include <Servo.h>
#include <SoftwareSerial.h>  //Soft serial port library

SoftwareSerial mySerial(10, 11); //MP3 TX pin to 10，RX pin to 11
 
//Please enter your sensitive data in the Secret TAB /arduino_secrets.h
char ssid[] = "test12";    // Your wifi SSID(Name)
char pass[] = "11111111";  // Your wifi password (for WPA, or as a WEP key)
int keyIndex = 0;          // Your wifi Key Index number (required for WEP only)
int val = 0;

int redPin = 6;    // define RGB redpin pin to D6
int greenPin = 5;  // define RGB greenpin pin to D5
int bluePin = 3;   // define RGB bluepin pin to D3
int buzzerPin = 2; // define active buzzer pin to D2
int motorPin = 9;  // define the digital control pin of DC motor to D9
int servoPin = 8;  // define servo pin to 8
Servo myservo;  // Create a servo object to control the servo

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600); // Initialize the hardware serial port
  mySerial.begin(9600); // Initialize the software serial port
  pinMode(redPin, OUTPUT);  // set RGB redpin pin to output
  pinMode(greenPin, OUTPUT);  // set RGB greenpin pin to output
  pinMode(bluePin, OUTPUT);  // set RGB bluepin pin to output
  pinMode(motorPin, OUTPUT);  // set DC motor motorPin pin to output
  pinMode(buzzerPin, OUTPUT);  // set active buzzer pin to output

  myservo.attach(servoPin);  //set servo pin to D8
  myservo.write(0); //Rotate to 0 degrees
  delay(1000); //delay 1s

  // Check WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // Not continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // Try to connect to a WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);     // Print Network Name (SSID)

    // Connect to a WPA/WPA2 network, if using an open or WEP network, change this line:
    status = WiFi.begin(ssid, pass);
    // Wait 10 seconds to connect:
    delay(10000);
  }
  server.begin();      // Start the web server on port 80
  printWifiStatus();   // You're now connected, so print out the status
}

void loop() {
  WiFiClient client = server.available();   // Monitor incoming clients in real time

  if (client) {                             // If you're listening to the client,
    Serial.println("new client");           // Print a message on the serial port
    String currentLine = "";                // Creates a string to hold the data passed in from the client
    while (client.connected()) {            // Loop when the client connects
      if (client.available()) {             // If there are bytes to be read from the client,
        char c = client.read();             // Read a byte, and then
        Serial.write(c);                    // Print to serial monitor
        if (c == '\n') {                    // If the byte is a newline character

          // If the current action is empty, there are two newlines in a line.
          // This is the end of the client's HTTP request, so a response is sent:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // And a content type so the client knows what's going to happen, followed by a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // The content of the HTTP response follows the header:
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/A\">here</a> turn on RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/B\">here</a> turn off RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/C\">here</a> turn on fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/D\">here</a> turn off fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/E\">here</a> turn on buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/F\">here</a> turn off buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/G\">here</a> turn on MP3<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> <br>servo turn to 180</p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/I\">here</a> <br>servo turn to 0</p>");
           
            // The HTTP response ends with another blank line:
            client.println();
            // exit the while loop:
            break;
          } else {    // If there is a newline, clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // If you have any characters other than the return character,
          currentLine += c;      // And add it to the end of currentLine
        }

        // Check whether the client request exists "GET /A"or"GET /B"or"GET /C"or"GET /D"or"GET /E"or"GET /F"or"GET /G"or"GET /H"or"GET /I":
        if (currentLine.endsWith("GET /A")) {    // GET /A RGB on
          // Cycle through basic colors
          color(255, 0, 0);  // Red
          delay(1000);       // Wait for 1 second
          color(0, 255, 0);  // Green
          delay(1000);       // Wait for 1 second
          color(0, 0, 255);  // Blue
          delay(1000);       // Wait for 1 second

          // Cycle through blended colors
          color(255, 0, 252);  // Magenta
          delay(1000);         // Wait for 1 second
          color(237, 109, 0);  // Orange
          delay(1000);         // Wait for 1 second
          color(255, 215, 0);  // Yellow
          delay(1000);         // Wait for 1 second
          color(34, 139, 34);  // Forest Green
          delay(1000);         // Wait for 1 second
          color(0, 112, 255);  // Light Blue
          delay(1000);         // Wait for 1 second
          color(0, 46, 90);    // Indigo
          delay(1000);         // Wait for 1 second
          color(128, 0, 128);  // Purple
          delay(1000);         // Wait for 1 second       
        }
        if (currentLine.endsWith("GET /B")) {    // GET /B RGB off
          color(0, 0, 0);  // Black
        }
        if (currentLine.endsWith("GET /C")) {  // GET /C DC motor rotates
          digitalWrite(motorPin, LOW);                
        }
        if (currentLine.endsWith("GET /D")) {  // GET /D DC motor does not rotate
          digitalWrite(motorPin, HIGH);               
        }
        if (currentLine.endsWith("GET /E")) {  // GET /E turn on buzzer
          digitalWrite(buzzerPin, HIGH);                               
        }
        if (currentLine.endsWith("GET /F")) {  // GET /F turn off buzzer
          digitalWrite(buzzerPin, HIGH);                               
        }
        if (currentLine.endsWith("GET /G")) {  // GET /F MP3 plays audio
          MP3();          
        }
        if (currentLine.endsWith("GET /H")) {  // GET /H servo rotates to 180°
          myservo.write(180); //servo rotates to 180°
          delay(1000); //delay 1s
        }
        if (currentLine.endsWith("GET /I")) {  // GET /I servo rotates to 0°
          myservo.write(0); //servo rotates to 0°
          delay(1000); //delay 1s
        }
      } 
    }
    // disconnect:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus() {
  // Print the SSID of the wifi you are connected to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address received by the main control board
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // Print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  
  // open http://[ip] in your browser
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

void MP3() {
  int cmd1[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x01, 0xef}; //song 01 corresponding command, hexadecimal
  for(char i=0; i<8; i++){  
    mySerial.write(cmd1[i]); 
  }
  delay(2000);

  int cmd2[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x02, 0xef}; //song 02 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd2[i]);
  }
  delay(2000);

  int cmd3[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x03, 0xef}; //song 03 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd3[i]);
  }
  delay(2000);

  int cmd4[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x04, 0xef}; //song 04 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd4[i]);
  }
  delay(2000);

  int cmd5[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x05, 0xef}; //song 05 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd5[i]);
  }
  delay(2000);

  int cmd6[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x06, 0xef}; //song 06 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd6[i]);
  }
  delay(2000);

  int cmd7[]={0x7e, 0xff, 0x06, 0x0f, 0x00, 0x01, 0x07, 0xef}; //song 07 corresponding command, hexadecimal
  for(char i=0; i<8; i++){
    mySerial.write(cmd7[i]);
  }
  delay(2000);
  
}

// Function to set the RGB LED color
void color(int red, int green, int blue) {    
  // Write analog values to the RGB pins
  analogWrite(redPin, red);   
  analogWrite(greenPin, green); 
  analogWrite(bluePin, blue); 
}
