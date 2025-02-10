# **🔥 Gas Leak Alarm using MQ-2 Sensor and Arduino**
## **Objective:**  
Create a **Gas Leak Detection System** using an **MQ-2 gas sensor** and a **buzzer** to alert when gas levels exceed a threshold.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| MQ-2 Gas Sensor | 1 |
| Buzzer | 1 |
| LED (Optional) | 1 |
| Resistor (220Ω for LED) | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 |

---

## **Concept:**  
- The **MQ-2 Sensor** detects gases like **LPG, butane, propane, methane, and smoke**.
- If the gas level exceeds a **set threshold**, the **buzzer sounds an alarm**, and an **LED turns ON**.
- The **Serial Monitor** displays the gas concentration in real-time.

---

## **Circuit Connections:**
| **MQ-2 Sensor Pin** | **Connection** |
|----------------|--------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| A0 (Analog Output) | A0 (Arduino) |

| **Buzzer Pin** | **Connection** |
|-------------|--------------|
| Positive (+) | Digital Pin 7 |
| Negative (-) | GND |

| **LED Pin (Optional)** | **Connection** |
|-------------|--------------|
| Positive (Anode) | Digital Pin 4 (through 220Ω resistor) |
| Negative (Cathode) | GND |

---

## **Arduino Code for Gas Leak Alarm**
```cpp
const int gasSensor = A0; // MQ-2 sensor connected to Analog Pin A0
const int buzzer = 7;      // Buzzer connected to Digital Pin 7
const int ledPin = 4;      // LED connected to Digital Pin 4
const int threshold = 300; // Gas level threshold

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Gas Leak Detector Ready...");
}

void loop() {
  int gasLevel = analogRead(gasSensor); // Read gas sensor value
  Serial.print("Gas Level: ");
  Serial.println(gasLevel); // Print value to Serial Monitor

  if (gasLevel > threshold) {
    Serial.println("🚨 ALERT! High Gas Level Detected! 🚨");
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  delay(1000); // Wait 1 second before next reading
}
```

---

## **Explanation:**
1. **Gas Detection Using MQ-2 Sensor**:  
   - The **sensor reads gas concentration** as an **analog value**.
   - The value is **compared to a threshold** (300 in this example).

2. **Buzzer & LED Alerts**:  
   - If **gas levels exceed the threshold**,  
     ✅ **Buzzer turns ON** 🚨  
     ✅ **LED turns ON** 🔴  
     ✅ **Serial Monitor prints an alert**  
   - If **gas levels are safe**,  
     ✅ **Buzzer stays OFF**  
     ✅ **LED stays OFF**  

3. **Real-time Monitoring via Serial Monitor**:  
   - Gas levels are **displayed every second** for monitoring.

---

## **Expected Output:**
1. **Safe Environment**:  
   - The **Serial Monitor shows normal gas levels**.  
   - The **buzzer remains OFF**.  
   - The **LED remains OFF**.  

2. **Gas Leak Detected**:  
   - The **Serial Monitor displays a high gas level alert**.  
   - The **buzzer sounds an alarm**.  
   - The **LED turns ON** for visual warning.

---

## **Advanced Ideas & Applications:**
✅ **Home Gas Leak Alarm** – Detects LPG leaks in kitchens.  
✅ **Industrial Safety System** – Monitors gas leaks in factories.  
✅ **Fire & Smoke Detection** – Alerts during fire hazards.  
✅ **Smart IoT Integration** – Send alerts via WiFi (ESP8266).  

---