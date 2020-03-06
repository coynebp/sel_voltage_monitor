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
*/#ifndef IPC_CM4_H
    
    #define IPC_CM4_H
    
    #include "project.h"
    #include "ipc_shared.h"
    #include <stdio.h>
    #include <stdlib.h>
    volatile bool rdyToReceive;
    
    void CM4_MessageCallback(uint32_t *msg);
    
  #endif
/* [] END OF FILE */
