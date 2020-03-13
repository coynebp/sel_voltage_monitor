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

    next = c->head + 1;  // next is where head will point to after this write.
    if (next >= c->maxlen)
        next = 0;
    c->buffer[c->head] = data;  // Load data and then move
    c->head = next;             // head to next data offset. // return success to indicate successful push.
}

/* [] END OF FILE */
