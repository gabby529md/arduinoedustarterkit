
int readValue = 0;
int writeValue = 0;

void setup() {
  pinMode(9, OUTPUT);   // declare LED1 as output
  pinMode(10, OUTPUT);  // declare LED2 as output
  pinMode(11, OUTPUT);  // declare LED3 as output
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(A0);  // store the value from the potentiometer
  writeValue = readValue / 4;  // divide the readValue by 4 and store as the writeValue

  if (writeValue >= 0 && writeValue <= 100) {
    analogWrite(9, writeValue);  // turn on LED1
    analogWrite(10,0);
    analogWrite(11,0);
  } else if (writeValue >= 101 && writeValue <= 200) {
    analogWrite(9, writeValue);
    analogWrite(10, writeValue);
    analogWrite(11,0);
  } else if (writeValue > 200) {
    analogWrite(9, writeValue);
    analogWrite(10, writeValue);
    analogWrite(11, writeValue);
    
  }

  Serial.println(writeValue);
  delay(1000);
}
