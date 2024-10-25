/*  
 * File name: Photoresistor
 * Function: read Photoresistor value to determine the light intensity
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ANALOG_IN = A0;   //define Photoresistor pin to A0

void setup() {
  Serial.begin(9600);   //baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    //set Photoresistor pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //read the analog value of Photoresistor
  int dacVal = map(adcVal, 0, 1023, 0, 255);
  double voltage = adcVal / 1023.0 * 5.0;
  Serial.print("ADC Val: ");    //print string ADC Val:
  Serial.print(adcVal);    //print adcVal
  Serial.print(" |DAC Val: ");    //print string   DAC Val:  
  Serial.print(dacVal);    //print adcVal
  Serial.print(" |Voltage: ");    //print string   Voltage:  
  Serial.println(voltage);    //print voltage
  delay(200);
}