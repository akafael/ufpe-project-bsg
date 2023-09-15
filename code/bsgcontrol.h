#ifndef BSG_CONTROL_H
#include "battery.h"
#include "bsg.h"
#include "vehicle.h"
#include "engine.h"

/**
 * @brief Define the expected BSG operation mode considering the current measurement
 * from vehicle sensor data.
 * 
 * @param vehicle Vehicle Driver and Odometry information 
 * @param engine Engine sensor data (RPM)
 * @param bsg  BSG sensor data (RPM,Voltage,Current)
 * @param battery Battery sensor data (Voltage)
 * @return StateBSG 
 */
StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery);

#endif // BSG_CONTROL_H
