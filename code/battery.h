#ifndef BATTERY_H

#include <stdint.h>

typedef struct {
  uint8_t voltage;
  uint8_t current;
} Battery;

typedef enum{
  BATTERY_DEAD = 0,
  BATTERY_LOW = 1,
  BATTERY_OPERATIONAL = 2,
  BATTERY_CHARGING = 3
} StateBattery;

StateBattery getBatteryState(Battery battery);

#endif // BATTERY_H