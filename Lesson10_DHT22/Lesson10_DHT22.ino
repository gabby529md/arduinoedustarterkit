#include <dht.h>
#define dataPin 11
dht DHT;

void setup() {
  Serial.begin(9600);
}
void loop() {

  int readData = DHT.read22(dataPin);  // DHT22/


  float t = DHT.temperature;  // Gets the values of the temperature
  float h = DHT.humidity;     // Gets the values of the humidity


  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" °C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);
  Serial.println(" °F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.println("");

  delay(2000);
}