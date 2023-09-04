#include <stdio.h>
#include "bsg.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg, Battery battery) {
  if (vehicle.angleAccPedal>70) {
    return BSG_STARTER;
  };
  if (vehicle.velocity == 0) {
      return BSG_IDLE;
  };
  if (vehicle.requestCarStart != 0) {
      return BSG_STARTER;
  };
  if (vehicle.angleBrakePedal > 0) {
      return BSG_GENERATOR;
  };
  if (battery.voltage < 30) {
      return BSG_IDLE;
  };
  if (battery.current > 100) {
      return BSG_IDLE;
  };
  return BSG_IDLE;
}
