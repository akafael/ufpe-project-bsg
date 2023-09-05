#include "bsgcontrol.h"
#include "utest/utest.h"

UTEST_MAIN();

/**
 * BSG IDLE whenever the engine is off and the vehicle stopped
 */
UTEST(bsg, idle) {
  Vehicle vehicle = {
    .velocity = 0,
    .angleAccPedal = 0,
    .angleBrakePedal = 0,
    .requestCarStart = 0
  };
  
  BSG bsg = {
    .currentMode = BSG_INDLE,
    .rpm = 0,
    .voltage = 0,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 0
  };
  
  Battery battery = {
    .voltage = 0,
    .current = 0
  };

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

/**
 * BSG IDLE whenever the engine is off and the vehicle stopped
 */
UTEST(bsg, engineOff) {
  Vehicle vehicle = {
    .velocity = 0,
    .angleAccPedal = 0,
    .angleBrakePedal = 0,
    .requestCarStart = 0
  };
  
  BSG bsg = {
    .currentMode = BSG_INDLE,
    .rpm = 0,
    .voltage = 0,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 0
  };
  
  Battery battery = {
    .voltage = 12,
    .current = 1
  };

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_INDLE);
}

UTEST(bsg, startEngine) {
  Vehicle vehicle = {
    .velocity = 0,
    .angleAccPedal = 0,
    .angleBrakePedal = 0,
    .requestCarStart = 1
  };
  
  BSG bsg = {
    .currentMode = BSG_INDLE,
    .rpm = 0,
    .voltage = 0,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 0
  };
  
  Battery battery = {
    .voltage = 12,
    .current = 1
  };
 
  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_STARTER);
}

UTEST(bsg, regenerativeBreak) {
  Vehicle vehicle = {
    .velocity = 60,
    .angleAccPedal = 0,
    .angleBrakePedal = 50,
    .requestCarStart = 1
  };
  
  BSG bsg = {
    .currentMode = BSG_INDLE,
    .rpm = 4000,
    .voltage = 48,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 4000
  };
  
  Battery battery = {
    .voltage = 30,
    .current = 1
  };

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_GENERATOR);
}