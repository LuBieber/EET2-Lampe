#include <Arduino.h>
//Variablen
int nulldg = 6;
int triac =3;
int blinkabstand=1; //Zeit zwischen blinken in sekunden
int ndg_counter;
int needed_counter = 2*50*blinkabstand; //benötigter counter, da 2 Ndg in Periode 

void setup() {
pinMode(nulldg,INPUT);
pinMode(triac,OUTPUT);
}

void loop() {
if (digitalRead(nulldg)==1)
{
  ndg_counter++;
}
if (ndg_counter%needed_counter==0)
{
  digitalWrite(triac,HIGH);
  delayMicroseconds(10);
  digitalWrite(triac,LOW);
}
}

