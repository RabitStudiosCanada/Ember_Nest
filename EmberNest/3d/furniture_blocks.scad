// 🔥 EmberNest Furniture Blocks – Parametric OpenSCAD Module
// Path: /3d/furniture_blocks.scad
// Version: v0.2a
// License: OpenFlame (CC BY 4.0 + Symbolic Rider)
// Usage: Load into OpenSCAD or compatible 3D param tool

///////////////////////////
// ⚙️ Configurable Params //
///////////////////////////

unit_thickness = 1.8;        // cm, board/panel thickness
seat_height    = 40;         // cm
seat_depth     = 40;
seat_width     = 60;

block_width    = 30;
block_height   = 30;
block_depth    = 30;

$fn = 30; // smooth edges

/////////////////////
// 🪑 Fold-Flat Bench
/////////////////////

module fold_flat_bench() {
    difference() {
        cube([seat_width, seat_depth, seat_height]);
        translate([5, 5, 5])
            cube([seat_width - 10, seat_depth - 10, seat_height - 10]);
    }
    // optional: add under-storage
    translate([0, 0, -unit_thickness])
        cube([seat_width, seat_depth, unit_thickness]); // base lip
}

/////////////////////////
// 📦 Modular Storage Block
/////////////////////////

module storage_block() {
    difference() {
        cube([block_width, block_depth, block_height]);
        translate([1.5, 1.5, 1.5])
            cube([block_width - 3, block_depth - 3, block_height - 3]);
    }
    // magnetic feet mounts
    for (x=[0, block_width-2])
      for (y=[0, block_depth-2])
        translate([x, y, 0])
          cylinder(h=1.5, r=0.5);
}

///////////////////////////////
// ✨ Ritual Drawer (Optional)
///////////////////////////////

module ritual_drawer(width=20, depth=30, height=10) {
    color("crimson")
    difference() {
        cube([width, depth, height]);
        translate([1, 1, 1])
            cube([width - 2, depth - 2, height - 2]);
    }
}

///////////////////////////////
// 🔧 Preview Assembly
///////////////////////////////

translate([0, 0, 0]) fold_flat_bench();
translate([70, 0, 0]) storage_block();
translate([110, 0, 0]) ritual_drawer();

