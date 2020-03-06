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
#include "IPC_CM4.h"

volatile bool rdyToReceive = true;

void CM4_MessageCallback(uint32_t *msg)
{
    rdyToReceive = false;
    unsigned long data = 0;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msg != NULL)
    {
        data = msgPtr->data;
        printf("NEW VALUE: 0x%lx\r\n", data);
    }
    rdyToReceive = true;
}
/* [] END OF FILE */
