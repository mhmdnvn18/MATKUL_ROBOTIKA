int M1 = 10;
int M2 = 9;

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  analogWrite(M1, 120);  // Set motor M1 to run at around 47% of its maximum speed
  analogWrite(M2, 0);    // Stop motor M2 by providing a constant 0 PWM signal
}
