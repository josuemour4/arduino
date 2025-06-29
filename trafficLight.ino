// C++ code
//

int lpGreen = 13;
int lpRed = 12;
int tlGreen = 9;
int tlYellow = 11;
int tlRed = 10;

void setup()
{
  pinMode(lpGreen, OUTPUT);
  pinMode(lpRed, OUTPUT);
  pinMode(tlGreen, OUTPUT);
  pinMode(tlYellow, OUTPUT);
  pinMode(tlRed, OUTPUT);
}

void loop()
{
  // Start with traffic light green on and pedestrian red on
  digitalWrite(lpRed, HIGH);
  digitalWrite(tlGreen, HIGH);
  delay(10000); // Wait for 10000 millisecond(s)
  digitalWrite(tlGreen, LOW);
  delay(1); // Wait for 1000 millisecond(s)
  
  // Condition for the yellow
  digitalWrite(tlYellow,HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(tlYellow, LOW);
  delay(1); // Wait for 1000 millisecond(s)
  digitalWrite(lpRed, LOW);
  delay(1); // Wait for 1000 millisecond(s)
  digitalWrite(lpGreen, HIGH);
  
  digitalWrite(tlRed, HIGH);
  delay(10000); // Wait for 10000 millisecond(s)
  digitalWrite(lpGreen, LOW);
  digitalWrite(tlRed, LOW);
  delay(1); // Wait for 1000 millisecond(s)
}