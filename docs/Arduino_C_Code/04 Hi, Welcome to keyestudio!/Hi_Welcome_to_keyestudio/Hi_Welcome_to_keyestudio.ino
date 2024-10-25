/*
 * Name       : Hi, Welcome to keyestudio!
 * Function   : Enter the letter“R”, serial port display“Hi, Welcome to keyestudio!”.
 * Compile IDE：ARDUINO 2.3.2
 * Author     : https://www.keyestudio.com/
*/
char val;   // Define the variable Val 

void setup(){
Serial.begin(9600);   // Set baud rate to 9600
}

void loop(){
  if (Serial.available() > 0) {
    val=Serial.read();  // Reads an instruction or character from a PC to an Arduino and assigns the value“Val”.
    if(val=='R') {  // Check that the letter entered is“R”, if it is
       Serial.println("Hi, Welcome to keyestudio!");  //Serial port printing“Hi, Welcome to keyestudio!”.
    }
  }
} 