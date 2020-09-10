/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * voltage_monitor.h
 * 
 * Header file for voltage_monitor.c
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

    void voltage_monitor_init(void);
    void ADC_Interrupt(void);
    void SCAN_Interrupt(void);
    void trigger(void);
    void clear_trigger(void);
    void extract_past_three_cycles(ring_buf_t *rbuf, int16_t *event_arr);
    void set_upper_threshold(uint16_t threshold);
    void set_lower_threshold(uint16_t threshold);
    void set_trigger_enable(bool val);
    void set_leds(bool over, bool under, bool normal);
    int32_t squared_magnitude(int32_t a, int32_t b);
    
#endif
/* [] END OF FILE */
