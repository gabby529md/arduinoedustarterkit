/*
  Multiple tone player

  Plays multiple tones on multiple pins in sequence

  circuit:
  - three 8 ohm speakers on digital pins 6, 7, and 8

  created 8 Mar 2010
  by Tom Igoe
  based on a snippet from Greg Borenstein

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/toneMultiple/
*/
const int buzzerPin = 8;

int rate = 500;
int frequency = 1000000 / (rate * 2);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.print(frequency);
}

void loop() {
 
   noTone(8);
  tone(8, 293, 500);
  delay(500);
   noTone(8);
  tone(8, 391, 500);
  delay(500);
   noTone(8);
  tone(8, 466, 500);
  delay(500);

   noTone(8);
  tone(8, 587, 1000);
  delay(1000);
   noTone(8);
  tone(8, 587, 500);
  delay(500);

   noTone(8);
  tone(8, 523, 500);
  delay(500);
   noTone(8);
  tone(8, 466, 500);
  delay(500);
   noTone(8);
  tone(8, 440, 500);
  delay(500);

   noTone(8);
  tone(8, 466, 2250);
  delay(2250);
   noTone(8);
  tone(8, 391, 250);
  delay(250);
   noTone(8);
  tone(8, 466, 250);
  delay(250);
   noTone(8);
  tone(8, 587, 250);
  delay(250);

   noTone(8);
  tone(8, 783, 1000);
  delay(1000);
   noTone(8);
  tone(8, 783, 500);
  delay(500);

   noTone(8);
  tone(8, 783, 500);
  delay(500);
   noTone(8);
  tone(8, 880, 500);
  delay(500);
   noTone(8);
  tone(8, 698, 250);
  delay(250);
   noTone(8);
  tone(8, 622, 250);
  delay(250);

   noTone(8);
  tone(8, 698, 2250);
  delay(2250);
   noTone(8);
  tone(8, 440, 250);
  delay(250);
   noTone(8);
  tone(8, 587, 250);
  delay(250);
   noTone(8);
  tone(8, 698, 250);
  delay(250);

   noTone(8);
  tone(8, 880, 1000);
  delay(1000);
   noTone(8);
  tone(8, 783, 500);
  delay(500);

   noTone(8);
  tone(8, 698, 500);
  delay(500);
   noTone(8);
  tone(8, 659, 500);
  delay(500);
   noTone(8);
  tone(8, 698, 500);
  delay(500);

   noTone(8);
  tone(8, 783, 1000);
  delay(1000);
   noTone(8);
  tone(8, 698, 500);
  delay(500);

   noTone(8);
  tone(8, 659, 1000);
  delay(1000);
   noTone(8);
  tone(8, 587, 500);
  delay(500);

   noTone(8);
  tone(8, 523, 500);
  delay(500);
   noTone(8);
  tone(8, 466, 500);
  delay(500);
   noTone(8);
  tone(8, 523, 500);
  delay(500);

   noTone(8);
  tone(8, 587, 500);
  delay(500);
   noTone(8);
  tone(8, 523, 500);
  delay(500);
   noTone(8);
  tone(8, 391, 500);
  delay(500);

   noTone(8);
  tone(8, 440, 1500);
  delay(1500); 


}
