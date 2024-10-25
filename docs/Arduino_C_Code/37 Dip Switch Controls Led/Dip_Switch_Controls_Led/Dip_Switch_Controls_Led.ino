/*  
 * File name: Dip_Switch_Controls_Leds
 * Function: Dip_Switch_Controls_Leds
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int redpin = 3; //define red LED to digital pin 3
int greenpin = 5; //define green LED to digital pin 5
int redled = 11;  //define red LED to digital pin 11
int greenled = 10; //define green LED to digital pin 10

void setup() {
  pinMode(redled,OUTPUT);   //set red LED pin to output
  pinMode(greenled, OUTPUT);   //set green LED pin to output 
  pinMode(redpin, INPUT);   //set red LED pin to input
  pinMode(greenpin,INPUT);   //set green LED pin to input
}

void loop(){
  int val = digitalRead(redpin); //read red LED value and assign it to variable val
  if (val == HIGH){  //If red LED value is HIGH 
    digitalWrite(redled, HIGH);  //red LED on
  }
  else{ //otherwise, red LED value is not HIGH 
    digitalWrite(redled,LOW);  //red LED off
  }
  int val1 = digitalRead(greenpin); //read green LED value and assign it to variable val1
  if (val1 == HIGH) { //If green LED value is HIGH 
    digitalWrite(greenled, HIGH);  //green LED on
  }
  else{  //otherwise, green LED value is not HIGH 
    digitalWrite(greenled,LOW);  //green LED off
  }
}

