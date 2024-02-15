#include <Servo.h>
#include <HCSR04.h>

Servo myservo;  // create servo object to control a servo
UltraSonicDistanceSensor distanceSensor(11, 12);

int pos = 0;    // variable to store the servo position

const int motor1Pin1 = 2; // Porta digital para o primeiro pino do motor 1
const int motor1Pin2 = 3; // Porta digital para o segundo pino do motor 1
const int motor2Pin1 = 4; // Porta digital para o primeiro pino do motor 2
const int motor2Pin2 = 5; // Porta digital para o segundo pino do motor 2
long duration; // variavel global para armazenar a duração do pulso
long distance; // variavel global para armazenar a distância em centímetros

void stop();
void forward();
void backwards();
void turnRight();
void turnLeft();
void search();
void garra();

void setup() {
  Serial.begin(9600); 
  delay(500);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

void loop() {

  garra();
  Serial.println(distanceSensor.measureDistanceCm());
  duration = distanceSensor.measureDistanceCm();
  distance = (duration / 2) / 29.1; // Distância em centímetros

  if (distance < 10) { // Se a distância for menor que 10 cm, pare o motor
    stop(); 
  } else if (distance > 30) { // Se a distância for maior que 30 cm, vire para a esquerda ou direita aleatoriamente
    if (random(2) == 0) {
      turnLeft();
    } else {
      turnRight();
    }
  } else { // Se a distância estiver entre 10 cm e 30 cm, mova o motor para frente
    search(); 
  }
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

void search() {
  duration = distanceSensor.measureDistanceCm();
  distance = (duration / 2) / 29.1; // Distância em centímetros

  if (distance < 10) { // Supondo que a distância esteja em centímetros
    forward();
  } else {
    backwards();
    delay(1000); // Espera por 1 segundo
    turnRight();
    delay(1000); // Espera por 1 segundo
    forward();
  }
}

void garra() {
  distance = distanceSensor.measureDistanceCm();

  if (distance <= 10) { // Se a distância for menor ou igual a 10 cm
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(1);                       // waits 15 ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(1);                       // waits 15 ms for the servo to reach the position
    }
  }
}
