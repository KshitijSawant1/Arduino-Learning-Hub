Here’s a well-formatted version of your **Blinking LED (Single LED)** tutorial that you can add to your test file:

---

# **1️⃣ Blinking a Single LED**
## **Objective:**  
Learn the basics of **digital output** using the `digitalWrite()` function and `delay()` in Arduino. This activity serves as an introduction to controlling an LED through programming.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| LED | 1 |
| Resistor (220Ω - 330Ω) | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

## **Circuit Connections:**  
| **LED Pin** | **Connection** |
|------------|--------------|
| **Anode (+)** | Connect to **Arduino Digital Pin 13** |
| **Cathode (-)** | Connect to **GND via a 220Ω resistor** |

### **Circuit Diagram:**
*(Add a simple circuit diagram here if needed, showing an LED connected to Pin 13 with a resistor to GND.)*

---

## **Arduino Code for Blinking a Single LED:**
```cpp
const int ledPin = 13;  // Define the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as an OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn ON the LED
  delay(1000);  // Wait for 1 second
  digitalWrite(ledPin, LOW);   // Turn OFF the LED
  delay(1000);  // Wait for 1 second
}
```

---

## **Explanation:**
1. **`pinMode(ledPin, OUTPUT);`** → Configures Pin 13 as an output.
2. **`digitalWrite(ledPin, HIGH);`** → Turns the LED ON.
3. **`delay(1000);`** → Waits for **1 second** before turning OFF the LED.
4. **`digitalWrite(ledPin, LOW);`** → Turns the LED OFF.
5. **`delay(1000);`** → Waits for **1 second** before repeating.

---

## **Expected Output:**  
- The LED will **blink ON and OFF** every 1 second continuously.

---
