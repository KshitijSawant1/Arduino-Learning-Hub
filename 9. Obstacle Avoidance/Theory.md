# **🔰 Obstacle Avoidance System using Arduino**
## **Objective:**  
Build an **Obstacle Avoidance System** using an **Ultrasonic Sensor and a Servo Motor** to detect and avoid obstacles dynamically.

---

## **Components Needed:**  
| **Component** | **Quantity** |
|-------------|-------------|
| Arduino Uno | 1 |
| Ultrasonic Sensor (HC-SR04) | 1 |
| Servo Motor (SG90 or similar) | 1 |
| Buzzer | 1 |
| LED (Optional) | 1 |
| Resistor (220Ω for LED) | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 |

---

## **Concept:**  
- The **Ultrasonic Sensor** detects obstacles by measuring the distance.
- The **Servo Motor** moves to scan the area for obstacles.
- If an **obstacle is detected within a threshold (e.g., 15 cm)**:
  - The **buzzer beeps**.
  - The **LED turns ON**.
  - The system can react by taking action (like stopping a robot or turning away).

---

## **Circuit Connections:**
| **Ultrasonic Sensor (HC-SR04) Pin** | **Connection** |
|----------------|--------------|
| VCC | 5V (Arduino) |
| GND | GND (Arduino) |
| Trig | Digital Pin 7 |
| Echo | Digital Pin 6 |

| **Servo Motor Pin** | **Connection** |
|-------------|--------------|
| VCC (Red) | 5V (Arduino) |
| GND (Black/Brown) | GND (Arduino) |
| Signal (Yellow/Orange) | Digital Pin 9 |

| **Buzzer Pin** | **Connection** |
|-------------|--------------|
| Positive ( + ) | Digital Pin 10 |
| Negative ( - ) | GND (Arduino) |

| **LED Pin** | **Connection** |
|-------------|--------------|
| Positive (Anode) | Digital Pin 11 (through 220Ω resistor) |
| Negative (Cathode) | GND |

---

## **Arduino Code for Obstacle Avoidance System**
```cpp
#include <Servo.h>

// Define Ultrasonic Sensor Pins
const int trigPin = 7;
const int echoPin = 6;

// Define Servo and Buzzer Pins
Servo scanServo;
const int servoPin = 9;
const int buzzer = 10;
const int led = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  
  scanServo.attach(servoPin);
  scanServo.write(90);  // Start at middle position

  Serial.println("Obstacle Avoidance System Active!");
}

void loop() {
  int distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 15) {  // Obstacle detected
    digitalWrite(buzzer, HIGH); // Buzzer ON
    digitalWrite(led, HIGH); // LED ON
    Serial.println("🚨 Obstacle Detected! 🚨");
    
    // Scan left and right
    scanServo.write(30); 
    delay(500);
    scanServo.write(150); 
    delay(500);
    scanServo.write(90);  // Return to center
  } else {
    digitalWrite(buzzer, LOW); // Buzzer OFF
    digitalWrite(led, LOW); // LED OFF
  }

  delay(500);  // Delay before next measurement
}

// Function to measure distance using Ultrasonic Sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}
```

---

## **Explanation:**
1. **Ultrasonic Sensor Measures Distance**:  
   - The `getDistance()` function sends an ultrasonic pulse and measures the return time.
   - The **distance is calculated** and returned in cm.

2. **Servo Scans for Obstacles**:  
   - The **servo moves left (30°), right (150°), and returns to center (90°)** to check surroundings.

3. **Buzzer and LED Alert**:  
   - If an **obstacle is detected within 15 cm**, the **buzzer beeps and the LED turns ON**.
   - Otherwise, they remain OFF.

4. **Serial Monitor Output**:  
   - The **distance** is displayed on the **Serial Monitor** for debugging.

---

## **Expected Output:**
1. **Normal Operation:**  
   - The **servo continuously scans** the area.
   - The **ultrasonic sensor detects distances**.
   - If **no obstacle**, the system remains inactive.

2. **Obstacle Detected (<15 cm):**  
   - The **buzzer beeps**.
   - The **LED lights up**.
   - The **servo scans** to detect alternative paths.

---

## **Advanced Ideas & Applications:**
✅ **Autonomous Robots** – Avoids obstacles and moves in a different direction.  
✅ **Smart Parking Assistant** – Helps cars park using distance measurement.  
✅ **Security Systems** – Detects intruders and triggers alarms.  
✅ **Blind Stick** – Alerts visually impaired individuals about obstacles.  

---