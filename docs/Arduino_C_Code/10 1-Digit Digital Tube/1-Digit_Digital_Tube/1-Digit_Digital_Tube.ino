/*
 * File name: 1-Digit_Digital_Tube
 * Function: 1-Digit_Digital_Tube shows number 0-9
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
// Set the IO pins of each segment
int a=7;// Set a-segment pin to digital pin 7
int b=6;// Set b-segment pin to digital pin 6
int c=5;// Set c-segment pin to digital pin 5
int d=10;// Set d-segment pin to digital pin 10
int e=11;// Set e-segment pin to digital pin 11
int f=8;// Set f-segment pin to digital pin 8
int g=9;// Set g-segment pin to digital pin 9
int dp=4;// Set dp-segment pin to digital pin 4

void setup(){
  int i;// Set variable
  for(i=4;i<=11;i++)
  pinMode(i,OUTPUT);// Set pins 4-11 to output
}

void loop(){
  while(1){
    digital_0();// Display number  0
    delay(1000);// Delay 1s
    digital_1();// Display number  1
    delay(1000);// Delay 1s
    digital_2();// Display number  2
    delay(1000); // Delay 1s
    digital_3();// Display number  3
    delay(1000); // Delay 1s
    digital_4();// Display number  4
    delay(1000); // Delay 1s
    digital_5();// Display number  5
    delay(1000); // Delay 1s
    digital_6();// Display number  6
    delay(1000); // Delay 1s
    digital_7();// Display number  7
    delay(1000); // Delay 1s
    digital_8();// Display number  8
    delay(1000); // Delay 1s
    digital_9();// Display number  9
    delay(1000); // Delay 1s
  }
}

void digital_0(void) { // Display number 0
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) { // Display number  1
  unsigned char j;
  digitalWrite(c,HIGH);// Set pin 5 to high, light up segment c
  digitalWrite(b,HIGH);// light up segment b
  for(j=7;j<=11;j++)// turn off other segments
  digitalWrite(j,LOW);
  digitalWrite(dp,LOW);// turn off segment dp
}
void digital_2(void) { // Display number  2
  unsigned char j;
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  for(j=9;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void digital_3(void) { // Display number  3
  digitalWrite(g,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(f,LOW);
  digitalWrite(e,LOW);
}
void digital_4(void) { // Display number  4
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}
void digital_5(void) { // Display number  5
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void digital_6(void) { // Display number  6
  unsigned char j;
  for(j=7;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
}
void digital_7(void) { // Display number  7
  unsigned char j;
  for(j=5;j<=7;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  for(j=8;j<=11;j++)
  digitalWrite(j,LOW);
}
void digital_8(void) { // Display number  8
  unsigned char j;
  for(j=5;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
}
void digital_9(void) { // Display number  9
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
