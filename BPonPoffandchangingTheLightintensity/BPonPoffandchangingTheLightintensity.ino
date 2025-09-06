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
  //Definicao dos pinos
  static int LED = 9;// pino analogico
  static int BT = 7;
  static int POT = A1;

  //Definicao das variaveis de estado
  bool led_ON_OFF = LOW;
  bool bt_Ultimo_Estado = LOW;
  bool bt_Estado;
  bool analogico = LOW;

  //Definicao das variaveis de debounce
  unsigned long deBounceDelay = 50;
  unsigned long lastDebounce;

  //Variavel para analisar que o botao esta precionado por 5s
  unsigned long bt_Precionado_5s = 5000;
  unsigned long cronometro;

  //varial para o valor do led no analogico
  static int valor;

  void setup() {
    pinMode(LED,OUTPUT);
    pinMode(BT,INPUT_PULLUP);

    Serial.begin(9600);
  }

  void loop() {
    bool ler = digitalRead(BT);

    if(ler != bt_Ultimo_Estado){
      lastDebounce = millis();
    }

    if((millis() - lastDebounce) > deBounceDelay) {

      //Condicao para acionar o analogico
      if(ler == 0 && bt_Estado == 0 && led_ON_OFF == HIGH && analogico == LOW){
        
        cronometro = millis() - lastDebounce;

        //Ao tempo de 5 millis segundos acionar a condicao abaixo
        if(cronometro >= bt_Precionado_5s){
          Serial.println("5 segundos");
          if(analogico == LOW){
            analogico = HIGH;
          }
        }
      }

      if(analogico == LOW){

        if(ler != bt_Estado) {

          bt_Estado = ler;

          if(bt_Estado == LOW){
            led_ON_OFF = !led_ON_OFF;
            digitalWrite(LED,led_ON_OFF);
          }

        }
      } else if( analogico == HIGH) {
        int valor_Analogico = analogRead(POT);
        valor = valor_Analogico/4;
        analogWrite(LED,valor);
        if(valor < 5){
          analogWrite(LED,LOW);
          delay(50);
          analogico = LOW;
        }
      }

    }

    bt_Ultimo_Estado = ler;
  }
