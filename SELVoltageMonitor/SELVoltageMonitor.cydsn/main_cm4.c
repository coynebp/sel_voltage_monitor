/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * main_cm4.c
 * 
 * Contains main function for the CM0+ processor, which handles the BLE
 * controller and host.
 *
 * ========================================
*/
#include "voltage_monitor.h"

int main(void)
{
    
    voltage_monitor_init();
   
    for(;;)
    {
        voltage_monitor_loop();
    }
}
/* [] END OF FILE */
