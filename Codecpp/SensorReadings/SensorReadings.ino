#include "String.h"

String comma = ",";
String message;
long startTime, endTime;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  startTime=micros();
  while(true){
    endTime=micros();
    if(endTime-startTime > 1000){
      Serial.print("500,");
      Serial.print(analogRead(A0));
      Serial.println(",580");
      startTime = micros();
    }
  }
  
}
