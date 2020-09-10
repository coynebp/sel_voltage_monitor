/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ble_monitor.h
 * 
 * Header file for bluetooth.c
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
    
    /**************
    function: init_ble
    description: Initializes BLE server
    parameters: const uint8** Ptrs (array of pointers to flash locations)
    returns: none
    notes: none
    ***************/
    void init_ble(const uint8_t** Ptrs);
    
    /**************
    function: BluetoothEventHandler
    description: Event handler for BLE events
    parameters: uint32 event, void *eventParam (Both parameters automatically passed)
    returns: none
    notes: none
    ***************/
    void BluetoothEventHandler(uint32 event, void *eventParam);
    
    /**************
    function: write_event_to_server
    description: Writes the given event to the BLE Event service
    parameters: uint8_t *event_byte_arr
    returns: none
    notes: assumes that event_byte_arr contains 160 16 bit values
        in little endian format.
    ***************/
    void write_event_to_server(uint8_t *event_byte_arr);
    
    /**************
    function: write_num_events_to_server
    description: Writes the given number of events to the BLE server.
    parameters: uint8_t * num_events_ptr
    returns: none
    notes: none
    ***************/
    void write_num_events_to_server(uint8_t * num_events_ptr);
    
    /**************
    function: write_voltage_to_server
    description: Writes the given voltage to the BLE server.
    parameters: uint8_t * voltage_ptr
    returns: none
    notes: voltage_ptr is a little endian representation of
        the 16 bit voltage
    ***************/
    void write_voltage_to_server(uint8_t * voltage_ptr);
    
    /**************
    function: write_threshold_to_server
    description: Writes the given voltage threshold to the BLE server
    parameters: uint8_t * threshold_ptr, char upper_or_lower
    returns: none
    notes: 
        -threshold_ptr is a little endian representation of
        the 16 bit voltage value
        -upper_or_lower should be 'u' for upeer and 'l' for lower
    ***************/
    void write_threshold_to_server(uint8_t * threshold_ptr, char upper_or_lower);
    
    /**************
    function: update_flash_config
    description: Updates the configuration information in flash storage
    parameters: none
    returns: none
    notes: none
    ***************/
    void update_flash_config(void);
    
    /**************
    function: record_event
    description: Records the given event in flash storage and in RAM
    parameters: uint8_t * new_event
    returns: none
    notes: new_event is a little endian array of 16 bit values making up
        the event
    ***************/
    void record_event(uint8_t * new_event);
    
    /**************
    function: record_voltage
    description: Records current voltage in the BLE server
    parameters: uint8_t * data
    returns: none
    notes: data is a little endian representation of
        the 16 bit voltage
    ***************/
    void record_voltage(uint8_t * data);
    
#endif
/* [] END OF FILE */
