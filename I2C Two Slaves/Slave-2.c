#include<Wire.h>
 byte myArray[2];
 int x;

void setup() {
  Serial.begin(9600);
  Wire.begin(8); 
  pinMode(A0,INPUT);
  Wire.onRequest(requestEvent); 
}

  void loop() {
  x=analogRead(A0);
  delay(100);
}
void requestEvent() {
  myArray[0]=(x>>8)&0xFF;
 myArray[1] = x&0xFF;
  Wire.write(myArray,2);
}