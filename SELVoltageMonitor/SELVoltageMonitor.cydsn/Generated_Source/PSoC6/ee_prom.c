/*******************************************************************************
* File Name: ee_prom.c
* Version 2.0
*
* Description:
*  This file provides source code of the API for the Emulated EEPROM
*  Component.
*
********************************************************************************
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ee_prom.h"

/** The instance-specific configuration structure. This should be used in the
*  associated ee_prom_Init() function.
*/
cy_stc_eeprom_config_t const ee_prom_config =
{
    1536U,
    1U,
    0U,
    0U,
    0U
};

/** The instance-specific context structure that holds all required information
* about an EEPROM instance. This structure is filled by the Em_EEPROM
* library Init() function and used by EEPROM library functions.
*/
cy_stc_eeprom_context_t ee_prom_context;

/* For PSoC 6 place EEPROM into Emulated EEPROM flash area */
#if ((CY_PSOC6) && (ee_prom_STORAGE_EM_EEPROM))

    CY_SECTION(".cy_em_eeprom") CY_ALIGN(CY_FLASH_SIZEOF_ROW)
    const uint8_t ee_prom_em_EepromStorage[ee_prom_ACTUAL_SIZE] = {0u};

#endif /* ((CY_PSOC6) && (ee_prom_STORAGE_EM_EEPROM)) */


/*******************************************************************************
* Function Name: ee_prom_Init
********************************************************************************
*
* Fills the start address of the EEPROM to the component configuration structure
* and invokes Cy_Em_EEPROM_Init() function. In case of PSoC 6 the function 
* is located in Cy_Em_EEPROM middleware library which is part of PDL. In case if
* it is utilized in the design based on non-PSOC 6 device the function is 
* located in internal design wide resource component - Em_EEPROM_Dynamic.
*
* \param startAddress
* Start address of the EEPROM storage. For PSoC 6, if Emulated EEPROM is 
* selected for EEPROM storage, the start address will be overwritten to some 
* address from Emulated EEPROM flash area.
*
* \return
* A result of function execution of type cy_en_em_eeprom_status_t.
*
*******************************************************************************/
cy_en_em_eeprom_status_t ee_prom_Init(uint32 startAddress)
{
    cy_en_em_eeprom_status_t ret;
    cy_stc_eeprom_config_t config;

    config.blockingWrite =      ee_prom_config.blockingWrite;
    config.eepromSize =         ee_prom_config.eepromSize;
    config.redundantCopy =      ee_prom_config.redundantCopy;
    config.wearLevelingFactor = ee_prom_config.wearLevelingFactor;
    
#if ((CY_PSOC6) && (ee_prom_STORAGE_EM_EEPROM))
    /* For PSoC 6, if Emulated EEPROM is selected - override the eeprom start 
    * address.
    */
    config.userFlashStartAddr = (uint32_t)ee_prom_em_EepromStorage;
#else
    config.userFlashStartAddr = startAddress;
#endif /* ((CY_PSOC6) && (ee_prom_STORAGE_EM_EEPROM)) */
        
    ret = Cy_Em_EEPROM_Init(&config, &ee_prom_context);

    return(ret);
}


/* [] END OF FILE */
