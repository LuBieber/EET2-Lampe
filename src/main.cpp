#include <Arduino.h>
#include <math.h>

//Variablen 
int hell=0; //Taster1
int dunkel=1; //Taster 2
int nulldg = 6; //Nulldurchgangeingang
int triac = 3; //Triacgate

int amin = 6;  //min Zuendwinkel
int amax = 176; //max Zuendwinkel
int zuendwinkel = 10; //bei Start in Grad 
int z_vor = 0;

void setup() {
pinMode(nulldg,INPUT);
pinMode(triac,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
}

void loop() {
//Dimm Taster
if (digitalRead(hell)==1) //werden beide gedrückt wird es heller
{
  zuendwinkel--;
}else if (digitalRead(dunkel)==1)
{
  zuendwinkel++; 
}

//Begrenzen des Zuendwinkel
if (zuendwinkel>amax)
{
  zuendwinkel=amax;
}else if (zuendwinkel<amin)
{
  zuendwinkel=amin;
}

//Zünden
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



