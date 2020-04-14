/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * ipc_cm0p.c
 * 
 * This file initilizes the variables and defines the functions
 * needed for the CM0+ processor to communicate with the CMO4.
 *
 * ========================================
*/
#include "ipc_cm0p.h"

// Variable to ensure messages don't overlap
volatile bool rdyToRecvMsg = true;

// Message structure for IPC
ipc_msg_t ipcMsgForCM4 = {
    .clientId = IPC_CM0_TO_CM4_CLIENT_ID,
    .userCode = 0,
    .intrMask = CY_IPC_CYPIPE_INTR_MASK,
    .type = 0,
    .data   = {0}
};

// Callback function when a message gets sent to the CM0+
void CM0_MessageCallback(uint32_t *msg)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    uint32_t type;
    uint8_t data[288];
    for (uint16_t i = 0; i < 288; ++i)
    {
        data[i] = 0;
    }
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case EVENT:
                // Check to make sure there is space for another event
                if (num_events < 10)
                {
                    // Incriment number of events
                    ++num_events;
                    // Add event data to events array
                    for(uint16_t i = 0; i < 144; ++i)
                    {
                        events[num_events - 1][i] = msgPtr->data[2 * i] + 256 * msgPtr->data[2 * i + 1];
                    }
                    // Update the number of events in server
                    handValPair.attrHandle = CY_BLE_CONTROL_NUMBER_OF_EVENTS_CHAR_HANDLE;
                    handValPair.value.val = &num_events;
                    handValPair.value.len = GATTS_NUM_EVENTS_SIZE;
                    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
                }
                break;

            case VOLTAGE:
                // Get data from message
                data[0] = msgPtr->data[0];
                data[1] = msgPtr->data[1];
                // Place data in server
                handValPair.attrHandle = CY_BLE_METER_CURRENT_VOLTAGE_CHAR_HANDLE;
                handValPair.value.val = data;
                handValPair.value.len = GATTS_VOLTAGE_SIZE;
                Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
                break;
            
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

void send_threshold(uint8_t * threshold, uint8_t upper_or_lower)
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
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

void send_trigger(void)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = TRIGGER;
    ipcMsgForCM4.data[0] = 1;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

void send_enable(uint8_t trigger)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = ENABLE;
    ipcMsgForCM4.data[0] = trigger;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}
/* [] END OF FILE */
