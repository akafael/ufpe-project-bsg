#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include <stdint.h>
#include "vehicle.h"
#include "engine.h"
#include "battery.h"
#include "bsg.h"

typedef struct{
    Vehicle vehicle;
    Engine engine;
    Battery battery;
    BSG bsg;
} VehicleData;

void writeCSV(VehicleData* csvdata, int numEntries, const char* filename);

void writeCSVLine(VehicleData data, char* csvLine);

void readCSV(VehicleData* csvdata, int numEntries, const char* filename);

void readCSVLine(VehicleData* data, const char* csvLine);

#endif
