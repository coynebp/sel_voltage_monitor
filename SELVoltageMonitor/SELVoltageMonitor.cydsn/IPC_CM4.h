/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm4.h
 * 
 * This file contains the included libraries, globals, and
 * function prototype for ipc_cm4.c
 *
 * ========================================
*/
#ifndef IPC_CM4_H
    
    #define IPC_CM4_H
    
    #include "project.h"
    #include "ipc_shared.h"
    #include <stdio.h>
    #include <stdlib.h>
    volatile bool rdyToReceive;
    
    void CM4_MessageCallback(uint32_t *msg);
    
  #endif
/* [] END OF FILE */
