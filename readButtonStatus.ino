/*
  Projeto: Controle de LED com botão
  Autor: Josue Moura
  Data: 06/07/2025
  
  Description: Toggles the LED state (on/off) 
  each time the button is pressed, with debounce handling.

  This code was improved by Deepseek chat. 

  The previous one simply analyzed the condition of 
  value = LOW & previous = HIGH. 
  If both conditions were met, 
  then the status value was changed => stutus = !status.
*/

const int LED_PIN = 9;
const int BUTTON_PIN = 7;

// State variables
bool ledState = LOW;        
bool lastButtonState = LOW;  
bool buttonState;

// Variables for debounce
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Usa resistor pull-up interno
  /* 
   BUTTON PULL-UP (ARDUINO)
   -----------------------
       +5V (VCC)
        |
        |
       [ ] <-- Resistor Pull-Up (10kΩ)
        |
        |-----> Pino Digital (Ex.: D2)
        |
       === <-- Botão (fechado = LOW, aberto = HIGH)
        |
       GND
*/
  Serial.begin(9600);
  
  // Initialize the LED as off
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // Read the button status
  bool reading = digitalRead(BUTTON_PIN);
  
  // Checks if there was a change in the button state (debounce)
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  // Update the button state after the debounce time
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      // If the button was pressed (changed to LOW because of the PULLUP)
      if (buttonState == LOW) {
        ledState = !ledState;  // Inverte o estado do LED
        digitalWrite(LED_PIN, ledState);
        
        // Debug on the serial monitor
        Serial.print("LED alterado para: ");
        Serial.println(ledState ? "LIGADO" : "DESLIGADO");
      }
    }
  }
  
  // Update the last state of the button
  lastButtonState = reading;
}
