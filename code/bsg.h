/**
 * Example
 */

#ifndef BSG_H
#define BSG_H

#include <stdint.h>

/**
 * @brief BSG Operation modes
 * 
 */
typedef enum StateBSGEnum {
  BSG_IDLE = 0,      ///< BSG state for machine off 
  BSG_STARTER = 1,   ///< BSG state for machine operating as Engine Starter 
  BSG_MOTOR = 2,     ///< BSG state for machine operating as Motor
  BSG_GENERATOR = 3  ///< BSG state for machine operating as Generator
  
} StateBSG;

/**
 * @brief BSG - Belt Starter Generator sensor data
 * 
 */
typedef struct BSGStruct {
  StateBSG currentMode;   ///< BSG Operation Mode
  uint16_t rpm;           ///< BSG rotation (RPM)
  uint16_t voltage;       ///< BSG voltage (V)
  uint16_t current;       ///< BSG current (A)
  uint16_t bsgReport;    ///< Time to report BSG status [S]
} BSG;

#endif // BSG_H
