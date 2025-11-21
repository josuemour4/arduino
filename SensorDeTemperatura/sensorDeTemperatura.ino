/*
  Projeto: Greenhouse Control
  Autor: Josue Moura
  Data: 20/07/2025
  
  Description: O objetivo deste projeto é
  enviar os dados de um sensor de temperatura
  (LM35 ou DHT11) para a saída serial.

*/
int sensor = A0;

//Tempo de atualizacao em ms
const int ATRASO = 5000;

// Base para conversao para Graus Celsius
// ((5/1023) * 100)

const float BASE_CELSIUS = 0.4887585532746823069403714565;

void setup(){

    Serial.begin(9600);

}

void loop() {

Serial.print("Temperatura: ");
Serial.print(lerTemperatura());
Serial.println("\260C");
delay(ATRASO);

}

float lerTemperatura() {
    return (analogRead(sensor) * BASE_CELSIUS);
}