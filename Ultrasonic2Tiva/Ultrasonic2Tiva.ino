
//global variables
#define echo 9
#define Trig 10
#define LED GREEN_LED


void setup() 
{
  // put your setup code here, to run once:
  // Init Serial port with 115200 boud rate

  Serial.begin (115200);
  SetupUltrasonic(); //function

}

void loop() 
{
  // put your main code here, to run repeatedly: 
  Update_Ultra_Sonic();
  delay(200); 
  
}


//Definition of function
void SetupUltrasonic()
{
  pinMode(Trig, OUTPUT);
  pinMode(echo, INPUT );
  pinMode(LED , OUTPUT); 
}

void Update_Ultra_Sonic()
{
  long duration, cm;
  
  digitalWrite (Trig, LOW);
  digitalWrite (LED, LOW);
  delayMicroseconds(2);
  
  digitalWrite (Trig, HIGH);
  digitalWrite (LED, HIGH);
  delayMicroseconds(10);
  
  digitalWrite (Trig, LOW);
  digitalWrite (LED, LOW);

  
  duration = pulseIn(echo, HIGH);
  
  //convert time to distance
  cm=microsecndsToCentimeters(duration);

  //Sending through serial port
  Serial.print("-duration= ");
  Serial.print(duration);
  Serial.print("us -distance= ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("\n");
}

long microsecndsToCentimeters(long microseconds)
{
  long ret;
  //340 m/s = 0.034 cm/us = 1/0.034 us/cm = 29.41 us/cm
  //ret= (microseconds/2)/58;
  
  ret = microseconds*0.017;
  
  return ret;
}
