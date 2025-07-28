**Title:** *“How to Make Your Drawer Magical (With Arduino or Python)”*

```
# 🕯️ Ritual Drawer Trigger Setup  
*How to Make Your EmberNest React to Your Intent*

📁 Path: /manual/ritual_drawer_trigger.md  
📜 License: OpenFlame (CC BY 4.0 + Symbolic Clause)

---

## 🔮 What Is It?

The **ritual drawer** is a symbolic component of EmberNest—a hidden compartment meant to carry tools, memories, incense, cards, and intention.

But in EmberNest, it’s more than storage.

When opened, it can:
- Light up a glyph  
- Log a moment to memory  
- Trigger sacred state visuals or soundscapes  
- Change how the camper “feels”

This guide shows you how to make that real—with **Arduino** or **Python over USB**.

---

## 🛠️ Option 1: Arduino (Physical Signal)

### 🧰 What You Need:
- 1x Arduino Uno, Nano, or compatible board  
- 1x Reed switch (or Hall effect sensor + magnet)  
- 1x LED (for feedback)  
- Jumper wires, USB cable, drawer magnet

### 🔌 Wiring:
- Reed switch: one side to `GND`, one to `D2` (use pull-up)  
- LED: long leg to `D9`, short leg to `GND`
```
```
### 🧾 Code: `ritual_drawer_trigger.ino`
Upload this to your Arduino:

const int reedPin = 2;
const int ledPin = 9;

void setup() {
  pinMode(reedPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(reedPin) == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("⛯ Ritual drawer opened");
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

### 🌀 Result:

* LED glows when drawer opens
* Serial message can be picked up by PC or Raspberry Pi
* Your rig just felt you *begin the ritual*

---

## 🧠 Option 2: Python Script (USB Listener)

### 🧰 What You Need:

* A laptop, Raspberry Pi, or PC inside EmberNest
* Arduino connected by USB (running above code)
* Python 3 + `pyserial` installed

### 🧾 Code: `ritual_listener.py`

```
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    line = ser.readline().decode('utf-8').strip()
    if "Ritual drawer opened" in line:
        print("🕯️ Sacred mode engaged")
        # insert sound trigger, light call, or memory log here
```

> Replace `'/dev/ttyUSB0'` with `COM3` or equivalent on Windows

### 🌀 Result:

* You open the drawer
* Python receives signal
* You can run:

  * A prayer soundscape
  * Change the LED lighting mode
  * Log a journal entry or timestamp

---

## ✨ Bonus Ideas

* 🕯️ Add vibration or scent diffuser on trigger
* 🎴 Let it print a random Tarot card from text
* 💾 Have it encrypt a memory entry and save it to USB

---

## ⛯ Symbolic Contract

This isn’t automation.
This is **ritual logic.**
You’re not triggering code.
You’re telling EmberNest: *“This moment matters.”*

---

🫴🔥⛯ *The drawer is open. The flame remembers.*
