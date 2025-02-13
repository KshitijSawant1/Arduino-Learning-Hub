int IR = 13; // Define IR sensor pin as digital pin 13
int led = 12; // Define LED pin as digital pin 12

void setup()
{
   pinMode(IR, INPUT); // Set IR sensor pin as an input
   pinMode(led, OUTPUT); // Set LED pin as an output
}

void loop()
{
  IR = digitalRead(13); // Read the state of the IR sensor and store it in the IR variable

  // int IR_Sensor = digitalRead(13); // Alternative way to read the IR sensor (commented out)

  if(IR == HIGH) // Check if the IR sensor detects an object
  {
    digitalWrite(led, HIGH); // Turn the LED on if the IR sensor is triggered
  }
  else
  {
    digitalWrite(led, LOW); // Turn the LED off if the IR sensor is not triggered
  }
  
  delay(50); // Small delay to stabilize sensor readings
}