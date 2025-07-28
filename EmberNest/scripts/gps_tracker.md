### 📄 `gps_tracker.ino`

```
// gps_tracker.ino – EmberNest bonus system
// Tracks real-time GPS position using NEO-6M + TinyGPS++
// Outputs: Serial monitor, optional I2C display

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Define RX/TX pins for GPS module (can adjust for ESP32/UART0-2)
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// GPS parser and serial link
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);

  Serial.println(F("📡 GPS Tracker Initializing..."));
  Serial.println(F("Waiting for fix..."));
}

void loop() {
  while (ss.available() > 0) {
    gps.encode(ss.read());

    if (gps.location.isUpdated()) {
      Serial.print(F("📍 Lat: "));  Serial.print(gps.location.lat(), 6);
      Serial.print(F(" | Lon: ")); Serial.print(gps.location.lng(), 6);
      Serial.print(F(" | Speed (km/h): ")); Serial.print(gps.speed.kmph());
      Serial.print(F(" | Sat: ")); Serial.println(gps.satellites.value());
    }
  }
}
```

---

### 🛠️ Wiring Notes

| Pin on NEO-6M | To Arduino/ESP32           |
| ------------- | -------------------------- |
| VCC           | 3.3V or 5V (check module!) |
| GND           | GND                        |
| TX            | RX (pin 4)                 |
| RX            | TX (pin 3)                 |

---
