/*
  Projeto: Display 7 segmentos
  Autor: Josue Moura
  Data: 04/04/2026
  
  Description: Usar o arduino Para
  controlar um Display 7 segmentos
  e exibir os numeros de 0-9
  
*/// C++ code
//
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int ponto = 9;
  
int zero [] = {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW};
int um [] = {LOW,HIGH,HIGH,LOW,LOW,LOW,LOW};
int dois [] = {HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH};
int tres [] = {HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH};
int quatro [] = {LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH};
int cinco[] = {HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH};
int seis[] = {HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH};


// Para usar depois
int numeros[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};





void setup()
{
  for(int pino = a; pino <= ponto; pino++ ){
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
  }  
  Serial.begin(9600);
}

void loop()
{
    
  inicio();
  
  F_00();
  delay(1000);
  F_01();
  delay(1000);
  F_02();
  delay(1000);
  F_03();
  delay(1000);
  F_04();
  delay(1000);
  
}

void F_00() {
	for(int x = a; x <= ponto; x++){
      int indice = x-2;      
		if(zero[indice]==LOW){
			 digitalWrite(x,LOW);
        } else {
          digitalWrite(x,HIGH);
        }
	}

}

void F_01() {
	for(int x = a; x <= ponto; x++){
      int indice = x-2;      
		if(um[indice]==LOW){
			 digitalWrite(x,LOW);
        } else {
          digitalWrite(x,HIGH);
        }
	}

}

void F_02() {
	for(int x = a; x <= ponto; x++){
      int indice = x-2;      
		if(dois[indice]==LOW){
			 digitalWrite(x,LOW);
        } else {
          digitalWrite(x,HIGH);
        }
	}

}

void F_03() {
	for(int x = a; x <= ponto; x++){
      int indice = x-2;      
		if(tres[indice]==LOW){
			 digitalWrite(x,LOW);
        } else {
          digitalWrite(x,HIGH);
        }
	}

}

void F_04() {
	for(int x = a; x <= ponto; x++){
      int indice = x-2;      
		if(quatro[indice]==LOW){
			 digitalWrite(x,LOW);
        } else {
          digitalWrite(x,HIGH);
        }
	}

}

void inicio(){
  for(int pino = a; pino <= ponto; pino++ ){
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
  }  
  for(int pino = a; pino <= ponto; pino++ ){
    digitalWrite(pino, HIGH);
    delay(1000);
    digitalWrite(pino, LOW);
  }

}