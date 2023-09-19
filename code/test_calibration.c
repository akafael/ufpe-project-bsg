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

