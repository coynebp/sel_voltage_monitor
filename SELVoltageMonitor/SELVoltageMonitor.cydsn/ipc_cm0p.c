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
    uint8_t data[300];
    for (uint16_t i = 0; i < 300; ++i)
    {
        data[i] = 0;
    }
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case EVENT_NUM:
                data[0] = msgPtr->data[0];
                handValPair.attrHandle = CY_BLE_CONTROL_EVENT_NUMBER_CHAR_HANDLE;
                handValPair.value.val = data;
                handValPair.value.len = GATTS_EVENT_NUM_SIZE;
                Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
                break;

            case EVENT:
                for (int i = 0; i < 288; ++i)
                {
                    data[i] = msgPtr->data[i];
                }
                write_event_to_server(data);
                break;
            
            case NUM_EVENTS:
                data[0] = msgPtr->data[0];
                handValPair.attrHandle = CY_BLE_CONTROL_NUMBER_OF_EVENTS_CHAR_HANDLE;
                handValPair.value.val = data;
                handValPair.value.len = GATTS_NUM_EVENTS_SIZE;
                Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
                break;

            case VOLTAGE:
                data[0] = msgPtr->data[0];
                data[1] = msgPtr->data[1];
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

void CM0_ReleaseCallback(void)
{
    /* Message processed by CM4. Ready to receive a new message */
    rdyToRecvMsg = true;
}

void send_threshold(uint8_t * threshold, uint8_t upper_or_lower)
{
    /* Wait for IPC Lane to be open. */
    while (rdyToRecvMsg == false) {};
    /* Prepare message and send data. */
    rdyToRecvMsg = false;
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = upper_or_lower;
    ipcMsgForCM4.data[0] = threshold[0];
    ipcMsgForCM4.data[1] = threshold[1];
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

void send_trigger(void)
{
    /* Wait for IPC Lane to be open. */
    while (rdyToRecvMsg == false) {};
    /* Prepare message and send trigger. */
    rdyToRecvMsg = false;
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = TRIGGER;
    ipcMsgForCM4.data[0] = 1;
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

void send_event_num(uint8_t * event_num)
{
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = EVENT_NUM;
    ipcMsgForCM4.data[0] = *event_num;
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}
/* [] END OF FILE */
