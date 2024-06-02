#include <Arduino.h>
#include <math.h>
//Variablen 
int hell=0; //Taster1
int dunkel=1; //Taster 2
int triac = 3; //Triacgate

int amin = 6;  //min Zuendwinkel
int amax = 176; //max Zuendwinkel
int zuendwinkel = 10; //bei Start in Grad 

void zuenden(){
  delayMicroseconds(round(pow(10,6)*(float)zuendwinkel*0.01/180));
  digitalWrite(triac,HIGH);
  delayMicroseconds(10);
  digitalWrite(triac,LOW);
}

void setup() {
pinMode(triac,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
attachInterrupt(digitalPinToInterrupt(9),zuenden,RISING);
}

void loop() {
//Dimm Taster
if (digitalRead(hell)==1 && zuendwinkel>amin) //werden beide gedrückt wird es heller
{
  zuendwinkel--;
}else if (digitalRead(dunkel)==1 && zuendwinkel<amax)
{
  zuendwinkel++; 
}
}
