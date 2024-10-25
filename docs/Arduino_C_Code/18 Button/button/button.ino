/*
 * File name: button
 * Function: read button value
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
int val = 0;            //initialize a variable to store the button value
int button = 7;         //set button pin to D7

void setup() {
  Serial.begin(9600);      //start serial monitor and set baud rate to 9600
  pinMode(button, INPUT);  //set button pin to input
}

void loop() {
  val = digitalRead(button);  //read button value and assign it to val
  Serial.print(val);          //print val
  if (val == 0) {             //press the button to read low, and print related messages
    Serial.print("    ");  
    Serial.println("Press the botton"); 
    delay(100);
  }
  else {               //release the button
    Serial.print("    ");
    Serial.println("Loose the botton");
    delay(100);
  }
}
