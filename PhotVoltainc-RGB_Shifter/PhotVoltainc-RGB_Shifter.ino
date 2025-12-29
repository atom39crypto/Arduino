int redPin = 2;
int greenPin = 3;
int bluePin = 4;

int ldrPin = A0;
int ldrValue = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);         // 0 to 1023
  int input = constrain(ldrValue, 0, 1000);

  int red = 0, green = 0, blue = 0;

  if (input <= 200) {
    // Red to Orange (Red=255, Green=0 → Red=255, Green=165)
    red = 255;
    green = map(input, 0, 200, 0, 165);
    blue = 0;
  } else if (input <= 400) {
    // Orange to Yellow (Green=165 → 255)
    red = 255;
    green = map(input, 200, 400, 165, 255);
    blue = 0;
  } else if (input <= 600) {
    // Yellow to Green (Red=255 → 0)
    red = map(input, 400, 600, 255, 0);
    green = 255;
    blue = 0;
  } else if (input <= 750) {
    // Green to Cyan (Blue=0 → 255)
    red = 0;
    green = 255;
    blue = map(input, 600, 750, 0, 255);
  } else if (input <= 900) {
    // Cyan to Blue (Green=255 → 0)
    red = 0;
    green = map(input, 750, 900, 255, 0);
    blue = 255;
  } else {
    // Blue to Purple (Red=0 → 128)
    red = map(input, 900, 1000, 0, 128);
    green = 0;
    blue = 255;
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  Serial.print("LDR: ");
  Serial.print(input);
  Serial.print(" | R: ");
  Serial.print(red);
  Serial.print(" G: ");
  Serial.print(green);
  Serial.print(" B: ");
  Serial.println(blue);

  delay(100);
}
