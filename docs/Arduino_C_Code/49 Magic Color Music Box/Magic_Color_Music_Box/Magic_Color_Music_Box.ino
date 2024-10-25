/*  
 * File name: Magic_Color_Music_Box
 * Function: Ultrasonic measurement distance control buzzer and 7 LED analog magic color music box
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int trig = A1;  //define ultrasonic Trig pin to A1
int echo = A0;  //define ultrasonic Echo pin to A0
int LED1 = 6;   //define LED1 pin to 6
int LED2 = 7;   //define LED2 pin to 7
int LED3 = 8;   //define LED3 pin to 8
int LED4 = 9;   //define LED4 pin to 9
int LED5 = 10;   //define LED5 pin to 10
int LED6 = 11;   //define LED6 pin to 1
int LED7 = 12;   //define LED7 pin to 12
int beeppin = 2;  //define passive buzzer pin to 2

int duration = 0;  //define variable duration with an initial value of 0
int distance = 0;  //define variable distance with an initial value of 0

void setup() {
  Serial.begin(9600);     //set baud rate to 9600
  pinMode(trig, OUTPUT);  //set ultrasonic Trig digital pin to output
  pinMode(echo, INPUT);   //set ultrasonic Echo digital pin to output
  pinMode(LED1, OUTPUT);  //set LED1 digital pin to output
  pinMode(LED2, OUTPUT);  //set LED2 digital pin to output
  pinMode(LED3, OUTPUT);  //set LED3 digital pin to output
  pinMode(LED4, OUTPUT);  //set LED4 digital pin to output
  pinMode(LED5, OUTPUT);  //set LED5 digital pin to output
  pinMode(LED6, OUTPUT);  //set LED6 digital pin to output
  pinMode(LED7, OUTPUT);  //set LED7 digital pin to output
  pinMode(beeppin, OUTPUT); //set passive buzzer digital pin to output
  noTone(beeppin);  //stop playing
}

void loop(){
  //Keep trigPin output high for 10μs to trigger HC_SR04
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Wait for HC-SR04 to return to high and measure this wait time
  duration = pulseIn(echo, HIGH);
  //Calculate distance based on time
  distance = (duration / 2) / 28.5;
  Serial.println(distance);  //Serial port print distance value
  if (distance > 0 && distance <= 5){  //if the detected distance is within 0~5cm 
    digitalWrite(LED1, HIGH);  //LED1 on
    tone(beeppin, 262);  //passive buzzer plays tone do
    delay(1000);  //delay 1000ms
  }
  else{  //or else, the detected distance is without 0~5cm 
    digitalWrite(LED1, LOW);  //LED1 off
    noTone(beeppin);  //stop playing
  }
  if (distance > 5 && distance <= 10){  //if the detected distance is within 5~10cm 
    digitalWrite(LED2, HIGH);  //LED2 on
    tone(beeppin, 294);  //passive buzzer plays tone re
    delay(750);
  }
  else{  //or else, the detected distance is without 5~10cm 
    digitalWrite(LED2, LOW);  //LED2 off
    noTone(beeppin);  //stop playing
  }
  if (distance > 10 && distance <= 15){  //if the detected distance is within 10~15cm 
    digitalWrite(LED3, HIGH);  //LED3 on
    tone(beeppin, 330);  //passive buzzer plays tone mi
    delay(625);
  }
  else{  //or else, the detected distance is without 10~15cm 
    digitalWrite(LED3, LOW);  //LED3 off
    noTone(beeppin);  //stop playing
  }
    if (distance > 15 && distance <= 20){  //if the detected distance is within 15~20cm 
    digitalWrite(LED4, HIGH);  //LED4 on
    tone(beeppin, 349);  //passive buzzer plays tone fa
    delay(500);
  }
  else{  //or else, the detected distance is without 15~20cm 
    digitalWrite(LED4, LOW);  //LED4 off
    noTone(beeppin);//stop playing
  }
  if (distance > 20 && distance <= 25){  //if the detected distance is within 20~25cm 
    digitalWrite(LED5, HIGH);  //LED5 on
    tone(beeppin, 392);  //passive buzzer plays tone so
    delay(375);
  }
  else{  //or else, the detected distance is without 20~25cm 
    digitalWrite(LED5, LOW);  //LED5 off
    noTone(beeppin);//stop playing
  }
  if (distance > 25 && distance <= 30){  //if the detected distance is within 25~30cm 
    digitalWrite(LED6, HIGH);  //LED6 on
    tone(beeppin, 440);   //passive buzzer plays tone la
    delay(250);
  }
  else{  //or else, the detected distance is without 25~30cm 
    digitalWrite(LED6, LOW);  //LED6 off
    noTone(beeppin);//stop playing
  }
  if (distance > 30 && distance <= 35){  //if the detected distance is within 30~35cm 
    digitalWrite(LED7, HIGH);  //LED7 on
    tone(beeppin, 494);  //passive buzzer plays tone si
    delay(125);
  }
  else{  //or else, the detected distance is without 30~35cm 
    digitalWrite(LED7, LOW);  //LED7 off
    noTone(beeppin);//stop playing
  }
}     
