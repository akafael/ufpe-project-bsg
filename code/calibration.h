#ifndef CALIBRATION_H
#define CALIBRATION_H
#include <stdint.h>

extern const uint8_t BSGMaxVoltage;

extern const uint16_t EngineRPMNeutral;       ///< Engine RPM at neutral gear
extern const uint16_t EngineRPMMaximum;       ///< Redline Max allowed by Engine

extern const uint8_t BatteryMinVoltage;
extern const uint8_t BatteryMinOperationVoltage;
extern const uint8_t BatteryMaxVoltage;
extern const uint8_t BatterySpecVoltage;

extern const uint16_t VehicleMinAccPedal;
extern const uint16_t VehicleHighAccPedal;

extern const uint16_t VehicleMinBrakePedal;
extern const uint16_t VehicleHighBrakePedal;

extern const uint16_t VehicleMinVelocity;

#endif
