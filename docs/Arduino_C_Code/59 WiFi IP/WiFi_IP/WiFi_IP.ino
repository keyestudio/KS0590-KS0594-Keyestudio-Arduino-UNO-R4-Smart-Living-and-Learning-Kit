/*
 * File name: WiFi IP
 * Function: connect to router, read wifi IP address
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "WiFiS3.h"
#include "arduino_secrets.h"

//Please enter your sensitive data in the Secret TAB /arduino_secrets.h
char ssid[] = "test12";   // your wifi SSID(name)
char pass[] = "11111111"; // your wifi passwords (For WPA, or as a WEP key)
int keyIndex = 0;         // your wifi key index number (required for WEP only)
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);  // baud rate to 9600

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
    Serial.println(ssid);                   // Print Network Name (SSID)

    // Connect to a WPA/WPA2 network, if using an open or WEP network, change this line:
    status = WiFi.begin(ssid, pass);
    // Wait 10 seconds to connect:
    delay(10000);
  }
  server.begin();                           // Start the web server on port 80
  printWifiStatus();                        // You're now connected, so print out the status
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
      }     
    }
    // disconnect
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus() {
  // Print the SSID of the wifi you are connected to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address received by the main control board:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // Print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
