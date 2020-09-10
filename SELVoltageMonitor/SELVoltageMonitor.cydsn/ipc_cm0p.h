/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cmop.h
 * 
 * Header file for ipc_cm0p.c
 *
 * ========================================
*/
#ifndef IPC_CM0P_H
#define IPC_CM0P_H
    
    #include "project.h"
    #include "ipc_shared.h"
    #include "bluetooth.h"
    #include <stdint.h>
    
    /**************
    function: CM0_MessageCallback
    description: Callback function when a message is received from CM4
    parameters: uint32_t *msg (Automatically passed)
    returns: none
    notes: none
    ***************/
    void CM0_MessageCallback(uint32_t *msg);
    
    /**************
    function: CM0_ReleaseCallback
    description: Notification callback when message is received by CM4
    parameters: none
    returns: none
    notes: none
    ***************/
    void CM0_ReleaseCallback(void);
    
    /**************
    function: send_threshold
    description: Sends upper or lower threshold to CM4
    parameters: uint8_t * threshold, ipc_msg_datatype upper_or_lower
    returns: none
    notes: threshold should be a little endian representation of 16 bit value. See ipc_shared.h for
        definition of ipc_msg_datatype enumerated type. Assumed that this value is either 
        upper_threshold_type or lower_threshold_type.
    ***************/
    void send_threshold(uint8_t * threshold, ipc_msg_datatype upper_or_lower);
    
    /**************
    function: send_trigger
    description: Manually sets a trigger to record an event in the CM4
    parameters: none
    returns: none
    notes: This function will trigger an event whether or not triggers have been
        enabled.
    ***************/
    void send_trigger(void);
    
    /**************
    function: send_enable
    description: Enables or disables automatic triggers in the CM4.
    parameters: uint8_t enable
    returns: none
    notes: enable should be '1' to enable triggers and '0' to disable triggers.
    ***************/
    void send_enable(uint8_t enable);
    
#endif
/* [] END OF FILE */
