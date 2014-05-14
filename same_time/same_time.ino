int inputPin = 7;
int startPin = 22;
int endPin = 45;
volatile bool fire = false;

void setup()
{
  // Interrupts
  attachInterrupt(inputPin, triggerCam, RISING);

  // set the digital pin as output:
  for(int i = startPin; i < endPin; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

// 22-29 PORTA (0x01-0x80)
// 30-37 PORTC (0x80-0x01)
// 38-45 PORTD (0x80-0x01)

void loop()
{
  if (state) {
    // Triggering output is delayed by 14 milliseconds due to the delay time it
    // takes the cameras to respond to the trigger sent to them. The different
    // models take different times and this is accounted for.
    PORTA = B11111111; // T1i fire here
    delay(1);  // Delay behind T3i for T1i
    PORTC = B11111111; // T3i fire here
    delay(13); // Delay behind T5i for T3i
    PORTD = B11111111; // T5i fire here

    // Wait and reset output back to low
    delay(20);    
    PORTA = B00000000;
    PORTC = B00000000;
    PORTD = B00000000;

    // One second reset time
    delay(1000);
    state = false;
  }
}

void triggerCam()
{
  state = true;
}
