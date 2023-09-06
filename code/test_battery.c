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