// This code is based on a program called "Sweep"
// by BARRAGAN <http://barraganstudio.com> 
// (which is an example placed in the public domain found under the example menu of the Arduino IDE)
// and we also utilize the Servo.h Library

//Creative commons license for my modifications
//
//I created additional functions created for handling continuous-rotation-servos as motors
//Forward, Backward, RotateLeft, RotateRight, Stop, and attachServo
//by gskielian  < http://www.kielian.net > 

double ForwardSpeed = 30.0;
double RotateSpeed = 30.0;
double BackwardSpeed = 30.0;

long duration;
long cm;
long distance;

int echoPin=11;
int trigPin =10;


#include <Servo.h> 
 
Servo LeftWheel;  // create servo object to control a servo 
Servo RightWheel;  // create servo object to control a servo 

// Note: a maximum of eight servo objects can be created 

int LWPin = 5; //set the pin number for your left servo-motors (just change the number if not pin 9)
int RWPin = 6; //right-wheel control pin



void setup() 
{ 
    pinMode(9,OUTPUT);

  
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  
  LeftWheel.attach( LWPin );  //  Connects LeftWheel to the pin LWPin
  RightWheel.attach( RWPin );  // Connects another wheel to be controlled by the pin RWPin

  Serial.begin(9600);
  tone(9,660,100);
   delay(150);
   tone(9,660,100);
  delay(300);
  tone(9,660,100);
  delay(300);
  tone(9,510,100);
  delay(100);
  tone(9,660,100);
  delay(300);
  tone(9,770,100);
  delay(550);

} 
 
 
void loop() 
{ 
    distance = getDistance();
    Serial.println(distance);
    if (distance < 30)
    {
      Serial.println("obstacle detected");
      Backward(1);
     tone(9,660,100);
   delay(150);
   tone(9,660,100);
  delay(300);
  tone(9,660,100);
  delay(300);
  tone(9,510,100);
  delay(100);
  tone(9,660,100);
  delay(300);
  tone(9,770,100);
  delay(550) 
      RotateLeft(1);
    }
    else
    {
      Forward(0.1);
tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);  
    }
    
     //Forward(0.1); 
     //Forward(0.1);
    // RotateLeft(2);
    // RotateRight(2);
    // Stop(3);

} 

long getDistance()
{
    //Triggering the ultrasonic to measure
digitalWrite(trigPin,LOW);
delayMicroseconds(2);

digitalWrite(trigPin,HIGH);
delayMicroseconds(80);

digitalWrite(trigPin,LOW);
//

//measure how long it takes to hear the echo
duration = pulseIn(echoPin,HIGH);
//

//57 microseconds for 1 cm
cm = duration/57;
//
delay(10);

return cm;
  
}




void Backward(double seconds)
{
    double speed = ForwardSpeed;

     attachServos(); //in case we disconnected them

     //The CRS thinks it is always at 90 degrees
     //if you tell it to go to 180 degrees it will go really fast clock-wise
     //0 degrees really quickly counterclockwise
     // 95 really slowly clockwise
     
    double leftspeed = (-speed/100.0*90.0 + 90) ;
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed); // Right wheel is backwards
 
   //delay wants an integer number of milliseconds, we turn seconds to milliseconds
   //then we turn the result into an int
   delay((int) (seconds*1000)); 
}



void Forward ( double seconds)
{
    double speed = BackwardSpeed; 

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;
    double rightspeed = (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed);
    
    delay((int) (seconds*1000));
}



void RotateLeft (double seconds)
{
    double speed = RotateSpeed;

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed);
    delay((int) (seconds*1000));
}

void RotateRight (double seconds)
{
    double speed = RotateSpeed;
    
    attachServos(); //in case we disconnected them
     
    double leftspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed); 

    delay((int) (seconds*1000));
}


void Stop( double seconds)
{
  LeftWheel.detach();  //to stop the motors, we have the Arduino stop sending signals entirely
  RightWheel.detach();

  delay((int) (seconds*1000));
}





void attachServos()
{
   LeftWheel.attach(LWPin);
   RightWheel.attach(RWPin);
}


void SingMario()
{
  tone(9,660,100);
delay(150);
tone(9,660,100);
delay(300);
tone(9,660,100);
delay(300);
tone(9,510,100);
delay(100);
tone(9,660,100);
delay(300);
tone(9,770,100);
delay(550);
tone(9,380,100);
delay(575);

tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);

tone(9,510,100);
delay(450);
tone(9,380,100);
delay(400);
tone(9,320,100);
delay(500);
tone(9,440,100);
delay(300);
tone(9,480,80);
delay(330);
tone(9,450,100);
delay(150);
tone(9,430,100);
delay(300);
tone(9,380,100);
delay(200);
tone(9,660,80);
delay(200);
tone(9,760,50);
delay(150);
tone(9,860,100);
delay(300);
tone(9,700,80);
delay(150);
tone(9,760,50);
delay(350);
tone(9,660,80);
delay(300);
tone(9,520,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,480,80);
delay(500);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(220);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,200);
delay(300);

tone(9,1020,80);
delay(300);
tone(9,1020,80);
delay(150);
tone(9,1020,80);
delay(300);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(420);

tone(9,585,100);
delay(450);

tone(9,550,100);
delay(420);

tone(9,500,100);
delay(360);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);
tone(9,500,100);
delay(150);
tone(9,500,100);
delay(300);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(220);

tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,200);
delay(300);

tone(9,1020,80);
delay(300);
tone(9,1020,80);
delay(150);
tone(9,1020,80);
delay(300);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);

tone(9,760,100);
delay(100);
tone(9,720,100);
delay(150);
tone(9,680,100);
delay(150);
tone(9,620,150);
delay(300);

tone(9,650,150);
delay(300);
tone(9,380,100);
delay(150);
tone(9,430,100);
delay(150);

tone(9,500,100);
delay(300);
tone(9,430,100);
delay(150);
tone(9,500,100);
delay(100);
tone(9,570,100);
delay(420);

tone(9,585,100);
delay(450);

tone(9,550,100);
delay(420);

tone(9,500,100);
delay(360);

tone(9,380,100);
delay(300);
tone(9,500,100);
delay(300);
tone(9,500,100);
delay(150);
tone(9,500,100);
delay(300);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(350);
tone(9,660,80);
delay(150);
tone(9,500,80);
delay(300);
tone(9,430,80);
delay(150);
tone(9,380,80);
delay(600);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(150);
tone(9,660,80);
delay(550);

tone(9,870,80);
delay(325);
tone(9,760,80);
delay(600);

tone(9,500,60);
delay(150);
tone(9,500,80);
delay(300);
tone(9,500,60);
delay(350);
tone(9,500,80);
delay(150);
tone(9,580,80);
delay(350);
tone(9,660,80);
delay(150);
tone(9,500,80);
delay(300);
tone(9,430,80);
delay(150);
tone(9,380,80);
delay(600);

tone(9,660,100);
delay(150);
tone(9,660,100);
delay(300);
tone(9,660,100);
delay(300);
tone(9,510,100);
delay(100);
tone(9,660,100);
delay(300);
tone(9,770,100);
delay(550);
tone(9,380,100);
delay(575);
}
