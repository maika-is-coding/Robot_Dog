#pragma once
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_NeoPixel.h>

class HardwareSerial;
extern HardwareSerial Serial;


#define LED_PIN   11
#define LED_COUNT 7

#define BAUDRATE 9600

#define SERVOMIN 60
#define SERVOMAX 580

char val;
int R_back[] = {0,1,2};
int L_back[] = {4,5,6};
int R_front[] = {8,9,10};
int L_front[] = {12,13,14};
int head[] = {7}; 
int test_servo[] = {11};

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);