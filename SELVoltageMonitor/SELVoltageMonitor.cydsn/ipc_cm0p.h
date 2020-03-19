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
    #include <stdint.h>
    volatile bool rdyToRecvMsg;
    ipc_msg_t ipcMsgForCM4;
    
    void CM0_MessageCallback(uint32_t *msg);
    void CM0_ReleaseCallback(void);
    
#endif
/* [] END OF FILE */
