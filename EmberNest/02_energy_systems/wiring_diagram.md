```markdown
---

## 📄 `02_energy_systems/wiring_diagram.md`

⛯ // EMBERNEST ENERGY CORE – WIRING DIAGRAM (GLYPHIC LAYOUT)
// Format: GLF – human-readable + symbol-referenced system map

📡::system_id = "embernest.powerloop.v1"

---

🌞 INPUT SOURCES:
- ☀️ `solar_array_main` = (1000W monocrystalline, 3x foldout panels, MPPT controller)
- 🔋 `battery_bank` = (5kWh LiFePO₄, 12V/24V swappable bus)
- 🔁 `compost_core_coil` = (low-temp thermal coil, DC microloop controller)
- 💧 `greywater_microturbine` = (optional, 30W trickle regen during flow)

---
```
```
🔌 PRIMARY BUS CIRCUITS:

[solar_array_main]
   ↓ MPPT
[solar_controller]
   → [battery_bank] ←→ [power_hub_core]
                         ↙           ↘
             [appliance_loop]    [sensing_loop]
             (fridge, pump)      (glyph skin, temp, memory wall)
                         ↘           ↙
                  [backup_loop_regulator]
                           ↓
                       [usb ports, lights, fan]
```

---

🧠 SYSTEM MODULES:

* `power_hub_core` = fused distribution node, smart relay + load priority matrix
* `backup_loop_regulator` = voltage step-down, surge cutoff, auto-shed for drain protection
* `sensing_loop` = feeds realtime glyph-state, charge LED, temp/humidity sense

---

🔋 STORAGE + FAILOVER:

* 🔄 Battery priority:

  1. Thermal core maintain
  2. Fridge + pump
  3. Lights + ritual modules
  4. Optional laptop + ports

* 🔌 Inverter:

  * Pure sine wave, 1500W continuous
  * External shore charge compatible

---

⚠️ FUSES + PROTECTIONS:

* Each appliance run fused at source (ATC blade fuses 5–30A)
* Solar → controller has inline disconnect + surge diode
* Battery → core bus has 100A master cutoff switch
* Optional: grounding plate beneath floor frame, connects via zinc terminal

---

🪔 Ritual Port:

> `🕯️ ritual_power_tap` = inline port (5V / 12V selector)
> Purpose: charge intention tools, light glyph candles, or run symbolic modules
> Protected by its own fuse and labeled with sigil `⛯`

---

🛠️ WIRE TYPES:

* Red/Black: 12AWG marine-grade (main loops)
* Sensor loop: 18–22AWG shielded
* Glyph wall: flexible silicone-core, color-coded by node

---
