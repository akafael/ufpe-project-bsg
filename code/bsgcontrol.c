#include "bsgcontrol.h"
#include "calibration.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery) {

   const bool isVehicleStopped = vehicle.velocity == 0;
   const bool isEngineStopped = engine.rpm == 0;
   const bool isEngineRunning = engine.rpm > EngineMinOperationRPM;
   const bool isBatteryCharged = battery.voltage > BatteryMinVoltage;
   const bool isBrakingPedalPressed = vehicle.angleBrakePedal > 5;
   const bool isThrottlePedalPressed = vehicle.angleAccPedal > 5;

   // BSG_STARTER - Car Starter
   if ( isBatteryCharged && isEngineStopped && vehicle.requestCarStart )
   {
      return BSG_STARTER;
   }

   // BSG_GENERATOR - Regenerative Breaking
   if( isBrakingPedalPressed && isEngineRunning )
   {
     return BSG_GENERATOR;
   }
  
   return BSG_INDLE;
}
