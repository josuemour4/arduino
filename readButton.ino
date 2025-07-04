/*
  Projeto Read button
  Autor: Josue Moura
  
  Date: 05/07/2025
*/

/*
This is another example of a simple project from the Arduino Basics book that I am studying.

The goal is to detect a signal change on a digital pin (D7), which simulates, for example, 
a light barrier sensor. When the barrier is interrupted — such as when someone passes through it — 
the input value changes from 0 to 1 (depending on the sensor).

The code reads this value and replicates it on pin D9, which can be connected to a warning light or
a machine stop system.

I also added Serial communication to view the state change (0 or 1) on the serial monitor.

*/

static int LED = 9;

static int bt = 7;

static int valor = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(bt, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valor = digitalRead(bt);
  digitalWrite(LED, valor);
  delay(500);
  Serial.println(valor);
}
