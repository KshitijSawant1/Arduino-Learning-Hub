int LED=13; // Define the LED pin as digital pin 13

void setup()
{
  pinMode(LED,OUTPUT); // Set the LED pin as an output
}

void loop()
{
  digitalWrite(LED,HIGH); // Turn the LED on
  delay(2000); // Wait for 2 seconds (2000 milliseconds)
  digitalWrite(LED,LOW); // Turn the LED off
  delay(2000); // Wait for 2 seconds (2000 milliseconds)
}