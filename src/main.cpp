#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
pinMode(14,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(14,HIGH);
delay(1000/2);
digitalWrite(14,LOW);
delay(1000/2);
}

