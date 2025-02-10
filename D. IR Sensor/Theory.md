# **4️⃣ IR Sensor for Object Detection**
## **Objective:**  
Learn how to use an **Infrared (IR) Sensor** to detect objects and trigger an LED or buzzer when an object is detected.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| IR Sensor (Infrared Sensor) | 1 |
| LED | 1 |
| Buzzer (Optional) | 1 |
| Resistor (220Ω - for LED) | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**
- An **IR sensor** detects objects by emitting infrared light and receiving reflections.
- The **output pin** of the IR sensor sends a **LOW (0V) signal** when an object is detected and **HIGH (5V) signal** when no object is present.
- The **Arduino reads** the IR sensor and triggers an **LED or buzzer** accordingly.

---

## **Circuit Connections:**
| **IR Sensor Pin** | **Connection** |
|------------------|---------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| OUT | Digital Pin 7 (Arduino) |

| **LED Pin** | **Connection** |
|------------|---------------|
| Anode (+) | Digital Pin 13 (Arduino) |
| Cathode (-) | GND via 220Ω Resistor |

| **Buzzer Pin (Optional)** | **Connection** |
|------------------------|---------------|
| Positive ( + ) | Digital Pin 8 (Arduino) |
| Negative ( - ) | GND |

---

## **Arduino Code for IR Sensor Object Detection**
```cpp
const int irSensor = 7; // IR sensor output pin
const int ledPin = 13;  // LED pin
const int buzzerPin = 8; // Buzzer pin (optional)

void setup() {
  pinMode(irSensor, INPUT);  // IR sensor as input
  pinMode(ledPin, OUTPUT);   // LED as output
  pinMode(buzzerPin, OUTPUT); // Buzzer as output
  Serial.begin(9600);        // Start Serial Monitor
}

void loop() {
  int sensorState = digitalRead(irSensor); // Read IR sensor state
  
  if (sensorState == LOW) { // Object detected (IR sensor gives LOW)
    digitalWrite(ledPin, HIGH); // Turn LED ON
    digitalWrite(buzzerPin, HIGH); // Turn buzzer ON
    Serial.println("Object Detected!");
  } else { // No object detected (IR sensor gives HIGH)
    digitalWrite(ledPin, LOW); // Turn LED OFF
    digitalWrite(buzzerPin, LOW); // Turn buzzer OFF
    Serial.println("No Object");
  }

  delay(200); // Small delay to avoid rapid fluctuations
}
```

---

## **Explanation:**
1. **IR Sensor Pin Setup:**  
   - `pinMode(irSensor, INPUT);` → Configures the IR sensor as an **input**.
   - `digitalRead(irSensor);` → Reads the sensor’s output.

2. **LED & Buzzer Activation:**  
   - When an object is detected (`LOW` output from IR sensor), the **LED & Buzzer** turn **ON**.
   - When no object is present (`HIGH` output from IR sensor), the **LED & Buzzer** turn **OFF**.

3. **Serial Monitor Feedback:**  
   - Displays `"Object Detected!"` when an object is close.
   - Displays `"No Object"` when there is no object.

---

## **Expected Output:**
1. Open the **Serial Monitor** (**Ctrl + Shift + M** in Arduino IDE).
2. Move an object **in front of the IR sensor**.
   - LED **turns ON**, buzzer **beeps**, and Serial Monitor prints:
     ```
     Object Detected!
     ```
3. Remove the object.
   - LED **turns OFF**, buzzer **stops**, and Serial Monitor prints:
     ```
     No Object
     ```

---

## **Activity Variations:**
🔹 Replace the LED with a **servo motor** to create an **automatic gate system**.  
🔹 Modify the code to **trigger a message on an LCD display**.  
🔹 Use multiple IR sensors for **advanced object tracking**.

---