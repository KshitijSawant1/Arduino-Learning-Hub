# **📊 Multi-Sensor Dashboard using Arduino & LCD**  

## **Objective:**  
Create a **real-time sensor monitoring system** where multiple sensors **(IR, MQ-2, Ultrasonic)** collect data and display it on an **LCD screen**. This project integrates **multiple inputs** and demonstrates data handling using **Arduino**.  

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| LCD 16x2 (I2C) | 1 |
| IR Sensor | 1 |
| MQ-2 Gas Sensor | 1 |
| Ultrasonic Sensor (HC-SR04) | 1 |
| Buzzer | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**  
- **IR Sensor** detects object presence.  
- **MQ-2 Gas Sensor** detects air quality/gas levels.  
- **Ultrasonic Sensor** measures distance from objects.  
- **LCD 16x2 (I2C)** displays real-time data.  
- **Buzzer** sounds an alarm when gas levels exceed the safe threshold.  

---

## **Circuit Connections:**
| **Component** | **Connection** |
|-------------|----------------|
| **IR Sensor** | Digital Pin 3 |
| **MQ-2 Sensor** | Analog Pin A0 |
| **Ultrasonic Sensor (Trig)** | Digital Pin 9 |
| **Ultrasonic Sensor (Echo)** | Digital Pin 10 |
| **LCD I2C (SDA)** | A4 |
| **LCD I2C (SCL)** | A5 |
| **Buzzer** | Digital Pin 6 |

---

## **Arduino Code for Multi-Sensor Dashboard**
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define IR_SENSOR 3
#define MQ2_SENSOR A0
#define TRIG 9
#define ECHO 10
#define BUZZER 6

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.backlight();
    
    pinMode(IR_SENSOR, INPUT);
    pinMode(MQ2_SENSOR, INPUT);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);
    
    lcd.setCursor(0, 0);
    lcd.print("Multi-Sensor");
    lcd.setCursor(0, 1);
    lcd.print("Dashboard");
    delay(2000);
    lcd.clear();
}

void loop() {
    // IR Sensor Reading
    int irStatus = digitalRead(IR_SENSOR);
    
    // MQ-2 Gas Sensor Reading
    int gasLevel = analogRead(MQ2_SENSOR);

    // Ultrasonic Distance Measurement
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2;

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Gas: ");
    lcd.print(gasLevel);
    
    lcd.setCursor(9, 0);
    lcd.print("Obj: ");
    if (irStatus == HIGH) {
        lcd.print("Yes");
    } else {
        lcd.print("No ");
    }

    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");
    
    // Buzzer Alert for Gas
    if (gasLevel > 400) {
        digitalWrite(BUZZER, HIGH);
    } else {
        digitalWrite(BUZZER, LOW);
    }

    Serial.print("Gas Level: ");
    Serial.print(gasLevel);
    Serial.print(" | IR: ");
    Serial.print(irStatus ? "Detected" : "Not Detected");
    Serial.print(" | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000);
}
```

---

## **Explanation:**
1. **IR Sensor** detects if an object is near.  
2. **MQ-2 Gas Sensor** measures gas levels (threshold = 400).  
3. **Ultrasonic Sensor** calculates distance in cm.  
4. **LCD 16x2** displays real-time sensor readings.  
5. **Buzzer** sounds an alert if gas levels are too high.  

---

## **Expected LCD Output:**
```
Gas: 350   Obj: No
Dist: 25 cm
```
If gas levels exceed 400:
```
Gas: 410   Obj: Yes
Dist: 12 cm
BUZZER ON!
```

---

## **Real-Life Applications:**
✅ **Smart Home System** – Monitor air quality, objects, and proximity.  
✅ **Factory Safety** – Detect gas leaks and ensure a safe working environment.  
✅ **IoT-based Smart Monitoring** – Can be expanded to send data to an app.  

---