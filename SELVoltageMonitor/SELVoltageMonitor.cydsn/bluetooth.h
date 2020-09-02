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
    #define GATTS_THRESHOLD_SIZE 2
    #define GATTS_TRIGGER_SIZE 1
    
    #include <project.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <string.h>
    #include <inttypes.h>
    #include "ipc_cm0p.h"
    
    uint16_t events[10][160];
    uint8_t num_events;
    uint8_t upper_thresh[2];
    uint8_t lower_thresh[2];
    
    const uint8_t** flashPtrs;
    
    void init_ble(const uint8_t** Ptrs);
    
    void GenericEventHandler(uint32 event, void *eventParam);
    
    void write_event_to_server(uint8_t *event_byte_arr);
    void write_num_events_to_server(uint8_t * num_events_ptr);
    void write_voltage_to_server(uint8_t * voltage_ptr);
    void write_threshold_to_server(uint8_t * threshold_ptr, char upper_or_lower);
    
    void update_flash_config(void);
    
#endif
/* [] END OF FILE */
