const int dataPin = 4;   // DS
const int latchPin = 3;  // STCP
const int clockPin = 2;  // SHCP

// Binary pattern for the digit 3 (common cathode)
byte three = 0b01001111;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  displayDigit(three);
}

void loop() {
  // Keep refreshing the digit if needed
  displayDigit(three);
  delay(100);
}

void displayDigit(byte value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
