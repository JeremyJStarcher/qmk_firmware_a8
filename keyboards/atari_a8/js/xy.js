"use strict";

const X_ORIG = 61;
const Y_ORIG = 177.75;


const UNIT = 19.05;

// Node.js program to demonstrate the 
// fs.readFileSync() method
 
// Include fs module
const fs = require('fs');
  
// Calling the readFileSync() method
// to read 'input.txt' file
const data = fs.readFileSync('../info.json',
            {encoding:'utf8', flag:'r'});
 
const d1 = JSON.parse(data);
    
let layout = d1.layouts.LAYOUT.layout;

// How much to move the diodes
const offset_x = 163.3487 - 156.21;
const offset_y = 196.2 - 186.68; 

layout.forEach(key => {
  //  console.log(key);
  // The keyboard layout editor and kicad have a different idea of what a key's position is.
  // this causes keys that are longer then 1 unit to "slide" to the left, relative to the size of the key

    const slide = 4/8;

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

layout.forEach(key => {
  //  console.log(`"${key.label}", ${key.kx}, ${key.ky}, ${key.rx}, ${key.ry}`);
  //  console.log(`"${key.label}", ${key.y}, ${key.x}`);
})
// Display the file data
// console.log(layout);


const out = [];

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
  out.push(`sleep 1`);
}

function placeItem(x, y) {
  out.push("# Activate edit mode")
  out.push(`xdotool key e`)
  out.push(`sleep 1`);
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
  out.push(`sleep 1`);
  out.push(`xdotool key Tab sleep 0.3 key Tab`);
  out.push(`xdotool key Tab sleep 0.3 key Tab`);
  out.push(`xdotool key Tab sleep 0.3`);
  out.push(`xdotool type ${deg}`); 
  out.push(`xdotool sleep 0.3 key Return`);
  out.push(`sleep 1`);
}

function selectFrontSilkScreen() {
  for(let i = 0; i < 20; i++) {
    out.push(`xdotool key Up`) ; // top of list
  }


  out.push("sleep 1");

  for(let i = 0; i < 6; i++) {
    out.push(`xdotool key Down`) ; // Get to right item
  }

}

function placeText(x, y, text) {
  out.push("# Activate edit mode")
  out.push(`xdotool key ctrl+shift+t`)
  out.push("sleep 1");
  out.push(`xdotool type "${text}"`); 
  out.push(`xdotool key ctrl+Tab key Return`);
  out.push("sleep 1");
  out.push(`xdotool key Return`);

  out.push(`xdotool key e sleep .5 key ctrl+Tab`); // escape the box
  out.push(`xdotool key space`) ; // Lock
  out.push(`xdotool key space`) ; // UnLock
  out.push(`xdotool key Tab`) ; // layer field
  
  selectFrontSilkScreen();

  for(let i = 0; i < 4; i++) {
    out.push(`xdotool key Tab`) ; // Get to right item
  }

  out.push(`xdotool type ${x-2}`) ; // x position
  out.push(`xdotool key Tab`) ; // Move to Y
  out.push(`xdotool type ${y+13}`) ; // Y Position

  out.push(`xdotool key ctrl+Return`) ; // Save window
}


out.push("#!/bin/sh");
out.push("WIN_ID=`xdotool search --name 'PCB Editor'`")
out.push("xdotool windowactivate $WIN_ID")
out.push("sleep 1")
out.push("xdotool windowactivate $WIN_ID")

// FIlter out things not on the grid itself
layout = layout.filter(l => l.x !== -1);

// layout.length = 10;


let idx = 201;

const doThese = [201, 208, 225, 241, 257, 266, 226, 242, 210, 258];

for (let xx = 0; xx < 100; xx+=1) {
  for (let yy = 0; yy < 100; yy += 1) {
    const items = layout.filter(key => key.matrix[0] === xx && key.matrix[1] === yy);
    if (items.length > 0) {

      const item = items[0];

      if (doThese.includes(idx) || false) {
        findItem("SW", idx);
        placeItem(item.kx, item.ky);
    
        if (true) {
          findItem("D", idx);
          placeItem(item.dx, item.dy);
          rotateItem(90);
        }
      //  placeText(item.kx, item.ky, item.label);

      }

      idx +=1;
    }
  }
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