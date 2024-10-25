/*  
 * File name: Responder
 * Function: Four buttons control the RGB to simulate responder
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
//define RGB and 4 button pins
int redled = 11;     
int greenled = 10; 
int blueled = 9;  
int redpin = 5;    
int greenpin = 4; 
int bluepin = 3;   
int restpin = 2;
//define variable   
int red;
int green;
int blue;

void setup(){
pinMode(redled,OUTPUT); //set R pin to output
pinMode(greenled,OUTPUT); //set G pin to output
pinMode(blueled,OUTPUT); //set B pin to output
pinMode(redpin,INPUT);  //set RGB red pin to input
pinMode(greenpin,INPUT); //set RGB green pin to input
pinMode(bluepin,INPUT); //set RGB blue pin to input
}

void loop() {
red = digitalRead(redpin); //read RGB light up in red value and store it in red
green = digitalRead(greenpin); //read RGB light up in green value and store it in green
blue = digitalRead(bluepin); //read RGB light up in blue value and store it in blue
if(red == LOW)RED_YES();  //if press RGB red button, execute function RED_YES() 
if(green == LOW)GREEN_YES(); //if press RGB greenbutton, execute function GREEN_YES
if(blue == LOW)BLUE_YES(); ////if press RGB bluebutton, execute function BLUE_YES()
}

void RED_YES() { //execute RGB light up in red until the reset button (connected to digital pin D2), then exit loop
  while(digitalRead(restpin) == 1){ 
    color(255, 0, 0);  //RGB light up in red 
 }
  clear_led(); //RGB off
}

void GREEN_YES(){ //execute RGB light up in greenuntil the reset button (connected to digital pin D2), then exit loop
  while(digitalRead(restpin) == 1){ //press RGB green button
    color(0, 255, 0); //RGB light up in green
  }
  clear_led(); 
}

void BLUE_YES(){ //execute RGB light up in blueuntil the reset button (connected to digital pin D2), then exit loop
  while(digitalRead(restpin) == 1){ 
    color(0, 0, 255); //RGB light up in blue
  }
  clear_led();
}

void clear_led(){ //press the reset button (connected to digital pin D2), RGB off
  color(0, 0, 0); 
}

void color (unsigned char red, unsigned char green, unsigned char blue){  //RGB color control    
  analogWrite(redled, red);   //RGB light up in red 
  analogWrite(greenled,green);  //RGB light up in green
  analogWrite(blueled, blue);   //RGB light up in blue
} 
