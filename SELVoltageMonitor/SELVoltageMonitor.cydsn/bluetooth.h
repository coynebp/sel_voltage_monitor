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
#ifndef BLUETOOTH_H
    #define BLUETOOTH_H
    
    #define GATTS_VOLTAGE_SIZE 2
    #define GATTS_EVENT_SIZE 20
    #define GATTS_NUM_EVENTS_SIZE 1
    #define GATTS_EVENT_NUM_SIZE 1
    #define GATTS_UPPER_THRESHOLD_SIZE 2
    #define GATTS_LOWER_THRESHOLD_SIZE 2
    #define GATTS_TRIGGER_SIZE 1
    
    #include <project.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdio.h>
    #include "ipc_cm0p.h"
    
    uint16_t events[10][144];
    
    void init_ble(void);
    
    void GenericEventHandler(uint32 event, void *eventParam);
    
    void write_event_to_server(uint8_t *event_byte_arr);
    
#endif
/* [] END OF FILE */