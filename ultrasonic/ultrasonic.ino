#include <LiquidCrystal.h>
LoquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tring = 9;
int echo = 10;
int duration;
int distances;
void setup() {
  Serial.begin(9600);
  pinMode(tring, OUTPUT);
  pinMode(echo, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  digitalWrite(tring, LOW);
  delayMicroseconds(2);
  digitalWrite(tring, HIGH);
  delayMicroseconds(10);
  digitalWrite(tring, LOW);
  duration = pulseIn(echo, HIGH);
  distances = (duration / 2) * 0.0343;
  delay(1000);
  lcd.println(distances);
  lcd.setCursor(0, 0);
  Serial.println(distances);
}
