## 📄 `thermal_loop_regulator.ino`

> Controls thermal coil or compost circuit.
> Activates a circulation pump, heat diverter, or relay when temp delta crosses threshold.

### 🧰 Requirements:

* 2x DS18B20 temp sensors (or thermistors)
  `sensorHot` = compost coil / source
  `sensorCold` = thermal sink / water tank
* Relay or MOSFET to activate solenoid or water pump

---

```cpp
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin config
#define ONE_WIRE_BUS 2
#define RELAY_PIN 5

// Temp control thresholds
const float deltaTrigger = 6.0;   // °C difference to activate loop
const float safetyMin = 2.0;      // °C hysteresis to turn off
const int delayBetweenReads = 5000; // ms

// DS18B20 Setup
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Store temp sensor addresses
DeviceAddress sensorHot, sensorCold;

void setup() {
  Serial.begin(115200);
  sensors.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  if (sensors.getDeviceCount() < 2) {
    Serial.println(F("❌ Not enough temperature sensors found!"));
  } else {
    sensors.getAddress(sensorHot, 0);
    sensors.getAddress(sensorCold, 1);
    Serial.println(F("🔥 Thermal loop regulator ready"));
  }
}

void loop() {
  sensors.requestTemperatures();
  float tempHot = sensors.getTempC(sensorHot);
  float tempCold = sensors.getTempC(sensorCold);
  float delta = tempHot - tempCold;

  Serial.print(F("🌡️ Hot: ")); Serial.print(tempHot);
  Serial.print(F("°C | Cold: ")); Serial.print(tempCold);
  Serial.print(F("°C | Δ: ")); Serial.print(delta); Serial.println("°C");

  static bool loopActive = false;

  if (!loopActive && delta > deltaTrigger) {
    Serial.println(F("♻️ Activating thermal circulation"));
    digitalWrite(RELAY_PIN, HIGH);
    loopActive = true;
  } else if (loopActive && delta < safetyMin) {
    Serial.println(F("🛑 Thermal loop cooling down, deactivating"));
    digitalWrite(RELAY_PIN, LOW);
    loopActive = false;
  }

  delay(delayBetweenReads);
}
```

---
