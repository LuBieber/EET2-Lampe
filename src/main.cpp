#include <Arduino.h>
#include <math.h>
//Variablen
int hell=0; //Taster1
int dunkel=1; //Taster 2
int nulldg = 6;
int triac = 3;
int zuendwinkel = 10; //in Grad
int z_vor = 0;


void setup() {
pinMode(nulldg,INPUT);
pinMode(triac,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
}

void loop() {
if (digitalRead(hell)==1)
{
  zuendwinkel--;
}

if (digitalRead(dunkel)==1)
{
  zuendwinkel++; 
}

if (digitalRead(nulldg)==1 && z_vor==0)
{
  delayMicroseconds(round(pow(10,6)*zuendwinkel*0.01/180));
  digitalWrite(triac,HIGH);
  delayMicroseconds(10);
  digitalWrite(triac,LOW);
  z_vor=1;
}else if (digitalRead(nulldg)==0) //verhindert wiederholtes Gatesignal
{
  z_vor=0;
}
}



