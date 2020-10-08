/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm0p.c
 * 
 * This file contains the functions and callbacks for the
 * CM0+ processor to communicate with the CM4
 *
 * ========================================
*/
#include "ipc_cm0p.h"

// Variable to ensure messages don't overlap
volatile bool rdyToRecvMsg = true;

// Flag to store event

// Message structure for IPC
ipc_msg_t ipcMsgForCM4 = {
    .clientId = IPC_CM0_TO_CM4_CLIENT_ID,
    .userCode = 0,
    .intrMask = CY_IPC_CYPIPE_INTR_MASK,
    .type = type_voltage,
    .data   = {0}
};

// Callback function when a message gets sent to the CM0+
void CM0_MessageCallback(uint32_t *msg)
{
    ipc_msg_datatype type;
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case type_event:
                record_event(msgPtr->data);
                event_to_record = true;
                break;
            case type_voltage:
            {
                write_voltage_to_server(msgPtr->data);
                break;
            }
            default:
                break;
        }
    }
}

// Release function when IPC message has been sent to CM0+ successfully
void CM0_ReleaseCallback(void)
{
    rdyToRecvMsg = true;
}

void send_threshold(uint8_t * threshold, ipc_msg_datatype upper_or_lower)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = upper_or_lower;
    ipcMsgForCM4.data[0] = threshold[0];
    ipcMsgForCM4.data[1] = threshold[1];
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result != CY_IPC_PIPE_SUCCESS);
}

void send_trigger(void)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = (ipc_msg_datatype)type_trigger;
    ipcMsgForCM4.data[0] = 1;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result != CY_IPC_PIPE_SUCCESS);
}

void send_enable(uint8_t enable)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = (ipc_msg_datatype)type_enable;
    ipcMsgForCM4.data[0] = enable;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result != CY_IPC_PIPE_SUCCESS);
}
/* [] END OF FILE */
