// C++ code
unsigned long previousmillis1=0;
unsigned long timenow=0;
int i=0;
const long interval=2;
float a[10];
float b[10];

void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop()
{
 int x;
  float voltage,current;
  unsigned long currentmillis1=millis();
  if(currentmillis1-previousmillis1>=interval&&i<10)
  {
    previousmillis1=currentmillis1;
    x=analogRead(A0);
    voltage=(5.0*x)/1023;
    a[i]=voltage;
    Serial.print("Volt: ");
    Serial.println(a[i]);

  int period=20;
  timenow=millis();
  while(millis()<timenow+period) {
  }
    x=analogRead(A1);
    voltage=(5.0*x)/1023;
    b[i]=voltage;
    Serial.println("Current:");
    Serial.println(b[i]);
    i++;
  }
  if(i==10)
  {
    
    float sum=0;
    for(int k=0;k<10;k++)
    {  
    sum=sum+(a[k]*b[k]);
    }
    sum=sum/10;
    Serial.println(sum);
                 
  }
}