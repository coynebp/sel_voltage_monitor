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

// Ring buffer
int16_t rb_buffer[RING_BUF_LEN];
ring_buf_t ring_buffer;

// Event array
int16_t event[EVENT_LENGTH];
    
// Cosine filter
int32 raw_samples[FILTER_LENGTH];
int16 cosine_taps[FILTER_LENGTH];
fir_filter_t cosine_filter;

// Averaging filter
int32 averaging_values[FILTER_LENGTH];
int16 averaging_taps[FILTER_LENGTH];
fir_filter_t averaging_filter;

void voltage_monitor_init(void)
{   
    // Initialize interrupts
    Cy_SysInt_Init(&ADC_INT_cfg, &ADC_Interrupt);
    NVIC_EnableIRQ(ADC_INT_cfg.intrSrc);
    Cy_SysInt_Init(&SCAN_INT_cfg, &SCAN_Interrupt);
    NVIC_EnableIRQ(SCAN_INT_cfg.intrSrc);
    
    // Enable global interrupts
    __enable_irq();
    
    // Initialize thresholds
    upper_threshold = 0;
    lower_threshold = 0;
    
    // Initialize ring buffer
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        rb_buffer[i] = 0;
    }
    initialize_ring_buffer(&ring_buffer, rb_buffer, RING_BUF_LEN);
    
    // Initialize cosine filter
    for (uint8_t i = 0; i < FILTER_LENGTH; ++i)
    {
        cosine_taps[i] = 1024 * cos(((2 * i + 1) * 2 * 3.141519) / (double)72);
    }
    for(uint8_t i = 0; i < FILTER_LENGTH; ++i)
    {
        raw_samples[i] = 0;
    }
    initialize_filter(FILTER_LENGTH, cosine_taps, 18 * 1024, raw_samples, &cosine_filter);
    
    // Initialize averaging filter for squared magnitudes
    for (uint8_t i = 0; i < FILTER_LENGTH; ++i)
    {
        averaging_taps[i] = 1;
    }
    for(uint8_t i = 0; i < FILTER_LENGTH; ++i)
    {
        averaging_values[i] = 0;
    }
    initialize_filter(FILTER_LENGTH, averaging_taps, 36, averaging_values, &averaging_filter);
    
    // Initialize trigger enable to false and indicate that voltage is normal
    trigger_enable = false;
    voltage_normal = true;
    
    // Initialize trigger to false
    trigger_set = false;
    samples_to_extract = 0;
    
    //Register the IPC callback function
    Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_ADDR,
                                 CM4_MessageCallback,
                                 IPC_CM0_TO_CM4_CLIENT_ID);
    
    // Initialize the event array
    for (uint16_t i = 0; i < EVENT_LENGTH; ++i)
    {
        event[i] = 0;
    }
    
    // Start the ADC
    ADC_Start();
}

void ADC_Interrupt(void)
{
    // Get adc result
    int16_t adc = Cy_SAR_GetResult16(SAR, 0);
    // Push result into filter
    insert_filter_value(&cosine_filter, adc);
    if (cosine_filter.is_charged)
    {
        // Push new value into ring buffer
        ring_buf_push(&ring_buffer, get_filtered_value(&cosine_filter));
        // If an event has been triggered, and more data is needed for event report, push data into event characteristic
        if (trigger_set)
        {
            event[EVENT_LENGTH - samples_to_extract] = ring_buffer.buffer[(ring_buffer.head + ring_buffer.maxlen - 1) % ring_buffer.maxlen];
            --samples_to_extract;
            if (!samples_to_extract)
            {
                trigger_set = false;
                int16_t short_event[144];
                for (uint16_t i = 0; i < EVENT_LENGTH; i += 3)
                {
                    short_event[i / 3] = event[i];
                }
                for (uint16_t i = 0; i < 144; ++i)
                {
                    printf("%" PRId16, short_event[i]);
                    printf(",");
                }
                printf("\r\n");
                send_event(short_event);
            }
        }
        // Calculate Squared Magnitude
        int32_t sq_mag = squared_magnitude(
                             ring_buffer.buffer[(ring_buffer.head + RING_BUF_LEN - 1) % RING_BUF_LEN],
                             ring_buffer.buffer[(ring_buffer.head + RING_BUF_LEN - 10) % RING_BUF_LEN]
                         );
        // Push squared magnitude into averaging filter
        insert_filter_value(&averaging_filter, sq_mag);
        if (averaging_filter.is_charged)
        {
            // Determine RMS value
            uint16_t rms = round(sqrt(get_filtered_value(&averaging_filter)) / sqrt(2));
            // Send RMS data to BLE server for phone to read
            send_voltage(&rms);
            // Check voltage level for triggers and LED behavior
            if (rms >= upper_threshold)
            {
                if(trigger_enable && voltage_normal)
                {
                    trigger();
                }
                voltage_normal = false;
                Cy_GPIO_Write(Undervoltage_LED_0_PORT, Undervoltage_LED_0_NUM, 0); //Undervoltage LED off
                Cy_GPIO_Write(Voltage_OK_0_PORT, Voltage_OK_0_NUM, 0); // Voltage OK LED off
                Cy_GPIO_Write(Overvoltage_LED_0_PORT, Overvoltage_LED_0_NUM, 1); // Overvoltage LED on
            }
            else if (rms <= lower_threshold)
            {
                if(trigger_enable && voltage_normal)
                {
                    trigger();
                }
                voltage_normal = false;
                Cy_GPIO_Write(Overvoltage_LED_0_PORT, Overvoltage_LED_0_NUM, 0); // Overvoltage LED off
                Cy_GPIO_Write(Voltage_OK_0_PORT, Voltage_OK_0_NUM, 0); // Voltage OK LED off
                Cy_GPIO_Write(Undervoltage_LED_0_PORT, Undervoltage_LED_0_NUM, 1); // Undervoltage LED on
            }
            else
            {
                voltage_normal = true;
                Cy_GPIO_Write(Overvoltage_LED_0_PORT, Overvoltage_LED_0_NUM, 0); // Overvoltage LED off
                Cy_GPIO_Write(Undervoltage_LED_0_PORT, Undervoltage_LED_0_NUM, 0); // Undervoltage LED off
                Cy_GPIO_Write(Voltage_OK_0_PORT, Voltage_OK_0_NUM, 1); // Voltage OK LED on
            }
        }
    }
}

void SCAN_Interrupt(void)
{
    Cy_SAR_StartConvert(SAR, CY_SAR_START_CONVERT_SINGLE_SHOT);
}

void trigger(void)
{
    printf("TRIGGER\r\n");
    trigger_set = true;
    extract_past_three_cycles(&ring_buffer, event);
    samples_to_extract = CYCLE_LENGTH * 9;
}

void extract_past_three_cycles(ring_buf_t *rbuf, int16_t *event_arr)
{    
    uint16_t event_index = 0;
    
    for(uint16_t index = (rbuf->head + rbuf->maxlen - (CYCLE_LENGTH * 3)) % rbuf->maxlen; index != rbuf->head + 1; ++index)
    {
        index = index % rbuf->maxlen;
        event_arr[event_index] = rbuf->buffer[index];
        ++event_index;
    }
}

int squared_magnitude(int a, int b)
{
    return pow(a, 2) + pow(b, 2);
}
/* [] END OF FILE */
