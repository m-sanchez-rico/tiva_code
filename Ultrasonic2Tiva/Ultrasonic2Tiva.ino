
//global variables
const int echo=9, Trig=10;
long duration, cm;



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
  pinMode (Trig, OUTPUT );
  pinMode (echo, INPUT  );
}

void Update_Ultra_Sonic()
{
  digitalWrite (Trig, LOW);
  delayMicroseconds(2);
  digitalWrite (Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite (Trig, LOW);

  duration = pulseIn(echo, HIGH);

  //convert time to distance
  cm=microsecndsToCentimeters(duration);

  //Sending through serial port
  Serial.print("distance=");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("\n");
}

long microsecndsToCentimeters(long microseconds)
{
  //340 m/s = 0.034 cm/us = 1/0.034 us/cm = 29.41 us/cm 
  return microseconds /29 /2;
}
