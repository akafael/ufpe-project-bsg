#include "calibration.h"
#include "battery.h"

StateBattery getBatteryState(Battery battery){
    
    if (battery.voltage > BatterySpecVoltage){
        return BATTERY_CHARGING;
    }
    if(battery.voltage < BatteryMinVoltage){
        return BATTERY_DEAD;
    }
    return BATTERY_CHARGING;
}