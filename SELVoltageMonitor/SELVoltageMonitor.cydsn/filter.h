/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * filter.h
 * 
 * 
 *
 * ========================================
*/
#ifndef FILTER_H
#define FILTER_H
    
    #include <stdint.h>
    
    typedef struct {
        uint8_t length;
        int16_t * taps;
        uint16_t gain;
        int32_t * samples;
    } fir_filter_t;
    
    int16_t get_filtered_value(uint16_t raw, fir_filter_t *filter);

#endif
/* [] END OF FILE */
