/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ble_monitor.h
 * 
 * This file contains the required libraries and
 * function prototype for ble_monitor.c.
 *
 * ========================================
*/
#ifndef BLE_MONITOR_H
    #define BLE_MONITOR_H
    
    #include <project.h>
    #include <stdlib.h>
    #include "ipc_cm0p.h"
    
    void GenericEventHandler(uint32 event, void *eventParam);
    
#endif
/* [] END OF FILE */
