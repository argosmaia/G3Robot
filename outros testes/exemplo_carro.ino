#include <NewPing.h>

#define TRIG_PIN 6
#define ECHO_PIN 7

NewPing sonar(TRIG_PIN, ECHO_PIN); 

#define M1A 11
#define M1B 13
#define M2B 10
#define M2A 9

void setup() {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm();
  int desiredDistance = 20;
  if (distance > desiredDistance) {
    digitalWrite(M1B, HIGH);
    digitalWrite(M1A, LOW);
    digitalWrite(M2B, HIGH);
    digitalWrite(M2A, LOW);
  }
  else if (distance < desiredDistance) {
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
  }
  else{
    digitalWrite(M1B, HIGH);
    digitalWrite(M1A, HIGH);
    digitalWrite(M2B, HIGH);
    digitalWrite(M2A, HIGH);
  }
}
