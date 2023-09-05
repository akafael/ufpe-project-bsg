#ifndef VEHICLE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint16_t velocity;
  uint16_t angleAccPedal;
  uint16_t angleBrakePedal;
  bool requestCarStart;
} Vehicle;

#endif // VEHICLE_H