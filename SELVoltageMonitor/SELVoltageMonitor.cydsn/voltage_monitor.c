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
    __enable_irq(); /* Enable global interrupts. */
    
    UART_Start();
    setvbuf ( stdin, NULL, _IONBF, 0);
    printf("Started UART\r\n");
    
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                                 CM4_MessageCallback,
                                 IPC_CM0_TO_CM4_CLIENT_ID);
    
    for (uint8_t i = 0; i < 10; ++i)
    {
        for (uint8_t j = 0; j < 144; ++j)
        {
            event[i][j] = 0;
        }
    }
    
    uint8_t event_num = 0x01;
    uint8_t num_events = 0x0A;
    uint16_t voltage = 0x3456;

    send_event_num(&event_num);
    send_num_events(&num_events);
    send_voltage(&voltage);
}

void voltage_monitor_loop(void)
{
    
}

/* [] END OF FILE */
