#include <Servo.h>

const int servoPin = 9; // Porta digital para o servo
const int triggerPin = 11; // Porta digital para o pino de trigger do sensor ultrassônico
const int echoPin = 12; // Porta digital para o pino de echo do sensor ultrassônico
const int motor1Pin1 = 2; // Porta digital para o primeiro pino do motor 1
const int motor1Pin2 = 3; // Porta digital para o segundo pino do motor 1
const int motor2Pin1 = 4; // Porta digital para o primeiro pino do motor 2
const int motor2Pin2 = 5; // Porta digital para o segundo pino do motor 2

void stop();
void forward();
void backwards();
void turnRight();
void turnLeft();

Servo servoMotor;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  servoMotor.attach(servoPin);
}

void loop() {
  // Verifica se há um objeto dentro do alcance do sensor ultrassônico
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Distância em centímetros

  if (distance < 10) { // Se a distância for menor que 10 cm, ative a garra
    moveServo();
    stop(); // Pare o motor
  } else {
    forward(); // Mova o motor para frente se a distância for maior que 10 cm
  }

  // Se passaram 5 minutos desde a última vez que um objeto foi detectado, gire 360 graus
  if (millis() - lastTimeObjectDetected > 5 * 60 * 1000) {
    for (int i = 0; i < 4; i++) { // Supondo que uma chamada para turnRight() ou turnLeft() gira o robô 90 graus
      turnRight(); // ou turnLeft() para girar para a esquerda
      delay(1000); // Ajuste este valor de acordo com o tempo que leva para o robô girar 90 graus
    }
    lastTimeObjectDetected = millis(); // Atualiza a última vez que um objeto foi detectado
  }
}

void moveServo() {
  // Código para fechar a garra
  servoMotor.write(0); // Ângulo para fechar a garra
  delay(1000); // Tempo para a garra fechar
}

void forward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void backwards() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

