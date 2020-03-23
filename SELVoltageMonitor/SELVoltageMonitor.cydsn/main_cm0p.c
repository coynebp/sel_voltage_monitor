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
    
    /* Register the IPC Callback Function.*/
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                         CM0_MessageCallback,
                         IPC_CM4_TO_CM0_CLIENT_ID);

    for(;;)
    {
        Cy_BLE_ProcessEvents();
    }
}

/* [] END OF FILE */
