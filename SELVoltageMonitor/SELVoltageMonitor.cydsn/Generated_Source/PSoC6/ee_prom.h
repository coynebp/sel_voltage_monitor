/*******************************************************************************
* File Name: ee_prom.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Emulated EEPROM
*  component.
*
********************************************************************************
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef CY_EM_EEPROM_ee_prom_H
#define CY_EM_EEPROM_ee_prom_H

#include "cyfitter.h"

#if (CYDEV_CHIP_FAMILY_USED != CYDEV_CHIP_FAMILY_PSOC6)
    #include "CyFlash.h"
    #include "cytypes.h"
    #include "cy_em_eeprom.h"
#else
    #include "syslib/cy_syslib.h"
    #include "em_eeprom/cy_em_eeprom.h"
#endif /* (CYDEV_CHIP_FAMILY_USED != CYDEV_CHIP_FAMILY_PSOC6) */

#if defined(__cplusplus)
extern "C" {
#endif


/***************************************
* Conditional Compilation Parameters
***************************************/
#define ee_prom_STORAGE_EM_EEPROM          (0U != ee_prom_USE_EMULATED_EEEPROM)

#if !defined(CY_PSOC6)
    #define CY_PSOC6                                    (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC6)
#endif /* !defined(CY_PSOC6) */


/***************************************
*        Function Prototypes
***************************************/

cy_en_em_eeprom_status_t ee_prom_Init(uint32 startAddress);

/*******************************************************************************
* Function Name: ee_prom_Write
****************************************************************************//**
*
* Invokes the Cy_Em_EEPROM_Write() function. In case of PSoC 6 the function 
* is located in Cy_Em_EEPROM middleware library which is part of PDL. In case if
* it is utilized in the design based on non-PSOC 6 device the function is 
* located in internal design wide resource component - Em_EEPROM_Dynamic.
*
*******************************************************************************/
#define ee_prom_Write(addr, eepromData, size) \
                                            Cy_Em_EEPROM_Write(addr, eepromData, size, &ee_prom_context)


/*******************************************************************************
* Function Name: ee_prom_Read
****************************************************************************//**
*
* Invokes the Cy_Em_EEPROM_Read() function. In case of PSoC 6 the function 
* is located in Cy_Em_EEPROM middleware library which is part of PDL. In case if
* it is utilized in the design based on non-PSOC 6 device the function is 
* located in internal design wide resource component - Em_EEPROM_Dynamic.
*
*******************************************************************************/
#define ee_prom_Read(addr, eepromData, size) \
                                            Cy_Em_EEPROM_Read(addr, eepromData, size, &ee_prom_context)


/*******************************************************************************
* Function Name: ee_prom_Erase
****************************************************************************//**
*
* Invokes the Cy_Em_EEPROM_Erase() function. In case of PSoC 6 the function 
* is located in Cy_Em_EEPROM middleware library which is part of PDL. In case if
* it is utilized in the design based on non-PSOC 6 device the function is 
* located in internal design wide resource component - Em_EEPROM_Dynamic.
*
*******************************************************************************/
#define ee_prom_Erase()                Cy_Em_EEPROM_Erase(&ee_prom_context)


/*******************************************************************************
* Function Name: ee_prom_NumWrites
****************************************************************************//**
*
* Invokes the Cy_Em_EEPROM_NumWrites() function. In case of PSoC 6 the function 
* is located in Cy_Em_EEPROM middleware library which is part of PDL. In case if
* it is utilized in the design based on non-PSOC 6 device the function is 
* located in internal design wide resource component - Em_EEPROM_Dynamic.
*
*******************************************************************************/
#define ee_prom_NumWrites()            Cy_Em_EEPROM_NumWrites(&ee_prom_context)


/***************************************
*   Initial Parameter Constants
****************************************/

/* Defines the location of the EEPROM storage (User flash or Emulated EEPROM flash area) */
#define ee_prom_USE_EMULATED_EEEPROM       (1U)
/* Defines if blocking or non-blocking writes will be used for writing flash */
#define ee_prom_USE_BLOCKING_WRITE         (0U)
/* The EEPROM size required by the user */
#define ee_prom_EEPROM_SIZE                (1536U)
/* The actual size of flash used to implement the EEPROM with the
* configuration entered by the user.
*/
#define ee_prom_ACTUAL_SIZE                (3072U)
#define ee_prom_PHYSICAL_SIZE              (ee_prom_ACTUAL_SIZE)
/* Holds the value of Wear Leveling option enter by user */
#define ee_prom_WEAR_LEVEL_FACTOR          (1U)
/* Holds the value of Redundant Copy option enter by user */
#define ee_prom_REDUNDANT_COPY             (0U)


/***************************************
*       Global Variables
***************************************/
extern cy_stc_eeprom_config_t const ee_prom_config;
extern cy_stc_eeprom_context_t ee_prom_context;
extern const uint8_t ee_prom_em_EepromStorage[ee_prom_ACTUAL_SIZE];

#if defined(__cplusplus)
}
#endif

#endif /* CY_EM_EEPROM_ee_prom_H */


/* [] END OF FILE */
