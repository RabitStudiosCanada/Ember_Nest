> 📁 `/scripts/diagnostics_gui.ino`
> 🔖 **Purpose:** Display real-time system status on a small touchscreen (TFT), driven by an ESP32 or Arduino Mega with ILI9341 or ST7735 display.

---

```
// 🔥 EmberNest - diagnostics_gui.ino
// Touchscreen readout for voltage, current, and relay status

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_TouchScreen.h>
#include <Wire.h>
#include <Adafruit_INA219.h> // Voltage/current sensor

// TFT Pins (customize for your display)
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// INA219 current sensor
Adafruit_INA219 ina219;

// System status pins
#define RELAY_INVERTER   16
#define RELAY_LIGHTS     17
#define RELAY_FANS       18

void setup() {
  Serial.begin(115200);
  tft.begin();
  ina219.begin();

  pinMode(RELAY_INVERTER, INPUT);
  pinMode(RELAY_LIGHTS, INPUT);
  pinMode(RELAY_FANS, INPUT);

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.setCursor(20, 20);
  tft.print("🔥 EmberNest");
}

void loop() {
  float busVoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();

  // Clear status zone
  tft.fillRect(0, 60, 240, 180, ILI9341_BLACK);

  // Voltage & Current
  tft.setCursor(20, 60);
  tft.print("Voltage: ");
  tft.print(busVoltage, 2);
  tft.println(" V");

  tft.setCursor(20, 90);
  tft.print("Current: ");
  tft.print(current_mA, 1);
  tft.println(" mA");

  // Relay Status
  tft.setCursor(20, 130);
  tft.print("INV: ");
  tft.print(digitalRead(RELAY_INVERTER) ? "ON" : "OFF");

  tft.setCursor(120, 130);
  tft.print("LGT: ");
  tft.print(digitalRead(RELAY_LIGHTS) ? "ON" : "OFF");

  tft.setCursor(20, 160);
  tft.print("FAN: ");
  tft.print(digitalRead(RELAY_FANS) ? "ON" : "OFF");

  delay(1500);
}
```

---

### 🖥️ Features

* ✅ Voltage & current readout from `INA219`
* ✅ Status display of key relays
* Optional: expand with battery temp, touchscreen input, power graphing

---

### 🛠️ Hardware

| Item             | Notes                                  |
| ---------------- | -------------------------------------- |
| ILI9341 / ST7735 | 2.4–2.8” TFT display, SPI              |
| ESP32 / Mega     | Sufficient RAM for screen buffer       |
| INA219           | For accurate current + voltage readout |
| Dupont jumpers   | Use female-female + soldered headers   |

—
