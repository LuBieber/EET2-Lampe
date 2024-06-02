#include <Arduino.h>
//Variablen
int An=0;
int Aus=1;

void setup() {
pinMode(0,INPUT);
pinMode(1,INPUT);
pinMode(LED1,OUTPUT);
}

void loop() {
if (digitalRead(An)==1)
{
  digitalWrite(LED1,HIGH);
}
if (digitalRead(Aus)==1)
{
  digitalWrite(LED1,HIGH);
}
}

