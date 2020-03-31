/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm4.c
 * 
 * This file initilizes the varaibles and defines the functions
 * needed for the CM4 processor to send data to the CMO+.
 *
 * ========================================
*/
#include "ipc_cm4.h"

// Variable to ensure messages don't overlap
volatile bool rdyToRecvMsg = true;

// Message structure for IPC
ipc_msg_t ipcMsgForCM0 = {
    .clientId = IPC_CM4_TO_CM0_CLIENT_ID,
    .userCode = 0,
    .intrMask = CY_IPC_CYPIPE_INTR_MASK,
    .type = 0,
    .data   = {0}
};

// Callback function when a message gets sent to the CM4
void CM4_MessageCallback(uint32_t *msg)
{
    uint32_t type;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    uint16_t val;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case UPPER_THRESHOLD:
                val = msgPtr->data[0] + 256 * msgPtr->data[1];
                upper_threshold = val;
                printf("New Upper Threshold: %" PRIx16, val);
                printf("\r\n");
                break;
            case LOWER_THRESHOLD:
                val = msgPtr->data[0] + 0x100 * msgPtr->data[1];
                lower_threshold = val;
                printf("New Lower Threshold: %" PRIx16, val);
                printf("\r\n");
                break;
            case TRIGGER:
                printf("TRIGGER\r\n");
                printf("[");
                for (uint8_t i = 0; i < 96; ++i)
                {
                    printf("%" PRId16, ring_buffer.buffer[i]);
                    printf(",");
                }
                printf("]\r\n");
                //trigger();
                break;
            case ENABLE:
                if (msgPtr->data[0])
                {
                    trigger_enable = true;
                }
                else
                {
                    trigger_enable = false;
                }
                printf("Enable: %s", trigger_enable ? "TRUE" : "FALSE");
                printf("\r\n");
            default:
                break;
        }
    }
}

// Release function when IPC message has been sent to CM0+ successfully
void CM4_ReleaseCallback(void)
{
    rdyToRecvMsg = true;
}

// Function for sending RMS voltage to CM0+
void send_voltage(uint16_t * voltage)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = VOLTAGE;
    ipcMsgForCM0.data[0] = ((uint8_t *)voltage)[0];
    ipcMsgForCM0.data[1] = ((uint8_t *)voltage)[1];
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

// Function for sending complete event to CM0+
void send_event(uint16_t * event, uint8_t event_num)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = EVENT;
    uint16_t entry;
    ipcMsgForCM0.data[0] = event_num;
    for (int i = 1; i < 145; ++i)
    {
        entry = event[i];
        ipcMsgForCM0.data[2 * i] = ((uint8_t *)&entry)[0];
        ipcMsgForCM0.data[2 * i + 1] = ((uint8_t *)&entry)[1];
    }
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                            CY_IPC_EP_CYPIPE_CM4_ADDR, 
                            &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}
/* [] END OF FILE */
