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
    .type = type_voltage,
    .data   = {0}
};

// Callback function when a message gets sent to the CM0+
void CM0_MessageCallback(uint32_t *msg)
{
    uint32_t type;
    uint8_t data[2];
    ipc_msg_t * msgPtr = (ipc_msg_t *)msg;
    if (msgPtr != NULL)
    {
        type = msgPtr->type;
        switch (type)
        {
            case type_event:
                // Check to make sure there is space for another event
                if (num_events < 10)
                {
                    // Incriment number of events
                    ++num_events;
                    // Update the number of events in server
                    write_num_events_to_server(&num_events);
                    // Add event data to events array
                    for(uint16_t i = 0; i < 144; ++i)
                    {
                        events[num_events - 1][i] = msgPtr->data[2 * i] + 256 * msgPtr->data[2 * i + 1];
                    }
                    // Write event data to flash
                    uint8_t ramData[CY_FLASH_SIZEOF_ROW];
                    for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
                    {
                        ramData[i] = 0;
                    }
                    ramData[0] = 1;
                    for(uint16_t i = 2; i < 322; ++i)
                    {
                        ramData[i] = msgPtr->data[i - 2];
                    }
                    cy_en_flashdrv_status_t result;
                    result = Cy_Flash_WriteRow((uint32_t)flashPtrs[num_events], (const uint32_t *)ramData);
                    if (result == CY_FLASH_DRV_SUCCESS)
                    {
                        printf("Event written to flash\r\n");
                    }
                }
                break;

            case type_voltage:
                // Get data from message
                data[0] = msgPtr->data[0];
                data[1] = msgPtr->data[1];
                // Place data in server
                write_voltage_to_server(data);
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
    } while (result != CY_IPC_PIPE_SUCCESS);
}

void send_trigger(void)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = type_trigger;
    ipcMsgForCM4.data[0] = 1;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result != CY_IPC_PIPE_SUCCESS);
}

void send_enable(uint8_t trigger)
{
    // Wait for previous message to send
    while (rdyToRecvMsg == false) {};
    rdyToRecvMsg = false;
    // Prepare message struct
    cy_en_ipc_pipe_status_t result;
    ipcMsgForCM4.type = type_enable;
    ipcMsgForCM4.data[0] = trigger;
    // Send message
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     &ipcMsgForCM4, CM0_ReleaseCallback);
    } while (result != CY_IPC_PIPE_SUCCESS);
}
/* [] END OF FILE */
