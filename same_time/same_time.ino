
int buttonState;

void setup() {
  
  // Input
  pinMode(7, INPUT);
  
  // set the digital pin as output:
  for(int i = 22; i <= 45; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  for(int i = 10; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}
// Port order
// B -> A -> C -> G -> L
void loop()
{
  buttonState = digitalRead(7); 
  if (buttonState == HIGH) {
    // XT
    PORTB = B11100000;  
    delayMicroseconds(500);
    // XXi
    PORTB = B00010000;
    PORTA = B11000000;
    delayMicroseconds(16500);
    // T1i
    PORTA = B00111110;
    delayMicroseconds(1300);
    // T3i
    PORTA = B00000001;
    PORTC = B11111111; 
    delayMicroseconds(1300);
    // T5i
    PORTG = B11111111; 
    PORTL = B11111111;
    delay(50);    
    PORTA = B00000000;
    PORTB = B00000000;
    PORTC = B00000000;
    PORTG = B00000000;
    PORTL = B00000000;
  }
}

