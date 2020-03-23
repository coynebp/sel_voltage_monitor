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
#include "bluetooth.h"

void GenericEventHandler(uint32 event, void *eventParam)
{
    cy_stc_ble_gattc_write_cmd_req_t *writeReqParam;
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
            if (writeReqParam->handleValPair.attrHandle == CY_BLE_CONTROL_EVENT_NUMBER_CHAR_HANDLE)
            {
                //uint8_t event_num = writeReqParam->handleValPair.value.val[0];
                //Send requested event number to CM4
                send_event_num(writeReqParam->handleValPair.value.val);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_CONTROL_UPPER_THRESHOLD_CHAR_HANDLE)
            {
                send_threshold(writeReqParam->handleValPair.value.val, UPPER_THRESHOLD);
                //Write new threshold to GATT server
                Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_CONTROL_LOWER_THRESHOLD_CHAR_HANDLE)
            {
                send_threshold(writeReqParam->handleValPair.value.val, LOWER_THRESHOLD);
                //Write new threshold to GATT server
                Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
            }
            else if (writeReqParam->handleValPair.attrHandle == CY_BLE_CONTROL_TRIGGER_CHAR_HANDLE)
            {
                send_trigger();
            }
            
            //Send write response//
            Cy_BLE_GATTS_WriteRsp(writeReqParam->connHandle);
            
            break;
            
        default:
            break;
    }
}

void write_event_to_server(uint8_t *event_byte_arr)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    handValPair.value.len = GATTS_EVENT_SIZE;
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_1_10_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_11_20_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 20;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_21_30_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 40;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_31_40_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 60;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_41_50_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 80;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_51_60_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 100;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_61_70_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 120;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_71_80_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 140;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_81_90_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 160;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_91_100_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 180;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_101_110_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 200;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_111_120_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 220;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_121_130_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 240;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_131_140_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 260;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
    
    handValPair.attrHandle = CY_BLE_EVENT_ES_141_144_CHAR_HANDLE;
    handValPair.value.val = event_byte_arr + 280;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
}

/* [] END OF FILE */
