/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cmop.h
 * 
 * This file contains the included libraries, globals, and
 * function prototype for ipc_cmop.c
 *
 * ========================================
*/
#ifndef IPC_CM0P_H
#define IPC_CM0P_H
    
    #include "project.h"
    #include "ipc_shared.h"
    #include "bluetooth.h"
    #include <stdint.h>
    volatile bool rdyToRecvMsg;
    ipc_msg_t ipcMsgForCM4;
    
    void CM0_MessageCallback(uint32_t *msg);
    void CM0_ReleaseCallback(void);
    
    void send_threshold(uint8_t * threshold, ipc_msg_datatype upper_or_lower);
    void send_trigger(void);
    void send_enable(uint8_t trigger);
    
#endif
/* [] END OF FILE */
