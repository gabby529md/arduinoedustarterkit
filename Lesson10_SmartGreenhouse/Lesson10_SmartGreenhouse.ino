#include <Servo.h>  // includes the Servo library
#include <dht.h> // includes the DHT22 library

dht myDHT;
Servo myServo;

// Arduino board pins
const int lightSensor = A0;
const int lightLED = 13;
const int DHT22Sensor = 11;
const int tempBuzzer = 9;
const int servoPin = 6;
const int waterLED = 4;

// sensing and angle variables
int lightAmount = 0;
int tempAmount = 0;
int humidAmount = 0;
int rate = 500;
int frequency = 1000000 / (rate * 2);
int servoAngle = 0;
int increment = 10;

void setup() {
  // setting pins to output
  pinMode(lightLED, OUTPUT);
  pinMode(tempBuzzer, OUTPUT);
  pinMode(waterLED, OUTPUT);

  // 
  myServo.attach(servoPin);
  myServo.write(servoAngle);

  Serial.begin(9600);
}

void loop() {
  // reading the amount of light/temperature/humidity on the corresponding sensor
  lightAmount = analogRead(lightSensor);
  int readData = myDHT.read22(DHT22Sensor);

  tempAmount = myDHT.temperature;
  humidAmount = myDHT.humidity;
  
  // Light Intensity with LED
  if (lightAmount <= 100) {
    digitalWrite(lightLED, HIGH);
  }
  else {
    digitalWrite(lightLED, LOW);
  }

    // Temperature with Buzzer
  if (tempAmount < 18) {
    noTone(9);
  tone(9, 261, 500);
  delay(500);
  }
  if (tempAmount > 24) {
    noTone(9);
  tone(9, 523, 500);
  delay(500);
  }

  // Humidity with Servo motor and water LED
  if (humidAmount < 47 ) {
    digitalWrite(waterLED, HIGH);
  }
  if (humidAmount > 70) {
    digitalWrite(waterLED, LOW);
    delay(100);
    digitalWrite(waterLED, HIGH);
    delay(100);
  }
  if (humidAmount > 46 && humidAmount < 70) {
    digitalWrite(waterLED, LOW);
  }

  Serial.print("Light Intensity: ");
  Serial.print(lightAmount);
  
  Serial.print("   Temperature: ");
  Serial.print(tempAmount);
  Serial.print("°C ");

  Serial.print("   Humidity: ");
  Serial.print(humidAmount);
  Serial.println("% ");
  delay(1000);

}

