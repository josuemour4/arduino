/*
  Projeto: Greenhouse Control
  Autor: Josue Moura
  Data: 20/07/2025
  
  Description: Controlling the brightness of a 
  greenhouse using sensors and screen opening 
  and closing controls that regulate sunlight entry.

  Design to maintain low light levels for ornamental plants.
  
*/


// Criacao das variaveis resonsavel pela conexao dos pinos 
static int bt = 7;
static int phtR = A1;
static int led_Vermelho = 8;
static int led_Amarelo = 4;
static int led_Verde = 2;

//Variaveis de condicao
bool bt_Ultimo_Estado = LOW;
bool bt_Estado;
bool sistema_ON_OFF = LOW;
bool led_Estado = LOW;

//Variaveis de debounce
static unsigned long ultimo_Debounce;
static unsigned long debounceDelay = 50;

//Variavel para armazenar o valor do analogico.
static int valor;

static int valorMaximo = 1028;

void setup(){
  pinMode(bt,INPUT_PULLUP);
  pinMode(phtR,INPUT);
  pinMode(led_Vermelho,OUTPUT);
  pinMode(led_Amarelo,OUTPUT);
  pinMode(led_Verde,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool ler = digitalRead(bt);

  if( bt_Ultimo_Estado != ler ) {
    ultimo_Debounce = millis();
  }

  if( (millis() - ultimo_Debounce) > debounceDelay ) {

    if(ler != bt_Estado) {

      bt_Estado = ler;

      if(bt_Estado == LOW) {
        sistemaOnOff();
      }
    }

  }

  bt_Ultimo_Estado = ler;

  if(sistema_ON_OFF == HIGH) {
    lerPhotoresistor();
  }
}

void sistemaOnOff() {
  sistema_ON_OFF = !sistema_ON_OFF;
  if(sistema_ON_OFF == LOW) {
    Serial.println("Sistema desligado");
  } else {
    Serial.println("Sistema ligado");
  }
}

void lerPhotoresistor(){
  valor = analogRead(phtR);
  alterarLed(valor);
}

void alterarLed(int valorIn) {

  int porcentagem = map(valorIn, 54, 974, 0, 100);
  
  if(porcentagem <= 50 ) {
    //Vermelho
    Serial.println("Escuro");
  } else if ( porcentagem >= 80) {
    Serial.println("Claro");
  } else {
    //verde
    Serial.println("Medade da capacidade");
  }

}

void ligarLed(int parametro) {

}


