# include <stdio.h>
#include "CSV_write.h"

void writeCSV(VehicleData* csvdata, int numEntries, const char* filename){
    FILE* file = fopen(filename,"w");   //opens 'filename' and assigns to 'file' the pointer to that file;

    if(file == NULL){
        printf("Failed to open file");
    }

    fprintf(file, "velocity,angleAccPedal,angleBrakePedal,requestCarStart,voltage,current,currentMode,rpm,voltage,current\n"); //csv header

    for(int i = 0; i < numEntries; i++){
        char csvLine[512]; // Arbitrary size
        writeCSVLine(csvdata[i], csvLine);
        fprintf(file, "%s\n", csvLine);
    }

    fclose(file);
}

void writeCSVLine(VehicleData data, char* csvLine){
    sprintf(csvLine, "%u,%u,%u,%d,%u,%u,%d,%u,%f,%f", 
        data.vehicle.velocity, 
        data.vehicle.angleAccPedal, 
        data.vehicle.angleBrakePedal,
        data.vehicle.requestCarStart,
        data.battery.voltage, 
        data.battery.current, 
        data.bsg.currentMode, 
        data.bsg.rpm, 
        data.bsg.voltage, 
        data.bsg.current
    );
}

