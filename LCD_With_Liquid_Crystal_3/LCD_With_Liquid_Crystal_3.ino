/*
  Projeto: LCD Controlling - using LiquidCrystal.h library 2
  Autor: Josue Moura
  Data: 25/10/2025
  
  Description: Controlling a 16x2 LCD screen using
  the LiquidCrystal.h library and 
  doing the text scrolling
  
*/
#include <LiquidCrystal.h>

#define TEMPO_DE_ATUALIZACAO 500

LiquidCrystal lcd (12,11,5,4,3,2);
int inicioDoDisplay = 0, fimDoDisplay = 16;
int quantidade = 0;

String texto = "Josue de Oliveira Moura", subTexto;	
int textoSize = texto.length();

void setup() {

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16,2);
}

void loop(){
  
  lcd.clear();
  
  if(quantidade< fimDoDisplay){
    subTexto = texto.substring(inicioDoDisplay,quantidade);
    lcd.setCursor((fimDoDisplay-quantidade),0);
    lcd.print(subTexto);
  } else {
    inicioDoDisplay++;
    subTexto = texto.substring(inicioDoDisplay,quantidade+1);
    
    lcd.setCursor(0,0);
    lcd.print(subTexto);
  }
  
  if(inicioDoDisplay == textoSize ){
    inicioDoDisplay = 0;
    fimDoDisplay = 16;
	quantidade = 0;
  }
  
  Serial.println(subTexto);
  
  quantidade++;
  delay(TEMPO_DE_ATUALIZACAO);
}