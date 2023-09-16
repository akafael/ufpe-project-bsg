#include "bsgcontrol.h"
#include "calibration.h"

StateBSG selectBSGMode(const Vehicle vehicle, const Engine engine, const BSG bsg,
                       const Battery battery) {

   // BSG_STARTER - Car Starter
   if (getBatteryState(battery) == BATTERY_OPERATIONAL && getEngineState(engine) == ENGINE_OFF && vehicle.requestCarStart) {
    
      return BSG_STARTER;
   }

   // BSG_GENERATOR - Regenerative Breaking
   if (getDriverIntention(vehicle) == DRIVE_INTENTION_REDUCE_SPEED && getEngineState(engine) != ENGINE_OFF ) {
      
      return BSG_GENERATOR;
   }

   //BSG_MOTOR - Torque Assistance
   if (getDriverIntention(vehicle) == DRIVE_INTENTION_INCREASE_SPEED && getEngineState(engine) == ENGINE_WORKING && getBatteryState(battery) != BATTERY_DEAD) {
      return BSG_MOTOR; 
   }
  
   return BSG_IDLE;
}
