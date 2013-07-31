//storage
long duration;
long cm;
long distance;

//nicknames

int echoPin = 11;
int trigPin = 10;


void setup()
{
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  for( int t = 2; t <= 8 ; t++)
 {
 pinMode(t,OUTPUT); 
 }
  
  
}

void loop()
{ 
  //Triggering the ultrasonic to measure
digitalWrite(trigPin,LOW);
delayMicroseconds(2);

digitalWrite(trigPIn,HIGH);
delayMicroseconds(80);

digitalWrite(trigPin,LOW);
//

//measure how long it takes to hear the echo
duration = pulseIn(echoPin,HIGH);
//

//57 microseconds for 1 cm
cm = duration/57;
//


for( int t = 2; t <= 8 ; t++)
 {
 digitalWrite(t,HIGH);
 delay( analogRead(A0));
 tone( 9, 100*t,1000 );
 digitalWrite(t,LOW);
 }
 
}
