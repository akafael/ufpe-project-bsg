#include "battery.h"
#include "utest/utest.h"

UTEST_MAIN()

UTEST(battery, dead){
  Battery battery = {
    .voltage = 2,
    .current = -5
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_DEAD);
}

UTEST(battery, low){
  Battery battery = {
    .voltage = 6,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_LOW);
}

UTEST(battery, operacional){
  Battery battery = {
    .voltage = 12,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_OPERATIONAL);
}

UTEST(battery, batteryCharging){
  Battery battery = {
    .voltage = 63,
    .current = 3
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_CHARGING);
}
