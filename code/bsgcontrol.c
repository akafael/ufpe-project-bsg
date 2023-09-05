#include "bsgcontrol.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery) {

const bool isVehicleStopped = vehicle.velocity == 0;
const bool isEngineStopped = engine.rpm == 0;
const bool isEngineRunning = engine.rpm > 1000;
const bool isBatteryCharged = battery.voltage > 10;
const bool isBrakingPedalPressed = vehicle.angleBrakePedal > 5;
const bool isThrottlePedalPressed = vehicle.angleAccPedal > 5;

 if ( isBatteryCharged && isEngineStopped && vehicle.requestCarStart )
 {
    return BSG_STARTER;
 }

 if( isBrakingPedalPressed && isEngineRunning )
 {
   return BSG_GENERATOR;
 }

  return BSG_INDLE;
}
