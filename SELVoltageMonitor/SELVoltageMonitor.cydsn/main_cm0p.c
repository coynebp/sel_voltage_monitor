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
#include "ble_monitor.h"

int main(void)
{
     /* Enable global interrupts. */
	__enable_irq();
	
	/* Start the BLE stack, register the event handler. */
    Cy_BLE_Start(GenericEventHandler); 
    while(Cy_BLE_GetState() != CY_BLE_STATE_ON)
    {
        Cy_BLE_ProcessEvents();
    }
    
    /* Enable CM4.*/
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR); 

    for(;;)
    {
        Cy_BLE_ProcessEvents();
    }
}

/* [] END OF FILE */
