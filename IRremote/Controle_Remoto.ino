/*
  Projeto: Acendendo e apagando um Led
            através do controle remoto
  Autor: Josue Moura
  Data: 26/07/2025
  
  Description: The objective of this project is to demonstrate 
  the use of an infrared receiver. 
  It will receive a signal from a remote control and control the switching on of several LED.
  
*/
#include <IRremote.h>

// Pinos dos LEDs
const byte pinosLed[] = {2, 3, 4, 5, 6, 7};

// Códigos dos botões que controlam os LEDs
const int botoes[] = {16, 17, 18, 20, 21, 22};

// Quantidade de LEDs
const byte totalLeds = sizeof(pinosLed) / sizeof(pinosLed[0]);

// Converte o código infravermelho em número de botão
int mapCodeToButton(unsigned long code) {
  if ((code & 0x0000FFFF) == 0x0000BF00) {
    code >>= 16;

    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF) {
      return code & 0xFF;
    }
  }

  return -1;
}

// Lê o controle infravermelho
int readInfrared() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    int resultado = mapCodeToButton(code);

    IrReceiver.resume();

    return resultado;
  }

  return -1;
}

// Liga ou desliga o LED correspondente ao botão
void ligarLed(int botao) {
  for (byte i = 0; i < totalLeds; i++) {
    if (botao == botoes[i]) {
      digitalWrite(pinosLed[i], !digitalRead(pinosLed[i]));
      break;
    }
  }
}

void setup() {
  Serial.begin(9600);

  // Configura todos os LEDs como saídas
  for (byte i = 0; i < totalLeds; i++) {
    pinMode(pinosLed[i], OUTPUT);
  }

  IrReceiver.begin(11);
}

void loop() {
  int botao = readInfrared();

  if (botao >= 0) {
    Serial.println(botao);
    ligarLed(botao);
  }
}

