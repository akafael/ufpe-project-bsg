#ifndef VEHICLE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint16_t velocity;
  uint16_t angleAccPedal;
  uint16_t angleBrakePedal;
  bool requestCarStart;
} Vehicle;

typedef enum {
  DRIVE_INTENTION_NOTHING = 0,
  DRIVE_INTENTION_REDUCE_SPEED = 1,
  DRIVE_INTENTION_KEEP_SPEED = 2,
  DRIVE_INTENTION_INCREASE_SPEED = 3,
 
} DriverIntention;

DriverIntention getDriverIntention(Vehicle vehicle);

#endif // VEHICLE_H
