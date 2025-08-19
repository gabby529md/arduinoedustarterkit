int readValue = 0;
int writeValue = 0;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  readValue = analogRead(A0);
  writeValue = readValue / 4;

  analogWrite(6, writeValue);
  analogWrite(11, writeValue);
  
  if (digitalRead(2) == HIGH) {
    digitalWrite(13, HIGH);
    digitalWrite(8, LOW);
  }
  if (digitalRead(2) == LOW) {
    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
  }
  
}
