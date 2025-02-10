# **5️⃣ Touch Sensor with Arduino**
## **Objective:**  
Learn how to use a **Touch Sensor** with Arduino to control an **LED or Buzzer** when touched.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| Touch Sensor | 1 |
| LED | 1 |
| Resistor (220Ω - for LED) | 1 |
| Buzzer (Optional) | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**
- A **Touch Sensor** detects physical contact and provides a **HIGH (5V) signal** when touched and a **LOW (0V) signal** when not touched.
- The **Arduino reads** the sensor’s output and controls an **LED or buzzer** accordingly.

---

## **Circuit Connections:**
| **Touch Sensor Pin** | **Connection** |
|----------------------|---------------|
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

## **Arduino Code for Touch Sensor**
```cpp
const int touchPin = 7; // Touch sensor output pin
const int ledPin = 13;  // LED pin
const int buzzerPin = 8; // Buzzer pin (optional)

void setup() {
  pinMode(touchPin, INPUT);  // Touch sensor as input
  pinMode(ledPin, OUTPUT);   // LED as output
  pinMode(buzzerPin, OUTPUT); // Buzzer as output
  Serial.begin(9600);        // Start Serial Monitor
}

void loop() {
  int sensorState = digitalRead(touchPin); // Read touch sensor state
  
  if (sensorState == HIGH) { // If touch detected
    digitalWrite(ledPin, HIGH); // Turn LED ON
    digitalWrite(buzzerPin, HIGH); // Turn buzzer ON
    Serial.println("Touch Detected!");
  } else { // If no touch
    digitalWrite(ledPin, LOW); // Turn LED OFF
    digitalWrite(buzzerPin, LOW); // Turn buzzer OFF
    Serial.println("No Touch");
  }

  delay(200); // Small delay to avoid rapid fluctuations
}
```

---

## **Explanation:**
1. **Touch Sensor Pin Setup:**  
   - `pinMode(touchPin, INPUT);` → Configures the touch sensor as an **input**.
   - `digitalRead(touchPin);` → Reads the sensor’s output.

2. **LED & Buzzer Activation:**  
   - When touched (`HIGH` output from sensor), the **LED & Buzzer** turn **ON**.
   - When not touched (`LOW` output from sensor), the **LED & Buzzer** turn **OFF**.

3. **Serial Monitor Feedback:**  
   - Displays `"Touch Detected!"` when the sensor is touched.
   - Displays `"No Touch"` when the sensor is not touched.

---

## **Expected Output:**
1. Open the **Serial Monitor** (**Ctrl + Shift + M** in Arduino IDE).
2. **Touch the sensor**.
   - LED **turns ON**, buzzer **beeps**, and Serial Monitor prints:
     ```
     Touch Detected!
     ```
3. **Release the touch**.
   - LED **turns OFF**, buzzer **stops**, and Serial Monitor prints:
     ```
     No Touch
     ```

---

## **Activity Variations:**
🔹 Use the **Touch Sensor** to trigger a **servo motor** for an **automated door system**.  
🔹 Modify the code to **display a message on an LCD screen** when touched.  
🔹 Implement **multiple touch sensors** for advanced input handling.

---

💡 **Next Activity:** Want to explore **distance measurement**? Let’s move on to **Ultrasonic Sensor Distance Measurement!** 🚀