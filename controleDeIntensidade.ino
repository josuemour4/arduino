// C++ code
//

static int LED = 9;

static int POT = A1;

static int valor = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  valor = analogRead(POT);
  
  if(valor > 0) {
    analogWrite(LED, (valor/4));
    Serial.println(valor);
  }
}
