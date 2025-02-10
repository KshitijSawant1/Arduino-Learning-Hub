# **6️⃣ MQ-2 Gas Sensor with Arduino**
## **Objective:**  
Learn how to use the **MQ-2 Gas Sensor** with Arduino to detect **smoke, LPG, CO, and other gases**, and display the values on the **Serial Monitor** or **LCD**.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| MQ-2 Gas Sensor | 1 |
| Resistor (10kΩ - optional) | 1 |
| LED (Optional for Indicator) | 1 |
| Buzzer (Optional for Alarm) | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**
- The **MQ-2 Sensor** detects gas levels and provides an **analog output** based on gas concentration.
- The **Arduino reads** the sensor output and displays the values on the **Serial Monitor**.
- If gas levels exceed a **safe threshold**, an **alarm (buzzer)** or **indicator LED** is activated.

---

## **Circuit Connections:**
| **MQ-2 Sensor Pin** | **Connection** |
|----------------------|---------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| A0 (Analog Output) | A0 (Arduino) |
| D0 (Digital Output - Optional) | D2 (Arduino - Optional) |

| **Buzzer Pin (Optional)** | **Connection** |
|------------------------|---------------|
| Positive ( + ) | Digital Pin 8 (Arduino) |
| Negative ( - ) | GND |

| **LED Pin (Optional)** | **Connection** |
|------------|---------------|
| Anode (+) | Digital Pin 13 (Arduino) |
| Cathode (-) | GND via 220Ω Resistor |

---

## **Arduino Code for MQ-2 Gas Sensor**
```cpp
const int gasSensorPin = A0; // Analog pin for MQ-2 sensor
const int buzzerPin = 8;  // Buzzer pin
const int ledPin = 13;    // LED pin for indication
const int threshold = 300; // Gas level threshold

void setup() {
  Serial.begin(9600);   // Start Serial Monitor
  pinMode(buzzerPin, OUTPUT); // Set buzzer as output
  pinMode(ledPin, OUTPUT);    // Set LED as output
  Serial.println("MQ-2 Gas Sensor Initialized...");
}

void loop() {
  int gasLevel = analogRead(gasSensorPin); // Read gas sensor value

  Serial.print("Gas Level: ");
  Serial.println(gasLevel); // Display gas level on Serial Monitor

  if (gasLevel > threshold) { // If gas level exceeds safe limit
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
    digitalWrite(ledPin, HIGH); // Turn LED ON
    Serial.println("⚠️ ALERT: High Gas Detected! ⚠️");
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate buzzer
    digitalWrite(ledPin, LOW); // Turn LED OFF
  }

  delay(500); // Wait before next reading
}
```

---

## **Explanation:**
1. **Gas Sensor Pin Setup:**  
   - `pinMode(gasSensorPin, INPUT);` → Reads gas concentration as **analog input**.
   - `analogRead(gasSensorPin);` → Fetches gas concentration value.

2. **Threshold-Based Alarm System:**  
   - If gas concentration **exceeds** the threshold (**300** in this case):
     - The **buzzer turns ON**.
     - The **LED turns ON**.
     - The **Serial Monitor** displays an alert message.
   - If gas levels are normal:
     - The **buzzer remains OFF**.
     - The **LED remains OFF**.

3. **Serial Monitor Feedback:**  
   - Displays real-time **gas levels**.
   - Alerts if gas levels **exceed the safe limit**.

---

## **Expected Output:**
1. Open the **Serial Monitor** (**Ctrl + Shift + M** in Arduino IDE).
2. Observe **real-time gas level readings**.
3. **Simulate Gas Presence** (Use a lighter gas leak or smoke).
   - If gas levels exceed the threshold, the **buzzer sounds**, and the **LED turns ON**.
   - Serial Monitor displays:
     ```
     Gas Level: 320
     ⚠️ ALERT: High Gas Detected! ⚠️
     ```
4. If gas dissipates, the buzzer and LED **turn OFF**.

---

## **Activity Variations:**
🔹 **Display gas levels on an LCD screen** instead of Serial Monitor.  
🔹 **Store readings in an SD card** for data logging.  
🔹 **Control a ventilation fan** if gas levels exceed a critical threshold.  

---