# **2️⃣ Buzzer Control with Arduino**

## **Objective:**

Learn how to control a **buzzer** using an Arduino. This activity demonstrates how to turn a buzzer **ON and OFF** using simple digital signals.

---

## **Components Needed:**

| **Component**                                           | **Quantity** |
| ------------------------------------------------------- | ------------ |
| Arduino Uno                                             | 1            |
| Buzzer (Piezo)                                          | 1            |
| Resistor (220Ω - 1kΩ) _(optional for current limiting)_ | 1            |
| Breadboard                                              | 1            |
| Jumper Wires                                            | As required  |

---

## **Circuit Connections:**

| **Buzzer Pin**          | **Connection**    |
| ----------------------- | ----------------- |
| **Buzzer (+) Terminal** | **Arduino Pin 7** |
| **Buzzer (-) Terminal** | **GND**           |

### **Circuit Diagram:**

_(Include a diagram showing the buzzer connected to Pin 7 and GND.)_

---

## **Arduino Code for Simple Buzzer Control:**

```cpp
const int buzzerPin = 7;  // Define buzzer pin

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as OUTPUT
}

void loop() {
  digitalWrite(buzzerPin, HIGH);  // Turn ON buzzer
  delay(1000);  // Wait for 1 second

  digitalWrite(buzzerPin, LOW);   // Turn OFF buzzer
  delay(1000);  // Wait for 1 second
}
```

---

## **Explanation:**

1. **`pinMode(buzzerPin, OUTPUT);`** → Configures the **buzzer pin** as an output.
2. **`digitalWrite(buzzerPin, HIGH);`** → Turns ON the buzzer.
3. **`delay(1000);`** → Keeps the buzzer ON for **1 second**.
4. **`digitalWrite(buzzerPin, LOW);`** → Turns OFF the buzzer.
5. **`delay(1000);`** → Keeps the buzzer OFF for **1 second** before repeating.

---

## **Expected Output:**

- The **buzzer will beep ON and OFF every 1 second**.

---

## **Variation: Controlling Buzzer with Serial Monitor**

You can **control the buzzer manually** using the **Serial Monitor** by sending "ON" or "OFF" commands.

### **Code for Serial Monitor Buzzer Control:**

```cpp
const int buzzerPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("Type 'ON' to activate buzzer or 'OFF' to stop it:");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readString();
    command.trim();

    if (command.equalsIgnoreCase("ON")) {
      digitalWrite(buzzerPin, HIGH);
      Serial.println("Buzzer is ON");
    } else if (command.equalsIgnoreCase("OFF")) {
      digitalWrite(buzzerPin, LOW);
      Serial.println("Buzzer is OFF");
    } else {
      Serial.println("Invalid Command! Type 'ON' or 'OFF'.");
    }
  }
}
```

---

## **Expected Output for Serial Monitor Version:**

- When the user types `"ON"`, the **buzzer turns ON**.
- When the user types `"OFF"`, the **buzzer turns OFF**.
- If an **invalid command** is entered, a message prompts the user to type `"ON"` or `"OFF"`.

---
