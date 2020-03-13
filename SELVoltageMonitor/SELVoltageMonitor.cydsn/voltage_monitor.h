/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * voltage_monitor.h
 * 
 * This file contains the included libraries and
 * function prototypes for voltage_monitor.c.
 *
 * ========================================
*/
#ifndef VOLTAGE_MONITOR_H
#define VOLTAGE_MONITOR_H
   
    #include "project.h"
    #include <stdio.h>
    #include "ipc_cm4.h"
    
    void voltage_monitor_init(void);
    void voltage_monitor_loop(void);
    
#endif
/* [] END OF FILE */
