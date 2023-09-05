#include "bsg.h"
#include "utest/utest.h"

UTEST_MAIN();
//testing idle
UTEST(bsg, idle) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  BSG bsg;
  bsg.currentMode = BSG_IDLE;
  bsg.rpm = 0;
  bsg.voltage = 0;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 0;
  battery.current = 0;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_IDLE);
}

UTEST(bsg, starter) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 1;

  BSG bsg;
  bsg.currentMode = BSG_IDLE;
  bsg.rpm = 0;
  bsg.voltage = 0;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 12;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_STARTER);
}