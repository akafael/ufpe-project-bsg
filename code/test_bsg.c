#include "bsg.h"
#include "utest/utest.h"

UTEST_MAIN();

UTEST(bsg, idle) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 0;
  battery.current = 0;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

UTEST(bsg, engineOff) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 12;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

UTEST(bsg, startEngine) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 1;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 12;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, battery);
  ASSERT_EQ(bsgMode, BSG_STARTER);
}