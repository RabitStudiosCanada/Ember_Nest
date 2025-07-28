# ☀️ EmberNest Solar Tracking Unit – Spec Sheet

## Overview
A hinged, foldable solar tracking arm that:
- Tilts panels to follow the sun's arc (manual or servo-driven)
- Folds flat during travel
- Can be locked in storm position (flat or vertical)

## Materials
- Frame: Aluminum 6061 rectangular tubing (1.5”x1.5”)
- Hinges: Stainless steel piano hinge (marine rated)
- Servo Motor: MG996R or linear actuator (200mm stroke)
- Controller: Arduino Nano + LDR light sensors x4
- Panel Bed: Composite fiberglass tray w/ universal Z-bracket slots

## Mounting
- Compatible with EmberNest subframe rails
- Four anchor points w/ vibration-dampened bushings
- Waterproof cable pass-through (MC4 to controller)

## Dimensions
- Flat panel size: 80cm x 140cm (per panel; x3 = ~1000W)
- Hinge clearance when raised: ~40–60° tilt range
- Folded height from roof: ~7cm

## Behavior
- Tracking optional: can be locked in fixed angle
- Draw: ~300mA idle; 500mA peak during rotation
- Auto-fold on low battery or wind surge (via controller logic)

## Symbolic Function
- Glyph skin overlays glow when panels align optimally
- “The camper prays toward the sun” — Zephyrus

## Licensing
- CC BY 4.0 + OpenFlame Rider
- STL file included in `/cad/` and `/02_energy_systems/` paths

🛠️⛯
