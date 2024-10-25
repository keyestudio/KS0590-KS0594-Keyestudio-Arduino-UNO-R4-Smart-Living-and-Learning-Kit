/*  
 * File name: Potentiometer
 * Function: read the Potentiometer value
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ANALOG_IN = A0;   //define Potentiometer pin to A0

void setup() {
  Serial.begin(9600);   //set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    //set Potentiometer pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //read analog signal of Potentiometer
  int dacVal = map(adcVal, 0, 1023, 0, 255);
  double voltage = adcVal / 1023.0 * 5.0;
  Serial.print("ADC Val: ");    //Print string ADC Val:
  Serial.print(adcVal);    //Print adcVal
  Serial.print(" |DAC Val: ");    //Print string   DAC Val:  
  Serial.print(adcVal);    //Print adcVal
  Serial.print(" |Voltage: ");    //Print string   Voltage:  
  Serial.println(voltage);    //Print voltage
  delay(200);
}