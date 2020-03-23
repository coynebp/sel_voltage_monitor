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
    #include "voltage_monitor.h"
    #include "ipc_shared.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <inttypes.h>
    volatile bool rdyToRecvMsg;
    ipc_msg_t ipcMsgForCM0;
    
    void CM4_MessageCallback(uint32_t *msg);
    void CM4_ReleaseCallback(void);
    
    void send_voltage(uint16_t * voltage);
    void send_event_num(uint8_t * event_num);
    void send_num_events(uint8_t * num_events);
    void send_event(uint16_t event[]);
    
  #endif
/* [] END OF FILE */
