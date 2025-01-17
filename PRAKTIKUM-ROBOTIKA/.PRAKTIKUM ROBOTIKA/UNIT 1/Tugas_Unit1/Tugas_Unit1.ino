int timer = 100;
int ledPins[] = {2, 3, 4, 5, 6, 7};
int pinCount = 6;
int SW1 = 8;
int SW2 = 9;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  if (digitalRead(SW1) == HIGH || digitalRead(SW2) == HIGH) {
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPins[thisPin], HIGH);
      delay(timer);
      digitalWrite(ledPins[thisPin], LOW);
      if (thisPin < pinCount - 1) {
        digitalWrite(ledPins[thisPin + 1], HIGH);
      }
      if (digitalRead(SW2) == HIGH) {
        delay(timer * 2); // Menambahkan delay jika SW2 ditekan untuk mengubah kecepatan gerakan LED
      }
    }
    delay(timer);
    
    for (int thisPin = pinCount - 1; thisPin > 0; thisPin--) {
      digitalWrite(ledPins[thisPin], LOW);
      delay(timer);
      digitalWrite(ledPins[thisPin - 1], HIGH);
      if (digitalRead(SW2) == HIGH) {
        delay(timer * 2); // Menambahkan delay jika SW2 ditekan untuk mengubah kecepatan gerakan LED
      }
    }
    delay(timer);
  } else {
    for (int i = 0; i < pinCount; i++) {
      digitalWrite(ledPins[i], LOW); // Matikan semua LED saat tombol tidak ditekan
    }
  }
}
