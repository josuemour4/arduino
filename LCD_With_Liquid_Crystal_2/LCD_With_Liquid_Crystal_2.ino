/*
  Projeto: LCD Controlling - using LiquidCrystal.h library 2
  Autor: Josue Moura
  Data: 18/10/2025
  
  Description: Controlling a 16x2 LCD screen using
  the LiquidCrystal.h library and 
  doing the text scrolling
  
*/
// Incluindo a biblioteca 
#include <LiquidCrystal.h>

#define TEMPO_ATUALILZACAO 500

// Declaracao da variavel com os parametros
LiquidCrystal lcd (12,11,5,4,3,2);
/*
  Funcionalidade de cada parametro
  11: Habilitar
  12: Selecao de registro
  2-5: Dados
*/

int inicio = 0, tamanho = 1;
boolean alterar = false;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  //Inicia o LCD com dimensoes 16x2 (16 Colunas e 2 Linhas )
  lcd.begin(16,2);
}

void loop() {
  lcd.clear();
  //     nome = [0][1][2][3][4][5][6][7][8][9][10]
  //     nome = [J][o][s][u][e][ ][M][o][u][r][a]
  String nome = "Josue Moura";

  if(tamanho < 16) {
    /*
    setCursor( coluna, linha )

    */
    lcd.setCursor(16 - tamanho, 0);

    //A funcao print(Data ) vai exibir o valor passado como parametro
    // A funcao substring()
    lcd.print(nome.substring(inicio,tamanho));
    tamanho++;
  } else {
    if(!alterar) {
      alterar = !alterar;
      tamanho = 16;
      lcd.setCursor(0,0);
    }
    lcd.print(nome.substring(inicio, inicio + tamanho));
    inicio++;
  }
  if(inicio > nome.length()) {
    inicio = 0;
    tamanho = 1;
    alterar = !alterar;
  }
  delay(TEMPO_ATUALILZACAO);
}