# *Arduino Latching Power Circuit with Auto Power Off & Digital/Analog Sensors* 🔋⚡

## *Overview* 🌍

This project demonstrates two main tasks:

1. *Latching Power Switch with Auto Power Off*🔲💡:
   - A *push button* and an *NPN transistor* are used to control the power state of a device (e.g., LED). The circuit includes an automatic turn-off feature after a set time.

2. *Digital and Analog Sensor Reading*📏🌡:
   - The project uses an *HC-SR04 ultrasonic sensor* for distance measurement and a *TMP36 temperature sensor* to read temperature values. The data is displayed on the *Serial Monitor* in real-time.

---

## *Features* 🌟

### 1. *Latching Power Switch*🔌:
   - Turn on and off devices using a *push button*.
   - The device will automatically power off after a set delay.

### 2. *Digital and Analog Sensors*📏:
   - *HC-SR04* to measure distance.
   - *TMP36* to measure temperature.
   - *Arduino Serial Monitor* for displaying the sensor data.

---

## *Hardware Required* 🔧🛠

### For Latching Power Circuit:
- *Arduino UNO* (or compatible)
- *NPN Transistor* (e.g., 2N2222)
- *Push Button*
- *LED* (any color)
- *Resistors* (1kΩ for transistor base, 220Ω for LED)
- *Breadboard and Jumper Wires*

### For Digital and Analog Sensors:
- *Arduino UNO* (or compatible)
- *HC-SR04 Ultrasonic Sensor*
- *TMP36 Temperature Sensor*
- *Breadboard and Jumper Wires*

---

## *Wiring* 📐🔌

### Latching Power Switch Circuit:
| Component         | Arduino UNO Pin  |
|-------------------|------------------|
| Push Button       | Pin 2            |
| NPN Transistor    | Pin 8 (Base)     |
| LED               | Pin 7            |
| Transistor Emitter| GND              |
| Transistor Collector| LED's negative terminal |

### Digital and Analog Sensors:
| Component         | Arduino UNO Pin  |
|-------------------|------------------|
| HC-SR04 Trig      | Pin 9            |
| HC-SR04 Echo      | Pin 10           |
| TMP36 Vout        | Pin A0           |
| TMP36 GND         | GND              |

---
## 📸 Project Results
### *Latching Power Circuit*:![صورة واتساب بتاريخ 1447-01-22 في 03 13 55_ba37ab9f](https://github.com/user-attachments/assets/ac683988-b8f5-462c-8f6a-85fc703a59f7)

### *Digital and Analog Sensors*:![صورة واتساب بتاريخ 1447-01-22 في 03 13 10_f46ff6d8](https://github.com/user-attachments/assets/6eda66cc-167b-4e6d-8b4f-ed45da4b0796)
![صورة واتساب بتاريخ 1447-01-22 في 03 14 33_f2903836](https://github.com/user-attachments/assets/a78fcc92-fe64-4a19-b390-7d073df4b342)

---
## 🧠 *How It Works*

### *Latching Power Circuit*:
1. When the *button* is pressed, the transistor switches and the device (e.g., LED) is turned on.
2. The *device* will remain on until the button is pressed again.
3. The device will automatically turn off after *10 seconds*.

### *Digital and Analog Sensors*:
1. The *HC-SR04 ultrasonic sensor* measures the distance.
2. The *TMP36 temperature sensor* reads the temperature in *Celsius*.
3. Data from both sensors is displayed on the *Serial Monitor*.

---

## *Code Explanation* 📝💻

### *Latching Power Circuit Code*:
The code is designed to toggle the power state of a device with a *button press, and turn off the device after a timeout of **10 seconds*.

```cpp
#define BUTTON_PIN 2
#define TRANSISTOR_PIN 8
#define AUTO_OFF_DELAY 10000

unsigned long lastPressTime = 0;
unsigned long currentMillis;
bool deviceState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(TRANSISTOR_PIN, OUTPUT);
  digitalWrite(TRANSISTOR_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    delay(50);
    lastPressTime = currentMillis;
    deviceState = !deviceState;
    digitalWrite(TRANSISTOR_PIN, deviceState ? HIGH : LOW);
  }
```
### *Code for the Ultrasonic and TMP36 Sensors*:

```cpp
#define TRIG_PIN 9
#define ECHO_PIN 10
#define TEMP_PIN A0

void setup() {
  pinMode(TRIG_PIN, OUTPUT);    // Set TRIG_PIN as an OUTPUT
  pinMode(ECHO_PIN, INPUT);     // Set ECHO_PIN as an INPUT
  pinMode(TEMP_PIN, INPUT);     // Set TEMP_PIN for TMP36 sensor
  Serial.begin(9600);           // Start the Serial Monitor at 9600 baud rate
}

void loop() {
  // Ultrasonic Sensor: Sending a pulse
  digitalWrite(TRIG_PIN, LOW); // Ensure trigger pin is low initially
  delayMicroseconds(2);        // Wait for a moment
  digitalWrite(TRIG_PIN, HIGH); // Send a 10 microsecond pulse to trigger the sensor
  delayMicroseconds(10);       // Pulse duration
  digitalWrite(TRIG_PIN, LOW); // End pulse
  
  // Read the response from the Echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);  // Get the pulse duration
  long distance = (duration / 2) * 0.0343; // Calculate distance in cm
  
  // TMP36: Read the temperature
  int tempValue = analogRead(TEMP_PIN); // Read analog value from TMP36
  float voltage = (tempValue / 1024.0) * 5.0; // Convert the value to voltage
  float temperatureC = (voltage - 0.5) * 100; // Convert voltage to temperature in Celsius

  // Print data to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(500); // Wait for half a second before the next reading
}

```
## 🧑‍💻 Author
- **khaled mahmoud sulaimani** – [@khaledsulimani](https://github.com/khaledsulimani)

---
