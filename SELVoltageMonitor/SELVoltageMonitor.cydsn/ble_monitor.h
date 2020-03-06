/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef BLE_MONITOR_H
    #define BLE_MONITOR_H
    
    #include <project.h>
    #include <stdlib.h>
    #include "IPC_CM0.h"
    
    void GenericEventHandler(uint32 event, void *eventParam);
    void updateNextEvent(void);
    
#endif
/* [] END OF FILE */
