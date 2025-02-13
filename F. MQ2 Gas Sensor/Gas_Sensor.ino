int gas = A0; // Define gas sensor pin as analog pin A0
int buzz = 8; // Define buzzer pin as digital pin 8

void setup()
{
  pinMode(gas, INPUT); // Set gas sensor pin as an input
  pinMode(buzz, OUTPUT); // Set buzzer pin as an output
  Serial.begin(9600); // Initialize serial communication at a baud rate of 9600
}

void loop()
{
  gas = analogRead(A0); // Read the analog value from the gas sensor
  Serial.println(gas); // Print the gas sensor value to the Serial Monitor
  
  if(gas > 300) // Check if the gas sensor value exceeds the threshold (300)
  {
    digitalWrite(buzz, HIGH); // Turn the buzzer on if gas level is high
  }
  else
  {
    digitalWrite(buzz, LOW); // Turn the buzzer off if gas level is normal
  }

  delay(150); // Wait for 150 milliseconds before reading again
}