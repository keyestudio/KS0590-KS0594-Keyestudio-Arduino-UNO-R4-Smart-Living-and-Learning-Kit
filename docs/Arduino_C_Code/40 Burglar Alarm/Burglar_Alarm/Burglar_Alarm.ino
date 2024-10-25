/*  
 * File name: Burglar_Alarm
 * Function: PIR controls the buzzer and LED to simulate anti-theft alarm
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#define ledPin  12  // define LED pin to 12
#define PIR_PIN  9  // pir motion sensor pin to 9
#define BUZZER_PIN  3  //define active buzzer pin to 3

int item = 0;  //define variable item with an initial value o f0

void setup() {
  Serial.begin(9600);//set baud rate to 9600
  pinMode(PIR_PIN, INPUT);  //set pir motion sensor pin to input
  pinMode(BUZZER_PIN, OUTPUT); //set active buzzer pin to output
  pinMode(ledPin, OUTPUT);// set led pin to output
}

void loop() {
  item = digitalRead(PIR_PIN); //read the digital signal output by the PIR motion sensor
  Serial.println(item);    //print item
  if (item == 1) {  //motion is detected
    digitalWrite(BUZZER_PIN, HIGH); //turn on buzzer
    digitalWrite(ledPin, HIGH); // turn on LED
    delay(200);//delay 200ms
    digitalWrite(BUZZER_PIN, LOW); //turn off buzzer
    digitalWrite(ledPin, LOW); // turn off LED
    delay(200);//delay 200ms
  } else {  //detect no signals
    digitalWrite(BUZZER_PIN, LOW); //turn off buzzer
    digitalWrite(ledPin, LOW); // turn off LED
  }
}