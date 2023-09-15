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

/**
 * @brief BSG - Belt Starter Generator sensor data
 * 
 */
typedef struct {
  StateBSG currentMode;   ///< BSG Operation Mode
  uint16_t rpm;           ///< BSG rotation (RPM)
  uint16_t voltage;       ///< BSG voltage (V)
  uint16_t current;       ///< BSG current (A)
} BSG;

#endif // BSG_H
