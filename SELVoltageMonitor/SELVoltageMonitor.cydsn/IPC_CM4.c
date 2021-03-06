/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm4.c
 * 
 * This file contains the functions and callbacks for the
 * CM4 processor to communicate with the CMO+
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
    ipc_msg_datatype type;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    uint16_t val;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case type_upper_threshold:
                val = msgPtr->data[0] + 256 * msgPtr->data[1];
                set_upper_threshold(val);
                break;
            case type_lower_threshold:
                val = msgPtr->data[0] + 256 * msgPtr->data[1];
                set_lower_threshold(val);
                break;
            case type_trigger:
                printf("MANUAL TRIGGER\r\n");
                trigger();
                break;
            case type_enable:
                set_trigger_enable(msgPtr->data[0]);
            case type_hold:
                set_hold_time(100);
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
    ipcMsgForCM0.type = (ipc_msg_datatype)type_voltage;
    ipcMsgForCM0.data[0] = ((uint8_t *)voltage)[0];
    ipcMsgForCM0.data[1] = ((uint8_t *)voltage)[1];
    // Send message
    Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     &ipcMsgForCM0, CM4_ReleaseCallback);
}

// Function for sending complete event to CM0+
void send_event(int16_t * event)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    // Set ready flag to false
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM0.type = (ipc_msg_datatype)type_event;
    uint16_t entry;
    for (int i = 0; i < 144; ++i)
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
