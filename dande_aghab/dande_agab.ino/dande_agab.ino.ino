int trig = 11;
int echo = 10;
int duration;
int distances;
int led = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distances = (duration / 2) * 0.0343;
  Serial.println(distances);
  if (distances <= 30) {
    int f = map(distances, 30, 4, 0, 255);
    analogWrite(led, f);
  }
  delay(10);
}
