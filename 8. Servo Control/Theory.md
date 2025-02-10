# **8️⃣ Servo Motor Control with Arduino**
## **Objective:**  
Learn how to control a **servo motor** using an **Arduino Uno** and set its position via code or user input.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| Servo Motor (SG90 or similar) | 1 |
| Power Supply (5V from Arduino or External) | 1 |
| Jumper Wires | As needed |

---

## **Concept:**  
- A **servo motor** moves to a specific angle **(0° to 180°)** based on a control signal.
- The Arduino sends a **PWM (Pulse Width Modulation) signal** to adjust the angle.
- The servo **rotates accordingly** and maintains its position.

---

## **Circuit Connections:**  
| **Servo Pin** | **Connection** |
|-------------|--------------|
| VCC (Red) | 5V (Arduino) |
| GND (Black/Brown) | GND (Arduino) |
| Signal (Yellow/Orange) | Digital Pin 9 (Arduino) |

---

## **Arduino Code for Basic Servo Control**
```cpp
#include <Servo.h>  // Include Servo library

Servo myServo;  // Create servo object

void setup() {
  myServo.attach(9);  // Attach servo to Pin 9
}

void loop() {
  myServo.write(0);  // Move servo to 0°
  delay(1000);  // Wait 1 second

  myServo.write(90); // Move servo to 90°
  delay(1000); // Wait 1 second

  myServo.write(180); // Move servo to 180°
  delay(1000); // Wait 1 second
}
```

---

## **Explanation:**
1. **Include the Servo Library:**  
   - The `<Servo.h>` library allows easy servo control.
   
2. **Attach the Servo to a Pin:**  
   - `myServo.attach(9);` assigns the servo signal to **pin 9**.

3. **Move the Servo to Specific Angles:**  
   - `myServo.write(0);` moves the servo to **0°**.
   - `myServo.write(90);` moves the servo to **90°**.
   - `myServo.write(180);` moves the servo to **180°**.
   - The delay ensures smooth transitions between movements.

---

## **Expected Output:**
- The **servo rotates** to **0°**, **90°**, and **180°** with **1-second intervals**.
- Repeats indefinitely.

---

## **Advanced Activity: Servo Control via Serial Monitor**
- Control the servo using **Serial Monitor** by **typing an angle**.

### **Modified Code:**
```cpp
#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600); // Start Serial Monitor
  myServo.attach(9);  // Attach servo to Pin 9
  Serial.println("Enter an angle (0-180):");
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt();  // Read angle from Serial
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);  // Move to entered angle
      Serial.print("Servo moved to ");
      Serial.print(angle);
      Serial.println(" degrees");
    } else {
      Serial.println("Invalid angle! Enter a value between 0-180.");
    }
  }
}
```

### **Expected Activity:**
1. Open the **Serial Monitor** (`Ctrl + Shift + M` in Arduino IDE).
2. **Enter an angle (e.g., 45, 90, 120)**.
3. The **servo moves** to the entered angle.

---

## **Further Applications:**
✅ **Automatic Door Opening System** (IR Sensor + Servo).  
✅ **Robotic Arm Control**.  
✅ **Obstacle Avoidance System** (Ultrasonic + Servo).  

---