# **4️⃣ Serial Monitor "Hello Arduino"**

## **Objective:**

Learn how to use the **Serial Monitor** to send and receive messages with the Arduino. This activity introduces basic **serial communication**.

---

## **Components Needed:**

| **Component**               | **Quantity** |
| --------------------------- | ------------ |
| Arduino Uno                 | 1            |
| USB Cable                   | 1            |
| Computer (with Arduino IDE) | 1            |

📌 _No additional hardware is required!_

---

## **Concept:**

- The **Serial Monitor** in the Arduino IDE allows communication between the Arduino and a computer.
- The `Serial.print()` function is used to **send messages** from the Arduino to the computer.
- The `Serial.readString()` function **receives input** from the user.

---

## **Arduino Code for Serial Hello:**

```cpp
void setup() {
  Serial.begin(9600);  // Start Serial communication at 9600 baud rate
  Serial.println("Hello! Type something in the Serial Monitor:");
}

void loop() {
  if (Serial.available()) {  // Check if data is received
    String input = Serial.readString();  // Read input
    Serial.print("You typed: ");
    Serial.println(input);  // Echo the input back
  }
}
```

---

## **Explanation:**

1. **`Serial.begin(9600);`** → Initializes the Serial Monitor at **9600 baud rate**.
2. **`Serial.println("Hello! Type something in the Serial Monitor:");`** → Prints an initial message.
3. **`if (Serial.available()) {}`** → Checks if **any input** has been received.
4. **`String input = Serial.readString();`** → Reads the user's input.
5. **`Serial.print("You typed: ");`** → Displays a response message.
6. **`Serial.println(input);`** → **Echoes** the received input back to the Serial Monitor.

---

## **Expected Output:**

1. Open the **Serial Monitor** in the Arduino IDE (**Ctrl + Shift + M**).
2. Type any text (e.g., `"Arduino is fun!"`) and press **Enter**.
3. The Arduino **echoes** back your message:
   ```
   You typed: Arduino is fun!
   ```

---

## **Activity Variations:**

🔹 **Modify the code** to send a custom greeting.  
🔹 **Use Serial input** to control an LED or a buzzer.  
🔹 **Try different baud rates (4800, 115200, etc.)** and observe any changes.

---
