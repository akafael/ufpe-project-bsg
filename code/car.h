#ifndef CAR_H
#include <stdint.h>
#include <time.h>
#include "vehicle.h"
#include "battery.h"
#include "bsg.h"

time_t t = time(NULL);
typedef struct{
    Vehicle vehicle;
    Battery battery;
    BSG bsg;
    struct tm tm = *localtime(&t);
} Car;

#endif
