# **7️⃣ Ultrasonic Sensor Distance Measurement with Arduino**
## **Objective:**  
Learn how to measure **distance** using an **HC-SR04 ultrasonic sensor** and display the readings on the **Serial Monitor** or **LCD**.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Resistor (Optional for signal stability) | 1 |
| LED (Optional for Indicator) | 1 |
| Buzzer (Optional for Alert) | 1 |
| LCD I2C Display (Optional) | 1 |
| Breadboard & Jumper Wires | As needed |

---

## **Concept:**
- The **HC-SR04 sensor** works on **ultrasonic waves**.
- It **emits sound pulses** that bounce off objects and return.
- The **time taken** for the signal to return is used to calculate **distance**.
- The measured distance is displayed on the **Serial Monitor** or **LCD**.

---

## **Circuit Connections:**
| **HC-SR04 Sensor Pin** | **Connection** |
|----------------------|---------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| Trig (Trigger) | Digital Pin 9 (Arduino) |
| Echo (Echo) | Digital Pin 10 (Arduino) |

| **Buzzer Pin (Optional)** | **Connection** |
|------------------------|---------------|
| Positive ( + ) | Digital Pin 8 (Arduino) |
| Negative ( - ) | GND |

| **LED Pin (Optional)** | **Connection** |
|------------|---------------|
| Anode (+) | Digital Pin 13 (Arduino) |
| Cathode (-) | GND via 220Ω Resistor |

---

## **Arduino Code for Ultrasonic Sensor**
```cpp
const int trigPin = 9;  // Trigger pin for ultrasonic sensor
const int echoPin = 10; // Echo pin for ultrasonic sensor
const int buzzerPin = 8; // Optional Buzzer for Alerts
const int ledPin = 13;  // Optional LED Indicator

void setup() {
  Serial.begin(9600); // Start Serial Monitor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Ultrasonic Sensor Initialized...");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Read echo signal duration
  int distance = duration * 0.034 / 2;  // Convert to distance (cm)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {  // If object is closer than 10cm
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
    digitalWrite(ledPin, HIGH);    // Turn LED ON
    Serial.println("⚠️ ALERT: Object too close! ⚠️");
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate buzzer
    digitalWrite(ledPin, LOW);    // Turn LED OFF
  }

  delay(500); // Wait before next reading
}
```

---

## **Explanation:**
1. **Ultrasonic Distance Measurement:**  
   - Sends a pulse (`digitalWrite(trigPin, HIGH);`).
   - Measures **time taken** for the echo (`pulseIn(echoPin, HIGH);`).
   - Converts time into **distance** using the formula:  
     ```
     Distance (cm) = Time (microseconds) * 0.034 / 2
     ```

2. **Threshold-Based Alert System:**  
   - If distance is **less than 10 cm**, it triggers:
     - **Buzzer ON**
     - **LED ON**
     - **Serial Monitor Alert**
   - Otherwise, **buzzer and LED stay OFF**.

3. **Serial Monitor Feedback:**  
   - Displays **real-time distance**.
   - Alerts if an object is **too close**.

---

## **Expected Output:**
1. Open the **Serial Monitor** (**Ctrl + Shift + M** in Arduino IDE).
2. Observe **real-time distance readings** in **cm**.
3. **Move an object closer** to test the **alert system**.
   - If distance < 10 cm:
     ```
     Distance: 5 cm
     ⚠️ ALERT: Object too close! ⚠️
     ```
   - If distance > 10 cm:
     ```
     Distance: 15 cm
     ```

---

## **Activity Variations:**
🔹 **Use an LCD** to display distance instead of Serial Monitor.  
🔹 **Control a Servo Motor** to rotate if an object is detected.  
🔹 **Implement an Automatic Parking Sensor**.  

---
