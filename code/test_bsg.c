#include "bsgcontrol.h"
#include "utest/utest.h"
#include "calibration.h"

UTEST_MAIN()

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
    .currentMode = BSG_IDLE,
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
  ASSERT_EQ(bsgMode, BSG_IDLE);
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
    .currentMode = BSG_IDLE,
    .rpm = 0,
    .voltage = 0,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 0
  };
  
  Battery battery = {
    .voltage = BatterySpecVoltage,
    .current = 1
  };

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_IDLE);
}

UTEST(bsg, startEngine) {
  Vehicle vehicle = {
    .velocity = 0,
    .angleAccPedal = 0,
    .angleBrakePedal = 0,
    .requestCarStart = 1
  };
  
  BSG bsg = {
    .currentMode = BSG_IDLE,
    .rpm = 0,
    .voltage = 0,
    .current = 0
  };
  
  Engine engine = {
    .rpm = 0
  };
  
  Battery battery = {
    .voltage = BatterySpecVoltage,
    .current = 1
  };
 
  ASSERT_EQ(getBatteryState(battery),BATTERY_OPERATIONAL);
  ASSERT_EQ(getEngineState(engine),ENGINE_OFF);
  ASSERT_TRUE(vehicle.requestCarStart);

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
    .currentMode = BSG_IDLE,
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

  ASSERT_EQ(getDriverIntention(vehicle), DRIVE_INTENTION_REDUCE_SPEED);
  ASSERT_NE(getEngineState(engine),ENGINE_OFF);

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_GENERATOR);
}

UTEST(bsg, motor) {

  Vehicle vehicle = {
    .velocity = 90,
    .angleAccPedal = 10,
    .angleBrakePedal = 0,
    .requestCarStart = 0
  };

  BSG bsg = {
    .currentMode = BSG_IDLE,
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
  ASSERT_EQ(bsgMode, BSG_MOTOR);

}
