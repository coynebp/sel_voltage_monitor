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
        buffer[i] = 0;
    }
    ring_buffer.buffer = buffer;
    ring_buffer.maxlen = RING_BUF_LEN;
    ring_buffer.head = 0;
    ring_buffer.check = RING_BUF_LEN - 288;
    
    // Initialize cosine filter
    cosine_taps[0] = 1020;
    cosine_taps[1] = 989;
    cosine_taps[2] = 928;
    cosine_taps[3] = 839;
    cosine_taps[4] = 724;
    cosine_taps[5] = 587;
    cosine_taps[6] = 433;
    cosine_taps[7] = 265;
    cosine_taps[8] = 89;
    cosine_taps[9] = -89;
    cosine_taps[10] = -265;
    cosine_taps[11] = -433;
    cosine_taps[12] = -587;
    cosine_taps[13] = -724;
    cosine_taps[14] = -839;
    cosine_taps[15] = -928;
    cosine_taps[16] = -989;
    cosine_taps[17] = -1020;
    
    for(uint8_t i = 0; i < FILTER_LENGTH; ++i)
    {
        raw_samples[i] = 0;
    }
    
    for (uint8_t i = 0; i <= FILTER_LENGTH; ++i)
    {
        temp_values[i] = 0;
    }
    
    cosine_filter.length = FILTER_LENGTH;
    cosine_filter.taps = cosine_taps;
    cosine_filter.gain = 18 * 1024;
    cosine_filter.samples = raw_samples;
    filter_charged = 0;
    temp_charged = 0;
    
    // Initialize Averaging Filter
    for (uint8_t i = 0; i < 32; i++)
    {
        averaging_array[i] = 0;
    }
    
    // Initialize trigger enable to false
    bool trigger_enable = false;
    
    //Register the IPC callback function
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                                 CM4_MessageCallback,
                                 IPC_CM0_TO_CM4_CLIENT_ID);
    
    // Initialize the event
    for (uint8_t i = 0; i < 144; ++i)
    {
        event[i] = 0;
    }
    
    // Start the ADC
    ADC_Start();
}

void ADC_Interrupt(void)
{
    // Get adc result
    int16_t adc = Cy_SAR_GetResult16(SAR, 0) - 0x7FF;
    // Push result into filter
    int16_t filtered_value = get_filtered_value(adc, &cosine_filter);
    if (filter_charged >= FILTER_LENGTH)
    {
        // Push filtered value into temp values
        for (uint8_t i = FILTER_LENGTH; i > 0; --i)
        {
            temp_values[i] = temp_values[i - 1];
        }
        temp_values[0] = filtered_value;
        if (temp_charged >= FILTER_LENGTH + 1)
        {
            // Push new value into ring buffer
            ring_buf_push(&ring_buffer, temp_values[0] - temp_values[FILTER_LENGTH]);
            int32_t sq_mag = pow(ring_buffer.buffer[(ring_buffer.head + RING_BUF_LEN - 1) % RING_BUF_LEN], 2)
                            + pow(ring_buffer.buffer[(ring_buffer.head + RING_BUF_LEN - 10) % RING_BUF_LEN], 2);
            int32_t total = 0;
            for (uint8_t i = 35; i > 0; --i)
            {
                averaging_array[i] = averaging_array[i - 1];
                total += averaging_array[i];
            }
                averaging_array[0] = sq_mag;
                total += averaging_array[0];
                uint16_t rms = sqrt(total / 36) / sqrt(2);
            if (averaging_charged >= 36)
            {
                send_voltage(&rms);
            }
            else
            {
                ++averaging_charged;
            }
        }
        else
        {
            // Wait for temporary storage to fill
            ++temp_charged;
        }
    }
    else
    {
        // Wait for filter to be charged
        ++filter_charged;
    }
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
    for (uint16_t i = 0; i < EVENT_LENGTH; ++i)
    {
        printf("%" PRId16, event[i]);
        printf(",");
    }
    printf("\r\n");
}

void event_extraction(ring_buf_t *rbuf, int16_t *event_arr)
{
    uint16_t index = (rbuf->head + rbuf->maxlen - (EVENT_LENGTH * 3)) % rbuf->maxlen + 2;
    
    for(uint16_t event_index = 0; index != ((rbuf->head + 2) % rbuf->maxlen); index += 3)
    {
        index = index % rbuf->maxlen;
        event_arr[event_index] = rbuf->buffer[index];
        ++event_index;
    }
    printf("Event Extracted\r\n");
}
/* [] END OF FILE */
