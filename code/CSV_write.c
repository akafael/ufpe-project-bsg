# include <stdio.h>
# include "battery.h"
# include "vehicle.h"
# include "bsg.h"

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

void writeCSV(csvdata* csvdata, int numEntries, const char* filename){
    FILE* file = fopen(filename,"w");   //opens 'filename' and assigns to 'file' the pointer to that file;

    if(file == NULL){
        printf("Failed to open file");
    }

    fprintf(file, "velocity,angleAccPedal,angleBrakePedal,requestCarStart,voltage,current,currentMode,rpm,voltage,current\n"); //csv header

    for(int i = 0; i < numEntries; i++){
        fprintf(file, "%u,%u,%u,%d,%u,%u,%d,%u,%f,%f\n", csvdata->velocity[i], csvdata->angleAccPedal[i], csvdata->angleBrakePedal[i],
        csvdata->requestCarStart[i], csvdata->batteryvoltage[i], csvdata->batterycurrent[i], csvdata->currentMode[i], csvdata->rpm[i], 
        csvdata->voltage[i], csvdata->current[i]);
    }

    fclose(file);
}

int main(){

    csvdata mycsvdata;

    //write values

    mycsvdata.velocity[0] = 100;
    mycsvdata.angleAccPedal[0] = 100;
    mycsvdata.angleBrakePedal[0] = 100;
    mycsvdata.batterycurrent[0] = 100;
    mycsvdata.batteryvoltage[0] = 100;
    mycsvdata.currentMode[0] = true;
    mycsvdata.requestCarStart[0] = true;
    mycsvdata.rpm[0] = 100;
    mycsvdata.current[0] = 100;
    mycsvdata.voltage[0] = 100;
  
    writeCSV(&mycsvdata, 1, "data.csv");

    return 0;

}