// C++ code
//

// Pino de entrada ligado ao potenciometro
int POT = A1;

// Pino conectado ao LED
int LED = 13;

/*
Variavel que armazenara o valor obtido do potenciometro
*/
int valor = 0;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  valor = analogRead(POT);
  digitalWrite(LED, HIGH);
  delay(valor);
  digitalWrite(LED, LOW);
  delay(valor);
}
