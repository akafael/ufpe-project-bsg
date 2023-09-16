#include "vehicle.h"
#include "utest/utest.h"

UTEST_MAIN()

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
