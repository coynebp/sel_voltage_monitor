/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * main_cm0p.c
 * 
 * Contains main function for the CM0+ processor, which handles the BLE
 * controller and host.
 *
 * ========================================
*/
#include "bluetooth.h"

int main(void)
{
    init_ble();
    
    for(;;)
    {
        Cy_BLE_ProcessEvents();
    }
}

/* [] END OF FILE */
