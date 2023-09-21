#ifndef CALIBRATION_H
#define CALIBRATION_H
#include <stdint.h>

extern const uint8_t BSGMaxVoltage;                ///< [V] BSG max allowed voltage
 
extern const uint16_t EngineRPMNeutral;            ///< [rpm] Engine rotation at neutral gear
extern const uint16_t EngineRPMMaximum;            ///< [rpm] Engine max allowed rotation

extern const uint8_t BatteryMinVoltage;            ///< [V] Battery minimal allowed voltage under operation
extern const uint8_t BatteryMaxVoltage;            ///< [V] Battery max allowed voltage under normal operation conditions
extern const uint8_t BatterySpecVoltage;           ///< [V] Battery specification voltage under normal operation conditions

extern const int8_t BatteryMinOperationalCurrent;   ///< [A] Battery minimal current under normal operation conditions 

extern const uint16_t VehicleMinAccPedal;          ///< [%] Vehicle gas pedal dead zone.
extern const uint16_t VehicleHighAccPedal;         ///< [%] Vehicle gas pedal value to consider it totally pressed.

extern const uint16_t VehicleMinBrakePedal;        ///< [%] Vehicle brake pedal (dead zone)
extern const uint16_t VehicleHighBrakePedal;       ///< [%] Vehicle brake pedal value to consider it totally pressed.

extern const uint16_t VehicleMinVelocity;

#endif
