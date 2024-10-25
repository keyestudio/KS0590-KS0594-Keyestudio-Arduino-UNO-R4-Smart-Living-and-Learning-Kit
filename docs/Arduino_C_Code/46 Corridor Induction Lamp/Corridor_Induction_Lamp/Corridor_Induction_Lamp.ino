/*  
 * File name: Corridor_Induction_Lamp
 * Function: photoresistor and pir motion sensor are used to control LED.
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int PIN_ADC0 = A0;   //define photoresistor pin to analog A0
int ledPin = 10;  //define LED pin to digital 10
int pirPin = 3;     //define pir motion sensor pin to digital 3
byte pirStat = 0;   //pir motion sensor state

void setup() {
  Serial.begin(9600);  //set baud rate 9600
  pinMode(ledPin, OUTPUT);  //set LED pin to output
  pinMode(PIN_ADC0, INPUT);  //set photoresistor pin to input
  pinMode(pirPin, INPUT);  //set pir motion sensor pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //read photoresistor analog value and assign it to variable adcVal
  Serial.println(adcVal); //serial monitor prints adcVal
  pirStat = digitalRead(pirPin); //read pir motion sensor value
  if (adcVal >= 600) { //if photoresistor analog value is greater than or equal to 600 
    if (pirStat == HIGH){  //if pir motion sensor detects a human motion 
      digitalWrite(ledPin, HIGH); //turn on external LED
      delay(5000);
    } 
    else{ //or else pir motion sensor does not detect a human motion 
      digitalWrite(ledPin, LOW); //turn off external LED   
    }
  }
  else{  //or else photoresistor analog value is less than 600 
    digitalWrite(ledPin, LOW); //turn off external LED
  }
}

