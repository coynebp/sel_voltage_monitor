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
    next_event_index = 0;
}

void ADC_Interrupt(void)
{
    // Remove DC offset
    int16_t adc = Cy_SAR_GetResult16(SAR, 0) - 0x7FF;
    // Push new ADC value into ring buffer
    ring_buf_push(&ring_buffer, adc);
    
    // Incriment sample counter and check for trigger every 8 samples.
    ++sample_counter;
    sample_counter = sample_counter % 8;
    if (sample_counter == 0 && trigger_enable)
    {
        int16_t rms = calc_rms();
        if (rms >= upper_threshold)
        {
            trigger();
            
        }
        else if (rms <= lower_threshold)
        {
            trigger();
            
        }
    }
}

void SCAN_Interrupt(void)
{
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_SINGLE_SHOT);
}

int16_t calc_rms()
{
    int16_t rms;
    int32_t sum = 0;
    for (int16_t i = ring_buffer.check - 31; i <= ring_buffer.check; ++i)
    {
           sum += pow(ring_buffer.buffer[i], 2);
    }
    rms = round(sqrt((double)sum / 32));
    return rms;
}

void trigger(void)
{
    printf("TRIGGER\r\n");
    extract_event(event, &ring_buffer);
    send_event(event, next_event_index);
}
/* [] END OF FILE */
