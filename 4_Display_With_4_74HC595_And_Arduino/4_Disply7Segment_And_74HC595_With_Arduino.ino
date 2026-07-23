/*
  Projeto: Controlling 4 displays with 4 74HC595.
  Autor: Josue Moura
  Data: 24/07/2026
  
  Description: Understanding how to use two 74HC595 chips
  to control 4 displays.

  Using 3 Arduino ports to control 16 bits of output.
  
*/

const int dataPin = 11;   // DS (Pino 14 do 1º Chip)
const int clockPin = 12;  // SH_CP (Pino 11 de todos os chips)
const int latchPin = 8;   // ST_CP (Pino 12 de todos os chips)

const long intervalo = 25;
unsigned long tempo_Previo = 0;

byte unidade = 0;
byte dezenas = 0;
byte segundo_Unidade = 0;
byte segundo_Dezenas = 0;

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

  unsigned long tempo_Atual = millis();

  if (tempo_Atual - tempo_Previo >= intervalo) {
    tempo_Previo = tempo_Atual;

    displayNumber(unidade, dezenas, segundo_Unidade, segundo_Dezenas);

    if(++unidade > 9){

      unidade = 0;

      if(++dezenas > 9 ){

        dezenas = 0;

        if(++segundo_Unidade > 9){
          segundo_Unidade = 0;

          if(++segundo_Dezenas > 9) {
            segundo_Dezenas =0;
          }
        }
      }
    }
  } 
  
}

void displayNumber(byte unidade, byte dezenas, byte segundo_Unidade, byte segundo_Dezenas) {
  
  digitalWrite(latchPin, LOW);
  // Ultimo
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[unidade]);
  // Terceiro
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[dezenas]);
  // Segundo
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[segundo_Unidade]);
  // Primeiro
  shiftOut(dataPin, clockPin, LSBFIRST, numeros[segundo_Dezenas]);
  
  digitalWrite(latchPin, HIGH);
}