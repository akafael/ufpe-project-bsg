#include "calibration.h"
#include "battery.h"

StateBattery getBatteryState(Battery battery){
    
    StateBattery stateBattery;
    if (battery.current >= BatteryMinOperationalCurrent ) {
        if (battery.voltage >= BatteryMaxVoltage){
            stateBattery = BATTERY_CHARGING;
        }
        
        else{
            if (battery.voltage >= BatteryMinVoltage && battery.voltage < BatterySpecVoltage){
                stateBattery = BATTERY_LOW;
            } 
        }

        if(battery.voltage >= BatteryMinVoltage && battery.voltage <= BatteryMaxVoltage){
            stateBattery = BATTERY_OPERATIONAL;
        }
    }
    else{
        stateBattery = BATTERY_DEAD;
    }
    return stateBattery;
}
