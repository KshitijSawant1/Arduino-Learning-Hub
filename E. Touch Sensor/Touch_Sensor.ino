int touch_sensor = 13; // Define touch sensor pin as digital pin 13
int led = 12; // Define LED pin as digital pin 12

void setup()
{
   pinMode(touch_sensor , INPUT); // Set touch sensor pin as an input
   pinMode(led, OUTPUT); // Set LED pin as an output
}

void loop()
{
  touch_sensor  = digitalRead(13); // Read the state of the touch sensor and store it in the IR variable

  // int IR_Sensor = digitalRead(13); // Alternative way to read the touch sensor (commented out)

  if(touch_sensor  == HIGH) // Check if the touch sensor detects an object
  {
    digitalWrite(led, HIGH); // Turn the LED on if the touch sensor is triggered
  }
  else
  {
    digitalWrite(led, LOW); // Turn the LED off if the touch sensor is not triggered
  }
  
  delay(50); // Small delay to stabilize sensor readings
}