/*
  Projeto: Display 7 segmentos
  Autor: Josue Moura
  Data: 04/04/2026
  
  Description: Usar o arduino Para
  controlar um Display 7 segmentos
  e exibir os numeros de 0-9
  
*/

// Pinos
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int ponto = 9;

//Matriz Numeros x Boleano para os pinos correspondentes a cada numero.
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
// Variavel contnador para ajudar no controle
int contador = 0;

void setup()
{
  // Iniciar tudo em nivel baixo
  for(int pino = a; pino <= ponto; pino++ ){
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
  }  
  Serial.begin(9600);
}

void loop()
{
  exibir(contador);
  contador++;
  if(contador > 10){
    contador = 0;
    inicio();
  }
  delay(1000);  
  
}

void exibir(int numero) {
  for(int x = a; x <= ponto; x++){
      int indice = x-2;
    Serial.println(indice);
		if(numeros[numero][indice]==LOW){
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
