#include <Servo.h>
Servo myservo; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  Serial.begin(9600);
}

void loop() {
  Serial.print(myservo.read());
}
