/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * voltage_monitor.c
 * 
 * This file defines the initialization function and
 * the interrupt routines for the voltage monitor.
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
    
    // Initialize thresholds
    upper_threshold = 0;
    lower_threshold = 0;
    
    // Initialize ring buffer.
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        arr[i] = 0;
    }
    ring_buffer.buffer = arr;
    ring_buffer.maxlen = RING_BUF_LEN;
    ring_buffer.head = 0;
    ring_buffer.check = RING_BUF_LEN - 288;
    
    // Initialize trigger enable to false
    bool trigger_enable = false;
    
    // Initialize counter. Counts samples to trigger an RMS calculation every 8 samples.
    sample_counter = 0;
    
    // Start the ADC
    ADC_Start();
    
    //Register the IPC callback function
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                                 CM4_MessageCallback,
                                 IPC_CM0_TO_CM4_CLIENT_ID);
    
    // Initialize the event
    for (uint8_t i = 0; i < 144; ++i)
    {
        event[i] = 0;
    }
}

void ADC_Interrupt(void)
{
    // Remove DC offset
    int16_t adc = Cy_SAR_GetResult16(SAR, 0);
    // Push new ADC value into ring buffer
    ring_buf_push(&ring_buffer, adc);
}

void SCAN_Interrupt(void)
{
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_SINGLE_SHOT);
}

void trigger(void)
{
    printf("TRIGGER\r\n");
    event_extraction(&ring_buffer, event);
    send_event(event);
}

void event_extraction(ring_buf_t *rbuf, uint16_t *event_arr)
{
    uint16_t index = (rbuf->head + rbuf->maxlen - (EVENT_LENGTH * 3)) % rbuf->maxlen + 2;
    
    for(uint16_t event_index = 0; index != ((rbuf->head + 2) % rbuf->maxlen); index += 3)
    {
        index = index % rbuf->maxlen;
        event_arr[event_index] = rbuf->buffer[index];
        ++event_index;
    }
}
/* [] END OF FILE */
