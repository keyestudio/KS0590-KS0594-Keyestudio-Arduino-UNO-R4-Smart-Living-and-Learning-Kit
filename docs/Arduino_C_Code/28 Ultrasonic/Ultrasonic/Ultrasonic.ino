/*  
 * File name: Ultrasonic
 * Function: detect distance via Ultrasonic sensor
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
const int TrigPin = 4; // define TrigPin
const int EchoPin = 5; // define EchoPin
int duration = 0; // define the initial value of the duration as 0
int distance = 0; // define the initial value of the distance as 0

void setup() {
  Serial.begin(9600);        // set baud rate to 9600
  pinMode(TrigPin, OUTPUT); // set trigPin to output
  pinMode(EchoPin, INPUT);  // set echoPin to input
}

void loop(){
  // Keep trigPin output high for 10μs to trigger HC_SR04
  digitalWrite(TrigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin , LOW);
  // Wait for HC-SR04 to return to high and measure this wait time
  duration = pulseIn(EchoPin , HIGH);
  // Calculate distance based on time
  distance = (duration/2) / 28.5 ;
  Serial.print("Distance: ");
  Serial.print(distance); //serial monitor prints distance value
  Serial.println("cm");
  delay(100); //Wait 100 milliseconds between pings (about 20 pings per second).
}