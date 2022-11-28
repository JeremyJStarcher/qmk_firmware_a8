"use strict";


//const LIMITED_ITEMS = [201, 208, 225, 241, 257, 266, 226, 242, 210, 258, 266];

const LIMITED_ITEMS = [264];
const DO_ALL_ITEMS = false;

const DO_MOVE_SWITCH = false;
const DO_MOVE_DIODE = false;
const DO_MOVE_MOUNT_HOLE = false;
const DO_SWITCH_FRONT_SILK = false;
const DO_SWITCH_REAR_SILK = false;
const DO_SWITCH_REAR_BBOX = false;
const DO_BOARD_BBOX = true;

// Sometimes, for the text insert, the MIRROR option gets stuck on.
const TEXT_MIRROR_SET = false

const STARTING_INDEX = 201;

const BOARD_BORDER = 10;

const X_ORIG = 61;
const Y_ORIG = 177.75;

const LAYER_FRONTSILK = 6;
const LAYER_BACKSILK = 7;
const LAYER_EDGECUT = 14;

const UNIT = 19.05;
 
const fs = require('fs');
  
const data = fs.readFileSync('../info.json', {encoding:'utf8', flag:'r'});
const d1 = JSON.parse(data);
    
let layout = d1.layouts.LAYOUT.layout;

// How much to move the diodes
const offset_x = 6.5;
const offset_y = 5.52; 

const bbox = {
  x1: Number.MAX_VALUE,
  y1: Number.MAX_VALUE,
  x2: Number.MIN_VALUE,
  y2: Number.MIN_VALUE,
}

layout.forEach(key => {
  //  console.log(key);

    key.w = key.w || 1;
    key.h = key.h || 1;

    // The keyboard config measures a key position from the top left corner
    // and KiCad measures from the center of the key
    let x = (key.x + (key.w /2)) * UNIT;
    let y = (key.y + (key.h /2)) * UNIT;

    x += X_ORIG;
    y += Y_ORIG;

    key.kx = x; // .toFixed(2);
    key.ky = y; //.toFixed(2);


    key.dx = x + offset_x; // .toFixed(2);
    key.dy = y + offset_y; // .toFixed(2);

    {
        /* Calculate the bounding box */

        // The measured difference between the pin 1
        // (the key origin) and the top edge of the 
        // box.  (Measured by hand)
        const KEYSWITCH_FIX_X = -11.565;
        const KEYSWITCH_FIX_Y = -3.946;

        const ww = (key.w-1) * UNIT;
        const hh = (key.h-1) * UNIT;


        let x1 = (key.kx - key.w/2) - ww/2 + KEYSWITCH_FIX_X ;
        let y1 = (key.ky - key.h/2) - hh /2 + KEYSWITCH_FIX_Y;
        let x2 = x1 + UNIT + ww;
        let y2 = y1 + UNIT + hh;

        // The math for figuring out the actual bounding box is off, so manually correct for
        // various key sizes.  (By hand/trial and error)
        let xfix = 0;
        if (key.w === 1) {
          xfix = 0;
        }
        if (key.w === 1.25) {
          xfix = 0.125;
        }
        if (key.w === 1.75) {
          xfix = 0.375;
        }
        if (key.w === 2) {
          xfix = .5;
        }
        if (key.w === 2.25) {
          xfix = .625;
        }
        if (key.w === 6.25) {
          xfix = 2.625;
        }
        x1 += xfix;
        x2 += xfix;

        if (key.x !== -1 && key.y !== -1) {
          bbox.x1 = Math.min(x1, bbox.x1);
          bbox.y1 = Math.min(y1, bbox.y1);

          bbox.x2 = Math.max(x2, bbox.x2);
          bbox.y2 = Math.max(y2, bbox.y2);
        }

        key.bb_x1 = x1;
        key.bb_y1 = y1;
        key.bb_x2 = x2;
        key.bb_y2 = y2;
    }
})



layout.sort((a, b) => {
    if (a.y < b.y) {
        return -1;
    }

    if (a.y > b.y) {
        return +1;
    }

       if (a.x < b.x) {
           return -1;
      }

    return 1;
})


const out = [];

function repeat(qty, cmd) {
  for(let i = 0; i < qty; i+=1) {
    out.push(cmd);
  }
}

function click() {
  out.push(`xdotool keydown Pointer_Button1 keyup Pointer_Button1`);
}

function clickat(x, y) {
  out.push(`xdotool mousemove ${x} ${y} keydown Pointer_Button1 keyup Pointer_Button1`);
}

function addKeyLabel() {
  out.push("# ADD LABEL")
  out.push(`xdotool key e`);
  clickat(570, 500);
}

function findItem(prefix, id) {
  out.push("# FIND THE DESIRED KEY")
  out.push(`xdotool key ctrl+f sleep 0.3 type ${prefix}${id}`)
  out.push(`sleep 1`);
  out.push(`xdotool key Return`)
  out.push(`sleep 1`);
  out.push(`xdotool key Escape`)
  out.push(`sleep 2`);
}

function placeItem(x, y) {
  out.push("# Activate edit mode")
  out.push(`xdotool key e`)
  out.push(`sleep 3`);
  out.push(`xdotool key Tab sleep 0.3 key Tab`);
  out.push(`xdotool type ${x}`); 
  out.push(`xdotool sleep 0.3 key Tab`);
  out.push(`xdotool type ${y}`); 
  out.push(`xdotool sleep 0.3 key Return`);
  out.push(`sleep 1`);
}

function rotateItem(deg) {
  out.push("# Activate edit mode")
  out.push(`xdotool key e`)
  out.push(`sleep 3`);
  out.push(`xdotool key Tab sleep 0.3 key Tab`);
  out.push(`xdotool key Tab sleep 0.3 key Tab`);
  out.push(`xdotool key Tab sleep 0.3`);
  out.push(`xdotool type ${deg}`); 
  out.push(`xdotool sleep 0.3 key Return`);
  out.push(`sleep 1`);
}


function selectLayer(layer) {
  repeat(20, `xdotool key Up`) ; // top of list)
  out.push("sleep 1");
  repeat(layer, `xdotool key Down`) ; // Go to front silk screen
  out.push("sleep 1");
}

function placeText(x, y, text, layer) {

  /* Can't reach the "mirrored" checkbox on the
     text tool, so we will put the text on the back
     of the board, then use the 'flip' command to
     move it forward. */

  out.push("# Activate edit mode")
  out.push(`xdotool key ctrl+shift+t`)
  out.push("sleep 3");
  out.push(`xdotool type "${text}"`); 
  out.push("sleep 1");
  out.push(`xdotool key ctrl+Tab sleep 0.5 key Return`);
  out.push("sleep 1");
  out.push(`xdotool key Return`);

  out.push("sleep 1")

  out.push(`xdotool key e sleep 3 key ctrl+Tab`); // escape the box
  // out.push(`xdotool key space`) ; // Lock
  // out.push(`xdotool key space`) ; // UnLock
  out.push(`xdotool key Tab`) ; // layer field
  
  if (TEXT_MIRROR_SET) {
    selectLayer(LAYER_BACKSILK);
  } else {
    selectLayer(LAYER_FRONTSILK);
  }
  out.push("sleep 1")

  for(let i = 0; i < 4; i++) {
    out.push(`xdotool key Tab`) ; // Get to right item
  }

  out.push(`xdotool type ${x-2}`) ; // x position
  out.push("sleep 1")
  out.push(`xdotool key Tab`) ; // Move to Y
  out.push(`xdotool type ${y+13}`) ; // Y Position
  out.push("sleep 1")

  out.push(`xdotool key ctrl+Return`) ; // Save window
  out.push("sleep 1")

  if ((layer === LAYER_FRONTSILK && TEXT_MIRROR_SET) || (layer === LAYER_BACKSILK && !TEXT_MIRROR_SET))  {
     out.push(`xdotool key f`) ; // Flip the silkscreen to the front.
     out.push("sleep 1")
  }
}


function drawRect(x1, y1, x2, y2, layer) {
  out.push(`xdotool key alt+p`); // Open menu
  out.push("sleep 1");

  repeat(8, `xdotool key Down`) ; // Go to right menu item
  out.push(`xdotool key Return`) ; // Select
  out.push("sleep 1");
  out.push(`xdotool key Return`) ; // Place the rect
  out.push("sleep 1")
  
  out.push(`xdotool key e`) ; // edit properties

  out.push("sleep 1")
  
  out.push(`xdotool type ${x1}`) ; 
  out.push(`xdotool key Tab`) ; // Select
  out.push(`xdotool type ${y1}`) ; 
  out.push(`xdotool key Tab`) ; // Select
  out.push(`xdotool type ${x2}`) ; 
  out.push(`xdotool key Tab`) ; // Select
  out.push(`xdotool type ${y2}`) ; 
 
  repeat(5, `xdotool key Tab`) ; // go to the layer selection

  out.push("sleep 1");

  selectLayer(layer);

  out.push("sleep 1");

  out.push(`xdotool key Tab`) ; // Next field

  out.push("sleep 1");

  out.push(`xdotool key Return`) ; // Select

  out.push("sleep 1");

  // Ok, this is a dumb thing to get us out of that rectangle
  // so it is fixed and a new one is created next time.
  out.push(`xdotool key ctrl+shift+t`)
  out.push("sleep 1");
  out.push(`xdotool key Escape`);
  out.push("sleep 1");
}

out.push("#!/bin/sh");
out.push("WIN_ID=`xdotool search --name 'PCB Editor'`")
out.push("xdotool windowactivate $WIN_ID")
out.push("sleep 1")
out.push("xdotool windowactivate $WIN_ID")

// FIlter out things not on the grid itself
layout = layout.filter(l => l.x !== -1);



function processAll(startingIndex) {
  let idx = startingIndex;

  for (let xx = 0; xx < 100; xx+=1) {
    for (let yy = 0; yy < 100; yy += 1) {
      const items = layout.filter(key => key.matrix[0] === xx && key.matrix[1] === yy);
      if (items.length > 0) {
  
        const item = items[0];
  
        if (LIMITED_ITEMS.includes(idx) || DO_ALL_ITEMS) {
          if (DO_MOVE_SWITCH) {
            findItem("SW", idx);
            placeItem(item.kx, item.ky);
          }
  
          if (DO_MOVE_DIODE) {
            findItem("D", idx);
            placeItem(item.dx, item.dy);
            rotateItem(90 + 180);
          }

          if (DO_MOVE_MOUNT_HOLE) {
            findItem("H", idx);
            if (true) {

              let extra_x = 0;
              let extra_y = 0;
              if (idx == 240) {
                extra_x = 3;
              }

              if (idx == 264) {
                extra_y = 3;
              }

              if (idx == 257) {
                extra_y = 3;
              }

              placeItem(item.bb_x1 + extra_x, item.bb_y1 +2 + extra_y);
              out.push(`xdotool key f`) ; // Flip the silkscreen to the back
            } else {
              out.push(`xdotool key Delete`) ; // Blow it away
            }
          }
  
          if (DO_SWITCH_FRONT_SILK) {
            placeText(item.kx, item.ky, item.label, LAYER_FRONTSILK);
          }
  
          if (DO_SWITCH_REAR_SILK) {
            placeText(item.kx, item.ky, item.label, LAYER_BACKSILK);
          }
  
          if (DO_SWITCH_REAR_BBOX) {
            drawRect(
              item.bb_x1,
              item.bb_y1,
              item.bb_x2,
              item.bb_y2,
              LAYER_BACKSILK
            );
          }
        }
  
        idx +=1;
      }
    }
  }
  
}

processAll(STARTING_INDEX);


if (DO_BOARD_BBOX) {

  const MOUNT_HOLE_OFFSET = 5;

  const mh_x1 = bbox.x1 - BOARD_BORDER + MOUNT_HOLE_OFFSET;
  const mh_y1 = bbox.y1 - BOARD_BORDER + MOUNT_HOLE_OFFSET;
  const mh_x2 = bbox.x2 + BOARD_BORDER - MOUNT_HOLE_OFFSET;
  const mh_y2 = bbox.y2 + BOARD_BORDER - MOUNT_HOLE_OFFSET;

  findItem("H", 101);
  placeItem(mh_x1, mh_y1);

  findItem("H", 102);
  placeItem(mh_x2, mh_y1);

  findItem("H", 103);
  placeItem(mh_x2, mh_y2);

  findItem("H", 104);
  placeItem(mh_x1, mh_y2);

  drawRect(
    bbox.x1 - BOARD_BORDER,
    bbox.y1 - BOARD_BORDER,
    bbox.x2 + BOARD_BORDER,
    bbox.y2 + BOARD_BORDER,
    LAYER_EDGECUT
  );

}

/*

layout.forEach(key => {
  //console.log(key);
  console.log(key.matrix);
  const id = (key.matrix[0] * 9) + key.matrix[1] + 201;   

  console.log(id);
  findItem("SW", id);
  placeItem(key.kx, key.ky);
})
*/

out.push("espeak 'Layout complete.'");

fs.writeFileSync("auto_it.sh", out.join("\n"));