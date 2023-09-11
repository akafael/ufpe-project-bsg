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
}

int main() {
    // Create instances of the necessary structs
    Vehicle vehicle;
    BSG bsg;
    Engine engine;
    Battery battery;

    // Initialize the vehicle parameters
    vehicle.velocity = 60;             // Vehicle speed in km/h
    vehicle.angleAccPedal = 30;        // Accelerator pedal angle in degrees
    vehicle.angleBrakePedal = 10;      // Brake pedal angle in degrees
    vehicle.requestCarStart = 1;       // Request to start the car (1 for yes, 0 for no)
    
    // Initialize the engine parameters
    bsg.currentMode = BSG_IDLE;     // Initial mode is IDLE
    bsg.rpm = 0;                    // Engine RPM
    bsg.voltage = 12.0;             // Engine voltage in volts
    bsg.current = 0.0;              // Engine current in amperes

    // Initialize the BSG parameters
    engine.rpm = 0;                       // BSG RPM

    // Initialize the battery parameters
    battery.voltage = 14.0;            // Battery voltage in volts
    battery.current = 0.0;             // Battery current in amperes

    return 0;
}
