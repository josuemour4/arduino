/*
  Projeto: LCD Controlling - using LiquidCrystal.h library
  Autor: Josue Moura
  Data: 11/10/2025
  
  Description: Control a 16x2 LCD screen using
  the LiquidCrystal.h library
  
*/
// Incluindo a biblioteca 
#include <LiquidCrystal.h>

#define TEMPO_ATUALILZACAO 500

// Declaracao da variavel com os parametros
LiquidCrystal lcd (12,11,5,4,3,2);
/*
  Funcionalidade de cada parametro
  11:
  12:
  2-5: 
*/

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  //Inicia o LCD com dimensoes 16x2 (16 Colunas e 2 Linhas )
  lcd.begin(16,2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0); //Linha 0 e Coluna 0
  lcd.print("Ola");
  lcd.setCursor(0,1); //Linha 1 e Coluna 0
  lcd.print("JOSUE");
  delay(TEMPO_ATUALILZACAO);
}