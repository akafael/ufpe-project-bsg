#ifndef CSV_WRITE_H
#define CSV_WRITE_H
#include <stdint.h>
#include "bsg.h"

typedef struct {
    Vehicle vehicle;
    Engine engine;
    Battery battery;
    BSG bsg;
}VehicleData;

void writeCSV(VehicleData* csvdata, int numEntries, const char* filename);

void WriteCSVLine(VehicleData data, char* csvLine);


#endif //CSV_WRITE_H