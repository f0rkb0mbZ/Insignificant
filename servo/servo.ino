/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servoLeft;//creates servo object to control a servo
Servo servoRight;// create servo object to control a servo
// twelve servo objects can be created on most boards

int lpos = 0;    // variable to store the servo position
int rpos = 180;
void setup() {
  servoLeft.attach(10);// attaches the servo on pin 9 to the servo object
  servoRight.attach(11);// attaches the servo on pin 9 to the servo object
}

void loop() {

  for (lpos = 0, rpos = 180; lpos <= 180 && rpos >= 0 ; lpos += 5, rpos -= 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoLeft.write(lpos); // tell servo to go to position in variable 'pos'
    servoRight.write(rpos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(500);
  for (lpos = 180, rpos = 0; lpos >= 0 && rpos <= 180 ; lpos -= 5, rpos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoLeft.write(lpos); // tell servo to go to position in variable 'pos'
    servoRight.write(rpos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

