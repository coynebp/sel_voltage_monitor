/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * main_cm4.c
 * 
 * Contains main function for the CM0+ processor, which handles the BLE
 * controller and host.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include "ipc_cm4.h"

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    UART_Start();
    
    setvbuf ( stdin, NULL, _IONBF, 0);
    
    printf("Started UART\r\n");
    
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                             CM4_MessageCallback,
                             IPC_CM0_TO_CM4_CLIENT_ID);   

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
