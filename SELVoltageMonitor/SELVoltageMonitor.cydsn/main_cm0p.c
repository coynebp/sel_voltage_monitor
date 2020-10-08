/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * main_cm0p.c
 *
 * ========================================
*/
#include "bluetooth.h"

// Declaring flash storage for configuration and event storage
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashInfo[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent1[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent2[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent3[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent4[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent5[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent6[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent7[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent8[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent9[CY_FLASH_SIZEOF_ROW] = {0};
CY_ALIGN(CY_FLASH_SIZEOF_ROW) const uint8_t flashEvent10[CY_FLASH_SIZEOF_ROW] = {0};

const uint8_t* arr[11];

int main(void)
{
    event_to_record = false;
    
    arr[0] = flashInfo;
    arr[1] = flashEvent1;
    arr[2] = flashEvent2;
    arr[3] = flashEvent3;
    arr[4] = flashEvent4;
    arr[5] = flashEvent5;
    arr[6] = flashEvent6;
    arr[7] = flashEvent7;
    arr[8] = flashEvent8;
    arr[9] = flashEvent9;
    arr[10] = flashEvent10;
    
    init_ble(arr);
    
    for(;;)
    {
        Cy_BLE_ProcessEvents();
        if (event_to_record)
        {
            store_recent_event();
            event_to_record = false;
        }
    }
}

/* [] END OF FILE */
