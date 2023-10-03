#ifndef VEHICLE_H
#define VEHICLE_H

#include <stdint.h>

/**
 * @brief Vehicle odometer and driver input data from pedals
 * 
 */
typedef struct VehicleStruct {
  uint16_t velocity;                   ///< [km/h] Vehicle velocity
  uint16_t angleAccPedal;              ///< [%] Vehicle throttle pedal pressed percentage 
  uint16_t angleBrakePedal;            ///< [%] Vehicle brake pedal pressed percentage
  uint8_t requestCarStart;             ///< [bool] Vehicle signil from requesting engine start
} Vehicle;

/**
 * @brief DriverIntention state representation considering Vehicle data
 * 
 */
typedef enum DriverIntentionEnum {
  DRIVE_INTENTION_NOTHING = 0,         ///< DriveIntention state for no input from driver
  DRIVE_INTENTION_REDUCE_SPEED = 1,    ///< DriveIntention state for reducing vehicle speed intention
  DRIVE_INTENTION_KEEP_SPEED = 2,      ///< DriveIntention state for keep vehicle speed intention
  DRIVE_INTENTION_INCREASE_SPEED = 3,  ///< DriveIntention state for increase vehicle speed intention
} DriverIntention;

/**
 * @brief Translate the current input from vehicle odometry into a DriverIntention state
 * 
 * @param[in] vehicle Vehicle Driver and Odometry data
 * @return DriverIntention 
 */
DriverIntention getDriverIntention(const Vehicle vehicle);

#endif // VEHICLE_H
