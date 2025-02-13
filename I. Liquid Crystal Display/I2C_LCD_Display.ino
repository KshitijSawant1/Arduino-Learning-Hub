#include <LiquidCrystal_I2C.h> // Include the library for I2C LCD
#include <Wire.h> // Include the Wire library for I2C communication

// Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  lcd.init(); // Initialize the LCD screen
  
  lcd.backlight(); // Turn on the LCD backlight
}

void loop() {
  delay(1000); // Wait for 1 second
  
  lcd.setCursor(0,0); // Set cursor to the first column and first row
  
  lcd.print("Hello"); // Print "Hello" on the LCD screen
}