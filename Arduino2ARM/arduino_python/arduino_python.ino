#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_NeoPixel.h>
#include "global.h"

// 函式宣告
void moveServo(int channel, int angle);
void white_light_open();
void light_close();
void head_zero();
void head_left();
void head_right();
void initialized();
void stand();

void setup() {
  Serial.begin(BAUDRATE);

  myServo.begin();
  myServo.setPWMFreq(50);  // 設定伺服 PWM 頻率
  
  strip.begin();       // 初始化燈條
  strip.show();        // 關閉所有 LED

  val = 't';
}

void loop() {
  if (Serial.available()) {
    char incoming = Serial.read();
    if (isAlpha(incoming)) {
      val = toupper(incoming);
      Serial.print("收到指令: ");
      Serial.println(val);
    }
  }

  switch (val) {
    case 'A':
      Serial.println("動作 A : 全腳位初始化");
      initialized();
      val = 'n';
      break;

    case 'B':
      Serial.println("動作 B : 站立");
      stand();
      val = 'n';
      break;

    case 'C':
      Serial.println("動作 C: 燈光開啟");
      white_light_open();
      val = 'n';
      break;

    case 'D':
      Serial.println("動作 D: 燈光關閉");
      light_close();
      val = 'n';
      break;

    case 'Z':
      Serial.println("動作 Z: ZERO");
      initialized();
      val = 'n';
      break;

    case 'T':
      Serial.println("動作 T: 測試");
      moveServo(11,90 );
      val = 'n';
      break;

    case 'J':
      Serial.println("動作 J: 轉向_邊");
      head_left();
      val = 'n';
      break;
    
    case 'K':
      Serial.println("動作 K: 看前面");
      head_zero();
      val = 'n';
      break;

    case 'L':
      Serial.println("動作 L: 轉向_邊");
      head_right();
      val = 'n';
      break;

    default:
      break;
  }

  delay(100);
}

