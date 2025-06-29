// C++ code
//

static int buzzer = 8;

int notas[] = {262, 294, 330, 349, 392};

int melodia[] = {
  0, 1, 2, 3, 3, 3,
  0, 1, 0, 1, 1, 1,
  0, 4, 3, 2, 2, 2,
  0, 1, 2, 3, 3, 3
};

int duracaoNotas = 300;

void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < 24; i++) {
    tone(buzzer, notas[melodia[i]], duracaoNotas);
    delay(duracaoNotas + 50);
  }
  noTone(8);
  delay(2000);
}