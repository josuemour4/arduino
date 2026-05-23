/* ********************************************************************** 
  Projeto: 7-SegmentDisplay - v1.0
  Autor: Josue Moura
  Data: 11/10/2025
  
  Description: This sketch illustrates the controlling a 7-segment display with
  a 74HC595 shift register.
  
*/

int Clock = 2;
int ST = 3;
int DADO = 4;

int numeros[10][8] = {
  {1,1,1,1,1,1,0,1}, // 0
  {0,1,1,0,0,0,0,1}, // 1
  {1,1,0,1,1,0,1,1}, // 2
  {1,1,1,1,0,0,1,1}, // 3
  {0,1,1,0,0,1,1,1}, // 4
  {1,0,1,1,0,1,1,1}, // 5
  {1,0,1,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0,1}, // 7
  {1,1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1,1}  // 9
};

int count = 0;

void setup() {

  pinMode(Clock,OUTPUT);
  pinMode(ST,OUTPUT);
  pinMode(DADO,OUTPUT);
  
}

void loop() {

  if(count < 10 ) {
      for (int x = 7; x >=0; x--){
      if(numeros[count][x] == 0) {
        digitalWrite(DADO, LOW);
      } else {
        digitalWrite(DADO, HIGH);
      }
      digitalWrite(Clock, HIGH);
      digitalWrite(Clock, LOW);
    }
    digitalWrite(ST, HIGH);
    digitalWrite(ST, LOW);
    delay(1000);
    count++;
  } else {
    count = 0;
  }  

}
