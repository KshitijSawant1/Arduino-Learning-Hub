# **🚨 Motion Alarm System using IR Sensor & Buzzer 🚨**  

## **Objective:**  
Create a **motion detection alarm system** using an **IR sensor and a buzzer**. When motion is detected, the **buzzer will sound an alarm** to notify the user.

---

## **Components Required:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| IR Sensor | 1 |
| Buzzer | 1 |
| LED (Optional) | 1 |
| Resistor (220Ω) | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**  
- The **IR sensor** detects motion when an object comes in front of it.  
- The **Arduino processes the signal** and activates the buzzer.  
- An **LED can be added** as a visual indicator of motion.  
- The system can be used for **security and automation applications**.

---

## **Circuit Connections:**  
| **Component** | **Arduino Pin** |
|-------------|----------------|
| **IR Sensor (VCC)** | 5V |
| **IR Sensor (GND)** | GND |
| **IR Sensor (OUT)** | Digital Pin 3 |
| **Buzzer (+)** | Digital Pin 6 |
| **Buzzer (-)** | GND |
| **LED (Optional, +)** | Digital Pin 5 |
| **LED (Optional, -)** | GND (via 220Ω Resistor) |

---

## **Arduino Code for Motion Alarm System**
```cpp
#define IR_SENSOR 3
#define BUZZER 6
#define LED 5  // Optional LED

void setup() {
    pinMode(IR_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(LED, OUTPUT);
    
    Serial.begin(9600);
    Serial.println("Motion Alarm System Active...");
}

void loop() {
    int motionDetected = digitalRead(IR_SENSOR);

    if (motionDetected == HIGH) {  // Motion detected
        digitalWrite(BUZZER, HIGH);
        digitalWrite(LED, HIGH);
        Serial.println("🚨 Motion Detected! Alarm ON!");
        delay(500);  // Buzzer ON time
    } else {
        digitalWrite(BUZZER, LOW);
        digitalWrite(LED, LOW);
        Serial.println("No Motion...");
    }

    delay(200);
}
```

---

## **Working of Motion Alarm System:**
1. The **IR sensor** continuously monitors for movement.  
2. When an object is detected, the **IR sensor outputs HIGH (1)**.  
3. The **Arduino triggers the buzzer** and turns on the **LED** (if included).  
4. The **Serial Monitor** displays "Motion Detected!" when movement is detected.  
5. If no movement is detected, the **buzzer and LED turn off**.  

---

## **Expected Serial Monitor Output:**
```
Motion Alarm System Active...
No Motion...
🚨 Motion Detected! Alarm ON!
No Motion...
No Motion...
🚨 Motion Detected! Alarm ON!
```

---

## **Real-Life Applications:**
✅ **Security System** – Used in homes or offices for intruder detection.  
✅ **Automated Lighting** – Lights up when motion is detected in a dark area.  
✅ **Visitor Alert** – Alerts when someone enters a room or space.  
✅ **Proximity-Based Devices** – Used in touchless gadgets or hands-free automation.

---