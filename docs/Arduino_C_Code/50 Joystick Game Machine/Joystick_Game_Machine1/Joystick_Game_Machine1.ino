/*  
 * File name: Joystick_Game_Machine1
 * Function: Joystick controls UNO R4 WIFI on-board LED matrix to simualte game machine
 * Compiling IDE: ARDUINO 2.3.2
 * Author: https://www.keyestudio.com/
*/
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// Define the pin of the joystick
const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickButtonPin = 7;

// Define the size of the matrix
const int width = 12;
const int height = 8;

// Define the position of the current square
int blockX = 5;
int blockY = 0;

// Define the state of the matrix
uint8_t grid[height][width] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
  pinMode(joystickButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read the X and Y axis values of the joystick
  int xValue = analogRead(joystickXPin);
  int yValue = analogRead(joystickYPin);

  // control the position of the square by moving the joystick
  if (xValue > 800) {
    // Shake the joystick to the left (positive on the X axis on the joystick module)
    if (blockX > 0) {
      blockX--;
    }
  } else if (xValue < 300) {
    // Shake the joystick to the right (opposite the X axis on the joystick module)
    if (blockX < width - 2) {
      blockX++;
    }
  }

  // Check that the button is pressed
  if (digitalRead(joystickButtonPin) == LOW) {
    // put a square
    placeBlock();
    delay(300); // Prevent button jitter
  }

  // Render matrix
  renderGrid();
  delay(100); // Delay 100 milliseconds to prevent joystick jitter
}

void placeBlock() {
  // Check if you can place squares
  if (blockY + 1 < height && grid[blockY + 1][blockX] == 0 && grid[blockY + 1][blockX + 1] == 0) {
    blockY++;
  } else {
    // place square
    grid[blockY][blockX] = 1;
    grid[blockY][blockX + 1] = 1;
    grid[blockY + 1][blockX] = 1;
    grid[blockY + 1][blockX + 1] = 1;

    // Check if it is full
    if (isGridFull()) {
      resetGrid();
    } else {
      // Reset square position
      blockX = 5;
      blockY = 0;
    }
  }
}

boolean isGridFull() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (grid[y][x] == 0) {
        return false;
      }
    }
  }
  return true;
}

void resetGrid() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      grid[y][x] = 0;
    }
  }
}

void renderGrid() {
  uint8_t frame[height][width];
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      frame[y][x] = grid[y][x];
    }
  }

  // Render current square
  if (blockY + 1 < height && grid[blockY + 1][blockX] == 0 && grid[blockY + 1][blockX + 1] == 0) {
    frame[blockY][blockX] = 1;
    frame[blockY][blockX + 1] = 1;
    frame[blockY + 1][blockX] = 1;
    frame[blockY + 1][blockX + 1] = 1;
  }

  // Render matrix
  matrix.renderBitmap(frame, height, width);
}