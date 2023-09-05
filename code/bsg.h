/**
 * Example
 */

#ifndef BSG_H

#include <stdint.h>

typedef enum {
  BSG_IDLE = 0,
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

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery);

#endif // BSG_H