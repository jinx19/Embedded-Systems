#include <Wire.h>
void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
}
float volt=0,temp=0;
byte a,b;

//checks the temperature and turns ON and OFF the motor.
void loop() {
  //requesting data from slave.
  Wire.requestFrom(7, 2);    
  int X=0;
  while (Wire.available()){  
    a = Wire.read();
	b = Wire.read(); 
  }
  X= a;
  X = (X<<8)|b;
  volt=(5.0*X/1023);
  temp=(volt*1000-500)/10; //converting to temperature.
  Serial.print("Temperature: ");
   Serial.println(temp); //printing temperature.
  delay(2000);
}
