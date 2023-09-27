#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

/**
 * @brief vehicle battery sensor data information
 * 
 */
typedef struct BatteryStruct {
  uint8_t voltage;           ///< Battery Voltage [V]
  int8_t current;            ///< Battery Current [A]
  uint16_t batteryReport;    ///< Time to report Battery status [S]
} Battery;

/**
 * @brief Battery state considering voltage data
 * 
 */
typedef enum StateBatteryEnum {
  BATTERY_DEAD = 0,          ///< Battery not working
  BATTERY_LOW = 1,           ///< Battery state low
  BATTERY_OPERATIONAL = 2,   ///< Battery under normal operation voltage
  BATTERY_CHARGING = 3       ///< Battery charging 
} StateBattery;

/**
 * @brief Convert the vehicle's voltage and current information into StateBattery 
 * 
 * @param battery Battery voltage and current information
 * @return StateBattery 
 */
StateBattery getBatteryState(Battery battery);

#endif // BATTERY_H
