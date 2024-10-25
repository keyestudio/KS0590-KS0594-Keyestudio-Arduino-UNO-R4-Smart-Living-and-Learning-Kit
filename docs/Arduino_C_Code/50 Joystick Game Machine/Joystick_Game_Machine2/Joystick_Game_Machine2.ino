/*  
 * 名称   : Joystick_Game_Machine2
 * 功能   : 摇杆控制UNO R4 WIFI主控板上内置的LED点阵模拟摇杆游戏机
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

// 定义摇杆的引脚
const int joystickXPin = A0;
const int joystickYPin = A1;
const int joystickButtonPin = 7;

// 定义数字显示的初始值
int number = 0;

// 定义桃心图案
uint8_t heart[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
  pinMode(joystickButtonPin, INPUT_PULLUP);
}

void loop() {
  // 读取摇杆的X和Y轴值
  int xValue = analogRead(joystickXPin);
  int yValue = analogRead(joystickYPin);

  // 根据摇杆的移动控制数字的增减
  if (yValue < 200) {
    // 向上摇动摇杆
    if (number < 100) {
      number++;
    }
  } else if (yValue > 800) {
    // 向下摇动摇杆
    if (number > 0) {
      number--;
    }
  } else if (xValue < 200) {
    // 向左摇动摇杆
    if (number < 98) {
      number += 2;
    }
  } else if (xValue > 800) {
    // 向右摇动摇杆
    // 显示桃心图案
    matrix.renderBitmap(heart, 8, 12);
    delay(500); // 显示桃心图案500毫秒
    return;
  }

  // 显示数字
  displayNumber(number);
  delay(200); // 延迟200毫秒，防止摇杆抖动
}

void displayNumber(int num) {
  uint8_t frame[8][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  // 将数字转换为点阵显示
  if (num >= 0 && num <= 9) {
    drawDigit(frame, num, 4, 2); // 单个数字显示在中间
  } else if (num >= 10 && num <= 99) {
    drawDigit(frame, num / 10, 2, 2); // 十位数字显示在中间偏左
    drawDigit(frame, num % 10, 6, 2); // 个位数字显示在中间偏右
  }

  // 渲染点阵
  matrix.renderBitmap(frame, 8, 12);
}

void drawDigit(uint8_t frame[8][12], int digit, int x, int y) {
  // 数字0-9的点阵图案
  uint8_t digits[10][5][3] = {
    { {1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1} }, // 0
    { {0, 1, 0}, {1, 1, 0}, {0, 1, 0}, {0, 1, 0}, {1, 1, 1} }, // 1
    { {1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1} }, // 2
    { {1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} }, // 3
    { {1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1} }, // 4
    { {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} }, // 5
    { {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1} }, // 6
    { {1, 1, 1}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {1, 0, 0} }, // 7
    { {1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1} }, // 8
    { {1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} }  // 9
  };

  // 将数字的点阵图案绘制到frame中
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      frame[y + i][x + j] = digits[digit][i][j];
    }
  }
}