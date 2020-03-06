/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "ble_monitor.h"

void GenericEventHandler(uint32 event, void *eventParam)
{
    cy_stc_ble_gattc_write_cmd_req_t *writeReqParam;
    switch(event) 
    {
        case CY_BLE_EVT_STACK_ON:
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 0);
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            break;
        case CY_BLE_EVT_GATT_CONNECT_IND:
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 1);
            break;
        case CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
            break;
        case CY_BLE_EVT_GATTS_WRITE_REQ:
            writeReqParam = (cy_stc_ble_gattc_write_cmd_req_t *)eventParam;
            if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_NEXT_EVENT_REQUEST_CHAR_HANDLE)
            {
                Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_VOLTAGE_MONITOR_UPPER_THRESHOLD_CHAR_HANDLE)
            {
                if (rdyToRecvMsg == true)
                {
                    rdyToRecvMsg = false;
                    ipcMsgForCM4.data = writeReqParam->handleValPair.value.val[0]*256 + writeReqParam->handleValPair.value.val[1];
                    Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
                    Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM4_ADDR,
                                                    CY_IPC_EP_CYPIPE_CM0_ADDR,
                                                    &ipcMsgForCM4, CM0_ReleaseCallback);
                }
            }
            Cy_BLE_GATTS_WriteRsp(writeReqParam->connHandle);
            break;
        default:
            break;
    }
}

void updateNextEvent(void)
{
    uint8_t value = 0;
    uint16 arr[12];
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    handValPair.attrHandle = CY_BLE_VOLTAGE_MONITOR_NEXT_EVENT_REQUEST_CHAR_HANDLE;
    handValPair.value.val = &value;
    handValPair.value.len = 1;
    Cy_BLE_GATTS_ReadAttributeValueLocal(NULL, &handValPair);
    if (value == 1)
    {
        value = 0;
        Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
        handValPair.attrHandle = CY_BLE_VOLTAGE_MONITOR_NEXT_EVENT_CHAR_HANDLE;
        handValPair.value.val = (uint8_t*)arr;
        handValPair.value.len = 24;
        Cy_BLE_GATTS_ReadAttributeValueLocal(NULL, &handValPair);
        for (int i = 0; i < 12; i += 1)
        {
            arr[i] += 1;
        }
        Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    }
    return;
}

/* [] END OF FILE */
