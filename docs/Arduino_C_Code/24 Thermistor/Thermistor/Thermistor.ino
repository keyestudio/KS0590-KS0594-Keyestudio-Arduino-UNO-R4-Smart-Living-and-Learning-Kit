/*  
 * File name: Thermistor
 * Function: detect temperature via Thermistor
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#define PIN_ANALOG_IN   A0

float Rt=0;      //NTC Thermistor
float R=10000;   //10K resistors with fixed resistance values
float T2=273.15+25; //Convert to Kelvin temperature
float B=3950;    //B value is an important parameter of thermistor
float K=273.15;  //Kelvin (K°)
float VR=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int AnalogValue = analogRead(PIN_ANALOG_IN);    //read analog value of pin A0
  VR = (float)(AnalogValue / 1023.0 * 5.0);  //convert to voltage value
  Rt = (5.0 - VR) / VR * 10000;    //calculate NTC Thermistor
  float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;//calculate temperature 
  Serial.print("Analog value:");
  Serial.print(AnalogValue);
  Serial.print("  |  Voltage:");
  Serial.print(VR);
  Serial.print("V");
  Serial.print("  |  Temperature:");
  Serial.print(temp);
  Serial.println("℃");
  delay(1000);
}
