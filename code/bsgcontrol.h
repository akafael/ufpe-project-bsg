#ifndef BSG_CONTROL_H
#include "battery.h"
#include "bsg.h"
#include "vehicle.h"
#include "engine.h"

/**
 * @brief Define the expected BSG operation mode considering the current measurement
 * from vehicle sensor data.
 * 
 * @param[in] vehicle Vehicle Driver and Odometry information 
 * @param[in] engine Engine sensor data (RPM)
 * @param[in] bsg  BSG sensor data (RPM,Voltage,Current)
 * @param[in] battery Battery sensor data (Voltage)
 * @return StateBSG 
 */
StateBSG selectBSGMode(const Vehicle vehicle,const Engine engine,const BSG bsg,
                       const Battery battery);

#endif // BSG_CONTROL_H
