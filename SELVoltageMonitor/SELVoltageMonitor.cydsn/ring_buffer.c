/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ring_buffer.c
 * 
 * Defines the push function for the ring buffer, as well as a function
 * for extracting events from the buffer.
 *
 * ========================================
*/
#include "ring_buffer.h"

void ring_buf_push(ring_buf_t *c, uint16_t data)
{
    uint16_t next;
    //Next is where head will point to after this write.
    next = c->head + 1;
    if (next >= c->maxlen)
        next = 0;
    // Load data and then move
    c->buffer[c->head] = data;
    // Head to next data offset.
    c->head = next;
}

void initialize_ring_buffer(ring_buf_t *ring_buf, int16_t * buffer, uint16_t maxlen)
{
    ring_buf->buffer = buffer;
    ring_buf->head = 0;
    ring_buf->maxlen = maxlen;
}
/* [] END OF FILE */
