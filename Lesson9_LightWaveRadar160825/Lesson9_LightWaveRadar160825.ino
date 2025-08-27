#include <Servo.h>

const int sensorPin = A0;
const int servoPin = 3;
const int LEDPin = 10;

int lightAmount = 0;
int servoAngle = 0;
int increment = 10;
int lightLow = 1023;
int lightHigh = 0;
int angleLow = 180;
int angleHigh = 0;

Servo myServo;

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(servoAngle);
  delay(500);
}

void loop() {
  for (servoAngle = 0; servoAngle <= 180; servoAngle = servoAngle + increment) {
    collectData();
    printData();
  }
  for (servoAngle = 180; servoAngle >= 0; servoAngle = servoAngle - increment) {
    collectData();
    printData();
  }
}

void collectData() {
  myServo.write(servoAngle);
  delay(100);

  lightAmount = analogRead(sensorPin);

  if (lightAmount > lightHigh) {
    lightHigh = lightAmount;
    angleHigh = servoAngle;
  }
  if (lightAmount < lightLow) {
    lightLow = lightAmount;
    angleLow = servoAngle;
  }
}

void printData() {
  Serial.print("Angle: ");
  Serial.print(servoAngle);
  Serial.print("  Light Intensity: ");
  Serial.print(lightAmount);
  Serial.print("  High: ");
  Serial.print(lightHigh);
  Serial.print("  Low: ");
  Serial.println(lightLow);
}
