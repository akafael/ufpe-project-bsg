#ifndef CSV_UTILS_H
#define CSV_UTILS_H

#include <stdint.h>
#include "vehicle.h"
#include "engine.h"
#include "battery.h"
#include "bsg.h"
#include "time.h"

/**
 * @brief Struct with Vehicle, Engine, Battery and BSG data
 * 
 */
typedef struct VehicleDataStruct {
    uint32_t timeMillis;      ///< Time (ms)
    Vehicle vehicle;          ///< Vehicle odometer and driver input
    Engine engine;            ///< Engine sensors data
    Battery battery;          ///< Battery sensors data
    BSG bsg;                  ///< BSG sensors data
} VehicleData;

/**
 * @brief Create a CSV file with all vehicle data signals stored at VehicleData
 * 
 * @param[in] csvdata VehicleData to be stored as CSV
 * @param[in] numEntries csvdata array size
 * @param[in] filename path to input file
 */
int writeCSV(const VehicleData* csvdata, int numEntries, const char* filename);

/**
 * @brief Convert VehicleData to string with fields splited by comma
 * 
 * @param[in] data input data
 * @param[out] csvLine String with fields splitedby comma
 */
void writeCSVLine(VehicleData data, char* csvLine);

/**
 * @brief Read a CSV file with all signals and generate a array with VehicleData
 * 
 * @param[out] csvdata 
 * @param[in] numEntries 
 * @param[in] filename 
 */
int readCSV(VehicleData* csvdata, int numEntries, const char* filename);

/**
 * @brief Convert a string with field splite by comma into a VehicleData
 * 
 * @param[out] data 
 * @param[in] csvLine 
 */
void readCSVLine(VehicleData* data, const char* csvLine);

#endif
