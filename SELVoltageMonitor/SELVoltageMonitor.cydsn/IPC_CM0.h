/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef IPC_CM0_H
    
    #define IPC_CM0_H
    #include "project.h"
    #include "ipc_shared.h"
    volatile bool rdyToRecvMsg;
    ipc_msg_t ipcMsgForCM4;
    
    void CM0_ReleaseCallback(void);
    
#endif
/* [] END OF FILE */
