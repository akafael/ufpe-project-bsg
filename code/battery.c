#include "calibration.h"
#include "battery.h"

StateBattery getBatteryState(Battery battery){
    
    if (battery.voltage > BatterySpecVoltage){
        return BATTERY_CHARGING;
    }
    if(battery.voltage < BatteryMinVoltage && battery.current < BatteryMinOperationalCurrent){
        return BATTERY_DEAD;
    }
    if(battery.voltage >= BatteryMinOperationVoltage && battery.voltage <= BatteryMaxVoltage){
        return BATTERY_OPERATIONAL;
    }
    if(battery.voltage < BatteryMinOperationVoltage){
        return BATTERY_LOW;
    }
    return BATTERY_OPERATIONAL;
}
