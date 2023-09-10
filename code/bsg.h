/**
 * Example
 */

#ifndef BSG_H
#define BSG_H

#include <stdint.h>

typedef enum {
  BSG_IDLE = 0,
  BSG_STARTER = 1,
  BSG_MOTOR = 2,
  BSG_GENERATOR = 3
} StateBSG;

typedef struct {
  StateBSG currentMode;
  uint16_t rpm;
  uint16_t voltage;
  uint16_t current;
} BSG;

typedef struct {
  uint16_t rpm;
} Engine;

#endif // BSG_H
