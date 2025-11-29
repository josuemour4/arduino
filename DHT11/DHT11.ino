/*
  Projeto: Sensor DHT11
  Autor: Josue Moura
  Data: 11/10/2025
  
  Description: Using sensor dht11
  
*/
#include <DHT11.h>
const int dht11Pino = 2;

const int ATRASO = 2000;

DHT11 sensor(dht11Pino);

float temperatura, umidade;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valor;
  valor = sensor.readTemperature();
  Serial.print("Temperatura: ");
  Serial.println(valor);
}