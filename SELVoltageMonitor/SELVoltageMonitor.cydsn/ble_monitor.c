/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * blemonitor.c
 * 
 * This file contains the BLE event handler which handles
 * basic BLE stack events and write requests. Also sends information
 * to the CM4 processor when received from the BLE client.
 *
 * ========================================
*/
#include "ble_monitor.h"

void GenericEventHandler(uint32 event, void *eventParam)
{
    cy_stc_ble_gattc_write_cmd_req_t *writeReqParam;
    cy_en_ipc_pipe_status_t result;
    switch(event) 
    {
        case CY_BLE_EVT_STACK_ON:
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            //Turn off connection LED
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 0);
            //Start advertising again
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            break;
            
        case CY_BLE_EVT_GATT_CONNECT_IND:
            //Turn on connection LED
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 1);
            break;
            
        case CY_BLE_EVT_GATTS_WRITE_REQ:
            writeReqParam = (cy_stc_ble_gattc_write_cmd_req_t *)eventParam;
            if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_EVENT_NUMBER_CHAR_HANDLE)
            {
                //Wait for IPC lane to be open
                while (rdyToRecvMsg != true) {}
                //Send event number to CM4
                rdyToRecvMsg = false;
                ipcMsgForCM4.type = EVENT_NUM;
                ipcMsgForCM4.data[0] = *(writeReqParam->handleValPair.value.val);
                do
                {
                result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                                 CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                                 &ipcMsgForCM4, CM0_ReleaseCallback);
                } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_UPPER_THRESHOLD_CHAR_HANDLE)
            {
                //Wait for IPC lane to be open
                while (rdyToRecvMsg != true) {}
                //Send new upper threshold to CM4
                rdyToRecvMsg = false;
                ipcMsgForCM4.type = UPPER_THRESHOLD;
                ipcMsgForCM4.data[0] = writeReqParam->handleValPair.value.val[0] + writeReqParam->handleValPair.value.val[1]*256;
                do
                {
                result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                                 CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                                 &ipcMsgForCM4, CM0_ReleaseCallback);
                } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
                
                //Write new threshold to GATT server
                Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_LOWER_THRESHOLD_CHAR_HANDLE)
            {
                //Wait for IPC lane to be open
                while (rdyToRecvMsg != true) {}
                //Send new lower threshold to CM4
                rdyToRecvMsg = false;
                ipcMsgForCM4.type = LOWER_THRESHOLD;
                ipcMsgForCM4.data[0] = writeReqParam->handleValPair.value.val[0];
                ipcMsgForCM4.data[1] = writeReqParam->handleValPair.value.val[1];
                do
                {
                result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                                 CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                                 &ipcMsgForCM4, CM0_ReleaseCallback);
                } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
                
                //Write new threshold to GATT server
                Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_TRIGGER_CHAR_HANDLE)
            {
                //Wait for IPC lane to be open
                while (rdyToRecvMsg != true) {}
                //Send trigger to CM4
                rdyToRecvMsg = false;
                ipcMsgForCM4.type = TRIGGER;
                ipcMsgForCM4.data[0] = 1;
                do
                {
                result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                                 CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                                 &ipcMsgForCM4, CM0_ReleaseCallback);
                } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
            }
            
            //Send write response//
            Cy_BLE_GATTS_WriteRsp(writeReqParam->connHandle);
            
            break;
            
        default:
            break;
    }
}

/* [] END OF FILE */
