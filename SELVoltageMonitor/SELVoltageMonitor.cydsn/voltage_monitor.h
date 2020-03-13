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
#define RING_BUF_LEN 10
   
    #include "project.h"
    #include <stdio.h>
    #include "ipc_cm4.h"
    #include "ring_buffer.h"
    #include <inttypes.h>
    
    uint16_t result;
    double adc_voltage;
    
    ring_buf_t rbuf;
    uint16_t arr[RING_BUF_LEN];
    
    void voltage_monitor_init(void);
    void voltage_monitor_loop(void);
    
#endif
/* [] END OF FILE */
