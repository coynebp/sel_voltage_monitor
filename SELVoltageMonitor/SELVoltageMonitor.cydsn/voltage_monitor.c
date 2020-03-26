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
    // Enable global interrupts.
    __enable_irq(); 
    
    // Start the UART Debug Output
    UART_Start();
    setvbuf ( stdin, NULL, _IONBF, 0);
    printf("Started UART\r\n");
    
    // Initialize ring buffer.
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        arr[i] = 0;
    }
    ring_buffer.buffer = arr;
    ring_buffer.maxlen = RING_BUF_LEN;
    ring_buffer.head = 0;
    
    // Start the ADC and register interrupt function
    ADC_StartEx(ADC_Interrupt);
    
    //Register the IPC callback function
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                                 CM4_MessageCallback,
                                 IPC_CM0_TO_CM4_CLIENT_ID);
    
    // Initialize the events
    for (uint8_t i = 0; i < 10; ++i)
    {
        for (uint8_t j = 0; j < 144; ++j)
        {
            event[i][j] = 0;
        }
    }
    event_index = 0;
}

void ADC_Interrupt(void)
{
    // Push new ADC value into ring buffer
    ring_buf_push(&ring_buffer, Cy_SAR_GetResult16(SAR, 0));   
}

void trigger(void)
{
    
}
/* [] END OF FILE */
