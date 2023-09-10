#ifndef ENGINE_H

#include <stdint.h>

typedef struct {
  uint16_t rpm;
  uint8_t velocity;
  uint8_t gear;
  } Engine;

typedef enum{
  ENGINE_OFF = 0,
  ENGINE_RPM = 4000,
  ENGINE_RPM_NEUTRAL = 1000,
  ENGINE_RPM_MAXIMUM = 8000,
  ENGINE_WORKING = 1,
  ENGINE_GEAR = 2,
} StateEngine;

StateEngine getEngineState(Engine engine);

#endif // ENGINE_H
