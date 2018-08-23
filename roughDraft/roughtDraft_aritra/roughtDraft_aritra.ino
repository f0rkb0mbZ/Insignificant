#include <Servo.h>

Servo servoLeft;//creates servo object to control a servo
Servo servoRight;// create servo object to control a servo
// twelve servo objects can be created on most boards


// variable to store the servo position
int lpos = 0;
int rpos = 180;


// defines pins numbers
const int LtrigPin = 7;
const int LechoPin = 8;

const int RtrigPin = A0 ;
const int RechoPin = A1;

// defines variables
long duration;
int distance;
int Ldistance;
int Rdistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(LtrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(LechoPin, INPUT); // Sets the echoPin as an Input
  pinMode(RtrigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(RechoPin, INPUT); // Sets the echoPin as an Input

  Serial.begin(9600); // Starts the serial communication

  servoLeft.attach(10);// attaches the servo on pin 9 to the servo object
  servoRight.attach(11);// attaches the servo on pin 9 to the servo object

}

void loop() {
  // put your main code here, to run repeatedly:
  for (lpos = 0, rpos = 180; lpos <= 180 && rpos >= 0 ; lpos += 5, rpos -= 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

    servoLeft.write(lpos); // tell servo to go to position in variable 'pos'
    Ldistance = ultra(LtrigPin, LechoPin);
    servoRight.write(rpos);// tell servo to go to position in variable 'pos'
    Rdistance = ultra(RtrigPin, RechoPin);
    delay(15);                       // waits 15ms for the servo to reach the position
    Serial.println(Ldistance+" "+Rdistance);
  }
  //delay(50);
  for (lpos = 180, rpos = 0; lpos >= 0 && rpos <= 180 ; lpos -= 5, rpos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree

    servoLeft.write(lpos); // tell servo to go to position in variable 'pos'
    Ldistance = ultra(LtrigPin, LechoPin);
    servoRight.write(rpos);// tell servo to go to position in variable 'pos'
    Rdistance = ultra(RtrigPin, RechoPin);
    delay(15);                       // waits 15ms for the servo to reach the position
    Serial.println(Ldistance+" "+Rdistance);
}
}


void ultra(int trigPin, int echoPin) {
  duration = 0;
  distance = 0;


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  return distance;

}

