/***************************************************************************//**
* \file CY_BLE_custom_config.c
* \version 2.0
* 
* \brief
*  This file contains the source code of initialization of the config structure for
*  the Custom Service.
*
********************************************************************************
* \copyright
* Copyright 2017-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "ble/cy_ble_custom.h"

#if(CY_BLE_MODE_PROFILE && defined(CY_BLE_CUSTOM))

#ifdef CY_BLE_CUSTOM_SERVER
/* If any Custom Service with custom characteristics is defined in the
* customizer's GUI, their handles will be present in this array.
*/
/* This array contains attribute handles for the defined Custom Services and their characteristics and descriptors.
   The array index definitions are located in the BLE_custom.h file. */
static const cy_stc_ble_customs_t cy_ble_customs[0x03u] = {

    /* Meter service */
    {
        0x0010u, /* Handle of the Meter service */ 
        {

            /* Current Voltage characteristic */
            {
                0x0012u, /* Handle of the Current Voltage characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
        }, 
    },

    /* Event service */
    {
        0x0013u, /* Handle of the Event service */ 
        {

            /* ES_1_10 characteristic */
            {
                0x0015u, /* Handle of the ES_1_10 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    0x0016u, /* Handle of the Custom Descriptor descriptor */ 
                }, 
            },

            /* ES_11_20 characteristic */
            {
                0x0018u, /* Handle of the ES_11_20 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_21_30 characteristic */
            {
                0x001Au, /* Handle of the ES_21_30 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_31_40 characteristic */
            {
                0x001Cu, /* Handle of the ES_31_40 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_41_50 characteristic */
            {
                0x001Eu, /* Handle of the ES_41_50 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_51_60 characteristic */
            {
                0x0020u, /* Handle of the ES_51_60 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_61_70 characteristic */
            {
                0x0022u, /* Handle of the ES_61_70 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_71_80 characteristic */
            {
                0x0024u, /* Handle of the ES_71_80 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_81_90 characteristic */
            {
                0x0026u, /* Handle of the ES_81_90 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_91_100 characteristic */
            {
                0x0028u, /* Handle of the ES_91_100 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_101_110 characteristic */
            {
                0x002Au, /* Handle of the ES_101_110 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_111_120 characteristic */
            {
                0x002Cu, /* Handle of the ES_111_120 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_121_130 characteristic */
            {
                0x002Eu, /* Handle of the ES_121_130 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_131_140 characteristic */
            {
                0x0030u, /* Handle of the ES_131_140 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* ES_141_144 characteristic */
            {
                0x0032u, /* Handle of the ES_141_144 characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
        }, 
    },

    /* Control service */
    {
        0x0033u, /* Handle of the Control service */ 
        {

            /* Trigger characteristic */
            {
                0x0035u, /* Handle of the Trigger characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* Event Number characteristic */
            {
                0x0037u, /* Handle of the Event Number characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* Upper Threshold characteristic */
            {
                0x0039u, /* Handle of the Upper Threshold characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* Lower Threshold characteristic */
            {
                0x003Bu, /* Handle of the Lower Threshold characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },

            /* Number of Events characteristic */
            {
                0x003Du, /* Handle of the Number of Events characteristic */ 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
            {
                CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                
                /* Array of Descriptors handles */
                {
                    CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
                }, 
            },
        }, 
    },
};


#endif /* (CY_BLE_CUSTOM_SERVER) */

#ifdef CY_BLE_CUSTOM_CLIENT


#endif /* (CY_BLE_CUSTOM_CLIENT) */

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for the Custom Services. */
cy_stc_ble_custom_config_t cy_ble_customConfig =
{
    /* Custom Services GATT DB handles structure */
    #ifdef CY_BLE_CUSTOM_SERVER
    .customs      = cy_ble_customs,
    #endif /* (CY_BLE_CUSTOM_SERVER) */

    /* Custom Service handle */
    #ifdef CY_BLE_CUSTOM_CLIENT
    .customc  = cy_ble_customCServ,
    #endif /* (CY_BLE_CUSTOM_CLIENT) */
};

/** @} group_globals */

#endif /* (CY_BLE_MODE_PROFILE && defined(CY_BLE_CUSTOM)) */

/* [] END OF FILE */
