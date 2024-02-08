#include <Servo.h>

// Definir pinos para motores, sensores, etc.
const int motorPin1 = 2;          // Pino do motor 1
const int motorPin2 = 3;          // Pino do motor 2
const int colorSensorPin = A0;    // Pino do sensor de cor
const int passengerSensorPin = 4; // Pino do sensor de passageiro
const int servoPin = 9;           // Pino do servo para a garra
// Criar objeto à garra
Servo servo;

// Maquinas de estados
enum Estado { ANDANDO, PARE_E_PEGUE, ANDE_PARA_FRENTE, VIRE, PARE };

Estado atual = ANDANDO;

void setup() {
  // Inicializar pinos
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(colorSensorPin, INPUT);
  pinMode(passengerSensorPin, INPUT);

  servo.attach(servoPin);
  // Iniciar comunicação serial
  Serial.begin(9600);
}

void paraFrente() {
  // Implementar a lógica para o robô andar para frente
  atual = ANDE_PARA_FRENTE;
}

void parePega() {
  // Implementar a lógica para o robô pare e pegar o passageiro
}

void virar() {
  // Lógica para virar para a direção do passageiro
}
void andeParaFrenteAposPegar() {
  // Lógica para movimento após pegar o passageiro
  atual = VIRE;
  virar();
  atual = ANDE_PARA_FRENTE;
  paraFrente();
}

// Regra de negócio - tudo o que ele faz
void condicoes() {
  // Verificar condições e atualizar o estado do robô
  // Lógica para verificar as condições de destino alcançado
  // Certifique-se de contar o número de passageiros entregues
  // e se a cor verde foi detectada
}

void destino() {
  // Lógica para determinar o destino final do robô
}

void situacaoCores(HSV hsv) {
  if (hsv.value < 50) {
    atual = ANDE_PARA_FRENTE;
  } else if (hsv.value > 150 && hsv.value < 300) {
    Serial.println("Cheguei ao meu destino, chupetas!");
    exit(0);
  } else {
    currentState = TURN_AROUND;
  }
}

// para converter RGB para HSV
HSV rgbToHsv(int r, int g, int b) {
  float min, max, delta;
  float h, s, v;

  min = min(min(r, g), b);
  max = max(max(r, g), b);
  v = max;

  delta = max - min;

  if (max != 0)
    s = delta / max;
  else {
    s = 0;
    h = -1;
    return HSV(h, s, v);
  }

  if (r == max)
    h = (g - b) / delta + (g < b ? 6 : 0);
  else if (g == max)
    h = 2 + (b - r) / delta;
  else
    h = 4 + (r - g) / delta;

  h *= 60;

  if (h < 0)
    h += 360;

  return HSV(h, s * 100, v * 100);
}

void abrirGarra() {
  servo.write(90); // Abre a garra
  delay(1000);     // Aguarda 1 segundo
}

void fecharGarra() {
  servo.write(anguloFechado); // Fecha a garra
  delay(1000);                // Aguarda 1 segundo
}

void maquinaEstados() {
  /*
   O que são máquinas de estados?
   Máquinas de estados são um tipo de automação que
   permite que um sistema seja automatizado de maneira
   mais eficiente. Elas são muito utilizadas em sistemas
   de controle de robôs, sistemas de automação industrial,
   sistemas de controle de veículos e muito mais.
  */
  switch (atual) {
  case ANDANDO:
    paraFrente();
    break;
  case PARE_E_PEGUE:
    paraePega();
    break;
  case ANDE_PARA_FRENTE:
    andeParaFrenteAposPegar();
    break;
  case VIRE:
    virar();
    break;
  case PARE:
    if (condicoes()) {
      destino();
    } else {
      atual = ANDANDO;
    }
    break;
  }
}

void loop() {
  // Ler valores dos sensores
  int colorValue = analogRead(colorSensorPin);
  if (colorValue > 100) {
    paraFrente();
  } else {
    situacaoCores(colorValue);
  }

  if (digitalRead(passengerSensorPin) == HIGH) {
    atual = PARE_E_PEGUE;
  }
  maquinaEstados();
}
