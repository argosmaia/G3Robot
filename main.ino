#include "motor.h"
#include <HCSR04.h>
#include <Servo.h>

Servo myservo; // create servo object to control a servo
UltraSonicDistanceSensor distanceSensor(13, 12);

int const aberto = 0; // estado da garra
int const fechado = 130; // estado da garra
long distance; // variavel global para armazenar a distância em centímetros 
               

void setup() {
  Serial.begin(9600);
  myservo.attach(10);

  motorSetup();
}

void loop() {
  distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  if (distance > 0 and
      distance < 12) { // Se a distância for menor que 12 cm, pare o motor
    stop();
    delay(500);
    Serial.print("garra");
    myservo.write(fechado);
    delay(500);
    forward();
    delay(2000);
    myservo.write(aberto);
    backwards();
    delay(1000);
  } else if (distance > 55) { // Se a distância for maior que 50 cm, vire para a esquerda ou direita aleatoriamente
    myservo.write(aberto);
    Serial.print("busca");
    delay(200);
    if (random(2) == 0) {
      turnLeft();
    } else {
      turnRight();
    }
    delay(500);
  } else {
    myservo.write(aberto); // Se a distância estiver entre 10 cm e 30 cm, mova o motor para frente
    forward();
    Serial.print("search");
  }
  delay(800);
} 
