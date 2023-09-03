#include "bsg.h"
#include <stdio.h>

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery) {
  return BSG_INDLE;
}

uint16_t sum(uint16_t a, uint16_t b) { return a + b; }