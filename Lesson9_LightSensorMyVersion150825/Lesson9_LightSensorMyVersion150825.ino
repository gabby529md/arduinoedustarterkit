const int sensorPin = A0;

int lightAmount = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lightAmount = analogRead(sensorPin);

  Serial.print("Light Intensity: ");
  Serial.println(lightAmount);

  delay(1000);

  if (lightAmount < 400) {
    analogWrite(8, 1023);
    analogWrite(10, 0);
    analogWrite(12, 0);
  }
  else if (lightAmount >= 400 && lightAmount < 800) {
    analogWrite(10, 1023);
    analogWrite(8, 0);
    analogWrite(12, 0);
  }
  else if (lightAmount >= 800 && lightAmount <=1023) {
    analogWrite(12, 1023);
    analogWrite(8, 0);
    analogWrite(10, 0);
  }

}