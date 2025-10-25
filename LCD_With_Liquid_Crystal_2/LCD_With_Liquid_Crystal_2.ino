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
  11: E (Enable)  
  12: RS (Register Select)
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
    O display usado sao de 16 colunas. 0-15
    tamanho = 1, 16 - 1 =15. logo, a primeira posicao ocupada no display sera 15
    */
    lcd.setCursor(16 - tamanho, 0);

    //A funcao print(nome) vai exibir o valor passado como parametro, que no caso e [nome]
    /* Atraves da funcao substring() e possivel manipular o objeto [nome] (que e usado como referencia) de varias formas
    neste caso, inicio = 0; tamanho = 1 
    1º nome.substring(0, 1) = Vai Exibir J
    6º nome.substring(0, 5) = Vai Exibir Josue
    */
    lcd.print(nome.substring(inicio,tamanho));
    tamanho++;
    // Apos [tamanho] assumir posicao maior que 15 o bloco acima e ignorado e e o bloco abaixo e executado
  } else {

    //O objetivo do bloco abaixo e usar o display no modo padrao. Ou seja o cursor esta no comeco da tela
    if(!alterar) {
      alterar = !alterar;
      tamanho = 16;
      lcd.setCursor(0,0);
    }
    /*
    Abaixo temos novamente a manipulacao do texto atraves da funcao substring,
    com a diferenca que a manipulacao de aprentacao esta no inicio da tela do display
    E a cada vez que inicio e encrementado o valor do texto e reduzido.
    Josue Moura
    nome.substring(1, 16) = Vai Exibir Josue
    */
    //     nome = [0][1][2][3][4][5][6][7][8][9][10]
    //     nome = [J][o][s][u][e][ ][M][o][u][r][a]
    lcd.print(nome.substring(inicio, inicio + tamanho));
    inicio++;
  }

  // a funcao lenght retorna a quantidade de caracter usado em nome. Logo, uma vez que o valor for maior que [inicio] o bloco abaixo e executado.
  // Voltado para as configuracoes iniciais
  if(inicio > nome.length()) {
    inicio = 0;
    tamanho = 1;
    alterar = !alterar;
  }
  delay(TEMPO_ATUALILZACAO);
}
