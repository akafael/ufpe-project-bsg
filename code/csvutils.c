#include "csvutils.h"
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//Write
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
    sprintf(csvLine, "%hu,%hu,%hu,%hu,%hu,%hhu,%d,%hu,%hu,%hu,%u,%hu,%hu", 
        data.vehicle.velocity, 
        data.vehicle.angleAccPedal, 
        data.vehicle.angleBrakePedal,
        data.vehicle.requestCarStart, 
        data.battery.voltage, 
        data.battery.current, 
        data.bsg.currentMode, 
        data.bsg.rpm, 
        data.bsg.voltage, 
        data.bsg.current,
        data.engine.rpm,
        data.engine.velocity,
        data.engine.gear
    );
}

// Read
void readCSV(VehicleData* csvdata, int numEntries, const char* filename){
    FILE* file = fopen(filename,"r");   //opens 'filename' and assigns to 'file' the pointer to that file;

    if(file == NULL){
        printf("Failed to open file");
    }

    csvdata;

    // TODO Read file until the last line and add each line as a new entry inside buffer.

    char csvLine[512];
    fgets(csvLine, 512, file);

    for( int i = 0; ( i < numEntries ) && fgets(csvLine, 512, file);  i++ ) {
        readCSVLine(&csvdata[i], csvLine);
    }

    fclose(file);
}

void readCSVLine(VehicleData* data, char* csvLine){
    sscanf(csvLine, "%hu,%hu,%hu,%hu,%hu,%hhu,%d,%hu,%hu,%hu,%hu,%hu,%hu", 
        &(data->vehicle.velocity), 
        &(data->vehicle.angleAccPedal), 
        &(data->vehicle.angleBrakePedal),
        &(data->vehicle.requestCarStart),
        &(data->battery.voltage), 
        &(data->battery.current), 
        &(data->bsg.currentMode), 
        &(data->bsg.rpm), 
        &(data->bsg.voltage), 
        &(data->bsg.current),
        &(data->engine.rpm),
        &(data->engine.velocity),
        &(data->engine.gear) 
    );
}
