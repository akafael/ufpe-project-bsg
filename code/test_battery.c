#include "battery.h"
#include "calibration.h"
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
    .voltage = BatteryMinVoltage,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_LOW);
}

UTEST(battery, operacional){
  Battery battery = {
    .voltage = BatterySpecVoltage,
    .current = 1
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_OPERATIONAL);
}

UTEST(battery, batteryCharging){
  Battery battery = {
    .voltage = BatteryMaxVoltage,
    .current = 3
  };

  const StateBattery batteryMode = getBatteryState(battery);
  ASSERT_EQ(batteryMode, BATTERY_CHARGING);
}
