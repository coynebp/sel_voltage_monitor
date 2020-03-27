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
    // Initialize interrupts
    Cy_SysInt_Init(&ADC_INT_cfg, &ADC_Interrupt);
    NVIC_EnableIRQ(ADC_INT_cfg.intrSrc);
    Cy_SysInt_Init(&SCAN_INT_cfg, &SCAN_Interrupt);
    NVIC_EnableIRQ(SCAN_INT_cfg.intrSrc);
    
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
    ADC_Start();
    
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
    
    //example code
    uint8_t event_num = 0x01;
    uint8_t num_events = 0x0A;
    uint16_t voltage = 0x3456;

    send_event_num(&event_num);
    send_num_events(&num_events);
    send_voltage(&voltage);
    
}

void ADC_Interrupt(void)
{
    // Push new ADC value into ring buffer
    uint16_t adc = Cy_SAR_GetResult16(SAR, 0);
    ring_buf_push(&ring_buffer, adc);
}

void SCAN_Interrupt(void)
{
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_SINGLE_SHOT);
}
/* [] END OF FILE */
