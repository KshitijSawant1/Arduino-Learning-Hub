
void setup()
{
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
}

void loop()
{
  // Serial.print("Hello World"); // Send "Hello World" message over serial communication (commented out)
  
  Serial.println("Hello World"); // Print "Hello World" with a new line after each print
  delay(1000); // Wait for 1 second before printing again
}
