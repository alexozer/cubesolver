#include "core.h"

void sune() {
  twist(1,1);  // R
  twist(5,1);  // U
  twist(1,3);  // R'
  twist(5,1);  // U
  twist(1,1);  // R
  twist(5,2);  // U2
  twist(1,3);  // R'
}

void antiSune() {
  twist(1,1);  // R
  twist(5,2);  // U2
  twist(1,3);  // R'
  twist(5,3);  // U'
  twist(1,1);  // R
  twist(5,3);  // U'
  twist(1,3);  // R'
}

void tPerm() {
  twist(1,1);  // R
  twist(5,1);  // U
  twist(1,3);  // R'
  twist(5,3);  // U'
  twist(1,3);  // R'
  twist(0,1);  // F
  twist(1,2);  // R2
  twist(5,3);  // U'
  twist(1,3);  // R'
  twist(5,3);  // U'
  twist(1,1);  // R
  twist(5,1);  // U
  twist(1,3);  // R'
  twist(0,3);  // F'
}

void clockwiseCornerCycle() {
  twist(3,3);  // L'
  twist(5,1);  // U
  twist(1,1);  // R
  twist(5,3);  // U'
  twist(3,1);  // L
  twist(5,1);  // U
  twist(1,3);  // R'
  twist(5,3);  // U'
}

void counterClockwiseCornerCycle() {    // Talk about long method names...
  twist(5,1);  // U
  twist(1,1);  // R
  twist(5,3);  // U'
  twist(3,3);  // L'
  twist(5,1);  // U
  twist(1,3);  // R'
  twist(5,3);  // U'
  twist(3,1);  // L
}

void orientCorner() {    // Orients corner in position 4
  for(int a = 0; a < 2; a++) {  // Repeat twice
    twist(1,3);  // R'
    twist(4,3);  // D'
    twist(1,1);  // R
    twist(4,1);  // D
  }
}

void inverseOrientCorner() { // Orients corner in position 4
  for(int a = 0; a < 2; a++) {  // Repeat twice
  twist(4,3);  // D'
  twist(1,3);  // R'
  twist(4,1);  // D
  twist(1,1);  // R
  }
}
