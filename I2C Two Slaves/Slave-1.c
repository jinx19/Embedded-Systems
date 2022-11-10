#include <Wire.h>
void setup()
{
  Serial.begin(9600);
  Wire.begin(9); 
  pinMode(12,OUTPUT);
  Wire.onRequest(requestEvent); 
}

void loop()
{
}

void requestEvent() {
  digitalWrite(12,HIGH);
  delay(1000);
}