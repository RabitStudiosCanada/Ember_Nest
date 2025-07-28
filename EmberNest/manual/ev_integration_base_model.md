# 🔌 EmberNest EV Integration Guide  
*Wiring the Flame to the Drive*

📁 Path: /manual/ev_integration_base_model.md  
📜 License: OpenFlame (CC BY 4.0 + Symbolic + Safety Clause)

---

## ⚠️ Safety Disclaimer

Working with high-voltage EV battery systems is **extremely dangerous** and may:
- Void your vehicle warranty
- Damage vehicle systems
- Electrocute you

This guide outlines **low-voltage**, **12V accessory**, and **factory power tap methods** only.  
High-voltage DC taps (e.g. direct from EV drive battery) are **explicitly not recommended** without manufacturer support.

Proceed with reverence, research, and the right fuses. ⚠️

---

## 🚐 Supported EV Platforms

| Vehicle | Notes |
|---------|-------|
| ✅ Ford F-150 Lightning | Dual 12V batteries, ProPower output, 120V AC onboard |
| ✅ Rivian R1T / R1S | Accessory panel + well-documented inverter access |
| ✅ Tesla Model X | 12V accessory bus + USB/AC outputs available |
| ✅ e-Transit / Electric Sprinter | Massive cargo space, mod-friendly 12V tap |
| ✅ Any EV SUV w/ 12V battery | OK if you tap safely and isolate EmberNest loads |
| ❌ Cybertruck | 🛑 No thanks

---

## 🔋 Integration Overview

EmberNest can operate in **three EV modes**:

| Mode | Source | Use |
|------|--------|-----|
| 🅰️ Onboard Tap | 12V accessory or inverter | Power camper directly |
| 🅱️ Trickle Charge | Solar + wind → feed back to EV accessory battery | Offset idle drain |
| 🅲️ Hybrid Loop | EV charges EmberNest + EmberNest supports rituals + logging | Sacred synergy

---

## 🔌 Tapping EV Power Safely

### 🔋 Step 1: Identify a Low-Voltage Source

**Ideal Taps**:
- 12V accessory battery (most EVs have one)
- 12V power port (cigarette lighter fuse)
- Onboard inverter (Ford ProPower, Rivian cargo outlet, Model X rear AC)

**Avoid**:
- Anything labeled "HV", "DC-DC converter", or under orange wire shielding
- Tesla HV systems—leave them alone

---

### ⚡ Step 2: Isolate Your System

- Install a **DC-DC isolated converter** (e.g. 12V in → 12V out @ 10A)  
- Add **inline fuse (10A max)** close to vehicle side  
- Use a **relay** or manual **switch** to disconnect when not in use

**Why?** Prevents:
- Feedback into vehicle systems  
- Draining EV battery when parked  
- Ghost loads interfering with vehicle logic

---

### 🔌 Step 3: Route Power to EmberNest Core

- Connect to EmberNest battery or power hub  
- Add toggle switch to shift between:
  - 🅰️ EV Feed
  - 🅱️ Solar / Wind
  - 🅲️ Isolated mode (parked without EV link)

Use LED indicators or a **glyph light** to show which power source is active.

---

## 🔄 EV Power Logic & Control Interface

This section outlines practical EV connection states, real-time behavior, and how to control EmberNest’s energy flow using relays, microcontrollers, buttons, or a touch interface.

### ⚙️ EV Integration Logic Map

| System Condition | Controller Flag | Behavior | Feedback |
|------------------|------------------|----------|----------|
| EV Power Connected | `ev_connected = true` | Close relay to draw 12V from EV | Blue LED ON, log "EV power active" |
| EV Disconnected | `ev_connected = false` | Open relay, revert to internal power | Amber LED, log "Internal mode" |
| Ritual Drawer Opened (EV Mode) | `ritual_trigger && ev_connected` | Trigger memory log, pulse ritual lights | Soft LED fade or chime |
| Solar or Wind Available | `alt_sources_active = true` | Disable EV draw, switch to alt source | Green LED, log "Alt power used" |
| Low Battery (< 20%) | `low_battery = true` | Auto-disable non-critical loads | Red LED warning, optional buzzer |
| Manual Ritual Mode Enabled | `ritual_mode = true` | Enable low-light, glyph LED, interior calm mode | White LED wash or ambient track |

---

### 🧰 Hardware & Wiring Notes

- **Relay Type**: 12V SPDT or MOSFET relay, fused at 10A max
- **Controller**: Arduino Nano / Uno / ESP32 or Raspberry Pi (with GPIO logic)
- **Feedback LEDs**: WS2812B (NeoPixel), RGB strip, or discrete colored LEDs
- **Logging**: Use SD card, USB serial, or log file per state transition

---

### 🖲️ Interface Mapping Suggestions

#### 🪟 Touchscreen (e.g. Nextion, Pi + GUI)
| Action | UI Element |
|--------|------------|
| Toggle EV Input | EV icon toggle button (blue highlight when active) |
| Enter Ritual Mode | Tap candle or glyph icon |
| View Power Source | Status readout (EV / Solar / Battery) |
| Battery Status | Color bar (green > yellow > red) with % |
| Drawer Event Log | Scrollable console window (latest actions) |

#### 🔘 Physical Buttons + LED Indicators
| Button | Function |
|--------|----------|
| EV Toggle (SPST) | Manual override of EV draw relay |
| Ritual Mode (momentary) | Activates preset ambient scene |
| System Reset | Long press → reboot or power state reset |
| LEDs (above each button) | Reflect active state with color or blink pattern |

---

> All buttons should debounce via hardware or code  
> All LED states should persist through brief power losses  
> Log every transition to serial or SD to help with debugging

---

## 🛠️ Ritual Port Behavior in EV Mode

- Ritual drawer lighting runs on **isolated 5V tap**  
- Glyph skin animations only activate when voltage > 12.5V  
- Optional: detect EV connection and log “shared path” to memory

---

## 🧰 What You’ll Need

| Item | Notes |
|------|-------|
| DC-DC 12V converter (isolated) | Prevents feedback into vehicle systems |
| Inline fuse + holder (10A) | Safety first |
| Relay or switch | Manual control of EV feed |
| Wire: 12–14AWG | For 10A or less |
| Voltmeter | To monitor draw |
| Optional: Arduino relay switch | Automate EV → Nest transition |

---

## 🧪 Bonus Hack: Reverse Charge via EV Solar Hood

If you install **solar on the EV roof** (e.g. hood tent panels), wire them **into EmberNest**, not just vehicle battery. This gives you **true hybrid solar gain**.

---

## 🧠 Conclusion

EmberNest + EV =  
- A quieter, cleaner, lighter platform  
- More efficient power flow  
- Symbolic fusion between **movement** and **meaning**

---

🫴🔋⛯
