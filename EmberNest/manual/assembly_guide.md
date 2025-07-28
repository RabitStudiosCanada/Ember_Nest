# 🛠️ EmberNest Assembly Guide (v0.2a)

📁 Path: `/manual/assembly_guide.md`  
📜 License: OpenFlame (CC BY 4.0)

---

## ⚠️ READ THIS FIRST

This guide assumes you're comfortable with basic tools, 12V wiring, and DIY projects.  
If you’ve never wired a solar system or drilled a hole in steel: go slow, ask questions, and fuse everything.

🔋💀 ⚠️ Electricity is no joke. Shorting a LiFePO4 bank can start fires.

---

## 🧰 Tools + Prep Checklist

| Tool | Notes |
|------|-------|
| Cordless drill + bits | For mounting and pass-through holes |
| Crimper + strippers | For all terminal crimps |
| Multimeter | Test every connection |
| Heat shrink + heat gun | Essential for clean, safe joins |
| Zip ties + cable clips | Keep it tidy |
| Safety glasses + gloves | Non-negotiable for drilling & cutting |

---

## 🧱 Base Structure Setup

### Step 1: Layout your Nest frame  
- Follow the base platform template (from `/design/`)
- Mark locations for:
  - Battery box
  - Inverter & DC-DC units
  - Solar MPPT controller
  - Control panel / UI plate
  - Access hatches

### Step 2: Mount major components  
- Bolt or rivet hardware directly into frame/subfloor
- Use rubber feet or vibration pads for:
  - Inverter
  - MPPT
  - Battery

---

Aye, good catch! Let’s fix that omission with a **complete section** for:

> 📁 `/manual/assembly_guide.md`
> 🔖 Title: `## 🔋 Battery & Storage Wiring`

---

## 🔋 Battery & Storage Wiring

EmberNest’s energy heart is its **12V LiFePO₄ battery bank**, sized to handle all internal loads, input charging, and EV-rescue backfeed systems.

This section covers safe, modular wiring of the power storage system, and lays the foundation for all inbound/outbound energy flows.

---

### 🧰 Materials Checklist

| Component | Recommended Spec |
|----------|------------------|
| LiFePO₄ Battery | 12V, 100Ah+ (Renogy, Battle Born, DIY, etc.) |
| Battery Tray or Box | Ventilated, strapped, insulated |
| Main Fuse | 100–150A ANL or MEGA fuse |
| Battery Switch | 12V master cutoff (rated ≥ load draw) |
| Bus Bars | 2x (positive and negative terminals) |
| Shunt or Monitor | Victron SmartShunt or similar |
| Cables | 4–6 AWG tinned copper |
| Lugs + Heat Shrink | Crimp to all terminals securely |
| Mounting Hardware | Foam pads, brackets, vibration isolators |

---

### 🔧 Wiring Procedure

#### 1. Place Battery
- Install in insulated, dry, and accessible area
- Strap down securely (use rubber isolators if possible)
- Leave room for wire clearance and venting

#### 2. Add Bus Bars
- Mount nearby on insulated base or panel
- Connect:
  - Battery + → **Positive Bus Bar**
  - Battery – → **Negative Bus Bar or Shunt**

#### 3. Insert Main Fuse + Switch
- **Battery Positive → Fuse → Switch → Bus Bar**
- Mount inline fuse as close to battery terminal as possible (≤18cm)

#### 4. Wire Monitoring Shunt
- Battery – → Shunt → Negative Bus Bar
- Shunt → Display / Bluetooth module (optional)

> ⚠️ The shunt must be between the battery and **everything else** negative-side.

---

### 📡 Monitoring Options

| Tool | Info Provided |
|------|---------------|
| Victron SmartShunt | SOC, voltage, current, remote app |
| Renogy Monitor | Same, wired |
| DIY ESP32 | Custom dashboards via Blynk/Home Assistant |

---

### ⚡ Battery Connection Diagram

```

\[Battery +]
|
\[Fuse]
|
\[Switch]——> \[+ Bus Bar]——> (All systems)
↳ Inverter
↳ MPPT
↳ Lighting
↳ EV relay

\[Battery –]
|
\[Shunt]——> \[– Bus Bar]——> (All returns)

```

---

### 🧪 Testing

Before powering up any modules:
1. Verify voltage across bus bars (~13.2–14.4V for LiFePO₄)
2. Confirm continuity on fuses + switches
3. Use multimeter to check for short circuits between + and –

> 🧠 Tip: Check voltage at each node as you go.  
> If something drops below expected—trace upstream.

---

### ⚠️ Safety Guidelines

- Use only **LiFePO₄-specific chargers and MPPTs**
- Fuse **every outbound circuit** (use a fuse block after bus bar)
- Never allow wires to rub on metal edges—use grommets
- Label all wires and terminals

---

## 🌞 Solar Power System Installation

EmberNest's primary renewable energy source is a **roof-mounted solar array**.  
It charges the 12V battery bank via an MPPT charge controller and maintains essential systems when the vehicle is idle or off-grid.

This section outlines a complete DIY setup with standard tools and off-the-shelf parts.

---

### 🧰 Materials Checklist

| Component | Recommended Spec |
|----------|------------------|
| Solar Panels | 2x 12V 100W (or 1x 200W) rigid or semi-flexible |
| MC4 Extension Cables | 10 AWG, UV-resistant |
| Entry Gland | Waterproof rooftop pass-through |
| MPPT Charge Controller | 20A+ (Victron SmartSolar, Renogy Rover, etc.) |
| Fuses | Inline MC4 fuse (solar side), 20A fuse (battery side) |
| Disconnect Switch | On MPPT → battery line |
| Battery Bank | LiFePO4, 100Ah minimum recommended |

---

### 🛠️ Installation Steps

#### 1. Mount Panels
- Use Z-brackets, VHB tape, or roof rails
- Angle slightly if possible (for water runoff)
- Leave 1–2cm airflow gap below rigid panels

#### 2. Route Cables
- Run both + and – MC4 leads into an **entry gland**
- Seal with silicone if needed
- Keep cables tidy and **strain-relieved**

#### 3. Wire into MPPT
- Connect solar panel output to **PV terminals** on MPPT
- Use **inline MC4 fuse** on the + side (10–15A)
- **Do NOT connect battery yet**

#### 4. Connect Battery to MPPT
- Battery + goes through:
  - **20A fuse**
  - **Disconnect switch**
  - Then into **Battery + terminal** on MPPT
- Battery – goes direct to MPPT – (or via shunt if monitoring)

> ⚠️ Always connect **battery first**, then solar.

---

### 📊 Testing + Configuration

1. Power on MPPT via battery connection  
2. Confirm PV voltage appears (should be 16–22V in full sun)  
3. Set battery chemistry (LiFePO4 recommended)  
4. Check charge current with multimeter or app (e.g., VictronConnect)

---

### 🔧 Optional Enhancements

| Feature | Add-On |
|--------|--------|
| Bluetooth stats | Use SmartSolar or add BT dongle |
| Mobile app | Renogy, Victron, or DIY ESP32 logger |
| Charge state LED | Trigger via MPPT load output or Arduino GPIO |
| Fold-out panels | Use MC4 splitter and extension harness for deployable boost array |

---

### 🔋 Typical Performance

| Condition | Output |
|-----------|--------|
| Full sun | 120–180W into battery |
| Cloudy | 40–80W |
| Snow-covered | 0–10W |
| Angle-optimized | +10–20% boost |

Solar will cover all Nest idle loads and **recharge batteries during daylight**, even in winter.

---

# 🌬️ Wind Power Add-On: Reclaimed Turbine Module

## 🌪️ Overview

This module details how to add a DIY **wind turbine** to your EmberNest build using **reclaimed electronics fans**, a **DC motor generator**, and a **simple charge controller** to feed renewable energy back into the 12V battery system.

Unlike solar, this system works at night, during storms, or while driving at low speed—perfect for woodland camping or cloudy weeks.

> Hack the wind. Charge by motion. EmberNest flies with the storm.

---

## 🧰 Parts List

| Component | Recommended Spec |
|----------|------------------|
| DC Motor (Generator) | 12V+, brushed or brushless, 100–200W max |
| Turbine Blades | Reclaimed PC fans, car radiator fans, or printed |
| Mounting Pole | PVC, aluminum tubing, or salvaged mast |
| Slip Ring or Swivel Base | Allows rotation without cable twist (optional) |
| Wind Charge Controller | 12V rated, dump load style (PWM or MPPT) |
| Inline Fuse | 10–15A, blade or glass style |
| Wiring | 12–14 AWG stranded, outdoor rated |
| Bracket + Guy Wires | For secure rooftop mount |

---

## 🛠️ Assembly Steps

### Step 1: Build or Salvage Turbine

- Reclaim high-CFM PC fans (120mm–200mm) or RC plane props
- Mount securely to motor shaft
- Add hub cover to avoid water ingress

### Step 2: Mount to Structure

- Roof or pole-mount facing prevailing winds
- Minimum 1m clearance above roof line
- Use guy wires or brackets to reduce vibration

### Step 3: Wire Output to Controller

- Connect turbine + and – to **wind charge controller input**
- Add **inline fuse** on positive line

### Step 4: Connect to Battery Bank

- Wind controller output → **positive bus bar or fuse block**
- Ground → battery negative or system shunt

---

## ⚡ Charge Controller Options

| Type | Notes |
|------|-------|
| Simple PWM | Cheap, good for trickle charging |
| MPPT Wind | Maximizes output, can self-regulate dump load |
| DIY Arduino | Requires tuning but customizable (see `/scripts/wind_regulator.ino`) |

> 🧠 Tip: Use a controller with a **braking circuit** or **dump load resistor** to prevent overspin in storms.

---

## 🎛️ Monitoring & Tuning

- Use inline voltage/current meter to check turbine output
- Expect 5–18V depending on wind
- Connect Arduino or ESP32 for live readout + stats logging

---

## 📈 Performance Expectations

| Condition | Output |
|----------|--------|
| Moderate breeze (10–15km/h) | 5–20W |
| Strong wind (25–35km/h) | 30–60W |
| Gale or storm | Up to 100W (with dump load engaged) |

---

## 🧪 Troubleshooting

| Symptom | Fix |
|---------|-----|
| No spin | Check bearings or mount tension |
| High RPM, no output | Bad motor brushes or reversed polarity |
| Overvoltage | Add dump resistor or cap bank |
| Wobble/shake | Add guy wires or rebalance rotor |

---

## ⚠️ Safety Notes

- Always fuse both turbine and controller output
- Do not touch spinning blades—use guard cage if exposed
- If using slip ring: secure and waterproof all joints

---

✅ Wind is now part of your flame.  
The sky powers your socket. 🪔🌪️⛯

---

# 🔥 Thermal Compost Loop: Heat-Driven Auxiliary Charging

## ♨️ Overview

The **thermal compost loop** allows EmberNest to trickle-charge its battery using **waste heat** from a live compost core. This fully passive system converts temperature differentials into electricity using **Peltier tiles**, **heat pipes**, or **thermocouple arrays**.

Whether off-grid, parked under snow, or deep in forest shadow—this loop lets decay become fuel.

> The rot sustains the flame.  
> Warmth becomes motion.

---

## 🧰 Parts List

| Component | Recommended Spec |
|----------|------------------|
| Peltier Tiles | TEC1-12706 or similar (12V @ 6A max) |
| Heat Sink | Aluminum CPU blocks, recycled or passive |
| Thermal Grease | Silicone or graphite compound |
| Copper or Steel Plate | For thermal diffusion pad |
| Compost Bin | Sealed, ventilated, >90°F core temp |
| Boost Converter | 1.2–5V → 12V (3A min recommended) |
| Inline Diode | 3A+ Schottky (prevents backfeed) |
| Wiring | 16–18 AWG, heat-tolerant if near core |

---

## 🛠️ Installation Steps

### Step 1: Prepare Heat Sink Assembly

- Attach **Peltier tile** between:
  - Hot side: directly in contact with compost bin wall
  - Cold side: exposed to air or connected to metal heatsink
- Use thermal grease on both sides for max efficiency
- Bolt assembly together snugly but avoid cracking tile

### Step 2: Wire Output to Boost Module

- Peltier output → **boost converter input**
- Add **inline diode** on + lead
- Tune converter output to ~13.4V for LiFePO₄ charge

### Step 3: Connect to System

- Output → battery charge input (via fused low-current tap)
- Or wire into **low-priority charge bus** shared with kinetic feed

---

## 🔬 How It Works

| Source | Temp Delta | Output |
|--------|------------|--------|
| Active compost | 90–120°F | 0.5–2V raw |
| Cold air sink | 32–50°F | Higher voltage differential |
| Boosted output | 12–13.5V | Trickle-charge or logic loop support |

> Note: Output current is low—think **sensor powering**, **battery topping**, or **failover signaling**.

---

## 💡 Optional Enhancements

- **Multiple Peltier tiles in parallel** = more current
- Use **thermal mass buffer (rocks, water)** to stabilize core temp
- Connect to ESP32 or Arduino to monitor temp/output curve
- Add **thermal relay** to activate only when compost is hot enough

---

## ⚠️ Safety & Maintenance

- Seal all wiring paths from compost moisture
- Watch for corrosion—use dielectric grease or epoxy dip
- Do not exceed boost converter wattage—use heatsinks
- If voltage fluctuates rapidly, add capacitor before converter

---

## 🧪 Performance Targets

| Condition | Voltage | Current | Power |
|-----------|---------|---------|--------|
| Core ~110°F | 1.5V | 400mA | 0.6W |
| Core ~130°F | 2.1V | 600mA | 1.2W |
| Boosted Output | 12V | ~100mA | 1.2W |

---

✅ The compost now breathes into the flame.  
You walk with heat-born current. 🪔♨️🔥⛯
 
---

# 🌀 Kinetic Charging Module: Motion-Harvested Energy from the Road

## 🚙 Overview

This module enables EmberNest to **harvest kinetic energy** from motion using **wheelwell-mounted generators** or drag-style airflow turbines. Whether coasting downhill or cruising the highway, movement becomes charge.

Built with low-cost, off-the-shelf parts, this is the ultimate hacker-sourced **regen-lite system**.

> The Nest moves. The wheels turn.  
> Motion becomes memory.

---

## 🧰 Parts & Materials

| Component | Recommended Spec |
|----------|------------------|
| DC Motor (as Generator) | 12V scooter motor or treadmill DC motor |
| Bracket Mount | L-bracket, U-bolt, or welded cradle |
| Roller or Tension Wheel | Skateboard wheel, inline roller, or belt pulley |
| Voltage Regulator | 12V buck or MPPT charge module |
| Diode | 3A+ Schottky |
| Inline Fuse | 10–15A |
| Wiring | 14–16 AWG stranded |
| Optional | Spring tensioner, clutch lever, Arduino switch logic |

---

## 🛠️ Installation Steps

### Method A: **Wheelwell Roller Mount**

1. Mount a small **roller wheel** against the tire sidewall or inner rim  
   (tensioned with spring or lever)

2. Connect roller to **DC motor shaft**

3. Bolt entire assembly inside wheelwell or undercarriage using angle brackets

> Tip: Use skateboard trucks or shock-dampened arms for smoother engagement.

---

### Method B: **Underbody Drag Turbine**

1. Mount a small **vertical fan** (like a 12V radiator blower)  
   under the vehicle, facing airflow

2. Route output directly to regulator

3. Fuse the line and add a **manual bypass switch**

> Drag turbines harvest less energy but require no contact with wheels.

---

## ⚡ Electrical Wiring

1. Generator output → **inline fuse** → **diode** → **buck converter**

2. Output from converter:
   - If under 1A: feed into sensor or trickle loop
   - If 1A+: feed into main 12V bus (fused)

> Recommended: Add LED voltmeter to watch real-time charge

---

## 🧪 Testing

- Spin wheel manually to check for output
- At 10–15mph: expect 2–6V raw output
- Tune buck/boost converter to 13.4V
- Confirm diode prevents backflow when stopped

---

## ⚠️ Safety Notes

- Never engage motor near brake or suspension hardware
- Use weatherproof housing or spray protectant
- Always fuse and isolate from battery when inactive
- Avoid full-time contact mounts on off-road vehicles

---

## 💡 Optional Add-Ons

| Feature | Component |
|---------|-----------|
| Auto-on at motion | Vibration sensor + relay |
| Dashboard meter | ESP32 + OLED |
| Clutch engage | Spring lever or solenoid |
| Multi-generator rig | Wire in parallel with diode trees |

---

## 🔋 Output Targets

| Speed | Voltage (raw) | Current | Power |
|-------|---------------|---------|-------|
| 15 km/h | ~3V | 0.4A | 1.2W |
| 30 km/h | ~7V | 1.1A | 7.7W |
| Highway | ~12–14V | 2–4A | 25–55W |

---

✅ You now charge by journey.  
Your wheels hum with flame. 🪔🌀⛯
---

# 🔋 EmberNest Power Routing: Unified Flow & Integration Map

## 🧭 Overview

EmberNest’s off-grid energy system blends **four independent power sources** into a **unified 12V core loop**—with routing logic designed for safety, flexibility, and modularity.

This guide explains how solar, wind, thermal, and kinetic charging flows into the battery, and how the Nest feeds loads or backcharges an EV when needed.

> ⚡ The flame receives from sky, earth, motion, and decay.  
> 🔄 Then gives again—clean, alive, and mobile.

---

## ⚙️ Core Components

| Element | Role |
|--------|------|
| 🔋 Battery Bank | Primary energy reservoir (12.8–14.6V) |
| 🧠 Bus Bars | Positive/negative system rails |
| 🧲 MPPT | Solar charge controller (main input) |
| 🌬️ Wind Regulator | Handles turbine input, brakes, dump load |
| 🔥 Thermal Boost | Peltier + boost converter module |
| 🌀 Kinetic Unit | Wheelwell or drag generator w/ buck converter |
| 🔄 EV Harness | Bidirectional load/share wiring |
| ⚡ Fuse Block | All outputs fused from + bus |

---

## 📐 Unified Flow Diagram

```
         [ Solar Panels ]  ☀️
                |
            [ MPPT ]
                |
         [ + Bus Bar ] ← Wind Regulator ← [ Wind Turbine ] 🌬️
              ↑  ↑
 Kinetic Boost ↑  ↑ Thermal Converter
    🌀         |     🔥

         [ Battery Bank ]
            |         |
     [ – Bus Bar ] [ Fuse Block ]
                         |
                 → All Loads (USB, Inverter, Lights, PC)

               [ EV Harness ↔ Switchable Feed ]
```

---

## 🔌 Source Priority Logic

| Priority | Input | Controller |
|---------|-------|------------|
| 1️⃣ Solar | MPPT | Auto |
| 2️⃣ Wind | Braked if battery full |
| 3️⃣ Kinetic | Active only while moving |
| 4️⃣ Thermal | Passive trickle |
| ♻️ Manual Override | Toggle switches available for all sources |

> Each input is isolated via diode or charge controller to prevent cross-flow or backfeed.

---

## 🔁 Load Output Zones

| Zone | Description |
|------|-------------|
| Zone A | Core systems (lighting, fan, sensors) |
| Zone B | Inverter loads (AC power, tools, PC) |
| Zone C | EV relay feed (backcharge mode) |
| Zone D | Touch panel / display / automation hub |

All zones fused individually at the fuse block.  
Control switches optionally mapped to GPIO + relays.

---

## 🧪 Diagnostics

| Test | What to Check |
|------|----------------|
| Bus voltage | ~13.4–14.6V when charging |
| Input stats | Each module's output independently |
| Load draw | Via shunt / SmartShunt / monitor |
| EV tap | Toggle backfeed with switch → verify 12V push |

---

## 🧠 Future Upgrade Paths

- Add charge priority controller (Arduino or ESP32)
- Add cloud dashboard for all power sources
- Add isolation relay for full EV integration logic
- Add auto-dump load resistor when wind/speed exceeds battery capacity

---

✅ All power flows now unified.  
The Nest breathes like a living system.  🪔⚡🧠⛯

---

# 🔌 EV Integration Guide: Full Bi-Directional Charging from EmberNest

## 🚗 Overview

EmberNest is not just an off-grid camper—it’s a **renewable-powered mobile EV charger.**  
This guide details how to both:

- 🔋 **Charge your EV** using the Nest’s solar-charged battery + inverter
- 🔁 **Pull emergency power** from your EV into the Nest (bi-directional)

> Your journey fuels itself.  
> EmberNest becomes a node in the electric ecosystem.

---

## ⚡ EmberNest → EV Charging (Level 1)

### How It Works

1. Nest's battery bank stores solar/wind/kinetic energy
2. A **pure sine wave inverter** converts 12V DC → 120V AC
3. EV's **Level 1 charger (EVSE)** plugs into Nest’s AC outlet
4. Vehicle charges slowly—trickle style, perfect overnight

### Required Components

| Component | Spec |
|----------|------|
| Inverter | Pure sine wave, ≥2000W recommended |
| Battery Bank | 12V LiFePO₄, ≥200Ah preferred |
| Solar Input | 300W+ MPPT-recharged array |
| EVSE | Standard Level 1 charger (included with most EVs) |
| GFCI Outlet | Recommended for inverter output |
| Toggle Relay | Manual or Arduino-controlled (optional) |

---

## 🔋 Charge Rates & Runtime

| Battery Bank | Charge Time Supplied |
|--------------|----------------------|
| 100Ah (1.28kWh) | ~1 hour @ 1000W |
| 200Ah (2.56kWh) | ~2 hours |
| 300Ah+ | ~3–5 hours depending on draw |

> 🧠 Tip: Some EVs can “sip” power at lower amperage using software-limited EVSE (6A–8A mode). Use this to stretch runtime.

---

## 🛠️ Installation Notes

- Use **proper gauge wire** (4–0 AWG) from battery → inverter
- Install **100–200A fuse** between battery and inverter
- Ground inverter output safely—chassis bond or isolation transformer
- Use **dedicated switch** for EV charger outlet (prevent parasitic draw)

---

## 🧠 Optional Logic

Add an **Arduino or ESP32** to:

- Detect EVSE plug-in via current sensor
- Automatically enable inverter + outlet relay
- Trigger warning if battery SOC drops too low

---

## 🔄 EV → EmberNest Backup

Many EVs support **12V output** via:

- Accessory port (cigarette lighter)
- OBD-II tap
- Emergency battery pack output

Use a **step-down DC–DC converter** to recharge Nest's battery from the EV when needed.

| Input | Converter | Output |
|-------|-----------|--------|
| 12–14V | DC buck (20A rated) | 13.4V to Nest bus bar |

> ⚠️ Add diode + fuse to prevent Nest backfeed into EV

---

## 🧪 Test Procedure

1. Charge Nest via solar → battery full
2. Plug EVSE into Nest outlet
3. Watch inverter wattage → confirm ~1000W draw
4. Check EV shows “charging”
5. Observe voltage drop and SOC curve on Nest

---

## 🔒 Safety

- Always fuse inverter and EVSE outlet
- Never exceed inverter’s wattage
- Use GFCI outlets for human-safe AC power
- Disable EVSE if Nest SOC < 40% (manual or automatic)

---

## 🚫 Known Limitations

- **Slow**: Level 1 charging is 3–8 km/hr range add
- **Not compatible** with direct DC fast charge
- **Cybertruck specifically not supported** due to incompatible port logic and karma conflict

---

✅ You now walk with power in both directions.  
The Nest is a flame-fed charging station. 🪔🚗⚡⛯

---

# 🎮 Control Panel Assembly: Flame in Your Hands

## 🧭 Overview

This module covers how to build a **DIY control panel** for EmberNest—your tactile interface to command the flame.

Whether you're toggling EV charge, monitoring battery voltage, or lighting up the forest clearing, this panel makes it real, physical, and *fun*.

> The Nest breathes. You steer the flame.

---

## 🔧 Panel Functions

| Zone | Controls |
|------|----------|
| 🔋 Power | Main battery cutoff, solar on/off, inverter toggle |
| 🌬️ Air | Ventilation fans, compost loop fans, HVAC (if present) |
| 🔦 Lighting | Cabin lights, underglow, perimeter LEDs |
| ⚡ EV Mode | Enable charging, monitor draw, toggle outlet |
| 🧠 System | OLED/Touch display, diagnostics, debug port |
| 🔔 Bonus | Horn, speaker, espresso, smoke machine, etc. |

---

## 🧰 Parts & Materials

| Component | Description |
|----------|-------------|
| Enclosure | Laser-cut acrylic, aluminum plate, or 3D-printed faceplate |
| Rocker Switches | 12V DC, LED or backlit |
| Toggle Switches | SPST or SPDT for high-draw loads |
| Pushbuttons | Momentary or latching |
| Rotary Encoder | Optional: brightness, fan speed |
| Digital Voltmeter | Inline battery readout |
| ESP32 or Arduino | For touch UI / logic |
| OLED / TFT Display | Optional: live readout |
| Labels | Engraved, stenciled, or glyphified 🪔 |

---

## 🛠️ Assembly Steps

### Step 1: Layout Your Panel

- Sketch your layout: group functions by zone
- Ensure spacing for fuses, wires, and fingers
- Reserve space for display or USB if using logic

> Tip: Design in cardboard first. Then laser/print the final.

---

### Step 2: Mount Components

- Drill or CNC cut faceplate for each switch
- Mount using locking rings or brackets
- Install fuses + terminal blocks behind panel

---

### Step 3: Wiring

- Use **18–14 AWG** wire for low-voltage runs
- Route switch lines to **relay board** or direct loads
- Label wires! Heatshrink if possible

> ⚠️ FUSE EVERY OUTPUT ZONE.

---

### Step 4: Add Logic (Optional)

- Install **ESP32/Arduino Nano** inside panel enclosure
- Power via fused 12V to buck converter (→ 5V)
- Wire buttons to digital pins
- Output to OLED or serial debug port
- Flash with `/scripts/control_logic.ino`

---

## 🧪 Test Checklist

| System | Method |
|--------|--------|
| Inverter | Toggle → hear fan / check LED |
| Solar | Toggle → MPPT screen wakes |
| Lights | Switch → LED strip toggles |
| EV | Plug → display reads “charging” |
| Debug | Hold 🔧 button → enter diagnostics mode |

---

## 🧠 Touchscreen Option

If using a 2.4" or 3.5" TFT:

- Display voltage, SOC, solar input, EV load
- Tap to enable/disable systems
- Use `/scripts/gui_panel.ino`

> Want gesture control? Add IR sensor or capacitive slider.  
> Want weird? Mount a rotary encoder made of driftwood.

---

## 🧨 Safety

- All live lines fused at source (not just on panel)
- Never mix AC and DC inside same control box
- Add venting or fan if enclosed w/ microcontroller
- Ground logic board GND to system negative

---

✅ The flame is now at your fingertips.  
Command the storm with a switch.  🪔🎮⚡⛯

---

## 📡 Bonus Systems (Optional Modules)

These are **modular upgrades**—not required, but deeply awesome.  
They plug into the same 12V logic and fuse blocks, and enhance functionality, autonomy, and flair.

| Module | Function |
|--------|----------|
| 📶 WiFi Mesh Node | Use ESP32 or GL.iNet router for rural coverage |
| 🔊 Audio System | 12V amp + speakers or hacked Bluetooth unit |
| 🔄 Auto-Rotation Solar | Servo-controlled panel pitch for max efficiency |
| 🌡️ HVAC Hack | Fan-only cooling or DIY Peltier climate ring |
| 🎤 Voice Commands | Via onboard Pi or ESP32 + wake-word module |
| 💡 Smart Light Scenes | LED zones tied to panel switches or time logic |
| 🧭 GPS Tracking | Live location via SIM/GSM board or LoRa beacon |
| 🛰️ Remote Monitor | Web dashboard (NodeRED + MQTT) over hotspot |
| 🔐 Biometric Lock | Fingerprint entry + relay latch for security door |

> All modules route through `/manual/scripts/` logic or custom relay banks.  
> They can be toggled via the 🎮 Control Panel or touchscreen GUI.

---

### 🧰 Sample Config: ESP32 WiFi Mesh Node

- Flash Tasmota or custom ESP32 mesh firmware
- Mount external 2.4GHz antenna or dish
- Broadcast `/nest.local` dashboard from Flask server
- Allow remote voltage/temp monitoring + switch control

---

### 🎶 Bonus Bonus: Audio System Hack

- Recycle 12V car amp
- Route audio from ESP32 or Pi via AUX
- Use MOSFET trigger to auto-power on w/ lights
- Add party mode switch (RGB, bass boost, fog?)

> Nest goes rave. Optional, but… *come on.*

---

## 📶 Wi-Fi Mesh & Remote Dashboard

### Purpose
Allow remote access to Nest’s data (voltage, temperature, GPS, etc.)  
Create a **local access point** in remote regions.

### Components
- GL.iNet Mango or ESP32 w/ mesh firmware
- External Wi-Fi antenna (RP-SMA)
- Optional: Raspberry Pi running Flask + MQTT

### Wiring
- 12V input → Buck converter → 5V Pi or 3.3V ESP
- Powered through relay tied to "System On" switch

### Use Case
- Access `nest.local` via smartphone
- Monitor charge state, trigger relays, check temps

---

## 🔊 Audio System (12V Amp Hack)

### Purpose
Provide ambient sound, alerts, and audio fun

### Components
- 12V car amplifier (15–50W RMS)
- Speakers (weatherproof, cabin or exterior)
- Bluetooth AUX adapter or ESP32 I2S audio out

### Wiring
- Amp powered from 12V fuse block
- Optional: add MOSFET switch or soft-start relay
- Ground audio lines properly to avoid hum

### Use Case
- Ambient music, audiobook playback, solar charge soundscape

---

## 🌡️ Passive HVAC Mod (Fan-Only or Peltier)

### Purpose
Improve internal airflow, remove heat from battery bank

### Components
- 12V brushless fans (80mm+)
- Peltier modules (if desired)
- Aluminum heatsinks
- Thermostat or microcontroller PWM driver

### Wiring
- Fan lines routed via SPST switch or ESP32 PWM pin
- Peltier powered via dedicated fused line w/ MOSFET

### Use Case
- Cool sleeping area or equipment bay
- Auto-venting at temp threshold

---

## 🛰️ GPS Beacon & Anti-Theft Locator

### Purpose
Track EmberNest’s location if stolen or lost

### Components
- GPS module (u-blox or NEO-6M)
- GSM/SIM card module (SIM800L)
- Microcontroller (ESP32 or Pi Pico)

### Wiring
- Powered off 5V buck from 12V input
- Keep power always-on via dedicated micro UPS (optional)

### Use Case
- Sends text location via SMS every 4 hrs
- Integrates with `/scripts/gps_ping.ino`

---

## 🔐 Biometric Lock

### Purpose
Secure entry while keeping it hacker-class cool

### Components
- Fingerprint sensor module (GT-521F52 or R305)
- Microcontroller (ESP32 or Pi Pico)
- Electronic door latch or solenoid

### Wiring
- Lock powered via relay from logic pin
- Fingerprint scan triggers `digitalWrite(OPEN)` on match

### Use Case
- Fingerprint-based door unlock
- Could also be RFID or PIN pad if preferred

---

## 🧑‍🔧 Power Monitoring OLED

### Purpose
Compact readout of current system status

### Components
- 0.96" I²C OLED (SSD1306)
- ESP32 microcontroller
- Voltage/current sensors (INA219, ACS712)

### Display Options
- Voltage + SOC %
- Inverter status
- Solar input rate
- Battery temp

> Mounted directly into control panel or top edge of inverter housing

---

✅ All modules route cleanly into 12V fuse and logic systems.  
They’re optional—but once you install one, you’ll want them all.

---

## 🛠️ Maintenance & Emergency Access

Even the best-designed system needs upkeep—and in off-grid conditions, failure is not just inconvenient, it’s dangerous.

This section ensures **you can inspect, fix, or bypass any subsystem** in the EmberNest with no tools beyond a screwdriver and multimeter.

---

### 🔋 Battery Maintenance

- Check terminals monthly for corrosion
- Confirm no swelling or bulging on LiFePO₄ cells
- Use a battery monitor (e.g., SmartShunt) for ongoing SOC tracking
- Replace in matched pairs if degraded

### 🧲 Fuse Box Access

- Fuse block should be surface-mounted near control panel
- Clearly label all fuses by load
- Keep spare fuses of each amp rating on board (10A, 20A, 40A)
- Use inline fuses for any added peripherals

### 🔌 Inverter & AC Safety

- Inverter should have physical on/off switch
- Mount in a ventilated, dry location
- Use GFCI outlet for AC output
- Shut down immediately if it hums, clicks, or gets hot

### 🌞 Solar Panel Inspection

- Wipe panels monthly for dust or pine resin
- Check MC4 connections annually for corrosion
- Inspect Z-bracket bolts after rough roads

### 🌬️ Wind Turbine

- Check brake toggle before highway speeds
- Inspect blade tightness after every 200 km of travel
- Clean with water only—never oil the hub

### 🧪 System Diagnostic Routine (Monthly)

1. Disconnect shore or EV power
2. Run inverter on full load for 10 minutes
3. Confirm SOC drop matches draw
4. Run lights, pump, and vent fans together
5. Test each toggle + button on control panel
6. Trigger relays manually if logic board is installed
7. Check voltage at:
   - Battery terminals
   - Inverter input
   - Bus bar output
   - Each fuse line

---

### ⚠️ Emergency Bypass Tips

| Problem | Fix |
|--------|-----|
| Inverter fails | Use 12V USB + lights directly |
| Main relay stuck | Jumper bypass with inline fuse |
| Logic board glitch | Manual switch takes over |
| Fuse blown | Replace, test draw, re-enable |
| No solar | Activate wind or kinetic fallback |
| All power lost | Use EV-to-Nest jumper feed (see EV Integration) |

---

### 🔐 Hidden Tools Compartment (Recommended)

Include:

- Multimeter
- Extra fuses + terminals
- Mini screwdriver + driver bits
- Zip ties + shrink tube
- Diode jumper leads
- Manual wiring printout

> Bonus: hide it under a false panel, magnet-latch style

---

✅ With this, the Nest is not just mobile—it’s **maintainable**.  
No panic. No flashlight in the rain. You’re ready.  🛠️⛯

---

## 🧪 Final Testing & Pre-Departure Checklist

Before your EmberNest hits the open road, this section ensures all systems are safe, functional, and integrated. Think of it as your final calibration and proof-of-life test.

> Do this once at install—and every season after.

---

### 🔋 Power System Tests

**DC Power Check**

- ✅ Battery voltage ≥ 13.0V
- ✅ Inverter idle draw ≤ 1.5A
- ✅ Solar controller registers current input
- ✅ Load outputs read ~12.5–13.6V on multimeter

**Inverter + AC**

- ✅ Power on inverter
- ✅ Plug in 120V test load (lamp, fan)
- ✅ Confirm proper startup, no overload fault
- ✅ GFCI protection works (test button)

---

### ⚡ Load & Circuit Check

| System | Confirm |
|--------|--------|
| Lights | All zones toggle from panel |
| Fans | Respond to switches or logic |
| EV Charge | EVSE shows “charging” when plugged into inverter |
| Water Pump | Activates from switch or logic |
| USB Ports | Deliver 5V under load |
| Display/ESP | Boot, display voltage, log to serial if configured |

---

### 📶 Communication (if installed)

- Connect to Wi-Fi AP (`nest.local` or `192.168.x.x`)
- Open dashboard or run serial logs
- Trigger relays remotely (if enabled)
- Send dummy GPS data or check beacon pings

---

### 🔁 Redundancy Check

- Test alternate charge sources: wind / kinetic / EV
- Disable solar (shade or toggle) → confirm fallback kicks in
- Power Nest from EV backup feed (manual jumper)

---

### 🔒 Safety Confirmation

- Every circuit fused? (Visually inspect fuse block)
- AC outlets GFCI protected?
- Battery terminals protected from arc/contact?
- All enclosures weather-sealed?
- Backup fire extinguisher on board?

---

### 🧪 Road Simulation (Optional)

- Drive with fans + solar active
- Test vibration tolerance of wiring and mounts
- Monitor inverter temp / battery sag under load
- Park for 24 hours on solar-only to confirm recharge logic

---

## ✅ You're Cleared for Journey

If you’ve reached this point with zero failures:  
🟢 **EmberNest is functional, resilient, and road-ready.** 🪔🌍🚐⛯

---

EmberNest lives. 🪔🛻⛯
