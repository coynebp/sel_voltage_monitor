/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "ring_buffer.h"

void ring_buf_push(ring_buf_t *c, uint16_t data)
{
    uint8_t next;
    //Next is where head will point to after this write.
    next = c->head + 1;
    if (next >= c->maxlen)
        next = 0;
    // Load data and then move
    c->buffer[c->head] = data;
    // Head to next data offset. // return success to indicate successful push.
    c->head = next;
}

void extract_event(uint8_t event_index, uint16_t * events, ring_buf_t * rbuf)
{
    
}
/* [] END OF FILE */
