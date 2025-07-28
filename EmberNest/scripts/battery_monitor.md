## 📄 `battery_monitor.ino`

> Real-time voltage, current, and power monitoring
> Compatible with 12V+ battery banks & DC buses
> Outputs data to Serial, optionally triggers alert LEDs or relays

---

```cpp
// battery_monitor.ino – EmberNest Diagnostics Module
// Uses Adafruit INA219 or basic voltage divider for battery status tracking

#include <Wire.h>
#include <Adafruit_INA219.h>

// Define sensor object
Adafruit_INA219 ina219;

// Optional: battery voltage input if using voltage divider
const int voltagePin = A0;
const float dividerRatio = 11.0;  // Adjust based on your resistor pair

// Config
const float lowVoltageThreshold = 11.8; // V (typical for 12V bank)
const float criticalVoltage = 10.5;
const float maxCurrentSafe = 15.0; // Amps
bool inaPresent = false;

void setup() {
  Serial.begin(115200);
  delay(500);

  if (ina219.begin()) {
    Serial.println(F("🔋 INA219 detected, advanced monitoring enabled"));
    inaPresent = true;
  } else {
    Serial.println(F("⚠️ INA219 not found, defaulting to voltage-only mode"));
    inaPresent = false;
  }

  pinMode(voltagePin, INPUT);
}

void loop() {
  if (inaPresent) {
    float busVoltage = ina219.getBusVoltage_V();     // direct voltage
    float shuntVoltage = ina219.getShuntVoltage_mV() / 1000.0;
    float loadVoltage = busVoltage + shuntVoltage;
    float current_mA = ina219.getCurrent_mA();
    float power_mW = ina219.getPower_mW();

    Serial.print(F("🔌 Load Voltage: ")); Serial.print(loadVoltage); Serial.print(F(" V"));
    Serial.print(F(" | Current: ")); Serial.print(current_mA / 1000.0); Serial.print(F(" A"));
    Serial.print(F(" | Power: ")); Serial.print(power_mW / 1000.0); Serial.println(F(" W"));

    if (loadVoltage < criticalVoltage) {
      Serial.println(F("❌ CRITICAL: Battery dangerously low!"));
    } else if (loadVoltage < lowVoltageThreshold) {
      Serial.println(F("⚠️ Warning: Battery voltage low."));
    }

  } else {
    int raw = analogRead(voltagePin);
    float measured = (raw / 1023.0) * 5.0 * dividerRatio;

    Serial.print(F("🔋 Battery Voltage (est.): ")); Serial.print(measured); Serial.println(F(" V"));

    if (measured < criticalVoltage) {
      Serial.println(F("❌ CRITICAL: Battery dangerously low!"));
    } else if (measured < lowVoltageThreshold) {
      Serial.println(F("⚠️ Warning: Battery voltage low."));
    }
  }

  delay(1000);
}
```

---

### 🔧 Wiring (for INA219)

| INA219 Pin | Connect To                  |
| ---------- | --------------------------- |
| VIN+       | Battery +                   |
| VIN-       | Load +                      |
| GND        | GND (shared)                |
| VCC        | 3.3V or 5V                  |
| SDA/SCL    | To microcontroller I2C pins |

### 🔧 Wiring (for voltage divider only)

Use a 10kΩ / 1kΩ or 30kΩ / 2.7kΩ pair on analog pin (A0).

---
