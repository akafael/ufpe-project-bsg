#ifndef ENGINE_H
#define ENGINE_H

#include <stdint.h>
#include <time.h>
typedef struct EngineStruct {
  uint16_t rpm;                ///< [rpm] Engine rotation
  uint8_t velocity;            ///< [km/h] Vehicle speed 
  uint8_t gear;                ///< Current gear number 
  time_t  time;                ///< Timestamp from last engine status report [s]
  } Engine;

typedef enum StateEngineEnum{
  ENGINE_OFF = 0,              ///< Engine off
  ENGINE_WORKING = 1,          ///< Engine at regular operation
  ENGINE_RPM_MAXIMUM = 2,      ///< Engine at max safe allowed
} StateEngine;

StateEngine getEngineState(Engine engine);

#endif // ENGINE_H
