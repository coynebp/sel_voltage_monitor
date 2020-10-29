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

const uint8_t* FLASH_BASE_ADDR = (uint8_t*)0x14000000;

const uint8_t* arr[11];

int main(void)
{
    event_to_record = false;
    
    arr[0] = FLASH_BASE_ADDR;
    arr[1] = FLASH_BASE_ADDR + CY_FLASH_SIZEOF_ROW;
    arr[2] = FLASH_BASE_ADDR + 2 * CY_FLASH_SIZEOF_ROW;
    arr[3] = FLASH_BASE_ADDR + 3 * CY_FLASH_SIZEOF_ROW;
    arr[4] = FLASH_BASE_ADDR + 4 * CY_FLASH_SIZEOF_ROW;
    arr[5] = FLASH_BASE_ADDR + 5 * CY_FLASH_SIZEOF_ROW;
    arr[6] = FLASH_BASE_ADDR + 6 * CY_FLASH_SIZEOF_ROW;
    arr[7] = FLASH_BASE_ADDR + 7 * CY_FLASH_SIZEOF_ROW;
    arr[8] = FLASH_BASE_ADDR + 8 * CY_FLASH_SIZEOF_ROW;
    arr[9] = FLASH_BASE_ADDR + 9 * CY_FLASH_SIZEOF_ROW;
    arr[10] = FLASH_BASE_ADDR + 10 * CY_FLASH_SIZEOF_ROW;
    
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
