#include "calibration.h"
#include "vehicle.h"

DriverIntention getDriverIntention(const Vehicle vehicle){
 
DriverIntention driverIntention = DRIVE_INTENTION_NOTHING;

      if( vehicle.angleBrakePedal > VehicleMinBrakePedal )
    {
        driverIntention = DRIVE_INTENTION_REDUCE_SPEED;
    }
    else
    {
        if( vehicle.angleAccPedal > VehicleMinAccPedal )
        {
            driverIntention = DRIVE_INTENTION_INCREASE_SPEED;
        }
        else
        {
            driverIntention = DRIVE_INTENTION_NOTHING; 
        }
    }

    return driverIntention;
}
