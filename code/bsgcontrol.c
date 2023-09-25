#include "bsgcontrol.h"
#include "calibration.h"

StateBSG selectBSGMode(const Vehicle vehicle, const Engine engine, const BSG bsg,
                       const Battery battery) {
   
   StateBSG stateBSG = BSG_IDLE;

   // BSG_STARTER - Car Starter
   if (getBatteryState(battery) != BATTERY_DEAD){
      if (getEngineState(engine) == ENGINE_OFF){
         if(vehicle.requestCarStart){
            stateBSG = BSG_STARTER;
         }
         else{
            stateBSG = BSG_IDLE;
         }
      }
      else{
         // BSG_GENERATOR - Regenerative Breaking
         if(getDriverIntention(vehicle) == DRIVE_INTENTION_REDUCE_SPEED){
            stateBSG = BSG_GENERATOR;
         }
         //BSG_MOTOR - Torque Assistance
         else if(getDriverIntention(vehicle) == DRIVE_INTENTION_INCREASE_SPEED){
            stateBSG = BSG_MOTOR;
         }
         if(getDriverIntention(vehicle) == DRIVE_INTENTION_NOTHING) {
            //BSG_IDLE - Energy Saving
            stateBSG = BSG_IDLE;
         }
      }
   }
   else{
      stateBSG = BSG_IDLE;
   }
   return stateBSG;
}
