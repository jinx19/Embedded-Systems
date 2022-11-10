#include <Wire.h>
void setup() {
  Wire.begin();
  Serial.begin(9600); 
}
float volt=0,temp=0;
byte a,b;
void loop() {
  Wire.requestFrom(8, 2);    
	int X=0;
  while (Wire.available()){ 
    a = Wire.read();
	b = Wire.read(); 
  }
 	X= a;
	X = (X<<8)|b;
  volt=(5.0*X/1023);
  temp=(volt*1000-500)/10;
  if(temp>=50){
    Wire.requestFrom(9,0);
    delay(1000);
  }
   Serial.println(temp);
  delay(1000);
}