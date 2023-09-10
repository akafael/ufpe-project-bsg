#ifndef ENGINE_H

#include <stdint.h>

typedef struct {
  uint16_t rpm;
  uint8_t velocity;
  uint8_t gear;
  } Engine;

typedef enum{
  ENGINE_OFF = 0,
  ENGINE_WAIT = 1000,
  ENGINE_MAXIMUM = 8000,
  ENGINE_WORKING = 1,
} StateEngine;

StateEngine getEngineState(Engine engine);

#endif // ENGINE_H