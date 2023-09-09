#include "battery.h"
#include "utest/utest.h"

UTEST_MAIN();

UTEST(battery, batteryCharging){
  Battery battery = {
    .voltage = 25,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_CHARGING);
}
UTEST(battery, dead){
  Battery battery = {
    .voltage = 2,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_DEAD);
}

UTEST(battery, low){
  Battery battery = {
    .voltage = 5,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_LOW);
}

UTEST(battery, operacional){
  Battery battery = {
    .voltage = 8,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_OPERATIONAL);
}
  
