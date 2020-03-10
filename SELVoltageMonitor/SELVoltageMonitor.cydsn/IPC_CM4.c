/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm4.c
 * 
 * This file initilizes the varaibles and defines the functions
 * needed for the CM4 processor to communicate with the CMO+.
 *
 * ========================================
*/
#include "ipc_cm4.h"

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
