#ifndef CSV_WRITE_H
#define CSV_WRITE_H
#include <stdint.h>
#include "bsg.h"

typedef struct {
    uint16_t velocity[1000];
    uint16_t angleAccPedal[1000];
    uint16_t angleBrakePedal[1000];
    bool requestCarStart[1000];
    uint8_t batteryvoltage[1000];
    uint8_t batterycurrent[1000];
    StateBSG currentMode[1000];
    uint16_t rpm[1000];
    float voltage[1000];
    float current[1000];
}csvdata;

void writeCSV(csvdata* csvdata, int numEntries, const char* filename);


#endif //CSV_WRITE_H