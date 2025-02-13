const int buzzerPin = 7;  // Define buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as OUTPUT
}

void loop() {
  digitalWrite(buzzerPin, HIGH);  // Turn ON buzzer
  delay(1000);  // Wait for 1 second

  digitalWrite(buzzerPin, LOW);   // Turn OFF buzzer
  delay(1000);  // Wait for 1 second
}