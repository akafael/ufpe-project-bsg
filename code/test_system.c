#include "battery.h"
#include "engine.h"
#include "bsgcontrol.h"
#include "vehicle.h"
#include "calibration.h"
#include "csvutils.h"
#include "utest/utest.h"

UTEST_MAIN()

UTEST(calibration, BatteryMaxVoltage) {
    ASSERT_TRUE(BatteryMaxVoltage > 0 && BatteryMaxVoltage <= 50);
}

UTEST(calibration, BSGMaxVoltage) {
    ASSERT_TRUE(BSGMaxVoltage > 0 && BSGMaxVoltage <= 50);
}

UTEST(calibration, BatteryMinVoltage ) {
    ASSERT_TRUE(BatteryMinVoltage >= 0 && BatteryMinVoltage <= BatteryMinOperationVoltage );
}

UTEST(calibration, BatteryMinOperationVoltage ) {
    ASSERT_TRUE(BatteryMinOperationVoltage > BatteryMinVoltage && BatteryMinOperationVoltage < BatterySpecVoltage );
}

UTEST(calibration, BatterySpecVoltage ) {
    ASSERT_TRUE(BatterySpecVoltage > BatteryMinOperationVoltage && BatterySpecVoltage < BatteryMaxVoltage );
}

UTEST(calibration, VehicleMinAccPedal  ) {
    ASSERT_TRUE(VehicleMinAccPedal  >= 0 && VehicleMinAccPedal  < VehicleHighAccPedal  );
}

UTEST(calibration, VehicleMinBrakePedal ) {
    ASSERT_TRUE(VehicleMinBrakePedal >= 0 && VehicleMinBrakePedal < VehicleHighBrakePedal );
}


UTEST(calibration, VehicleMinVelocity ) {
    ASSERT_TRUE( VehicleMinVelocity  >= 0 && VehicleMinVelocity < 10 );
}

UTEST(calibration, EngineRPMNeutral) {
    ASSERT_TRUE( EngineRPMNeutral >= 0 && EngineRPMNeutral < EngineRPMMaximum );
}

UTEST(calibration, EngineRPMMaximum) {
    ASSERT_TRUE( EngineRPMMaximum >= 0 && EngineRPMMaximum <= 8000 );
}

UTEST(engine, engineOff){
 Engine engine= {
  .rpm = 25,
  .velocity = 150,
   .gear = 4
 };

const StateEngine test_engine = getEngineState(engine);
ASSERT_EQ(test_engine, ENGINE_OFF);
}

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
    .voltage = 12,
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
  ASSERT_EQ(bsgMode, BSG_GENERATOR);
}

UTEST(bsg, motor) {

  Vehicle vehicle = {
    .velocity = 90,
    .angleAccPedal = 10,
    .angleBrakePedal = 0,
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

  const StateBSG bsgMode = selectBSGMode(vehicle, engine, bsg, battery);
  ASSERT_EQ(bsgMode, BSG_MOTOR);

}

UTEST(vehicle, driverNothing){
  Vehicle vehicle = {
    .angleAccPedal = 0,
    .angleBrakePedal = 0,
    .velocity = 0
  };
  
  const DriverIntention driverMode = getDriverIntention(vehicle);
  ASSERT_EQ(driverMode, DRIVE_INTENTION_NOTHING);
}

UTEST(vehicle, driverReduce){
  Vehicle vehicle = {
    .angleAccPedal = 4,
    .angleBrakePedal = 70
  };
  
  const DriverIntention driverMode = getDriverIntention(vehicle);
  ASSERT_EQ(driverMode, DRIVE_INTENTION_REDUCE_SPEED);
}

UTEST(vehicle, driverIncrease){
  Vehicle vehicle = {
    .angleAccPedal = 70,
    .angleBrakePedal = 4
  };
  
  const DriverIntention driverMode = getDriverIntention(vehicle);
  ASSERT_EQ(driverMode, DRIVE_INTENTION_INCREASE_SPEED);
}

UTEST(csvutils, writeCSVline) {
  VehicleData vehicleData = {
    .vehicle = {
        .velocity = 1,
        .angleAccPedal = 2,
        .angleBrakePedal = 3,
        .requestCarStart = 4
        },
    .battery = {
        .voltage = 5,
        .current = 6
        },
    .bsg = {
        .currentMode = BSG_IDLE,
        .rpm = 8,
        .voltage = 9,
        .current = 10
       },
    .engine = {
        .rpm = 11,
        .velocity = 12,
        .gear = 13
        },
  };

  /* Coluumns order:
    1. data.vehicle.velocity, 
    2. data.vehicle.angleAccPedal, 
    3. data.vehicle.angleBrakePedal,
    4. data.vehicle.requestCarStart,
    5. data.battery.voltage,
    6. data.battery.current, 
    7. data.bsg.currentMode, 
    9. data.bsg.rpm,
    10. data.bsg.voltage,
    11. data.bsg.current
    12. engine.rpg,
    13. engine.velocity,
    14. engine.gear
  */
  
  char* expectedCsvLine = "1,2,3,4,5,6,0,8,9,10,11,12,13";

  char csvLine[512];
  writeCSVLine(vehicleData, csvLine);

  ASSERT_STREQ(expectedCsvLine,csvLine);
}

UTEST(csv, readCSVline) {
  const VehicleData expectedVehicleData = {
    .vehicle = {
        .velocity = 1,
        .angleAccPedal = 2,
        .angleBrakePedal = 3,
        .requestCarStart = 4
        },
    .battery = {
        .voltage = 5,
        .current = 6
        },
    .bsg = {
        .currentMode = BSG_IDLE,
        .rpm = 8,
        .voltage = 9,
        .current = 10
       },
    .engine = {
        .rpm = 11,
        .velocity = 12,
        .gear = 13
        },
  };

  /* Coluumns order:
    1. data.vehicle.velocity, 
    2. data.vehicle.angleAccPedal, 
    3. data.vehicle.angleBrakePedal,
    4. data.vehicle.requestCarStart,
    5. data.battery.voltage,
    6. data.battery.current, 
    7. data.bsg.currentMode, 
    9. data.bsg.rpm,
    10. data.bsg.voltage,
    11. data.bsg.current
    12. engine.rpg,
    13. engine.velocity,
    14. engine.gear
  */
  
  const char* csvLine = "1,2,3,4,5,6,0,8,9,10,11,12,13";

  VehicleData vehicleData;
  readCSVLine(&vehicleData, csvLine);

  EXPECT_EQ(expectedVehicleData.vehicle.velocity,vehicleData.vehicle.velocity);
  EXPECT_EQ(expectedVehicleData.vehicle.angleAccPedal,vehicleData.vehicle.angleAccPedal);
  EXPECT_EQ(expectedVehicleData.vehicle.angleBrakePedal,vehicleData.vehicle.angleBrakePedal);
  EXPECT_EQ(expectedVehicleData.vehicle.requestCarStart,vehicleData.vehicle.requestCarStart);
  EXPECT_EQ(expectedVehicleData.battery.voltage,vehicleData.battery.voltage);
  EXPECT_EQ(expectedVehicleData.battery.current,vehicleData.battery.current);
  EXPECT_EQ(expectedVehicleData.bsg.currentMode,vehicleData.bsg.currentMode);
  EXPECT_EQ(expectedVehicleData.bsg.rpm,vehicleData.bsg.rpm);
  EXPECT_EQ(expectedVehicleData.bsg.voltage,vehicleData.bsg.voltage);
  EXPECT_EQ(expectedVehicleData.bsg.current,vehicleData.bsg.current);
  EXPECT_EQ(expectedVehicleData.engine.rpm,vehicleData.engine.rpm);
  EXPECT_EQ(expectedVehicleData.engine.velocity,vehicleData.engine.velocity);
  EXPECT_EQ(expectedVehicleData.engine.gear,vehicleData.engine.gear);
}

/**
 * Ensure that data is preserved after converting
 *  VehicleData -> csv string -> VehicleData
 */
UTEST(csv, preserveVehicleData) {
  const VehicleData vehicleData = {
    .vehicle = {
        .velocity = 1,
        .angleAccPedal = 2,
        .angleBrakePedal = 3,
        .requestCarStart = 4
        },
    .battery = {
        .voltage = 5,
        .current = 6
        },
    .bsg = {
        .currentMode = BSG_IDLE,
        .rpm = 8,
        .voltage = 9,
        .current = 10
       },
    .engine = {
        .rpm = 11,
        .velocity = 12,
        .gear = 13
        },
  };

  char csvLineWriter[100];
  writeCSVLine(vehicleData,csvLineWriter);

  VehicleData vehicleDataReader;
  readCSVLine(&vehicleDataReader, csvLineWriter);

  EXPECT_EQ(vehicleDataReader.vehicle.velocity,vehicleData.vehicle.velocity);
  EXPECT_EQ(vehicleDataReader.vehicle.angleAccPedal,vehicleData.vehicle.angleAccPedal);
  EXPECT_EQ(vehicleDataReader.vehicle.angleBrakePedal,vehicleData.vehicle.angleBrakePedal);
  EXPECT_EQ(vehicleDataReader.vehicle.requestCarStart,vehicleData.vehicle.requestCarStart);
  EXPECT_EQ(vehicleDataReader.battery.voltage,vehicleData.battery.voltage); // TODO Fix bug
  EXPECT_EQ(vehicleDataReader.battery.current,vehicleData.battery.current);
  EXPECT_EQ(vehicleDataReader.bsg.currentMode,vehicleData.bsg.currentMode);
  EXPECT_EQ(vehicleDataReader.bsg.rpm,vehicleData.bsg.rpm);
  EXPECT_EQ(vehicleDataReader.bsg.voltage,vehicleData.bsg.voltage);
  EXPECT_EQ(vehicleDataReader.bsg.current,vehicleData.bsg.current);
  EXPECT_EQ(vehicleDataReader.engine.rpm,vehicleData.engine.rpm);
  EXPECT_EQ(vehicleDataReader.engine.velocity,vehicleData.engine.velocity);
  EXPECT_EQ(vehicleDataReader.engine.gear,vehicleData.engine.gear);
}

/**
 * Ensure that data is preserved after converting
 *  csv string -> VehicleData -> csv string
 */
UTEST(csv, preserveCSVline) {
  const char* csvLine = "1,2,3,4,5,6,0,8,9,10,11,12,13";

  VehicleData vehicleData;
  readCSVLine(&vehicleData, csvLine);

  char csvLineWriter[100];
  writeCSVLine(vehicleData,csvLineWriter);

  EXPECT_STREQ(csvLine,csvLineWriter);
}
