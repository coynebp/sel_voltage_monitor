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
    uint16_t threshold;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case EVENT_NUM:
                printf("Event Number: %" PRIx8, msgPtr->data[0]);
                printf("\r\n");
                break;
            case UPPER_THRESHOLD:
                threshold = msgPtr->data[1];
                threshold = threshold <<8;
                threshold += msgPtr->data[0];
                printf("New Upper Threshold: %" PRIx16, threshold);
                printf("\r\n");
                break;
            case LOWER_THRESHOLD:
                threshold = msgPtr->data[1];
                threshold = threshold <<8;
                threshold += msgPtr->data[0];
                printf("New Lower Threshold: %" PRIx16, threshold);
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
    rdyToRecvMsg = true;
}

void send_voltage(uint16_t * voltage)
{
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = VOLTAGE;
    ipcMsgForCM0.data[0] = ((uint8_t *)voltage)[0];
    ipcMsgForCM0.data[1] = ((uint8_t *)voltage)[1];
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                            CY_IPC_EP_CYPIPE_CM4_ADDR, 
                            &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
    if (result == CY_IPC_PIPE_SUCCESS)
    {
        printf("SUCCESS\r\n");
    }
}

void send_event_num(uint8_t * event_num)
{
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = EVENT_NUM;
    ipcMsgForCM0.data[0] = *event_num;
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                            CY_IPC_EP_CYPIPE_CM4_ADDR, 
                            &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
    if (result == CY_IPC_PIPE_SUCCESS)
    {
        printf("SUCCESS\r\n");
    }
}

void send_num_events(uint8_t * num_events)
{
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = NUM_EVENTS;
    ipcMsgForCM0.data[0] = *num_events;
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                            CY_IPC_EP_CYPIPE_CM4_ADDR, 
                            &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
    if (result == CY_IPC_PIPE_SUCCESS)
    {
        printf("SUCCESS\r\n");
    }
}

void send_event(uint16_t * event)
{
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = EVENT;
    uint16_t entry;
    for (int i = 0; i < 144; ++i)
    {
        entry = event[i];
        ipcMsgForCM0.data[2 * i] = ((uint8_t *)&entry)[0];
        ipcMsgForCM0.data[2 * i + 1] = ((uint8_t *)&entry)[1];
    }
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                            CY_IPC_EP_CYPIPE_CM4_ADDR, 
                            &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
    if (result == CY_IPC_PIPE_SUCCESS)
    {
        printf("SUCCESS\r\n");
    }
}
/* [] END OF FILE */
