# 🔌 EmberNest EV Power Harness  
*A complete guide to safely wiring EmberNest to an electric vehicle.*

📁 Path: /hardware/ev_power_harness.md  
📜 License: OpenFlame (CC BY 4.0 + No HV Disclaimer)

---

## ⚠️ WARNING

Working with EV power systems is dangerous and can damage your vehicle if done incorrectly.  
This guide only covers **12V accessory**, **120V inverter-based**, and **isolated input** methods.

**DO NOT** attempt to tap high-voltage DC power unless you're a certified EV tech with proper PPE.  
Always fuse, test, and isolate. Respect the amperage.

---

## 🔋 Goals of This Harness

- Draw safe, fused power from an EV (e.g. Ford Lightning, Tesla Model X, Rivian R1T)  
- Send it into EmberNest’s internal system  
- Allow manual or automatic switching between EV, solar, wind, or battery  
- Keep EV and EmberNest **electrically isolated**

---

## 🧰 Required Components

| Item | Spec | Qty |
|------|------|-----|
| DC-DC Isolated Converter | 12V in → 12V out @ 10A min | 1 |
| SPDT Automotive Relay | 12V trigger, 30A rating | 1 |
| Inline Fuse Holders | ATC blade or microfuse | 2–3 |
| Toggle Switch or GPIO Trigger | Manual override or microcontroller pin | 1 |
| 12–14 AWG Wire | Marine-grade preferred | ~10 ft |
| Anderson Connectors (optional) | High-current modular plug | 2 |
| Volt/Amp Meter Module | Optional inline feedback | 1 |

---

## 🔧 Where to Tap Power from the EV

### ✅ Primary Options:
1. **12V Accessory Port (Fused)**
   - Via cigarette lighter or direct from the fuse box
   - Add inline fuse (~10A) as close to vehicle tap as possible

2. **Onboard Inverter or Outlet**
   - If EV has built-in 120V AC outlet, use it to power a smart battery charger
   - Add GFCI + surge protector + wattmeter

3. **USB-C PD Port**
   - Can trickle charge a small EmberNest LiFePO4 via USB-PD → DC buck
   - Very limited current (~60–100W)

---

## 🛠️ Installation Steps

1. **Mount the DC-DC Isolated Converter**
   - Attach to an aluminum plate or screw it to EmberNest’s subfloor wall
   - Add rubber grommets for vibration isolation

2. **Wire EV Output to Converter Input**
   - Use 14 AWG red/black marine wire  
   - Fuse the red line with 10A inline fuse near EV tap point

3. **Wire Converter Output to EmberNest Battery Bus**
   - Use Anderson connectors or terminal block  
   - Fuse again before entering power hub (~10A recommended)

4. **Install Manual Switch or Relay**
   - SPDT relay lets you switch between EV feed, solar, or battery
   - Control via GPIO (Arduino/RPi) or physical switch

5. **Test With Multimeter**
   - Verify voltage before connecting live  
   - Check for grounding issues or shorts

---

## 🧪 Suggested Relay Logic

| Source | Condition | Result |
|--------|-----------|--------|
| EV Connected | Switch closed | Relay passes EV power to Nest |
| Solar Available | `voltage_in_solar > 13V` | Disconnect EV feed |
| Manual Override | Toggle switch flipped | EV feed disabled |

Use 12V automotive relay or MOSFET switch with logic-level trigger.

---

## 🔎 Optional Additions

- Inline shunt for amp logging  
- LED indicator (blue = EV feed, green = solar, red = battery)  
- Plug monitor (like a Renogy voltmeter) inside Nest interface panel  
- Surge arrestor on AC inverter path (if using 120V outlet from EV)

---

## 🧠 Best Practices

- Keep EmberNest and EV **electrically isolated** using DC-DC isolation  
- Fuse EVERY path  
- Run all wires through grommets and conduit  
- Check connections after 1 week of driving  
- Do not leave EV plugged in unattended until tested

---

## 🛻 Vehicles Confirmed Compatible (12V Tap)

| Vehicle | Notes |
|---------|-------|
| Ford F-150 Lightning | 12V & AC ProPower | ✅  
| Rivian R1T / R1S | Bed outlets + 12V available | ✅  
| Tesla Model X | Rear 12V accessory plug | ✅  
| e-Transit / Sprinter EV | Multiple power points | ✅  
| Nissan Leaf, Chevy Bolt | Lighter port only (low power) | ⚠️

---

## 🔁 EV ↔ EmberNest Power Loop  
### *Mobile Renewable Rescue for Electric Vehicles*

### 🧭 Overview

When properly wired, EmberNest becomes more than just a powered living space—it transforms into a **mobile, renewable energy rescue station** for electric vehicles.

By harvesting solar, wind, thermal, and kinetic energy into its internal battery bank, EmberNest can **backfeed power into an EV’s 12V system**, helping restore critical voltage and reboot otherwise stranded vehicles.

> This is not just camping. This is off-grid vehicle resilience.

---

### 🔋 Why It Matters

Most EVs rely on a **12V accessory battery** to boot their main computer and power basic systems.  
If the 12V goes flat, the EV may become unresponsive—even with 80% charge remaining in its high-voltage battery.

EmberNest:
- **Charges itself** from natural sources while stationary
- **Monitors EV 12V state** during long parked sessions
- **Auto-triggers or manually initiates** a safe recharge cycle
- **Restores EV function** without cables, jumps, or tows

---

### ⚙️ Two Charging Modes

#### ✅ 1. Automatic EV Rescue Mode
- Microcontroller monitors EV voltage (`<12.2V`)
- If Nest has reserve (`>12.5V`), it activates a DC-DC loop
- Sends up to **10A safely** into the EV 12V system
- Powers up computers, unlocks doors, enables boot sequence

#### 🛠️ 2. Manual Rescue Mode (Recommended)
- Switch-activated: driver presses a **dedicated button**
- Nest feeds EV battery for 10–15 minutes
- Indicator LED confirms backfeed is active
- Optionally controlled by relay, timer, or touch UI
- Ensures function **even when sensors fail**

---

### 🧰 What You'll Need

| Component | Purpose |
|-----------|---------|
| Bi-directional or isolated DC-DC converter | Enables safe 12V charge feed |
| Inline fuse (10A max) | Protects both ends of the loop |
| Momentary or toggle switch | Manual override |
| RGB LED (status feedback) | Visual state indicator |
| Arduino or Raspberry Pi | Voltage sensing + timed logic (optional) |

---

### 🧪 Use Case: Remote Resurrection

- You camp in the woods for 4 days.  
- The EV’s 12V slowly drains due to cold or parasitic load.  
- It won’t boot. The touchscreen is dead.  
- Instead of calling for a tow…

🪔 *EmberNest backfeeds life.*

- Power flows silently into the 12V rail.  
- Systems wake. Doors unlock. Ignition succeeds.  
- You drive home on **sunlight and compost heat**.

---

### ⚠️ Safety & Limitations

- Never attempt to charge the EV’s **high-voltage pack**  
- Only backfeed to **12V accessory battery**  
- Use isolated converters and fuses on both ends  
- Only activate when EV is **fully off**  
- Include manual cutoff or timeout logic to prevent overcharge

---

### ✅ Summary

| Capability | Status |
|------------|--------|
| EV → EmberNest charge | ✅ Fully supported (12V, 120V) |
| EmberNest → EV rescue | ✅ Supported (12V only) |
| High-voltage EV pack charging | ❌ Not supported (unsafe, proprietary) |

---

## 🌞🛻 The Nest as a Nomadic Solar Power Station

This system means EmberNest is not just a van or trailer.  
It’s a **mobile renewable energy platform**—capable of:

- Off-grid self-sufficiency  
- Mutual charging with EVs  
- Renewable infrastructure in disaster zones  
- Field station support for research, travel, or emergency response

Build it right, and it won’t just shelter you—it’ll resurrect your vehicle.  
🛠️🔋🪔⛯
