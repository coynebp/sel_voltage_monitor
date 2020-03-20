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
    
    cy_en_ipc_pipe_status_t result;
    
    result = Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                             CM4_MessageCallback,
                             IPC_CM0_TO_CM4_CLIENT_ID);

    rbuf.maxlen = RING_BUF_LEN;
    rbuf.buffer = arr;
    rbuf.head = 0;
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        rbuf.buffer[i] = 2;
    }

    for (int j = 0; j < 144; ++j)
    {
        event[j] = 0x1234;
    }
    
    uint8_t event_num = 5;
    uint8_t num_events = 7;
    uint16_t voltage = 0x0123;
    
    send_event(event);
    send_event_num(&event_num);
    send_num_events(&num_events);
    send_voltage(&voltage);
}

void voltage_monitor_loop(void)
{
    
}

/* [] END OF FILE */
