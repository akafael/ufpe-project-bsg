#include <stdint.h>
#include "calibration.h"

const uint8_t BSGMaxVoltage = 50;

const uint16_t EngineRPMNeutral = 1000;
const uint16_t EngineRPMMaximum = 8000;


const uint8_t BatteryMinVoltage = 5;
const uint8_t BatteryMinOperationVoltage = 7;
const uint8_t BatteryMaxVoltage = 50;
const uint8_t BatterySpecVoltage = 48;

const int8_t BatteryMinOperationalCurrent = 1;

const uint16_t VehicleMinAccPedal = 5;
const uint16_t VehicleHighAccPedal = 60;

const uint16_t VehicleMinBrakePedal = 5;
const uint16_t VehicleHighBrakePedal = 60;
