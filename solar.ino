// Green ON when path is clear, Red ON when an obstacle is detected.

const int IR_PIN    = 10;
const int GREEN_PIN = 5;
const int RED_PIN   = 6;

void setup() {
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
}

void loop() {
  int sensor = digitalRead(IR_PIN);
  bool obstacle = (sensor == LOW);

  if (sensor == HIGH) {
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
  }
  else if (sensor == LOW) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  }

  delay(20);
}