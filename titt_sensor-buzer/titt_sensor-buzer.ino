int tiltPin = 2;    // Tilt switch connected to digital pin 2
int ledPin = 3;    // Onboard LED (or use an external one)

void setup() {
  pinMode(tiltPin, INPUT_PULLUP);  // Use internal pull-up
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tiltState = digitalRead(tiltPin);  // LOW = tilted, HIGH = upright

  if (tiltState == HIGH) {
    digitalWrite(ledPin, HIGH);  // LED ON (upright)
    Serial.println("Upright");
  } else {
    digitalWrite(ledPin, LOW);   // LED OFF (tilted)
    Serial.println("Tilted");
  }

  delay(100);
}
