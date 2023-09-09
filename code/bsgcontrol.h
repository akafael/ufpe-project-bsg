#ifndef BSG_CONTROL_H

#include "battery.h"
#include "bsg.h"
#include "vehicle.h"

StateBSG selectBSGMode(Vehicle vehicle, Engine engine, BSG bsg,
                       Battery battery);

#endif // BSG_CONTROL_H
