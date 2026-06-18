const int buttonPin = 3;
const int ledPin = 5;
const int buzzerPin = 7;

bool alarmArmed = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  // Toggle alarm when button is pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    alarmArmed = !alarmArmed;
    delay(200); // debounce
  }

  lastButtonState = buttonState;

  if (alarmArmed) {

    digitalWrite(ledPin, HIGH);

    // Alarm sound
    tone(buzzerPin, 1000);
    delay(200);

    tone(buzzerPin, 1500);
    delay(200);

  } else {

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

  }
}
