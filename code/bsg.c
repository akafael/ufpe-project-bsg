#include <stdio.h>
#include "bsg.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg, Battery battery) {
   if (vehicle.requestCarStart != 0) {
      return BSG_STARTER;
  };
  if (vehicle.velocity == 0) {
    return BSG_IDLE;
  };
  if (vehicle.angleBrakePedal > 0) {
      return BSG_GENERATOR;
  };
  if (vehicle.angleBrakePedal == 0){
    return BSG_STARTER;
  }
  if (battery.voltage >= 0) {
      return BSG_STARTER;
  };
  if (battery.current >= 0) {
      return BSG_STARTER;
  };
  return BSG_STARTER;
}
