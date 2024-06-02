#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
pinMode(14,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int frequenz =1000/2;
digitalWrite(14,HIGH);
delay(frequenz);
digitalWrite(14,LOW);
delay(frequenz);
}

