/*
ONE-Shield library V0.2
All rights reserved by One Degree Production Service Limited
onedpro.com
Last Update: 02/12/2018
Author: Darren Chan
*/

#ifndef ONE_Shield_h
#define ONE_Shield_h
#include "Arduino.h"
//Pin definitions for Pro Micro
#define left_LED_Pin 2
#define right_LED_Pin 3
#define		PWMA  6
#define		AIN1  8
#define		AIN2  7
#define		PWMB  9
#define		BIN1  16
#define		BIN2  10
#define 	EN	15
//Pin definitions for Pro Mini
#ifdef PRO_MINI
#define		BIN1  11
#define		BIN2  10
#define 	EN	13
#endif

class LED
{
public:
LED(String LED_Name);
void on();
void off();
private:
int _pin;
};

class Motor
{
public:
Motor(int Motor_Name);
void on(int direction = 1);
void off();
void turn(int motorValue);
bool reversed = 0;
int defaultSpeed = 255;
private:
int PWM,IN1,IN2;
};

#endif
