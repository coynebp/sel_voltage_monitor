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
    
    /**************
    function: voltage_monitor_init
    description: Initializes all required values for the voltage monitor
    parameters: ring_buf_t *c, uint16_t data
    returns: none
    notes: none
    ***************/
    void voltage_monitor_init(void);
    
    /**************
    function: ADC_Interrupt
    description: Routine when a new ADC value is ready to be processed. Pushes data into
        the FIR filter, calculates the new average RMS value, extracts samples for events
        if required, and sends required information to the CM0+.
    parameters: none
    returns: none
    notes: This function is called when the "end of scan" output is asserted on the ADC.
    ***************/
    void ADC_Interrupt(void);
    
    /**************
    function: SCAN_Interrupt
    description: Interrupt function to start an ADC reading.
    parameters: None
    returns: none
    notes: Called repeatedly at 2.16kHz to acheive desired sample rate
    ***************/
    void SCAN_Interrupt(void);
    
    /**************
    function: trigger
    description: Starts the event capture process by setting the trigger and calling
        extract_last_three_cycles.
    parameters: None
    returns: none
    notes: none
    ***************/
    void trigger(void);
    
    /**************
    function: clear_trigger
    description: Finishes the event capture process by sending the 144-sample event
        the CM0+ and clearing the trigger.
    parameters: None
    returns: none
    notes: none
    ***************/
    void clear_trigger(void);
    
    /**************
    function: extract_past_three_cycles
    description: Pulls the most recent twelve cycles from the provided ring buffer
        and places the samples in the provided event array.
    parameters: ring_buf_t *rbuf, int16_t *event_arr
    returns: none
    notes: Assumes a sample rate of 2.16kHz
    ***************/
    void extract_past_twelve_cycles(ring_buf_t *rbuf, int16_t *event_arr);
    
    /**************
    function: set_upper_threshold
    description: Sets upper threshold to provided 16 bit value.
    parameters: uint16_t threshold
    returns: none
    notes: none
    ***************/
    void set_upper_threshold(uint16_t threshold);
    
    /**************
    function: set_lower_threshold
    description: Sets lower threshold to provided 16 bit value.
    parameters: uint16_t threshold
    returns: none
    notes: none
    ***************/
    void set_lower_threshold(uint16_t threshold);
    
    /**************
    function: set_trigger_enable
    description: Sets the trigger_enable to the provided boolean value
    parameters: bool val
    returns: none
    notes: none
    ***************/
    void set_trigger_enable(bool val);
    
    /**************
    function: set_leds
    description: Sets the voltage indication leds to the provided values.
    parameters: bool over, bool under, bool normal
    returns: none
    notes: over - indicates overvoltage condition
           under - indicates undervoltage condition
           normal - indicates normal voltage condition
    ***************/
    void set_leds(bool over, bool under, bool normal);
    
    /**************
    function: squared_magnitude
    description: Returns the squared magnitude using the real and imaginary
        parts provided
    parameters: int32_t real, int32_t imag
    returns: int32_t
    notes: Assumes the squared magnitude can be represented in 32 bits.
    ***************/
    int32_t squared_magnitude(int32_t real, int32_t imag);
    
    /**************
    function: set hold time
    description: Sets a number of samples during which triggers will be disabled
    parameters: uint32_t hold_time
    returns: none
    ***************/
    void set_hold_time(uint32_t hold_time);
    
#endif
/* [] END OF FILE */
