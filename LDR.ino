// C++ code
//

//Lendo o valor de entrada atraves do sensor de luminosidade
static int LDR = A1;

//Saida
static int LED = 13;

//Amarzenando o valor lido
static int valor = 0;

void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  valor = analogRead(LDR);
  
  if(valor<500) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
    delay(100);
  }  
}
