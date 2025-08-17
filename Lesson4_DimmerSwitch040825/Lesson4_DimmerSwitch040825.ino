
int readValue = 0;
int writeValue = 0;

void setup() {
  pinMode(9, OUTPUT);   // declare LED1 as output
  pinMode(10, OUTPUT);    // declare LED2 as output
  pinMode(11, OUTPUT);    // declare LED3 as output
  Serial.begin(9600);

}

void loop() {
  readValue = analogRead(A0);   // store the value from the potentiometer  
  writeValue = readValue / 4;   // divide the readValue by 4 and store as the writeValue

  analogWrite(9, writeValue);
  analogWrite(10, writeValue);
  analogWrite(11, writeValue);

  if (readValue > 1000) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(250);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(250);
  }
  else {
    analogWrite(9, writeValue);
    analogWrite(10, 0);
    analogWrite(11,0);
  }

  Serial.print(readValue);
  Serial.print(" : ");
  Serial.println(writeValue);
  delay(100); 
}
