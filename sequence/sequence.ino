int inputPin = 7;
int startPin = 22;
int endPin = 45;

long wait = 20;

void setup() {
  
  // Input
  pinMode(inputPin, INPUT);
  
  // set the digital pin as output:
  for(int i = startPin; i < endPin; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop()
{
  buttonState = digitalRead(7); 
  if (buttonState == HIGH) {
    for(int i = startPin; i < endPin; i++) {    
      digitalWrite(i, HIGH);
      delay(1);
      digitalWrite(i, LOW);
      delay(wait - 1);
    }
  }
}
