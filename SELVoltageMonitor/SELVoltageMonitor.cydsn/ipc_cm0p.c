/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm0p.c
 * 
 * This file initilizes the varaibles and defines the functions
 * needed for the CM0+ processor to communicate with the CMO4.
 *
 * ========================================
*/
#include "ipc_cm0p.h"

volatile bool rdyToRecvMsg = true;

ipc_msg_t ipcMsgForCM4 = {              /* IPC structure to be sent to CM4  */
    .clientId = IPC_CM0_TO_CM4_CLIENT_ID,
    .userCode = 0,
    .intrMask = CY_IPC_CYPIPE_INTR_MASK,
    .type = 0,
    .data   = {0}
};

void CM0_MessageCallback(uint32_t *msg)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    uint32_t type;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case EVENT_NUM:

                break;
            
            case EVENT:
                
                break;
            
            case NUM_EVENTS:

                break;

            case VOLTAGE:

                break;
            
            default:
                break;
        }
    }
}

void CM0_ReleaseCallback(void)
{
    /* Message processed by CM4. Ready to receive a new message */
    rdyToRecvMsg = true;
}
/* [] END OF FILE */
