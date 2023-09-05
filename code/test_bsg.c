#include "bsgcontrol.h"
#include "utest/utest.h"

UTEST_MAIN();

/**
 * BSG IDLE whenever the engine is off and the vehicle stopped
 */
UTEST(bsg, idle) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  BSG bsg;
  bsg.currentMode = BSG_INDLE;
  bsg.rpm = 0;
  bsg.voltage = 0;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 0;
  battery.current = 0;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

/**
 * BSG IDLE whenever the engine is off and the vehicle stopped
 */
UTEST(bsg, engineOff) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  BSG bsg;
  bsg.currentMode = BSG_INDLE;
  bsg.rpm = 0;
  bsg.voltage = 0;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 0;

  Battery battery;
  battery.voltage = 12;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

UTEST(bsg, startEngine) {
  Vehicle vehicle;
  vehicle.velocity = 0;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 1;

  BSG bsg;
  bsg.currentMode = BSG_INDLE;
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

UTEST(bsg, regenerativeBreak) {
  Vehicle vehicle;
  vehicle.velocity = 60;
  vehicle.angleAccPedal = 0;
  vehicle.angleBrakePedal = 50;
  vehicle.requestCarStart = 0;

  BSG bsg;
  bsg.currentMode = BSG_INDLE;
  bsg.rpm = 4000;
  bsg.voltage = 48;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 4000;

  Battery battery;
  battery.voltage = 30;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_GENERATOR);
}

UTEST(bsg, torqueAssistance) {
  Vehicle vehicle;
  vehicle.velocity = 60;
  vehicle.angleAccPedal = 100;
  vehicle.angleBrakePedal = 0;
  vehicle.requestCarStart = 0;

  BSG bsg;
  bsg.currentMode = BSG_INDLE;
  bsg.rpm = 4000;
  bsg.voltage = 48;
  bsg.current = 0;

  Engine engine;
  engine.rpm = 4000;

  Battery battery;
  battery.voltage = 30;
  battery.current = 1;

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_MOTOR);
}