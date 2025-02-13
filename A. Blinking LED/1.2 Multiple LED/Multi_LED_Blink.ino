int LED1=13; // Define LED1 pin as digital pin 13
int LED2=12; // Define LED2 pin as digital pin 12
int LED3=11; // Define LED3 pin as digital pin 11

void setup()
{
  pinMode(LED1,OUTPUT); // Set LED1 pin as an output
  pinMode(LED2,OUTPUT); // Set LED2 pin as an output
  pinMode(LED3,OUTPUT); // Set LED3 pin as an output
}

void loop()
{
  digitalWrite(LED1,HIGH); // Turn LED1 on
  digitalWrite(LED2,LOW); // Turn LED2 off
  digitalWrite(LED3,LOW); // Turn LED3 off
  delay(500); // Wait for 500 milliseconds

  digitalWrite(LED1,LOW); // Turn LED1 off
  digitalWrite(LED2,HIGH); // Turn LED2 on
  digitalWrite(LED3,LOW); // Turn LED3 off
  delay(700); // Wait for 700 milliseconds

  digitalWrite(LED1,LOW); // Turn LED1 off
  digitalWrite(LED2,LOW); // Turn LED2 off
  digitalWrite(LED3,HIGH); // Turn LED3 on
  delay(900); // Wait for 900 milliseconds
}