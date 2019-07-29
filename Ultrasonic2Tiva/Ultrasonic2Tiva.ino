
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
  
  digitalWrite (Trig, LOW);
  digitalWrite (LED, LOW);
  delayMicroseconds(2);
  digitalWrite (Trig, HIGH);
  digitalWrite (LED, HIGH);
  delayMicroseconds(10);
  digitalWrite (Trig, LOW);
  digitalWrite (LED, LOW);

  long duration;
  duration = pulseIn(echo, HIGH);
  Serial.print("Reading duration from pulseIn(echo, HIGH)= ");
  Serial.print(duration);
  Serial.print("\n");
  
  //convert time to distance
  long cm;
  cm=microsecndsToCentimeters(duration);

  //Sending through serial port
  Serial.print("-distance= ");
  Serial.print(cm);
  Serial.print("cm -duration= ");
  Serial.print(duration);
  Serial.print("us");
  Serial.print("\n");
}

long microsecndsToCentimeters(long microseconds)
{
  //340 m/s = 0.034 cm/us = 1/0.034 us/cm = 29.41 us/cm 
  long ret;
  //ret= (microseconds/2)/58;
  ret = microseconds*0.017;
  return ret;
}
