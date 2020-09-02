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
#define RING_BUF_LEN 1000
#define EVENT_LENGTH 432
#define CYCLE_LENGTH 36
#define FILTER_LENGTH 36

    #include "project.h"
    #include <stdio.h>
    #include <math.h>
    #include "ipc_cm4.h"
    #include "ring_buffer.h"
    #include "filter.h"
    #include <inttypes.h>
    
    // Trigger Enable
    bool trigger_enable;
    bool voltage_normal;

    // Trigger
    bool trigger_set;
    uint16_t samples_to_extract;

    // Thresholds
    uint16_t upper_threshold;
    uint16_t lower_threshold;

    void voltage_monitor_init(void);
    void ADC_Interrupt(void);
    void SCAN_Interrupt(void);
    void trigger(void);
    void extract_past_three_cycles(ring_buf_t *rbuf, int16_t *event_arr);
    int squared_magnitude(int a, int b);
    
#endif
/* [] END OF FILE */
