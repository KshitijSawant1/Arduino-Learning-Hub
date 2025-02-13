# **🚪 Automatic Door Opener using Arduino**
## **Objective:**  
Create an **Automatic Door Opening System** using an **IR sensor and Servo Motor** to detect motion and open a door.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| IR Sensor | 1 |
| Servo Motor (SG90) | 1 |
| LED (Optional) | 1 |
| Resistor (220Ω for LED) | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 |

---

## **Concept:**  
- The **IR Sensor** detects motion when an object or person is nearby.
- If an object is detected, the **servo motor rotates** to **open the door**.
- After a few seconds, the **servo returns** to the closed position.

---

## **Circuit Connections:**
| **IR Sensor Pin** | **Connection** |
|----------------|--------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| OUT | Digital Pin 2 |

| **Servo Motor Pin** | **Connection** |
|-------------|--------------|
| VCC (Red) | 5V (Arduino) |
| GND (Black/Brown) | GND (Arduino) |
| Signal (Yellow/Orange) | Digital Pin 9 |

| **LED Pin (Optional)** | **Connection** |
|-------------|--------------|
| Positive (Anode) | Digital Pin 4 (through 220Ω resistor) |
| Negative (Cathode) | GND |

---

## **Arduino Code for Automatic Door Opener**
```cpp
#include <Servo.h>

// Define IR Sensor and Servo
const int irSensor = 2; 
const int ledPin = 4;
Servo doorServo;

void setup() {
  Serial.begin(9600);
  pinMode(irSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  doorServo.attach(9); // Servo connected to pin 9

  doorServo.write(0); // Start with the door closed
  Serial.println("Automatic Door System Ready!");
}

void loop() {
  int motion = digitalRead(irSensor);

  if (motion == HIGH) {  // If motion is detected
    Serial.println("🚪 Motion Detected! Opening Door...");
    digitalWrite(ledPin, HIGH);
    doorServo.write(90);  // Rotate servo to open the door
    delay(3000);  // Keep door open for 3 seconds
  } else {
    Serial.println("🔒 No Motion. Closing Door...");
    digitalWrite(ledPin, LOW);
    doorServo.write(0); // Close the door
  }

  delay(500); // Small delay to avoid multiple triggers
}
```

---

## **Explanation:**
1. **IR Sensor Detects Motion**:  
   - The **IR sensor sends a HIGH signal** when it detects motion.
   - If motion is detected, the **servo rotates 90° to open the door**.

2. **LED Indicator (Optional)**:  
   - **LED turns ON** when the door is open.
   - **LED turns OFF** when the door is closed.

3. **Servo Operates the Door**:  
   - After **3 seconds**, the **servo moves back to 0°**, closing the door.

4. **Serial Monitor Output**:  
   - Displays **"Motion Detected! Opening Door..."** when movement is detected.
   - Displays **"No Motion. Closing Door..."** when no motion is present.

---

## **Expected Output:**
1. **Person Approaches**:  
   - The **IR sensor detects motion**.  
   - The **door (servo) opens** for **3 seconds**.  
   - The **LED turns ON** (if used).  

2. **Person Leaves**:  
   - The **IR sensor no longer detects movement**.  
   - The **door (servo) closes**.  
   - The **LED turns OFF**.

---

## **Advanced Ideas & Applications:**
✅ **Smart Home Doors** – Automatic opening for convenience.  
✅ **Automatic Shop Doors** – Hands-free operation in commercial spaces.  
✅ **Pet Doors** – Opens for pets based on sensor input.  
✅ **Hygienic Public Doors** – Reduces touch-based contamination.  

---
