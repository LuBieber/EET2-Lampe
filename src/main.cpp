#include <Arduino.h>
#include <math.h>
//Variablen
int nulldg = 6;
int triac = 3;
int zuendwinkel = 10; //in Grad
int t_s = round(pow(10,6)*zuendwinkel*0.01/180); //t_s in us


void setup() {
pinMode(nulldg,INPUT);
pinMode(triac,OUTPUT);
}

void loop() {
if (digitalRead(nulldg)==1)
{
  delayMicroseconds(t_s);
  digitalWrite(triac,HIGH);
  delayMicroseconds(10);
  digitalWrite(triac,LOW);
}
while (nulldg==1)
{
  //warten
}

}

