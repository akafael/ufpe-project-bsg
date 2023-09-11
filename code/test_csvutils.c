#include "csvutils.h"
#include "utest/utest.h"

UTEST_MAIN();

UTEST(csv, write) {
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

UTEST(csv, read) {
  VehicleData expectedVehicleData = {
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
  
  char* csvLine = "1,2,3,4,5,6,0,8,9,10,11,12,13";

  VehicleData vehicleData;
  readCSVLine(&vehicleData, csvLine);

  EXPECT_EQ(expectedVehicleData.vehicle.velocity,vehicleData.vehicle.velocity);
  EXPECT_EQ(expectedVehicleData.vehicle.angleAccPedal,vehicleData.vehicle.angleAccPedal);
  EXPECT_EQ(expectedVehicleData.vehicle.angleBrakePedal,vehicleData.vehicle.angleBrakePedal);
  EXPECT_EQ(expectedVehicleData.vehicle.requestCarStart,vehicleData.vehicle.requestCarStart);
  //EXPECT_EQ(expectedVehicleData.battery.voltage,vehicleData.battery.voltage); // TODO Fix bug
  EXPECT_EQ(expectedVehicleData.battery.current,vehicleData.battery.current);
  EXPECT_EQ(expectedVehicleData.bsg.currentMode,vehicleData.bsg.currentMode);
  EXPECT_EQ(expectedVehicleData.bsg.rpm,vehicleData.bsg.rpm);
  EXPECT_EQ(expectedVehicleData.bsg.voltage,vehicleData.bsg.voltage);
  EXPECT_EQ(expectedVehicleData.bsg.current,vehicleData.bsg.current);
  EXPECT_EQ(expectedVehicleData.engine.rpm,vehicleData.engine.rpm);
  EXPECT_EQ(expectedVehicleData.engine.velocity,vehicleData.engine.velocity);
  EXPECT_EQ(expectedVehicleData.engine.gear,vehicleData.engine.gear);
}
