## 📄 `touch_panel_input.ino`

> Reads input from a touch interface or keypad and sends control signals to EmberNest logic layer.

---

### 🧰 Supports:

* 🧲 **TTP223 capacitive modules**
* 🔲 **4x4 button matrix**
* 🖲️ **Resistive touch shields (optional upgrade)**

---

### ✳️ Variant A: Capacitive Touch Buttons (TTP223 or similar)

```cpp
// touch_panel_input.ino – Capacitive Touch Interface

#define NUM_TOUCH 4
int touchPins[NUM_TOUCH] = {2, 3, 4, 5};  // Connected to touch modules
bool lastState[NUM_TOUCH] = {false, false, false, false};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_TOUCH; i++) {
    pinMode(touchPins[i], INPUT);
  }
  Serial.println(F("📟 Touch panel ready"));
}

void loop() {
  for (int i = 0; i < NUM_TOUCH; i++) {
    bool current = digitalRead(touchPins[i]) == HIGH;
    if (current && !lastState[i]) {
      Serial.print(F("🖲️ Touch activated: Button "));
      Serial.println(i + 1);
      sendCommand(i);  // Dispatch to logic
    }
    lastState[i] = current;
  }
  delay(100);
}

void sendCommand(int btn) {
  switch (btn) {
    case 0: Serial.println(F("→ Toggle solar input")); break;
    case 1: Serial.println(F("→ Cycle diagnostic mode")); break;
    case 2: Serial.println(F("→ Reset wind loop")); break;
    case 3: Serial.println(F("→ Emergency shutdown")); break;
  }
}
```

---

### 🧪 Optional Expansion:

* Upgrade `sendCommand()` to send signals via `Serial1.write()` to `control_logic.ino` running on separate MCU
* Add LCD display feedback for each input if wiring to a TFT panel
* Map long-press vs tap by tracking `millis()`

---
