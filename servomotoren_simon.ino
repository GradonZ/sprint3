#include <Servo.h>

Servo myservo;            // create servo object to control a servo
Servo myservo2; 
Servo myservo3;                     

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(8);  // attaches the servo on a pin to the servo object
  myservo2.attach(7);
  myservo3.attach(6);
}

void loop() {
  
  for (pos = 0; pos <= 150; pos += 1) { // goes from 0 degrees to 150 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    myservo3.write(pos);
    delay(20);                       // waits 20ms for the servo to reach the position
  }
  for (pos = 150; pos >= 0; pos -= 1) { // goes from 150 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    myservo3.write(pos);
    delay(20);                       // waits 20ms for the servo to reach the position
  }
  
}



