/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * voltage_monitor.h
 * 
 * This file contains the included libraries,
 * function prototypes, and globals, for voltage_monitor.c.
 *
 * ========================================
*/
#ifndef VOLTAGE_MONITOR_H
#define VOLTAGE_MONITOR_H
#define RING_BUF_LEN 400
   
    #include "project.h"
    #include <stdio.h>
    #include "ipc_cm4.h"
    #include "ring_buffer.h"
    #include <inttypes.h>
    
    uint16_t event[10][144];
    uint8_t next_event_index;
    
    uint16_t arr[RING_BUF_LEN];
    ring_buf_t ring_buffer;
    
    uint16_t upper_threshold;
    uint16_t lower_threshold;
    
    void voltage_monitor_init(void);
    void ADC_Interrupt(void);
    void SCAN_Interrupt(void);
    uint16_t calc_rms(ring_buf_t * ring_buf);
    
#endif
/* [] END OF FILE */
