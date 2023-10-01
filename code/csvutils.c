#include "csvutils.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int writeCSV(const VehicleData* csvdata, int numEntries, const char* filename){
    FILE* file = fopen(filename,"w");   //opens 'filename' and assigns to 'file' the pointer to that file;
    int errnoValue = 0;
   
    if(file == NULL){
        perror(strerror(errno));
        errnoValue = 2;
    }
    else{
        fprintf(file, "timestamp,velocity,angleAccPedal,angleBrakePedal,requestCarStart,voltage,current,currentMode,rpm,voltage,current\n"); //csv header
        for(int i = 0; i < numEntries; i++){
            char csvLine[512]; // Arbitrary size
            writeCSVLine(csvdata[i], csvLine);
            fprintf(file, "%s\n", csvLine);
        }
        errnoValue = 0;
    }
    fclose(file);
    return errnoValue;
}

void writeCSVLine(const VehicleData data, char* csvLine){
    sprintf(csvLine, "%u,"   // timeMillis
                     "%hu,"  // vehicle.velocity
                     "%hu,"  // vehicle.angleAccPedal
                     "%hu,"  // vehicle.angleBrakePedal
                     "%hu,"  // vehicle.requestCarStart
                     "%hu,"  // battery.voltage
                     "%hhd," // battery.current
                     "%d,"   // bsg.currentMode
                     "%hu,"  // bsg.rpm
                     "%hu,"  // bsg.voltage
                     "%hu,"  // bsg.current
                     "%u,"   // engine.rpm
                     "%hu,"  // engine.velocity
                     "%hu",  // engine.gear
        data.timeMillis, 
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

int readCSV(VehicleData* csvdata, int numEntries, const char* filename){
    FILE* file = fopen(filename,"r");   //opens 'filename' and assigns to 'file' the pointer to that file;
    int errnoValue = 0;

    if(file == NULL){
        perror(strerror(errno));
        errnoValue = 2;
    }
    else{
        const int bufferSize = 512;
        char csvLine[bufferSize];

        fgets(csvLine, bufferSize, file); // Drop First Line with header

        for( int i = 0; ( i < numEntries ) && fgets(csvLine, 512, file);  i++ ) {
            readCSVLine(&csvdata[i], csvLine);
        }
        errnoValue = 0;
    } 
    fclose(file);
    return errnoValue;
}

void readCSVLine(VehicleData* data, const char* csvLine){
    sscanf(csvLine,  "%u,"    // Timestamp    
                     "%hu,"   // vehicle.velocity
                     "%hu,"   // vehicle.angleAccPedal
                     "%hu,"   // vehicle.angleBrakePedal
                     "%hhu,"  // vehicle.requestCarStart
                     "%hhu,"  // battery.voltage
                     "%hhd,"  // battery.current
                     "%u,"    // bsg.currentMode
                     "%hu,"   // bsg.rpm
                     "%hu,"   // bsg.voltage
                     "%hu,"   // bsg.current
                     "%hu,"   // engine.rpm
                     "%hhu,"  // engine.velocity
                     "%hhu",  // engine.gear
        &(data->timeMillis),
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
