/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm4.h
 * 
 * Header file for ipc_cm4.c
 *
 * ========================================
*/
#ifndef IPC_CM4_H
#define IPC_CM4_H
    
    #include "project.h"
    #include "voltage_monitor.h"
    #include "ipc_shared.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <inttypes.h>
    
    /**************
    function: CM4_MessageCallback
    description: Callback function when CM4 receives a message from the CM0+
    parameters: uint32_t *msg (automatically passed)
    returns: none
    notes: none
    ***************/
    void CM4_MessageCallback(uint32_t *msg);
    
    /**************
    function: CM4_ReleaseCallback
    description: Release callback for when the CM0+ 
    parameters: uint32_t *msg (automatically passed)
    returns: none
    notes: none
    ***************/
    void CM4_ReleaseCallback(void);
    
    /**************
    function: send_voltage
    description: Sends the voltage value provided to the CM0+ to be placed
        in the BLE server
    parameters: uint16_t * voltage
    returns: none
    notes: none
    ***************/
    void send_voltage(uint16_t * voltage);
    
    /**************
    function: send_event
    description: Sends the provided event report to the CM0+
    parameters: int16_t * event
    returns: none
    notes: none
    ***************/
    void send_event(int16_t * event);
    
  #endif
/* [] END OF FILE */
