/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ring_buffer.h
 * 
 * Header file for ring_buffer.c
 * Defines ring_buf_t struct datatype
 *
 * ========================================
*/
#ifndef RING_BUFFER_H
#define RING_BUFFER_H
    
    #include <stdint.h>
    
    typedef struct {
        int16_t * buffer;
        uint16_t head;
        uint16_t maxlen;
    } ring_buf_t;
    
    /**************
    function: ring_buf_push
    description: Pushes the provided value into the provided ring buffer
    parameters: ring_buf_t *c, uint16_t data
    returns: none
    notes: none
    ***************/
    void ring_buf_push(ring_buf_t *c, int16_t data);
    
    /**************
    function: initialize_ring_buffer
    description: Initializes the provided ring buffer with the provided values and variables
    parameters: ring_buf_t *ring_buf, int16_t * buffer, uint16_t maxlen
    returns: none
    notes: none
    ***************/
    void initialize_ring_buffer(ring_buf_t *ring_buf, int16_t * buffer, uint16_t maxlen);
#endif
/* [] END OF FILE */
