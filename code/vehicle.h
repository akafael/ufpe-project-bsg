#ifndef VEHICLE_H

#include <stdint.h>

typedef struct {
  uint16_t velocity;
  uint16_t angleAccPedal;
  uint16_t angleBrakePedal;
  uint8_t requestCarStart;
} Vehicle;

#endif // VEHICLE_H