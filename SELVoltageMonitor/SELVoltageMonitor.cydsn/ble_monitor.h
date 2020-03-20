/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ble_monitor.h
 * 
 * This file contains the required libraries and
 * function prototype for ble_monitor.c.
 *
 * ========================================
*/
#ifndef BLE_MONITOR_H
    #define BLE_MONITOR_H
    
    #define GATTS_VOLTAGE_SIZE 2
    #define GATTS_EVENT_SIZE 288
    #define GATTS_NUM_EVENTS_SIZE 1
    #define GATTS_EVENT_NUM_SIZE 1
    #define GATTS_UPPER_THRESHOLD_SIZE 2
    #define GATTS_LOWER_THRESHOLD_SIZE 2
    #define GATTS_TRIGGER_SIZE 1
    
    #include <project.h>
    #include <stdlib.h>
    #include "ipc_cm0p.h"
    
    void GenericEventHandler(uint32 event, void *eventParam);
    
#endif
/* [] END OF FILE */
