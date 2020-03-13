/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * voltage_monitor.c
 * 
 * This file defines the initialization function and
 * main loop function for the voltage monitor project.
 *
 * ========================================
*/
#include "voltage_monitor.h"

void voltage_monitor_init(void)
{
    UART_Start();
    setvbuf ( stdin, NULL, _IONBF, 0);
    printf("Started UART\r\n");
    
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                             CM4_MessageCallback,
                             IPC_CM0_TO_CM4_CLIENT_ID);
    
    
    ADC_1_Start();
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_CONTINUOUS);
    double result = 0;
    uint16_t counts = 0;
}

void voltage_monitor_loop(void)
{
    ;//insert loop here
}

/* [] END OF FILE */
