#include <stdint.h>
#include "calibration.h"

const uint8_t BSGMaxVoltage = 55;

const uint16_t EngineMaxRPM = 10000;
const uint16_t EngineMinOperationRPM = 1000;

const uint8_t BatteryMinVoltage = 5;
const uint8_t BatteryMinOperationVoltage = 7;
const uint8_t BatteryMaxVoltage = 60;
const uint8_t BatterySpecVoltage = 12;

const uint16_t VehicleMinAccPedal = 5;
const uint16_t VehicleHighAccPedal = 60;

const uint16_t VehicleMinBrakePedal = 5;
const uint16_t VehicleHighBrakePedal = 60;

const uint16_t VehicleMinVelocity = 1;
