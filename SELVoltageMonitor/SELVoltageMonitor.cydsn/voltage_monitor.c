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
    
    ipcMsgForCM0.type = NUM_EVENTS;
    ipcMsgForCM0.data[0] = 0x12;
    
    do
    {
    result = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM0_ADDR, 
                                     CY_IPC_EP_CYPIPE_CM4_ADDR, 
                                     &ipcMsgForCM0, CM4_ReleaseCallback);
    } while (result == CY_IPC_PIPE_ERROR_SEND_BUSY);
}

void voltage_monitor_loop(void)
{
    
}

/* [] END OF FILE */
