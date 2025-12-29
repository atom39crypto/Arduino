const int ne555OutputPin = 2;  // Arduino pin connected to NE555 Pin 3 (OUTPUT)
const int ledPin = 3;          // Built-in LED to show status on Arduino

void setup() {
  pinMode(ne555OutputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int state = digitalRead(ne555OutputPin);  // Read NE555 output HIGH or LOW

  digitalWrite(ledPin, state);               // Mirror the NE555 output on Arduino LED

  Serial.print("NE555 Output: ");
  Serial.println(state == HIGH ? "HIGH" : "LOW");

  delay(100);
}