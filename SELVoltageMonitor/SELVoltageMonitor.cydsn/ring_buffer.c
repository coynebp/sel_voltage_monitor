/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ring_buffer.c
 *
 * Circular buffer used for storing past sample values.
 * 
 * Based on code by Siddharth Chandrasekaran
 * Published at: https://embedjournal.com/implementing-circular-buffer-embedded-c/
 *
 * ========================================
*/
#include "ring_buffer.h"

void ring_buf_push(ring_buf_t *c, int16_t data)
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
