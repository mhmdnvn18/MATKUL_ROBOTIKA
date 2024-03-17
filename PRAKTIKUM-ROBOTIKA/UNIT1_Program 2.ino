int timer = 100;
int ledPins[] = {2, 3, 4, 5, 6, 7}; // Use curly braces to define the array
int pinCount = 6;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { // Fixed variable naming and added opening curly brace
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { // Fixed variable naming and added opening curly brace
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    digitalWrite(ledPins[thisPin], LOW);
  }

  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { // Fixed variable naming and added opening curly brace
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    digitalWrite(ledPins[thisPin], LOW);
  }
}
