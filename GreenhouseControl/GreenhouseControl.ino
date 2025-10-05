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
static int buzzer = 12;

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

bool p_80 = LOW;
bool p_5179 = LOW;
bool p_50 = LOW;

void setup(){
  pinMode(bt,INPUT_PULLUP);
  pinMode(phtR,INPUT);
  pinMode(led_Vermelho,OUTPUT);
  pinMode(led_Amarelo,OUTPUT);
  pinMode(led_Verde,OUTPUT);
  pinMode(buzzer,OUTPUT);

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
    int par = lerPhotoresistor();

    // Checar valor em porcentagem para o tratamento de tomada de decisao
    int porcentagem = map(par, 54, 974, 0, 100);
    if(porcentagem <= 50 ) {
      //Vermelho
      ligarLed(led_Verde);
      p_80 = LOW;
      if(!p_50) {
        tocarBuzzer(1);
        p_50 = !p_50;
      }      
      //Serial.println("Escuro");
    } else if ( porcentagem >= 80) {
      ligarLed(led_Vermelho);
      p_5179 = LOW;
      if(!p_80) {
        tocarBuzzer(3);
        p_80 = !p_80;
      }
    } else {
      ligarLed(led_Amarelo);
      p_50 = LOW;
      if(!p_5179) {
        tocarBuzzer(2);
        p_5179 = !p_5179;
      }
    }
    
  }
}

void sistemaOnOff() {
  sistema_ON_OFF = !sistema_ON_OFF;
  if(sistema_ON_OFF == LOW) {
    digitalWrite(led_Amarelo, LOW);
    digitalWrite(led_Verde, LOW);
    digitalWrite(led_Vermelho, LOW);
	p_80 = LOW;
    p_5179 = LOW;
    p_50 = LOW;
    Serial.println("Sistema desligado");
  } else {
    Serial.println("Sistema ligado");
  }
}

int lerPhotoresistor(){
  valor = analogRead(phtR);
  return valor;
}

void ligarLed(int ledEscolhido) {
  digitalWrite(led_Verde, ( ledEscolhido == led_Verde) ? HIGH : LOW);
  digitalWrite(led_Amarelo, ( ledEscolhido == led_Amarelo) ? HIGH : LOW);
  digitalWrite(led_Vermelho, (ledEscolhido == led_Vermelho) ? HIGH : LOW);
}

void tocarBuzzer(int par) {
  Serial.println(par);
  for(int x =0; x < par;x++){
	tone(buzzer,500,500);
	delay(1500);
	}
}
