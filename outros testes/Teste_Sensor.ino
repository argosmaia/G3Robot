#include <HCSR04.h>
#include <Servo.h>

#define TRI 11
#define ECO 12
//#define DIS 100

#define IN1 5 // Motor A
#define IN2 4 // Motor A
#define IN3 3 // Motor A
#define IN4 2 // Motor A

UltraSonicDistanceSensor distanceSensor(11, 12);

void stop();
void forward();
void backward();
void horario();
void anthorario();

void setup()
{
  Serial.print(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  Serial.println(distanceSensor.measureDistanceCm());
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN4, LOW);
  delay(30);
}

void horario() {
  
}
