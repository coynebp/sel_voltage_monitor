/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_shared.h
 * 
 * This file defines common data types and constants needed for the CM0+
 * and the CM4 processor to communicate.
 * 
 * ========================================
*/
#ifndef IPC_SHARED_H
#define IPC_SHARED_H	
    
    #include <stdint.h>

    #define IPC_CM0_TO_CM4_CLIENT_ID        0
    #define IPC_CM4_TO_CM0_CLIENT_ID        1

    typedef enum ipc_msg_datatype
    {
        type_voltage,
        type_event,
        type_upper_threshold,
        type_lower_threshold,
        type_trigger,
        type_enable,
        type_hold,
    } ipc_msg_datatype;

    #define MESSAGE_SIZE 288

    typedef struct __attribute__((packed, aligned(4)))
    {
        uint8_t             clientId;
        uint8_t             userCode;
        uint16_t            intrMask;
        ipc_msg_datatype    type;
        uint8_t             data[MESSAGE_SIZE];
    } ipc_msg_t;

#endif 
/* [] END OF FILE */
