> 📁 `/scripts/control_logic.ino`
> 🔖 **Purpose:** Handle switch input, relay control, status LEDs, and basic logic for EmberNest's hardware control panel.

---

```
// 🔥 EmberNest - control_logic.ino
// Core system control sketch for ESP32 or Arduino Nano
// Handles input switches, relay toggles, system status

// Pin assignments (customize to your build)
const int RELAY_INVERTER   = 2;
const int RELAY_LIGHTS     = 3;
const int RELAY_FANS       = 4;
const int RELAY_USB        = 5;
const int RELAY_EV_CHARGE  = 6;

const int SWITCH_INVERTER  = 7;
const int SWITCH_LIGHTS    = 8;
const int SWITCH_FANS      = 9;
const int SWITCH_USB       = 10;
const int SWITCH_EV_CHARGE = 11;

const int LED_STATUS       = 13;

void setup() {
  Serial.begin(9600);

  // Relays as outputs
  pinMode(RELAY_INVERTER, OUTPUT);
  pinMode(RELAY_LIGHTS, OUTPUT);
  pinMode(RELAY_FANS, OUTPUT);
  pinMode(RELAY_USB, OUTPUT);
  pinMode(RELAY_EV_CHARGE, OUTPUT);

  // Switches as inputs
  pinMode(SWITCH_INVERTER, INPUT_PULLUP);
  pinMode(SWITCH_LIGHTS, INPUT_PULLUP);
  pinMode(SWITCH_FANS, INPUT_PULLUP);
  pinMode(SWITCH_USB, INPUT_PULLUP);
  pinMode(SWITCH_EV_CHARGE, INPUT_PULLUP);

  pinMode(LED_STATUS, OUTPUT);
  digitalWrite(LED_STATUS, HIGH); // ON at boot
}

void loop() {
  // Simple switch-to-relay logic
  digitalWrite(RELAY_INVERTER,  !digitalRead(SWITCH_INVERTER));
  digitalWrite(RELAY_LIGHTS,    !digitalRead(SWITCH_LIGHTS));
  digitalWrite(RELAY_FANS,      !digitalRead(SWITCH_FANS));
  digitalWrite(RELAY_USB,       !digitalRead(SWITCH_USB));
  digitalWrite(RELAY_EV_CHARGE, !digitalRead(SWITCH_EV_CHARGE));

  // Status pulse every few seconds
  static unsigned long lastPulse = 0;
  if (millis() - lastPulse > 2000) {
    digitalWrite(LED_STATUS, LOW);
    delay(100);
    digitalWrite(LED_STATUS, HIGH);
    lastPulse = millis();
  }
}
```

---

### 🛠️ How to Use

1. Wire each switch to a `NO` pushbutton (tied to GND)
2. Wire relays to their respective pins and control the 12V loads
3. Flash this sketch onto an ESP32 or Nano with USB
4. System will toggle relays based on physical button presses
5. Modify or expand logic as needed (timers, sensors, etc.)

—
