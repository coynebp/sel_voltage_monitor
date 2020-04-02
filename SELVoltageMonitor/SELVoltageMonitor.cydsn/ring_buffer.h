/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ring_buffer.h
 * 
 * This file contains the included libraries, data types, and
 * function prototype for ring_buffer.c.
 *
 * ========================================
*/
#ifndef RING_BUFFER_H
#define RING_BUFFER_H
    
    #include <stdint.h>
    
    typedef struct {
        int16_t * buffer;
        uint16_t head;
        uint16_t check;
        uint16_t maxlen;
    } ring_buf_t;
    
    void ring_buf_push(ring_buf_t *c, uint16_t data);
#endif
/* [] END OF FILE */
