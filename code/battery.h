#ifndef BATTERY_H

#include <stdint.h>

typedef struct {
  StateBattery currentBatteryMode;
  float voltage;
  float current;
} Battery;

typedef enum{
  BATTERY_CHARGING = 0,
  BATTERY_DEAD = 1,
  BATTERY_LOW = 2
} StateBattery;



#endif // BATTERY_H