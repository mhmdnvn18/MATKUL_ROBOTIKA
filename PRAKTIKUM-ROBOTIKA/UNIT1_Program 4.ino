const int LEDPin = 2;
const int SW1 = 12;
const int SW2 = 13;

void setup() 
{
  pinMode(LEDPin, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() 
{
  if (digitalRead(SW1) == HIGH) 
    {
    digitalWrite(LEDPin, HIGH);
    }
  if (digitalRead(SW2) == HIGH) 
  {
      digitalWrite(LEDPin, LOW);
  }
}
