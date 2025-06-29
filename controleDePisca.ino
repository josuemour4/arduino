// C++ code
//

static int LED = 13;

static int POT = A1;

static int valor = 0;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  valor = analogRead(POT);
  digitalWrite(LED, HIGH);
  delay(valor); // Wait for 1000 millisecond(s)
  digitalWrite(LED, LOW);
  delay(valor); // Wait for 1000 millisecond(s)
}
