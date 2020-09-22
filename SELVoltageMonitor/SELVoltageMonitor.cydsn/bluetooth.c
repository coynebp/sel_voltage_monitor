/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 *
 * blemonitor.c
 *
 * This file contains functions and event handlers for initializing
 * and operating the BLE server for the SEL Voltage Monitor.
 *
 * ========================================
*/
#include "bluetooth.h"

const uint8_t** flashPtrs;
uint16_t events[10][160];
uint8_t num_events;
uint8_t upper_thresh[2];
uint8_t lower_thresh[2];

void init_ble(const uint8** Ptrs)
{
    // Set flash pointers address
    flashPtrs = Ptrs;
    
    // Enable global interrupts.
	__enable_irq();
    
    // Enable CM4.
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR);
    
    // Start the UART Debug Output
    UART_Start();
    setvbuf(stdin, NULL, _IONBF, 0);
    printf("***********************************\r\n");
    printf("***     SEL VOLTAGE MONITOR     ***\r\n");
    printf("***       TEAM REMBRANDT        ***\r\n");
    printf("*** WASHINGTON STATE UNIVERSITY ***\r\n");
    printf("***            2020             ***\r\n");
    printf("***********************************\r\n\n");

    
    // Register the IPC Callback Function.
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                         CM0_MessageCallback,
                         IPC_CM4_TO_CM0_CLIENT_ID);
    
    // Pull number of events, thresholds, and events from flash storage
    // if data has been written before.
    if(flashPtrs[0][0] == 'W' && flashPtrs[0][1] == 'S' && flashPtrs[0][2] == 'U')
    {
        printf("Flash Data Present\r\n");
        // W S U indicates that flash data has been previously written
        // Pull thresholds
        upper_thresh[0] = flashPtrs[0][3];
        upper_thresh[1] = flashPtrs[0][4];
        lower_thresh[0] = flashPtrs[0][5];
        lower_thresh[1] = flashPtrs[0][6];
        // Pull events and number of events
        // A 1 at the beginning of the event array indicates that an event has been stored
        // in flash at that location
        num_events = 0;
        for(uint8_t i = 0; i < 10; ++i)
        {
            num_events += flashPtrs[i+1][0];
            for(uint16_t j = 0; j < 160; ++j)
            {
                events[i][j] = flashPtrs[i+1][2 * j + 2] + 256 * flashPtrs[i+1][2 * j + 3];
            }
        }
    }
    else
    {
        printf("Flash Data NOT Present\r\n");
        // Flash data not present, writing default values to flash
        num_events = 0;
        // Default upper threshold = 130V
        upper_thresh[0] = 0x55;
        upper_thresh[1] = 0x04;
        // Default lower threshold = 120V
        lower_thresh[0] = 0xAB;
        lower_thresh[1] = 0x03;
        // Initialize events
        for(uint8_t i = 0; i < 10; ++i)
        {
            for(uint16_t j = 0; j < 160; ++j)
            {
                events[i][j] = 0;
            }
        }
        // Write config values to flash
        update_flash_config();
        // Initialize events in flash
        uint8_t ramData[CY_FLASH_SIZEOF_ROW];
        for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
        {
            ramData[i] = 0;
        }
        for (uint8_t i =1; i < 11; ++i)
        {
            Cy_Flash_WriteRow((uint32_t)flashPtrs[i],(const uint32_t *)ramData);
        }
    }

	// Start the BLE stack, register the event handler.
    Cy_BLE_Start(BluetoothEventHandler); 
    while(Cy_BLE_GetState() != CY_BLE_STATE_ON)
    {
        Cy_BLE_ProcessEvents();
    }
    
    send_threshold(upper_thresh, type_upper_threshold);
    send_threshold(lower_thresh, type_lower_threshold);
    
    // Send config values to BLE Server
    write_num_events_to_server(&num_events);
    write_threshold_to_server(upper_thresh, 'u');
    write_threshold_to_server(lower_thresh, 'l');
}

void BluetoothEventHandler(uint32 event, void *eventParam)
{
    switch(event) 
    {
        case CY_BLE_EVT_STACK_ON:
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
        {
            printf("BLE device DISCONNECTED. Starting advertisement...\r\n");
            // Turn off connection LED
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 0);
            // Start advertising again
            Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST, CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX);
            break;
        }
        case CY_BLE_EVT_GATT_CONNECT_IND:
        {
            printf("BLE device CONNECTED\r\n");
            // Turn on connection LED
            Cy_GPIO_Write(Connection_LED_0_PORT, Connection_LED_0_NUM, 1);
            break;
        }
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        {
            cy_stc_ble_gattc_write_cmd_req_t *writeReqParam;
            writeReqParam = (cy_stc_ble_gattc_write_cmd_req_t *)eventParam;
            cy_ble_gatt_db_attr_handle_t handle = writeReqParam->handleValPair.attrHandle;
            switch(handle)
            {
                case CY_BLE_CONTROL_ENABLE_CHAR_HANDLE:
                {
                    bool enable = writeReqParam->handleValPair.value.val[0];
                    // Send enable to CM4
                    send_enable(enable);
                    // Write enable to GATT server
                    Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
                    break;
                }
                case CY_BLE_CONTROL_EVENT_NUMBER_CHAR_HANDLE:
                {
                    uint8_t event_num = writeReqParam->handleValPair.value.val[0];
                    // Check for valid event number
                    if (event_num <= num_events)
                    {
                        // Place requested event in GATT server
                        write_event_to_server((uint8_t *)events[event_num - 1]);
                        // Write new event number to GATT server
                        Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
                    }
                    break;
                }
                case CY_BLE_CONTROL_DELETE_EVENT_NUMBER_CHAR_HANDLE:
                {
                    uint8_t event_num = writeReqParam->handleValPair.value.val[0];
                    // Check for valid event number to delete
                    if (event_num <= num_events)
                    {
                        delete_event(event_num);
                    }
                    break;
                }
                case CY_BLE_CONTROL_UPPER_THRESHOLD_CHAR_HANDLE:
                {
                    // Send threshold to CM4
                    send_threshold(writeReqParam->handleValPair.value.val, (ipc_msg_datatype)type_upper_threshold);
                    // Write new threshold to flash
                    upper_thresh[0] = writeReqParam->handleValPair.value.val[0];
                    upper_thresh[1] = writeReqParam->handleValPair.value.val[1];
                    update_flash_config();
                    // Write new threshold to GATT server
                    Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
                    break;
                }
                case CY_BLE_CONTROL_LOWER_THRESHOLD_CHAR_HANDLE:
                {
                    // Send threshold to CM4
                    send_threshold(writeReqParam->handleValPair.value.val, (ipc_msg_datatype)type_lower_threshold);
                    // Write new threshold to flash
                    lower_thresh[0] = writeReqParam->handleValPair.value.val[0];
                    lower_thresh[1] = writeReqParam->handleValPair.value.val[1];
                    update_flash_config();
                    // Write new threshold to GATT server
                    Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam->connHandle, &writeReqParam->handleValPair);
                    break;
                }
                case CY_BLE_CONTROL_TRIGGER_CHAR_HANDLE:
                {
                    // Send trigger indication to CM4
                    send_trigger();
                    break;
                }
                default:
                    break;
            }
            // Send write response
            Cy_BLE_GATTS_WriteRsp(writeReqParam->connHandle);
            break;
        }
        default:
            break;
            
    }
}

void write_event_to_server(uint8_t *event_byte_arr)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    handValPair.value.len = GATTS_EVENT_SIZE;
    // Write each set of values to the GATT server
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

void write_num_events_to_server(uint8_t * num_events_ptr)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    handValPair.attrHandle = CY_BLE_CONTROL_NUMBER_OF_EVENTS_CHAR_HANDLE;
    handValPair.value.val = num_events_ptr;
    handValPair.value.len = GATTS_NUM_EVENTS_SIZE;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
}

void write_voltage_to_server(uint8_t * voltage_ptr)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    handValPair.attrHandle = CY_BLE_METER_CURRENT_VOLTAGE_CHAR_HANDLE;
    handValPair.value.val = voltage_ptr;
    handValPair.value.len = GATTS_VOLTAGE_SIZE;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);   
}

void write_threshold_to_server(uint8_t * threshold_ptr, char upper_or_lower)
{
    cy_stc_ble_gatt_handle_value_pair_t handValPair;
    if (upper_or_lower == 'u')
    {
        handValPair.attrHandle = CY_BLE_CONTROL_UPPER_THRESHOLD_CHAR_HANDLE;
    }
    else
    {
        handValPair.attrHandle = CY_BLE_CONTROL_LOWER_THRESHOLD_CHAR_HANDLE;
    }
    handValPair.value.val = threshold_ptr;
    handValPair.value.len = GATTS_THRESHOLD_SIZE;
    Cy_BLE_GATTS_WriteAttributeValueLocal(&handValPair);
}

void update_flash_config(void)
{
    uint8_t ramData[CY_FLASH_SIZEOF_ROW];
    for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
    {
        ramData[i] = 0;
    }
    ramData[0] = 'W';
    ramData[1] = 'S';
    ramData[2] = 'U';
    ramData[3] = upper_thresh[0];
    ramData[4] = upper_thresh[1];
    ramData[5] = lower_thresh[0];
    ramData[6] = lower_thresh[1];
    cy_en_flashdrv_status_t result;
    result = Cy_Flash_WriteRow((uint32)flashPtrs[0],(const uint32_t *) ramData);
    if(result == CY_FLASH_DRV_SUCCESS)
    {
        printf("Settings updated in flash\r\n");
    }
}

void record_event(uint8_t * new_event)
{
    if (num_events < 10)
    {
        // Incriment number of events
        ++num_events;
        // Update the number of events in server
        write_num_events_to_server(&num_events);
        // Record event in RAM
        for(uint16_t i = 0; i < 144; ++i)
        {
            events[num_events - 1][i] = new_event[2 * i] + 256 * new_event[2 * i + 1];
        }
        // Write event data to flash
        uint8_t ramData[CY_FLASH_SIZEOF_ROW];
        for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
        {
            ramData[i] = 0;
        }
        ramData[0] = 1; // This indicates that an event has been written at this location
        for(uint16_t i = 2; i < 322; ++i)
        {
            ramData[i] = new_event[i - 2];
        }
        cy_en_flashdrv_status_t result;
        result = Cy_Flash_WriteRow((uint32_t)flashPtrs[num_events], (const uint32_t *)ramData);
        if (result == CY_FLASH_DRV_SUCCESS)
        {
            printf("New event written to flash\r\n");
        }
        else
        {
            printf("New event failed to write to flash\r\n");
        }
    }
    else
    {
        printf("Event storage full!\r\n");
    }
}

void delete_event(uint8_t event_num)
{
    bool success = true;
    cy_en_flashdrv_status_t result;
    // Delete event from RAM and flash storage
    uint8_t ramData[CY_FLASH_SIZEOF_ROW];
    for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
    {
        ramData[i] = 0;
    }
    ramData[0] = 1;
    for (uint8_t i = event_num; i < num_events; ++i)
    {
        for (uint16_t j = 0; j < 160; ++j)
        {
            events[i - 1][j] = events[i][j];
            memcpy(ramData + 2, events[i - 1], 288);
        }
        result = Cy_Flash_WriteRow((uint32_t)flashPtrs[i], (const uint32_t *)ramData);
        if (result != CY_FLASH_DRV_SUCCESS)
        {
            success = false;
        }
    }
    // Reset RAM and flash storage for deleted event
    for (uint16_t j = 0; j < 160; ++j)
    {
        events[num_events - 1][j] = 0;
    }
    for (uint16_t i = 0; i < CY_FLASH_SIZEOF_ROW; ++i)
    {
        ramData[i] = 0;
    }
    result = Cy_Flash_WriteRow((uint32_t)flashPtrs[num_events],(const uint32_t *)ramData);
    if (result != CY_FLASH_DRV_SUCCESS)
    {
        success = false;
    }
    // Update number of events
    --num_events;
    // Update number of events in server
    write_num_events_to_server(&num_events);
    if (success)
    {
        printf("Event successfully removed\r\n");
    }
    else
    {
        printf("Event removal unsuccessful\r\n");
    }
}

void record_voltage(uint8_t * data)
{
    uint8_t voltage[2];
    // Get data from message
    voltage[0] = data[0];
    voltage[1] = data[1];
    // Place data in server
    write_voltage_to_server(voltage);
}
/* [] END OF FILE */
