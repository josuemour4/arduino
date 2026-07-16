/*
  Projeto: Controlling two displays with two 74HC595.
  Autor: Josue Moura
  Data: 12/07/2026
  
  Description: Understanding how to use two 74HC595 chips
  to control two displays.

  Using 3 Arduino ports to control 16 bits of output.
  
*/

const int dataPin = 11;   // DS (Pino 14 do 1º Chip)
const int clockPin = 12;  // SH_CP (Pino 11 de ambos)
const int latchPin = 8;   // ST_CP (Pino 12 de ambos)

byte unidade = 0;
byte dezenas = 0;

const byte numeros[] =
{
  B11111100, //0
  B01100000, //1
  B11011010, //2
  B11110010, //3
  B01100110, //4
  B10110110, //5
  B10111110, //6
  B11100000, //7
  B11111110, //8
  B11110110  //9
};

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop()
{
  displayNumber(unidade, dezenas);
  
  delay(500);// Mudar depois

  if(++unidade > 9){

    unidade = 0;

    if(++dezenas > 9 ){
      dezenas = 0;
    }
  }
  
  
  
}

void displayNumber(byte unidade, byte dezenas) {
  
  digitalWrite(latchPin, LOW);
  // Segundo
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[unidade]);
  // Primeiro
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[dezenas]);
  
  digitalWrite(latchPin, HIGH);
}