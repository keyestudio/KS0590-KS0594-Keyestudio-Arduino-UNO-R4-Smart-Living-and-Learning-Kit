/*  
 * File name: xht11
 * Function: detect temperature and humidity via xht11
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "DHT.h"  //DHT library
#define DHTPIN 3  //define XHT11 pin to digital pin 3
DHT dht(DHTPIN, DHT11);  //initialize

void setup() {
  Serial.begin(9600); //start serial monitor and set baud rate to 9600
  Serial.println(F("DHTxx test!")); //serial monitor shows “DHTxx test!”
  dht.begin(); //dht works
}

void loop() {
  // Wait a few seconds between measurements.
  delay(500);
  // Reading the temperature or humidity takes about 250 milliseconds!
  // Sensor readings can also be as high as 2 seconds (this is a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature in degrees Celsius (default)
  float t = dht.readTemperature();
  // The reading temperature is degrees Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check for read failures and exit early (try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Calculate the Fahrenheit Temperature index (default)
  float hif = dht.computeHeatIndex(f, h);
  // The heat index is calculated in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
