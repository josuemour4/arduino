/*
  Projeto LCD 1602 sem biblioteca
  Autor: Josue Moura (corrigido por ChatGPT)
*/

const int RS = 12;     // Register Select
const int RW = 11;     // Read/Write (sempre LOW para escrita)
const int EN = 2;      // Enable

const int DB[8] = {3, 4, 5, 6, 7, 8, 9, 10}; // D0 a D7

void LcdCommandWrite(int value) {
  digitalWrite(RS, LOW);  // Modo comando
  digitalWrite(RW, LOW);  // Escrevendo

  for (int i = 0; i < 8; i++) {
    digitalWrite(DB[i], value & 1);
    value >>= 1;
  }

  // Pulso de habilitação
  digitalWrite(EN, LOW);
  delayMicroseconds(1);
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(100);
}

void LcdDataWrite(int value) {
  digitalWrite(RS, HIGH); // Modo dado
  digitalWrite(RW, LOW);  // Escrevendo

  for (int i = 0; i < 8; i++) {
    digitalWrite(DB[i], value & 1);
    value >>= 1;
  }

  // Pulso de habilitação
  digitalWrite(EN, LOW);
  delayMicroseconds(1);
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(100);
}

void setup() {
  // Configura os pinos como saída
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(EN, OUTPUT);
  for (int i = 0; i < 8; i++) {
    pinMode(DB[i], OUTPUT);
  }

  delay(100); // Aguarda estabilização

  // Inicialização do LCD
  LcdCommandWrite(0x38); // 8-bit, 2 linhas, 5x7
  delay(5);
  LcdCommandWrite(0x38);
  delay(5);
  LcdCommandWrite(0x38);
  delay(5);
  LcdCommandWrite(0x0E); // Display ON, cursor ON
  delay(5);
  LcdCommandWrite(0x06); // Modo de entrada
  delay(5);
  LcdCommandWrite(0x01); // Limpa display
  delay(5);
  LcdCommandWrite(0x80); // Posição inicial
  delay(5);
}

void loop() {
  // Primeira linha: "Welcome to"
  LcdCommandWrite(0x01); // Limpa tela
  delay(5);
  LcdCommandWrite(0x80 + 3); // Cursor na posição 3 da primeira linha

  const char* msg1 = "Welcome";
  for (int i = 0; msg1[i] != '\0'; i++) {
    LcdDataWrite(msg1[i]);
  }

  delay(2000);

  // Segunda linha: "Lecy"
  LcdCommandWrite(0xC0 + 1); // Cursor na linha 2, posição 1
  const char* msg2 = "Lecy";
  for (int i = 0; msg2[i] != '\0'; i++) {
    LcdDataWrite(msg2[i]);
  }

  delay(2000);

  // Exibe "LOVE" no início novamente
  LcdCommandWrite(0x01);
  delay(10);
  LcdCommandWrite(0x80 + 6); // Linha 1, posição 6
  const char* msg3 = "My LOVE";
  for (int i = 0; msg3[i] != '\0'; i++) {
    LcdDataWrite(msg3[i]);
  }

  delay(3000);
}
