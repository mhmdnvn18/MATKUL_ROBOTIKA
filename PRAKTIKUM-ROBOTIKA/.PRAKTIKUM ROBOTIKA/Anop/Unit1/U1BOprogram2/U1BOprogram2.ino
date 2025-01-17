int timer = 100;
int ledPins[] = {2, 3, 4, 5, 6, 7 };
const int SW1 = 12;

void setup() 
{
  {
    pinMode(ledPins,OUTPUT);
    pinMode(SW1, INPUT);
  }
}
void loop() 
{
  {
    digitalRead(ledPins, HIGH);
    delay(timer);
    digitalRead(ledPins, LOW);
  }

}
 
