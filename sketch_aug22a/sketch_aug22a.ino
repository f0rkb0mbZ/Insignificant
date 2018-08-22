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

int pos =180;    // variable to store the servo position

void setup() {
  servoLeft.attach(10);// attaches the servo on pin 9 to the servo object
  servoRight.attach(11);// attaches the servo on pin 9 to the servo object
}

void loop() {
  servoLeft.write(pos);
  servoRight.write(pos);
}

