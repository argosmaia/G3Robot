#include <Servo.h>
#include <HCSR04.h>
#include "motor.h"

Servo myservo;  // create servo object to control a servo
UltraSonicDistanceSensor distanceSensor(12, 11);

long distance; // variavel global para armazenar a distância em centímetros

void setup() {
  Serial.begin(9600); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  motorSetup();
}

void loop() {
  distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);

  if (distance <= 10) { // Se a distância for menor que 10 cm, pare o motor
    stop();
    //delay(200);
    myservo.write(90);
  } else if (distance > 50) { // Se a distância for maior que 30 cm, vire para a esquerda ou direita aleatoriamente
    myservo.write(0);
    if (random(2) == 0) {
      turnLeft();
    } else {
      turnRight();
    }
  }else {
    myservo.write(0);// Se a distância estiver entre 10 cm e 30 cm, mova o motor para frente
    search();
    Serial.print("search"); 
  }
  delay(100);
}

void search() {
  forward();
}
