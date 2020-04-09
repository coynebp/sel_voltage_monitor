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
#define FILTER_LENGTH 18
   
    #include "project.h"
    #include <stdio.h>
    #include <math.h>
    #include "ipc_cm4.h"
    #include "ring_buffer.h"
    #include "filter.h"
    #include <inttypes.h>
    
    // Event memory
    int16_t event[EVENT_LENGTH];
    
    // Ring buffer
    int16_t buffer[RING_BUF_LEN];
    ring_buf_t ring_buffer;
    
    // Cosine filter
    int32 raw_samples[FILTER_LENGTH];
    int16 cosine_taps[FILTER_LENGTH];
    fir_filter_t cosine_filter;
    int16 temp_values[FILTER_LENGTH + 1];
    uint8_t filter_charged;
    uint8_t temp_charged;
    
    // Averaging
    int32_t averaging_array[36];
    uint8_t averaging_charged;
    
    // Trigger Enable
    bool trigger_enable;
    
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
    
#endif
/* [] END OF FILE */
