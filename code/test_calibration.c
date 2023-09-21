#include "calibration.h"
#include "utest/utest.h"

UTEST_MAIN()

// The reference below describes information that establishes a maximum limit of 50 volts for the battery for this project.
// Reference:
//  "Progress and recent trends in 48V hybridisation and e-boosting technology on passenger vehicles – a review"
//   Authors: Bo Hu, Chunlin Chen and Zhiyong Yang
//   Link: https://doi.org/10.1177/0954407017729950

UTEST(calibration, BatteryMaxVoltage) {
    ASSERT_TRUE(BatteryMaxVoltage > 0);
    ASSERT_TRUE(BatteryMaxVoltage <= 50);
}

UTEST(calibration, BSGMaxVoltage) {
    ASSERT_TRUE(BSGMaxVoltage > 0);
    ASSERT_TRUE(BSGMaxVoltage <= 50);
}

UTEST(calibration, BatteryMinVoltage ) {
    ASSERT_TRUE(BatteryMinVoltage >= 0);
    ASSERT_TRUE(BatteryMinVoltage <= BatterySpecVoltage);
}

UTEST(calibration, BatterySpecVoltage ) {
    ASSERT_TRUE(BatterySpecVoltage > BatteryMinVoltage);
    ASSERT_TRUE(BatterySpecVoltage < BatteryMaxVoltage);
}

UTEST(calibration, VehicleMinAccPedal) {
    ASSERT_TRUE(VehicleMinAccPedal >= 0);
    ASSERT_TRUE(VehicleMinAccPedal < VehicleHighAccPedal);
}

UTEST(calibration, VehicleMinBrakePedal) {
    ASSERT_TRUE(VehicleMinBrakePedal >= 0);
    ASSERT_TRUE(VehicleMinBrakePedal < VehicleHighBrakePedal);
}

UTEST(calibration, EngineRPMNeutral) {
    ASSERT_TRUE(EngineRPMNeutral >= 0 && EngineRPMNeutral < EngineRPMMaximum);
}

// The reference below describes information that establishes an RPM limit that is within the Redline range, in this project it is 8000 RPM.
// Reference:
//   https://en.wikipedia.org/wiki/Redline#:~:text=Gasoline%20automobile%20engines%20typically%20will,car%20rated%20at%209000%20rpm.

UTEST(calibration, EngineRPMMaximum) {
    ASSERT_TRUE(EngineRPMMaximum >= 0 && EngineRPMMaximum <= 8000);

}
