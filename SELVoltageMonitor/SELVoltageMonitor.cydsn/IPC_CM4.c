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

volatile bool rdyToRecvMsg = true;

ipc_msg_t ipcMsgForCM0 = {
    .clientId = IPC_CM4_TO_CM0_CLIENT_ID,
    .userCode = 0,
    .intrMask = CY_IPC_CYPIPE_INTR_MASK,
    .type = 0,
    .data   = {0}
};

void CM4_MessageCallback(uint32_t *msg)
{
    uint32_t type;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case EVENT_NUM:
                printf("Event Number: %" PRIx16, msgPtr->data[0]);
                printf("\r\n");
                break;
            case UPPER_THRESHOLD:
                printf("New Upper Threshold: %" PRIx16, msgPtr->data[0]);
                printf("\r\n");
                break;
            case LOWER_THRESHOLD:
                printf("New Lower Threshold: %" PRIx16, msgPtr->data[0]);
                printf("\r\n");
                break;
            case TRIGGER:
                printf("TRIGGER\r\n");
                break;
            default:
                break;
        }
    }
}

void CM4_ReleaseCallback(void)
{
    /* Message processed by CM4. Ready to receive a new message */
    rdyToRecvMsg = true;
}
/* [] END OF FILE */
