/*
  Projeto: Termometro digital
  Autor: Josue Moura
  Data: 11/10/2025
  
  Description: Assemble a digital thermometer that 
  allows you to choose the temperature scale 
  to be displayed.
  
*/
// Incluindo a biblioteca
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int bt_A0 = 13;// Mudar a escla de temperatura

// Tensao de referencia
float tensaoRef = 5.0;

// Variaveis de debounce
static unsigned long ultimoDebounceTime;
static unsigned long bounceDelay = 20;

//Variaveis do estado do botao
static bool estadoBotao =  HIGH;
static bool botaoPressionado  =  HIGH;
static bool ultimoEstadoBotao = LOW;
bool escala = LOW;

void setup()
{
  pinMode(bt_A0, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
    int leitura = digitalRead(bt_A0);
    Serial.println(leitura);
  
    if(leitura == LOW && ultimoEstadoBotao == HIGH) {

        botaoPressionado = LOW;
        
    }
    
    if (leitura != ultimoEstadoBotao) {
      	ultimoDebounceTime = millis();
       		
    }
    
    if ((millis() - ultimoDebounceTime) > bounceDelay) {
        
        if (botaoPressionado != estadoBotao) {
            estadoBotao = botaoPressionado;
            
            if (estadoBotao == LOW) {
                escala = !escala; // Alterna escala
              	botaoPressionado = !botaoPressionado;
              	estadoBotao = !estadoBotao;
            }
        }
    }
    
    ultimoEstadoBotao = leitura;

    float temp = funcaoTemp();
    lcd.clear();
    lcd.print(temp);

    delay(250);
}

float funcaoTemp() {

    // Ler o valor analogico do sensor TMP
    int valor = analogRead(A0);// Valores entre 20-358

    // Tensao correspondente ao valor lido
    float tensao = valor * tensaoRef;
    tensao /= 1023.0;

    // Valor da temperatura correspondente ao valor da tensao

    float temp;

    if( escala == LOW) {
        temp = (tensao - 0.5 ) * 100;
    } else {
        temp = (((tensao - 0.5 ) * 100) * 9/5) + 32;
    }

    return temp;
    
}