#include "calibration.h"
#include "vehicle.h"

DriverIntention getDriverIntention(const Vehicle vehicle){

    if ( vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal && vehicle.velocity < VehicleMinVelocity) {
        return DRIVE_INTENTION_NOTHING; 
    }
    if(vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal){
        return DRIVE_INTENTION_KEEP_SPEED;
    }
    if(vehicle.angleAccPedal > VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal){
        return DRIVE_INTENTION_INCREASE_SPEED;
    }
    if(vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal > VehicleMinBrakePedal){
        return DRIVE_INTENTION_REDUCE_SPEED;
    }
 
    return DRIVE_INTENTION_NOTHING;
}
