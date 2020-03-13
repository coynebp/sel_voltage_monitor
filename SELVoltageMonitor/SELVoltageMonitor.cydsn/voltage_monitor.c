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

    rbuf.maxlen = RING_BUF_LEN;
    rbuf.buffer = arr;
    rbuf.head = 0;
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        rbuf.buffer[i] = 0;
    }
}

void voltage_monitor_loop(void)
{
    result = Cy_SAR_GetResult16(SAR, 0);
    ring_buf_push(&rbuf, result);
    adc_voltage = Cy_SAR_CountsTo_Volts(SAR, 0, result);
    printf("Voltage: %.2lf\r\n", adc_voltage);
    printf("Buffer: [");
    for (int i = 0; i < RING_BUF_LEN; ++i)
    {
        printf("0x%" PRIx16, rbuf.buffer[i]);
        printf(",");
    }
    printf("]\r\n");
    CyDelay(1000);
}

/* [] END OF FILE */
