
int buttonState;

void setup() {
  
  // Input
  pinMode(7, INPUT);
  
  // set the digital pin as output:
  for(int i = 22; i < 45; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop()
{
  buttonState = digitalRead(7); 
  if (buttonState == HIGH) {
    PORTA = B11111111; // T1i
    delay(1);
    PORTC = B11111111; // T3i
    delay(13); // Deplay behind T5i for T3i
    PORTD = B11111111; // T5i
    delay(20);    
    PORTA = B00000000;
    PORTC = B00000000;
    PORTD = B00000000;
  }
}

