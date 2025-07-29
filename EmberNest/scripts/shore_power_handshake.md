## 📄 `shore_power_handshake.ino`

> Detects AC/grid connection.
> Activates relays and triggers charging protocol switch.

---

### 🧰 Requirements:

* **Optocoupler or GPIO logic pin** to detect AC presence
* **Relay or SSR** to enable charging or disable internal loops
* Optional: LED indicator or LCD display update

---

```cpp
// shore_power_handshake.ino
// Detects shore power and safely reroutes power logic

#define SHORE_SENSE_PIN 6     // Digital pin from optocoupler circuit (LOW = AC present)
#define AC_CONTACTOR_PIN 7    // High-power relay or SSR to switch shore charging
#define LOOP_DISABLE_PIN 8    // Optional disable signal for DC loops

bool shoreConnected = false;

void setup() {
  Serial.begin(115200);
  pinMode(SHORE_SENSE_PIN, INPUT_PULLUP);  // Opto pulls LOW when AC detected
  pinMode(AC_CONTACTOR_PIN, OUTPUT);
  pinMode(LOOP_DISABLE_PIN, OUTPUT);

  digitalWrite(AC_CONTACTOR_PIN, LOW);
  digitalWrite(LOOP_DISABLE_PIN, LOW);

  Serial.println(F("🔌 Shore Power Handshake ready"));
}

void loop() {
  bool shoreNow = digitalRead(SHORE_SENSE_PIN) == LOW;

  if (shoreNow && !shoreConnected) {
    Serial.println(F("✅ Shore power detected. Switching to AC mode."));
    digitalWrite(AC_CONTACTOR_PIN, HIGH);
    digitalWrite(LOOP_DISABLE_PIN, HIGH);  // Optionally disable DC
    shoreConnected = true;
  }

  if (!shoreNow && shoreConnected) {
    Serial.println(F("🔄 Shore power removed. Reverting to DC."));
    digitalWrite(AC_CONTACTOR_PIN, LOW);
    digitalWrite(LOOP_DISABLE_PIN, LOW);
    shoreConnected = false;
  }

  delay(1000);
}
```

---

### 🧪 How it works:

* When you plug EmberNest into a wall outlet, an optocoupler triggers `SHORE_SENSE_PIN` low.
* A relay (AC\_CONTACTOR) enables the grid-charging logic.
* Optional: disables all internal loops like wind/thermal/solar to avoid DC overlap.

---
