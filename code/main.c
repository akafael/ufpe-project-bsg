#include "bsgcontrol.h"
#include "csvutils.h"
#include <stdio.h>

void printVehicleData(VehicleData vehicleData)
{
    // Determine the BSG mode based on vehicle and engine parameters
    StateBSG mode = selectBSGMode(vehicleData.vehicle, vehicleData.engine, vehicleData.bsg, vehicleData.battery);

    // Display the selected BSG mode
    switch (mode) {
        case BSG_IDLE:
            printf("BSG Mode: IDLE\n");
            break;
        case BSG_STARTER:
            printf("BSG Mode: STARTER\n");
            break;
        case BSG_MOTOR:
            printf("BSG Mode: MOTOR\n");
            break;
        case BSG_GENERATOR:
            printf("BSG Mode: GENERATOR\n");
            break;
        default:
            printf("Unknown BSG Mode\n");
            break;
    }
    //printf("Vehicle Velocity:\n\t-Km/h:%d\n",vehicleData.vehicle.velocity);
    //printf("Vehicle Accpedal:\n\t-Acc:%d\n",vehicleData.vehicle.angleAccPedal);
    //printf("BSG info:\n\t-RPM:%d\n",vehicleData.bsg.rpm);
    //printf("BSG info:\n\t-Voltage(V):%d\n",vehicleData.bsg.voltage);
    //printf("BSG info:\n\t-Current(I):%d\n",vehicleData.bsg.current);
    //printf("Combustion Engine:\n\t-RPM:%d\n",vehicleData.engine.rpm);
    //printf("Battery:\n\t-Voltage(V):%d\n",vehicleData.battery.voltage);
    //printf("Battery:\n\t-Current(I):%d\n",vehicleData.battery.current);
}

int main(int argc, char *argv[]) {

    if(argc < 3)
    {
        printf("Error: Invalid number of arguments. Expecting 2.\n");
        return(1);
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];

    VehicleData csvdata[100];

    const int numEntries = 10;

    printf(">> Reading input file: %s\n",inputFile);

    readCSV(csvdata,numEntries,inputFile);

    for(int i = 0; i < numEntries; i++){
        printf("(%d) ------ \n",i);
        printVehicleData(csvdata[i]);
    }

    printf(">> Writting output file: %s\n",outputFile);
    writeCSV(csvdata,numEntries,outputFile);

    return 0;
}
