/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * filter.h
 * 
 * ========================================
*/
#ifndef FILTER_H
#define FILTER_H
    
    #include <stdint.h>
    #include <stdbool.h>
    
    typedef struct {
        uint8_t length; // Filter length
        int16_t * taps; // Array of filter taps
        uint16_t gain; // Gain of filter (for use in calculations)
        int32_t * samples; // Array of samples
        bool is_charged;// Returns true when filter is charged.
        uint8_t num_samples;
    } fir_filter_t;
    
    void initialize_filter(uint8_t length, int16_t * taps, int16_t gain, int32_t * samples, fir_filter_t * filter);
    void insert_filter_value(fir_filter_t *filter, int32_t value);
    int16_t get_filtered_value(fir_filter_t *filter);

#endif
/* [] END OF FILE */
