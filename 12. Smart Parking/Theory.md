# **🚗 Smart Parking Assistant using Ultrasonic Sensor & Arduino**  

## **Objective:**  
Build a **Smart Parking System** that measures the distance between a vehicle and an obstacle using an **Ultrasonic Sensor** and **displays the distance on an LCD**. It also uses an LED indicator or buzzer for alerts.  

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| Ultrasonic Sensor (HC-SR04) | 1 |
| LCD 16x2 (I2C) | 1 |
| Buzzer (Optional) | 1 |
| LED (Red, Yellow, Green) | 3 |
| Resistors (220Ω) | 3 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**  
- The **ultrasonic sensor** continuously measures the distance between the car and an obstacle.  
- The **LCD displays the distance in centimeters (cm)**.  
- **LED Indicators**:
  - 🟢 **Green LED (Safe Zone)** → Distance > 20cm  
  - 🟡 **Yellow LED (Caution)** → Distance between 10cm - 20cm  
  - 🔴 **Red LED (Danger)** → Distance < 10cm, Buzzer sounds  

---

## **Circuit Connections:**
| **Ultrasonic Sensor** | **Connection** |
|------------------|----------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| Trig | Digital Pin 9 |
| Echo | Digital Pin 10 |

| **LCD I2C** | **Connection** |
|--------|--------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 (Arduino) |
| SCL | A5 (Arduino) |

| **LEDs** | **Connection** |
|-------------|----------------|
| Green LED | Digital Pin 5 |
| Yellow LED | Digital Pin 6 |
| Red LED | Digital Pin 7 |
| Buzzer | Digital Pin 8 |

---

## **Arduino Code for Smart Parking System**
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG 9
#define ECHO 10
#define GREEN_LED 5
#define YELLOW_LED 6
#define RED_LED 7
#define BUZZER 8

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.backlight();
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    
    lcd.setCursor(0, 0);
    lcd.print("Smart Parking");
    delay(2000);
}

void loop() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print(" cm");

    if (distance > 20) {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(RED_LED, LOW);
        digitalWrite(BUZZER, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Status: Safe");
    } else if (distance <= 20 && distance > 10) {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(BUZZER, LOW);
        lcd.setCursor(0, 1);
        lcd.print("Status: Caution");
    } else {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("Status: STOP! 🚨");
    }

    delay(500);
}
```

---

## **Explanation:**
1. **Distance Measurement with Ultrasonic Sensor**  
   - Sends an ultrasonic pulse and measures **time-of-flight**.  
   - Converts time into **distance (cm)**.  

2. **LCD Display for Real-Time Distance**  
   - Shows **live distance readings**.  
   - Displays **"Safe", "Caution", or "STOP!"** based on the distance.  

3. **LED & Buzzer Alerts Based on Distance**  
   - 🟢 **Green LED** → Safe (>20cm)  
   - 🟡 **Yellow LED** → Caution (10cm-20cm)  
   - 🔴 **Red LED + Buzzer** → Danger (<10cm)  

---

## **Expected Output:**
| **Distance (cm)** | **LCD Display** | **LEDs** | **Buzzer** |
|---------------|----------------|------|------|
| >20 cm | "Safe" | 🟢 Green ON | OFF |
| 10-20 cm | "Caution" | 🟡 Yellow ON | OFF |
| <10 cm | "STOP! 🚨" | 🔴 Red ON | ON |

---

## **Real-Life Applications:**
✅ **Smart Parking Assistant** – Guides vehicles to park safely.  
✅ **Reverse Parking System** – Prevents collisions when reversing.  
✅ **Industrial Safety** – Detects obstacles near machinery.  
✅ **IoT-based Smart Parking** – Can be connected to a mobile app for **smart city parking solutions**.  

---