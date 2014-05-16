
long wait = 20;
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

void loop()
{
  buttonState = digitalRead(7); 
  if (buttonState == HIGH) {
    for(int i = 10; i <= 13; i++) {
      digitalWrite(i, HIGH);
      delay(1);
      digitalWrite(i, LOW);
      delay(wait - 1);
    }  
    for(int i = 22; i < 45; i++) {    
      digitalWrite(i, HIGH);
      delay(1);
      digitalWrite(i, LOW);
      delay(wait - 1);
    }
  }
}

