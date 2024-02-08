// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motorE(2);
AF_DCMotor motorD(1);

uint8_t vel_geral = 255;

void setup() {
  motorE.setSpeed(vel_geral);
  motorD.setSpeed(vel_geral);
  
  motorE.run(RELEASE);
  motorD.run(RELEASE);
}

void loop() {
  motorE.run(FORWARD);
  motorD.run(FORWARD);
  delay(2000);
  motorE.run(BACKWARD);
  motorD.run(BACKWARD);
  delay(2000);
  motorE.run(FORWARD);
  motorD.run(BACKWARD);
  delay(2000);
  motorD.run(FORWARD);
  motorE.run(BACKWARD);
  delay(2000);
  motorE.run(RELEASE);
  motorD.run(RELEASE);
  delay(2000);
}
