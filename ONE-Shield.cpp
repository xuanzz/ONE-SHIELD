#include "Arduino.h"
#include"ONE-Shield.h"

LED::LED(String LED_Name)
{
	if (LED_Name == "left" || LED_Name == "green" || LED_Name == "g" || LED_Name == "l")
	{
		  _pin = left_LED_Pin;
	}
		if (LED_Name == "right" || LED_Name == "red" || LED_Name == "r")
	{
		  _pin = right_LED_Pin;
	}
  pinMode(_pin, OUTPUT);
}

void LED::on()
{
  digitalWrite(_pin,HIGH);
}

void LED::off()
{
  digitalWrite(_pin,LOW);
}


Motor::Motor(int Motor_Name)
{
	if (Motor_Name == 1)
	{
		PWM = PWMA;
		IN1 = AIN1;
		IN2 = AIN2;
	}
		if (Motor_Name == 2)
	{
		PWM = PWMB;
		IN1 = BIN1;
		IN2 = BIN2;
	}
  pinMode(PWM, OUTPUT);
    pinMode(IN1, OUTPUT);
	  pinMode(IN2, OUTPUT);
}

void Motor::on(int direction)
{
	if (direction)
	{
		Motor::turn(defaultSpeed);
	}
	else
	{
		Motor::turn(-defaultSpeed);
	}
}
void Motor::off()
{
	analogWrite(PWM,0);
}
void Motor::turn(int motorValue)
{
	if (motorValue<0){digitalWrite(IN1,HIGH-reversed);digitalWrite(IN2,reversed-LOW);motorValue=-motorValue;}
	else if (motorValue>0){digitalWrite(IN1,reversed-LOW);digitalWrite(IN2,HIGH-reversed);}
	analogWrite(PWM,constrain(motorValue,0,255));
	digitalWrite(EN,HIGH);
}
