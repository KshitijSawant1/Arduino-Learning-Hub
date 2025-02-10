# **2️⃣ Blinking Multiple LEDs (Up to 5 LEDs)**
## **Objective:**  
Learn how to control **multiple LEDs** using the `digitalWrite()` function and `delay()` in Arduino. This activity extends the basic blinking LED experiment to multiple LEDs.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| LEDs | 5 |
| Resistors (220Ω - 330Ω) | 5 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

## **Circuit Connections:**  
| **LED Pin** | **Connection** |
|------------|--------------|
| **LED 1 (Anode)** | Arduino **Pin 8** |
| **LED 2 (Anode)** | Arduino **Pin 9** |
| **LED 3 (Anode)** | Arduino **Pin 10** |
| **LED 4 (Anode)** | Arduino **Pin 11** |
| **LED 5 (Anode)** | Arduino **Pin 12** |
| **Cathodes (-)** | Connect all to **GND via a 220Ω resistor** |

### **Circuit Diagram:**
*(Add a circuit diagram showing 5 LEDs connected to pins 8-12 with resistors to GND.)*

---

## **Arduino Code for Blinking Multiple LEDs:**
```cpp
const int ledPins[] = {8, 9, 10, 11, 12};  // Define LED pins
const int ledCount = 5;  // Number of LEDs

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set all LED pins as OUTPUT
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn ON each LED one by one
    delay(500);  // Wait for 500ms
  }

  delay(1000);  // Wait before turning LEDs OFF

  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);  // Turn OFF each LED one by one
    delay(500);  // Wait for 500ms
  }

  delay(1000);  // Wait before repeating
}
```

---

## **Explanation:**
1. **`pinMode(ledPins[i], OUTPUT);`** → Configures all LED pins as outputs.
2. **First `for` loop:** Turns ON LEDs **one by one** with a **500ms delay**.
3. **Middle `delay(1000);`** → Keeps all LEDs ON for 1 second.
4. **Second `for` loop:** Turns OFF LEDs **one by one** with a **500ms delay**.
5. **Final `delay(1000);`** → Keeps all LEDs OFF for 1 second before repeating.

---

## **Expected Output:**  
- The LEDs will **turn ON sequentially**, stay ON for a second, and then **turn OFF sequentially**.

---