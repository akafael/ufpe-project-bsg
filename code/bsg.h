/**
 * Example
 */

#ifndef BSG_H

#include <stdint.h>

typedef enum {
  BSG_INDLE = 0,
  BSG_STARTER = 1,
  BSG_MOTOR = 2,
  BSG_GENERATOR = 3
} StateBSG;

typedef struct {
  uint16_t velocity;
  uint16_t angleAccPedal;
  uint16_t angleBrakePedal;
  uint8_t requestCarStart;
} Vehicle;

typedef struct {
  StateBSG currentMode;
  uint16_t rpm;
  float voltage;
  float current;
} BSG;

typedef struct {
  uint16_t rpm;
} Engine;

typedef struct {
  float voltage;
  float current;
} Battery;

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, Battery battery);

uint16_t sum(uint16_t a, uint16_t b);

#endif // BSG_H