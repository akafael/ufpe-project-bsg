#include "battery.h"
#include "calibration.h"

StateBattery selectBatteryMode(Battery battery){
    const float batteryVoltage = battery.voltage;
    
    if (batteryVoltage > 12){
        return BATTERY_CHARGING;
    }
    if(batteryVoltage < BatteryMinVoltage){
        return BATTERY_DEAD;
    }
    if(batteryVoltage > 5 && batteryVoltage < 7){
        return BATTERY_LOW;
    }
    return BATTERY_CHARGING;
}


