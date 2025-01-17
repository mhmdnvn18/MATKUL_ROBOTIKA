int M1 = 10;
int M2 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(M1, 50);
analogWrite(M2, 0);
}
