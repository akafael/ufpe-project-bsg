#include "calibration.h"
#include "vehicle.h"

DriverIntention getDriverIntention(const Vehicle vehicle){

    if ( vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal && vehicle.velocity < VehicleMinVelocity) {
        return DRIVE_INTENTION_NOTHING; 
    }
    else if(vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal){
        return DRIVE_INTENTION_KEEP_SPEED;
    }
    else if(vehicle.angleAccPedal > VehicleMinAccPedal && vehicle.angleBrakePedal < VehicleMinBrakePedal){
        return DRIVE_INTENTION_INCREASE_SPEED;
    }
    else if(vehicle.angleAccPedal < VehicleMinAccPedal && vehicle.angleBrakePedal > VehicleMinBrakePedal){
        return DRIVE_INTENTION_REDUCE_SPEED;
    }
    else {
    return DRIVE_INTENTION_NOTHING;
    }
}
