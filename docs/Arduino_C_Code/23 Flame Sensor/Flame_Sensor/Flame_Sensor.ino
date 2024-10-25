/*  
 * File name: Flame_Sensor
 * Function: read Flame_Sensor value
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ANALOG_IN = A0;   //define Flame_Sensor pin to A0

void setup() {
  Serial.begin(9600);   //baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    //set Flame_Sensor pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //read the analgo value of Flame_Sensor
  int dacVal = map(adcVal, 0, 1023, 0, 255);
  double voltage = adcVal / 1023.0 * 5.0;
  Serial.print("ADC Val: ");    //print string ADC Val:
  Serial.print(adcVal);    //print adcVal 
  Serial.print(" |DAC Val: ");    //print string   DAC Val:  
  Serial.print(adcVal);    //print adcVal 
  Serial.print(" |Voltage: ");    //print string   Voltage:  
  Serial.println(voltage);    //print voltage 
  delay(200);
}