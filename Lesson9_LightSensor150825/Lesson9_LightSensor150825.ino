#include <Servo.h>

const int sensorPin = A0;
const servoPin = 3;
const int LEDPin = 10;

int lightAmount = 0;
int servoAngle = 0;
int inputCommand = 0;

Servo myServo;

void setup() {
  pinMode (LEDPin, OUTPUT);
  Serial.begin(9600);

  myServo.attach(servoPin);
}

void loop() {
  transmitter();
  receiver();
}

void transmitter() {
  if (millis() >= timerLED + 2000){
    toggleLED = !toggleLED;
    digitalWrite(LEDPin, toggleLED);
    timerLED = millis();
  }
}

void receiver() {
  if (millis() >= timerSensor + 100) {
    lightAmount = analogRead(sensorPin);

    Serial.print("Light Intensity: ");
    Serial.println(lightAmount);

    timerSensor = millis();
  }
}

