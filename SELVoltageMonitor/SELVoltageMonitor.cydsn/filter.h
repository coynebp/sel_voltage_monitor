/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * filter.h
 *
 * Header file for header.c
 * Defines a struct for an FIR filter.
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
    
    /**************
    function: initialize_filter
    description: Sets up the given filter struct with the given values and variables
    parameters: uint8_t length, int16_t * taps, int16_t gain, int32_t * samples, fir_filter_t * filter
    returns: none
    notes: none
    ***************/
    void initialize_filter(uint8_t length, int16_t * taps, int16_t gain, int32_t * samples, fir_filter_t * filter);
    
    /**************
    function: insert_filter_value
    description: Inserts given value into the given filter, removes oldest sample
    parameters: fir_filter_t *filter, int32_t value
    returns: none
    notes: none
    ***************/
    void insert_filter_value(fir_filter_t *filter, int32_t value);
    
    /**************
    function: get_filtered_value
    description: Returns current filtered value, divided by gain of filter
    parameters: fir_filter_t *filter
    returns: none
    notes: none
    ***************/
    int16_t get_filtered_value(fir_filter_t *filter);

#endif
/* [] END OF FILE */
