#include "String.h"

String comma = ",";
String message;

void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int i=0;i<10;i++){
    message = "acasf(";
    message = message + i + comma + 2*i + comma + 3*i;
    message = message + ")asdwa";
    Serial.println(message);
    delay(500);
  }
  
}
