/*
This sample uses Motor Port 2 in ONE-Shield as a driver for a fan.
*/

#include <ONE-Shield.h>
Motor FAN(2); //create a motor object using Morot 2
LED green("green"); //create a green LED object

void setup() {
  // put your setup code here, to run once:
  FAN.off();
}

void loop() {
  // put your main code here, to run repeatedly:
FAN.on();
green.on();
delay(2000);
green.off();
FAN.off();
delay(2000);
}