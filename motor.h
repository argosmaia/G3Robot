#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

const int motor1Pin1 = 5; // Porta digital para o primeiro pino do motor 1
const int motor1Pin2 = 3; // Porta digital para o segundo pino do motor 1
const int motor2Pin1 = 6; // Porta digital para o primeiro pino do motor 2
const int motor2Pin2 = 11; // Porta digital para o segundo pino do motor 2

const int vs = 75;
//const global pra regulação da velocidade 


void motorSetup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void forward() {
  analogWrite(motor1Pin1, vs);
  analogWrite(motor1Pin2, LOW);
  analogWrite(motor2Pin1, vs);
  analogWrite(motor2Pin2, LOW);
}

void backwards() {
  analogWrite(motor1Pin1, LOW);
  analogWrite(motor1Pin2, vs);
  analogWrite(motor2Pin1, LOW);
  analogWrite(motor2Pin2, vs);
}

void turnRight() {
  analogWrite(motor1Pin1, vs);
  analogWrite(motor1Pin2, LOW);
  analogWrite(motor2Pin1, LOW);
  analogWrite(motor2Pin2, vs);
}

void turnLeft() {
  analogWrite(motor1Pin1, LOW);
  analogWrite(motor1Pin2, vs); 
  analogWrite(motor2Pin1, vs);
  analogWrite(motor2Pin2, LOW);
}

void stop() {
  analogWrite(motor1Pin1, LOW);
  analogWrite(motor1Pin2, LOW);
  analogWrite(motor2Pin1, LOW);
  analogWrite(motor2Pin2, LOW);
}

# endif
