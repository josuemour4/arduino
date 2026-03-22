/*
  Projeto: Car parking system.
  Autor: Josue Moura
  Data: 21/02/2026
  
  Description: Create a parking system for cars.

Objective: The goal of this project is to create a 
parking system for cars. This system assists the driver 
when parking their car in spaces that require reversing maneuvers.

- HC-SR04: Measure distance

- LED (3): Display distance (Green = Safe, Yellow = Caution, Red = Stop)

- Buzzer: Inform the distance through sound. 
(
  Safe = Sound alternating with longer duration, 
  Caution = Sound with shorter alternation time, 
  Red = Frenetic sound
)
  
*/

// ---------------- PINOS ----------------
const int echoPin = 12;
const int trigPino = 13;

const byte buzzer = 7;

const byte ledVerde = 2;
const byte ledAmarelo = 8;
const byte ledVermelho = 4;

// ---------------- DISTÂNCIAS ----------------
const int DISTANCIA_SAFETY = 40;
const int DISTANCIA_ALERT = 20;
const int DISTANCIA_STOP = 12;

// ---------------- ESTADOS ----------------
enum Estado {
  SAFE,
  CAUTION,
  STOP,
  OUT_OF_RANGE,
  ERROR
};

Estado estadoAtual = OUT_OF_RANGE;

// ---------------- CONFIG ----------------
struct Config {
  int freq;
  int duration;
  byte led;
};

// IMPORTANTE: ordem precisa bater com enum
Config estados[] = {
  {650, 200, ledVerde},     // SAFE
  {800, 100, ledAmarelo},   // CAUTION
  {1000, 50, ledVermelho}   // STOP
};

// ---------------- TEMPO ----------------
unsigned long previousMillis = 0;
const unsigned long interval = 50;

// ---------------- VARIÁVEIS ----------------
long duracao = 0;
long distancia = 0;

// =====================================================

void setup() {
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigPino, OUTPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

// =====================================================

void loop() {
  atualizarTempo();
}

// =====================================================

void atualizarTempo() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    medirDistancia();
    determinarEstado();
    atualizarSaidas();
  }
}

// =====================================================

void medirDistancia() {

  digitalWrite(trigPino, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPino, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPino, LOW);

  duracao = pulseIn(echoPin, HIGH, 30000);

  if (duracao == 0) {
    estadoAtual = ERROR;
    return;
  }

  distancia = duracao / 58;

  Serial.print("Distancia: ");
  Serial.println(distancia);
}

// =====================================================

void determinarEstado() {

  if (estadoAtual == ERROR) return;

  if (distancia <= DISTANCIA_STOP) {
    estadoAtual = STOP;

  } else if (distancia <= DISTANCIA_ALERT) {
    estadoAtual = CAUTION;

  } else if (distancia <= DISTANCIA_SAFETY) {
    estadoAtual = SAFE;

  } else {
    estadoAtual = OUT_OF_RANGE;
  }
}

// =====================================================

void atualizarSaidas() {

  switch (estadoAtual) {

    case STOP:
    case CAUTION:
    case SAFE: {
      Config cfg = estados[estadoAtual];
      tone(buzzer, cfg.freq, cfg.duration);
      turnLedOn(cfg.led);
      break;
    }

    case OUT_OF_RANGE:
      turnAllOff();
      noTone(buzzer);
      break;

    case ERROR:
      Serial.println("Erro sensor");
      piscarErro();
      break;
  }
}

// =====================================================

void turnLedOn(byte led) {
  digitalWrite(ledVerde, (led == ledVerde));
  digitalWrite(ledAmarelo, (led == ledAmarelo));
  digitalWrite(ledVermelho, (led == ledVermelho));
}

// =====================================================

void turnAllOff() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
}

// =====================================================

void piscarErro() {
  static bool estado = false;

  estado = !estado;

  digitalWrite(ledVermelho, estado);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  tone(buzzer, 200, 100);
}