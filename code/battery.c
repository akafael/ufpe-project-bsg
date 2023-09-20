#include "calibration.h"
#include "battery.h"

StateBattery getBatteryState(Battery battery){
    
    StateBattery stateBattery = BATTERY_OPERATIONAL;
    if (battery.voltage >= BatteryMaxVoltage){
        stateBattery = BATTERY_CHARGING;
    }
    else if ( battery.voltage >= BatteryMinVoltage)
    {
        if( battery.voltage < BatterySpecVoltage )
        {
            stateBattery = BATTERY_LOW;
        }
        else
        {
            stateBattery = BATTERY_OPERATIONAL;
        }
    }
    else 
    {
        stateBattery = BATTERY_DEAD;
    }
    return stateBattery;
}
