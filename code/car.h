#ifndef CAR_H
#include <stdint.h>
#include "vehicle.h"
#include "battery.h"
#include "bsg.h"
typedef struct{
    Vehicle vehicle;
    Battery battery;
    BSG bsg;
    
} Car;

#endif
