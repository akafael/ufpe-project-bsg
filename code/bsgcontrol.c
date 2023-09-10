#include "bsgcontrol.h"
#include "calibration.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery) {

   const bool isVehicleStopped = vehicle.velocity == 0;
   const bool isEngineStopped = engine.rpm == 0;
   const bool isEngineRunning = engine.rpm > EngineRPMNeutral;
   const bool isBatteryCharged = battery.voltage > BatteryMinVoltage;
   const bool isBrakingPedalPressed = vehicle.angleBrakePedal > 5;
   const bool isThrottlePedalPressed = vehicle.angleAccPedal > 5;
   const bool isTorqueAssistanceRequired = isThrottlePedalPressed && vehicle.velocity > VehicleMinVelocity;

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
   //BSG_MOTOR - Torque Assistance
   if(isTorqueAssistanceRequired)
   {
      return BSG_MOTOR;
   }
  
   return BSG_IDLE;
}
