## 📄 `wind_microloop_controller.ino`

> Regulates micro-scale wind or kinetic inputs into the power bus.
> Prevents backfeed, protects batteries, and enables efficient trickle charging.

### 🧰 Requirements

* INA219 or ACS712 current/voltage sensor
* MOSFET or relay on charge path
* Optional dump load resistor path for braking

---

```cpp
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

// CONFIG
const float minVoltage = 13.0;      // V - only charge above this
const float maxVoltage = 16.5;      // V - disable or brake above this
const float maxSafeCurrent = 2.0;   // A - microloops only!

const int CHARGE_RELAY_PIN = 4;     // Enable charge path
const int DUMP_LOAD_PIN = 5;        // Optional brake resistor

bool charging = false;

void setup() {
  Serial.begin(115200);
  ina219.begin();

  pinMode(CHARGE_RELAY_PIN, OUTPUT);
  pinMode(DUMP_LOAD_PIN, OUTPUT);

  digitalWrite(CHARGE_RELAY_PIN, LOW);
  digitalWrite(DUMP_LOAD_PIN, LOW);

  Serial.println(F("🌬️ Wind/Kinetic Microloop Controller Ready"));
}

void loop() {
  float voltage = ina219.getBusVoltage_V();
  float current = ina219.getCurrent_mA() / 1000.0;

  Serial.print(F("🔄 Wind Loop V: ")); Serial.print(voltage);
  Serial.print(F(" | I: ")); Serial.print(current); Serial.println(F(" A"));

  if (!charging && voltage > minVoltage && voltage < maxVoltage && current < maxSafeCurrent) {
    Serial.println(F("✅ Charging enabled"));
    digitalWrite(CHARGE_RELAY_PIN, HIGH);
    digitalWrite(DUMP_LOAD_PIN, LOW);
    charging = true;
  } else if (voltage > maxVoltage || current > maxSafeCurrent) {
    Serial.println(F("🛑 Overvoltage or current — braking"));
    digitalWrite(CHARGE_RELAY_PIN, LOW);
    digitalWrite(DUMP_LOAD_PIN, HIGH);
    charging = false;
  } else if (voltage < minVoltage - 0.5) {
    Serial.println(F("⚠️ Input too low — idle"));
    digitalWrite(CHARGE_RELAY_PIN, LOW);
    digitalWrite(DUMP_LOAD_PIN, LOW);
    charging = false;
  }

  delay(2000);
}
```

---
