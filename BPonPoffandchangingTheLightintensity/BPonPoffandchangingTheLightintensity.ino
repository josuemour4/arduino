/*
  Projeto: Controle de LED com botão + 
  Alterar a luminosidade de
  intensidade luminosa de um LED
  Autor: Josue Moura
  Data: 26/07/2025
  
  Description: Toggles the LED state (on/off) 
  each time the button is pressed and
  changing the light intensity
  
*/

static int botao = 7;
static int led = 9;

static int POT = A1;
static int POTValor = 0;
bool condicao =  false;

//Possivel estado para botao, led e analog
bool ledOnOff = LOW;
bool ultimoPocisaoDoBotao =  HIGH;
bool analog = LOW;

unsigned long tempo = 0;
unsigned long longTempo = 5000;// 5*10^-3 =  5 Segundos

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop()
{
  bool ler =  digitalRead(botao);
  
  if(analog == 1 ) {
    
    POTValor = analogRead(POT);
    int intensidade = map(POTValor, 0, 1023, 0, 255); // Mapeia para 0-255
    analogWrite(led, (intensidade/4));
    
    if(!condicao) {
      condicao = !condicao;
      analogWrite(led,intensidade);
    }
    
    if(POTValor < 5 ) {
      condicao = !condicao;
      analogWrite(led,LOW);
      analog = 0;
    }
        
    Serial.println(POTValor);
    
    
  } else {
    
    if(ler != ultimoPocisaoDoBotao && analog == LOW){
    
      tempo = millis();// Registra o exato momento que o botao foi precionado
      
      
      alterar(ler);
      digitalWrite(led,ledOnOff);
      ultimoPocisaoDoBotao = ler;
    }
  
    if(ler == LOW && (millis() - tempo >= longTempo)) {
      analog = !analog;
      Serial.println("5 Segundos. Agora o led deve ficar sempre acesso.");
    }
    
  }
     
}

void alterar(bool valor){
  if(valor == LOW) {
    ledOnOff = !ledOnOff;
  }  
}
