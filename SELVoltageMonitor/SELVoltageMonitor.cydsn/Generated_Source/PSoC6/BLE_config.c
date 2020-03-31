/***************************************************************************//**
* \file CY_BLE.c
* \version 2.0
* 
* \brief
*  This file contains the source code of initialization of the config structure
*  for BLE.
* 
********************************************************************************
* \copyright
* Copyright 2017-2018, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_config.h"

#if CY_BLE_MODE_PROFILE
#include "flash/cy_flash.h"
#include "ble/cy_ble_event_handler.h"

    
/***************************************
* Global Variables
***************************************/
/* Initializes the cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo  structure */
#if(CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER)
static cy_stc_ble_gapp_adv_params_t cy_ble_gappAdvConfig[0x01u] = {

    /* Peripheral configuration 0 */
    {
        .fastAdvIntervalMin                 = 0x0020u, 
        .fastAdvIntervalMax                 = 0x0030u, 
        .fastAdvTimeOut                     = 0x0000u, 
        .slowAdvEnable                      = 0x00u, 
        .slowAdvIntervalMin                 = 0x0640u, 
        .slowAdvIntervalMax                 = 0x4000u, 
        .slowAdvTimeOut                     = 0x0096u, 
    },
};


cy_stc_ble_gapp_disc_param_t cy_ble_discoveryParam[0x01u] = {

    /* Peripheral configuration 0 */
    {
        0x0020u, /* uint16_t advertising_interval_min */ 
        0x0030u, /* uint16_t advertising_interval_max */ 
        CY_BLE_GAPP_CONNECTABLE_UNDIRECTED_ADV, /* uint8_t advertising_type */ 
        0x00u, /* uint8_t own_addr_type */ 
        0x00u, /* uint8_t direct_addr_type */ 
        {0x00u, 0x00u, 0x00u, 0x50u, 0xA0u, 0x00u}, /* uint8_t* direct_addr */ 
        0x07u, /* uint8_t advertising_channel_map */ 
        0x00u, /* uint8_t advertising_filter_policy */ 
    },
};


cy_stc_ble_gapp_disc_data_t cy_ble_discoveryData[0x01u] = {

    /* Peripheral configuration 0 */
    {
        { 0x02u, 0x01u, 0x06u, 0x0Cu, 0x09u, 0x53u, 0x45u,
        0x4Cu, 0x20u, 0x4Du, 0x6Fu, 0x6Eu, 0x69u, 0x74u,
        0x6Fu, 0x72u, 0x07u, 0x03u, 0xAFu, 0xE5u, 0x9Cu,
        0xF8u, 0x05u, 0x58u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u }, /* uint8_t advertising_data[CY_BLE_MAX_ADV_DATA_LEN] */ 
        0x18u, /* uint8_t adv_data_length */ 
    },
};


cy_stc_ble_gapp_scan_rsp_data_t cy_ble_scanRspData[0x01u] = {

    /* Peripheral configuration 0 */
    {
        { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u }, /* uint8_t scan_rsp_data[CY_BLE_MAX_SCAN_RSP_DATA_LEN] */ 
        0x00u, /* uint8_t scan_rsp_data_length */ 
    },
};


/* This array of type cy_stc_ble_gapp_disc_mode_info_t is present only when the 
   BLE component is configured for Peripheral or Broadcaster GAP roles. 
   It contains the Advertisement settings and also the Advertisement and 
   Scan response data parameters entered in the customizer. This variable
   can be used by advanced users to change Advertisement settings,
   Advertisement or Scan response data in runtime. 
*/
cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo[0x01u] = {

    /* Peripheral configuration 0 */
    {
        0x02u, /* uint8_t discMode */ 
        &cy_ble_discoveryParam[0], 
        &cy_ble_discoveryData[0], 
        &cy_ble_scanRspData[0], 
        0x0000u, /* uint16_t advTo */ 
    },
};


#endif /* CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER */

/* Initializes the cy_stc_ble_gapc_disc_info_t  cy_ble_discoveryInfo  structure */
#if(CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER)

#endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER */

#if ((CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES))

#if(CY_BLE_MODE_PROFILE)
    CY_SECTION(".cy_em_eeprom") CY_ALIGN(CY_FLASH_SIZEOF_ROW) static const cy_stc_ble_flash_storage_t cy_ble_flashStorage =
    {
        { 0x00u }, 
        {{
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u /* CRC */
        }}, 
        0x02u, /* CY_BLE_GATT_DB_CCCD_COUNT */ 
        0x11u, 
    };
#endif /* (CY_BLE_MODE_PROFILE) */

#endif  /* (CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES) */

#if(CY_BLE_GATT_ROLE_SERVER)
static const cy_stc_ble_gatts_t cy_ble_gatts =
{
    0x000Cu,    /* Handle of the GATT service */
    0x000Eu,    /* Handle of the Service Changed characteristic */
    0x000Fu,    /* Handle of the Client Characteristic Configuration descriptor */
};
static const cy_stc_ble_gaps_t cy_ble_gaps =
{
    0x0001u,    /* Handle of the GAP service */
    0x0003u,    /* Handle of the Device Name characteristic */
    0x0005u,    /* Handle of the Appearance characteristic */
    0x0007u,    /* Handle of the Peripheral Preferred Connection Parameters characteristic */
    0x0009u,    /* Handle of the Central Address Resolution characteristic */
    0x000Bu,    /* Handle of the Resolvable Private Address Only characteristic */
};
static uint8_t cy_ble_attValues[0x0162u] = {
    /* Device Name */
    (uint8_t)'S', (uint8_t)'E', (uint8_t)'L', (uint8_t)' ', (uint8_t)'M', (uint8_t)'o', (uint8_t)'n', (uint8_t)'i',
(uint8_t)'t', (uint8_t)'o', (uint8_t)'r', 

    /* Appearance */
    0x00u, 0x00u, 

    /* Peripheral Preferred Connection Parameters */
    0x06u, 0x00u, 0x28u, 0x00u, 0x00u, 0x00u, 0xE8u, 0x03u, 

    /* Central Address Resolution */
    0x00u, 

    /* Resolvable Private Address Only */
    0x00u, 

    /* Service Changed */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* Current Voltage */
    0x00u, 0x00u, 

    /* ES_1_10 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* Custom Descriptor */
    0x00u, 0xFBu, 0x0Bu, 0x28u, 0xC6u, 0x17u, 0xEBu, 0xCCu, 0xA4u, 0x6Eu, 0x47u, 0xBBu, 0xECu, 0xF2u, 0xBBu, 0x4Bu, 0x2Du, 

    /* ES_11_20 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_21_30 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_31_40 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_41_50 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_51_60 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_61_70 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_71_80 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_81_90 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_91_100 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_101_110 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_111_120 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_121_130 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_131_140 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* ES_141_144 */
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
0x00u, 0x00u, 0x00u, 

    /* Trigger */
    0x00u, 

    /* Event Number */
    0x00u, 

    /* Upper Threshold */
    0x34u, 0x12u, 

    /* Lower Threshold */
    0x45u, 0x23u, 

    /* Number of Events */
    0x00u, 

    /* Enable */
    0x00u, 

};
#if(CY_BLE_GATT_DB_CCCD_COUNT != 0u)
static uint8_t cy_ble_attValuesCCCD[CY_BLE_GATT_DB_CCCD_COUNT];
#endif /* CY_BLE_GATT_DB_CCCD_COUNT != 0u */

static const uint8_t cy_ble_attUuid128[][16u] = {
    /* Current Voltage */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x5Bu, 0xF3u, 0x46u, 0x5Cu },
    /* ES_1_10 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x12u, 0xC2u, 0xEFu, 0x83u },
    /* ES_11_20 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x04u, 0xDEu, 0xD3u, 0x86u },
    /* ES_21_30 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xC5u, 0x4Fu, 0x9Eu, 0x5Fu },
    /* ES_31_40 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xC4u, 0x8Bu, 0x4Au, 0x4Eu },
    /* ES_41_50 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x3Du, 0x4Du, 0xD7u, 0x09u },
    /* ES_51_60 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xC9u, 0x80u, 0x83u, 0x12u },
    /* ES_61_70 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xAAu, 0x22u, 0x1Fu, 0x1Eu },
    /* ES_71_80 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x13u, 0x5Eu, 0x8Au, 0x1Au },
    /* ES_81_90 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xF7u, 0x01u, 0x05u, 0x69u },
    /* ES_91_100 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x7Eu, 0xFBu, 0x8Cu, 0xEAu },
    /* ES_101_110 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x15u, 0x3Fu, 0x69u, 0xC8u },
    /* ES_111_120 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xE2u, 0xDFu, 0x9Au, 0x82u },
    /* ES_121_130 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x81u, 0xD1u, 0x94u, 0x18u },
    /* ES_131_140 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x4Eu, 0x63u, 0xF6u, 0x84u },
    /* ES_141_144 */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x57u, 0xCAu, 0x5Du, 0x6Au },
    /* Trigger */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x4Du, 0x16u, 0x67u, 0x04u },
    /* Event Number */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x94u, 0xABu, 0x3Cu, 0x4Fu },
    /* Upper Threshold */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0xA9u, 0x1Fu, 0xABu, 0xCEu },
    /* Lower Threshold */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x22u, 0xBDu, 0x7Bu, 0x49u },
    /* Number of Events */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x5Eu, 0x47u, 0x58u, 0x02u },
    /* Enable */
    { 0xFBu, 0x34u, 0x9Bu, 0x5Fu, 0x80u, 0x00u, 0x00u, 0x80u, 0x00u, 0x10u, 0x00u, 0x00u, 0x56u, 0x9Eu, 0xEBu, 0x25u },
};

static cy_stc_ble_gatts_att_gen_val_len_t cy_ble_attValuesLen[0x34u] = {
    { 0x000Bu, (void *)&cy_ble_attValues[0] }, /* Device Name */
    { 0x0002u, (void *)&cy_ble_attValues[11] }, /* Appearance */
    { 0x0008u, (void *)&cy_ble_attValues[13] }, /* Peripheral Preferred Connection Parameters */
    { 0x0001u, (void *)&cy_ble_attValues[21] }, /* Central Address Resolution */
    { 0x0001u, (void *)&cy_ble_attValues[22] }, /* Resolvable Private Address Only */
    { 0x0004u, (void *)&cy_ble_attValues[23] }, /* Service Changed */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[0] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[0] }, /* Current Voltage UUID */
    { 0x0002u, (void *)&cy_ble_attValues[27] }, /* Current Voltage */
    { 0x0010u, (void *)&cy_ble_attUuid128[1] }, /* ES_1_10 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[29] }, /* ES_1_10 */
    { 0x0001u, (void *)&cy_ble_attValues[49] }, /* Custom Descriptor */
    { 0x0010u, (void *)&cy_ble_attUuid128[2] }, /* ES_11_20 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[66] }, /* ES_11_20 */
    { 0x0010u, (void *)&cy_ble_attUuid128[3] }, /* ES_21_30 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[86] }, /* ES_21_30 */
    { 0x0010u, (void *)&cy_ble_attUuid128[4] }, /* ES_31_40 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[106] }, /* ES_31_40 */
    { 0x0010u, (void *)&cy_ble_attUuid128[5] }, /* ES_41_50 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[126] }, /* ES_41_50 */
    { 0x0010u, (void *)&cy_ble_attUuid128[6] }, /* ES_51_60 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[146] }, /* ES_51_60 */
    { 0x0010u, (void *)&cy_ble_attUuid128[7] }, /* ES_61_70 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[166] }, /* ES_61_70 */
    { 0x0010u, (void *)&cy_ble_attUuid128[8] }, /* ES_71_80 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[186] }, /* ES_71_80 */
    { 0x0010u, (void *)&cy_ble_attUuid128[9] }, /* ES_81_90 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[206] }, /* ES_81_90 */
    { 0x0010u, (void *)&cy_ble_attUuid128[10] }, /* ES_91_100 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[226] }, /* ES_91_100 */
    { 0x0010u, (void *)&cy_ble_attUuid128[11] }, /* ES_101_110 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[246] }, /* ES_101_110 */
    { 0x0010u, (void *)&cy_ble_attUuid128[12] }, /* ES_111_120 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[266] }, /* ES_111_120 */
    { 0x0010u, (void *)&cy_ble_attUuid128[13] }, /* ES_121_130 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[286] }, /* ES_121_130 */
    { 0x0010u, (void *)&cy_ble_attUuid128[14] }, /* ES_131_140 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[306] }, /* ES_131_140 */
    { 0x0010u, (void *)&cy_ble_attUuid128[15] }, /* ES_141_144 UUID */
    { 0x0014u, (void *)&cy_ble_attValues[326] }, /* ES_141_144 */
    { 0x0010u, (void *)&cy_ble_attUuid128[16] }, /* Trigger UUID */
    { 0x0001u, (void *)&cy_ble_attValues[346] }, /* Trigger */
    { 0x0010u, (void *)&cy_ble_attUuid128[17] }, /* Event Number UUID */
    { 0x0001u, (void *)&cy_ble_attValues[347] }, /* Event Number */
    { 0x0010u, (void *)&cy_ble_attUuid128[18] }, /* Upper Threshold UUID */
    { 0x0002u, (void *)&cy_ble_attValues[348] }, /* Upper Threshold */
    { 0x0010u, (void *)&cy_ble_attUuid128[19] }, /* Lower Threshold UUID */
    { 0x0002u, (void *)&cy_ble_attValues[350] }, /* Lower Threshold */
    { 0x0010u, (void *)&cy_ble_attUuid128[20] }, /* Number of Events UUID */
    { 0x0001u, (void *)&cy_ble_attValues[352] }, /* Number of Events */
    { 0x0010u, (void *)&cy_ble_attUuid128[21] }, /* Enable UUID */
    { 0x0001u, (void *)&cy_ble_attValues[353] }, /* Enable */
};

static const cy_stc_ble_gatts_db_t cy_ble_gattDB[0x3Fu] = {
    { 0x0001u, 0x2800u /* Primary service                     */, 0x00000001u /*       */, 0x000Bu, {{0x1800u, NULL}}                           },
    { 0x0002u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0003u, {{0x2A00u, NULL}}                           },
    { 0x0003u, 0x2A00u /* Device Name                         */, 0x01020001u /* rd    */, 0x0003u, {{0x000Bu, (void *)&cy_ble_attValuesLen[0]}} },
    { 0x0004u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0005u, {{0x2A01u, NULL}}                           },
    { 0x0005u, 0x2A01u /* Appearance                          */, 0x01020001u /* rd    */, 0x0005u, {{0x0002u, (void *)&cy_ble_attValuesLen[1]}} },
    { 0x0006u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0007u, {{0x2A04u, NULL}}                           },
    { 0x0007u, 0x2A04u /* Peripheral Preferred Connection Par */, 0x01020001u /* rd    */, 0x0007u, {{0x0008u, (void *)&cy_ble_attValuesLen[2]}} },
    { 0x0008u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0009u, {{0x2AA6u, NULL}}                           },
    { 0x0009u, 0x2AA6u /* Central Address Resolution          */, 0x01020001u /* rd    */, 0x0009u, {{0x0001u, (void *)&cy_ble_attValuesLen[3]}} },
    { 0x000Au, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x000Bu, {{0x2AC9u, NULL}}                           },
    { 0x000Bu, 0x2AC9u /* Resolvable Private Address Only     */, 0x01020001u /* rd    */, 0x000Bu, {{0x0001u, (void *)&cy_ble_attValuesLen[4]}} },
    { 0x000Cu, 0x2800u /* Primary service                     */, 0x00000001u /*       */, 0x000Fu, {{0x1801u, NULL}}                           },
    { 0x000Du, 0x2803u /* Characteristic                      */, 0x00200001u /* ind   */, 0x000Fu, {{0x2A05u, NULL}}                           },
    { 0x000Eu, 0x2A05u /* Service Changed                     */, 0x01200000u /* ind   */, 0x000Fu, {{0x0004u, (void *)&cy_ble_attValuesLen[5]}} },
    { 0x000Fu, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr */, 0x000Fu, {{0x0002u, (void *)&cy_ble_attValuesLen[6]}} },
    { 0x0010u, 0x2800u /* Primary service                     */, 0x00000001u /*       */, 0x0012u, {{0xE5AFu, NULL}}                           },
    { 0x0011u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0012u, {{0x0010u, (void *)&cy_ble_attValuesLen[7]}} },
    { 0x0012u, 0xF35Bu /* Current Voltage                     */, 0x09020001u /* rd    */, 0x0012u, {{0x0002u, (void *)&cy_ble_attValuesLen[8]}} },
    { 0x0013u, 0x2800u /* Primary service                     */, 0x00000001u /*       */, 0x0032u, {{0xF89Cu, NULL}}                           },
    { 0x0014u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0016u, {{0x0010u, (void *)&cy_ble_attValuesLen[9]}} },
    { 0x0015u, 0xC212u /* ES_1_10                             */, 0x09020001u /* rd    */, 0x0016u, {{0x0014u, (void *)&cy_ble_attValuesLen[10]}} },
    { 0x0016u, 0xBBF2u /* Custom Descriptor                   */, 0x09000001u /*       */, 0x0016u, {{0x0001u, (void *)&cy_ble_attValuesLen[11]}} },
    { 0x0017u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0018u, {{0x0010u, (void *)&cy_ble_attValuesLen[12]}} },
    { 0x0018u, 0xDE04u /* ES_11_20                            */, 0x09020001u /* rd    */, 0x0018u, {{0x0014u, (void *)&cy_ble_attValuesLen[13]}} },
    { 0x0019u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x001Au, {{0x0010u, (void *)&cy_ble_attValuesLen[14]}} },
    { 0x001Au, 0x4FC5u /* ES_21_30                            */, 0x09020001u /* rd    */, 0x001Au, {{0x0014u, (void *)&cy_ble_attValuesLen[15]}} },
    { 0x001Bu, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x001Cu, {{0x0010u, (void *)&cy_ble_attValuesLen[16]}} },
    { 0x001Cu, 0x8BC4u /* ES_31_40                            */, 0x09020001u /* rd    */, 0x001Cu, {{0x0014u, (void *)&cy_ble_attValuesLen[17]}} },
    { 0x001Du, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x001Eu, {{0x0010u, (void *)&cy_ble_attValuesLen[18]}} },
    { 0x001Eu, 0x4D3Du /* ES_41_50                            */, 0x09020001u /* rd    */, 0x001Eu, {{0x0014u, (void *)&cy_ble_attValuesLen[19]}} },
    { 0x001Fu, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0020u, {{0x0010u, (void *)&cy_ble_attValuesLen[20]}} },
    { 0x0020u, 0x80C9u /* ES_51_60                            */, 0x09020001u /* rd    */, 0x0020u, {{0x0014u, (void *)&cy_ble_attValuesLen[21]}} },
    { 0x0021u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0022u, {{0x0010u, (void *)&cy_ble_attValuesLen[22]}} },
    { 0x0022u, 0x22AAu /* ES_61_70                            */, 0x09020001u /* rd    */, 0x0022u, {{0x0014u, (void *)&cy_ble_attValuesLen[23]}} },
    { 0x0023u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0024u, {{0x0010u, (void *)&cy_ble_attValuesLen[24]}} },
    { 0x0024u, 0x5E13u /* ES_71_80                            */, 0x09020001u /* rd    */, 0x0024u, {{0x0014u, (void *)&cy_ble_attValuesLen[25]}} },
    { 0x0025u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0026u, {{0x0010u, (void *)&cy_ble_attValuesLen[26]}} },
    { 0x0026u, 0x01F7u /* ES_81_90                            */, 0x09020001u /* rd    */, 0x0026u, {{0x0014u, (void *)&cy_ble_attValuesLen[27]}} },
    { 0x0027u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0028u, {{0x0010u, (void *)&cy_ble_attValuesLen[28]}} },
    { 0x0028u, 0xFB7Eu /* ES_91_100                           */, 0x09020001u /* rd    */, 0x0028u, {{0x0014u, (void *)&cy_ble_attValuesLen[29]}} },
    { 0x0029u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x002Au, {{0x0010u, (void *)&cy_ble_attValuesLen[30]}} },
    { 0x002Au, 0x3F15u /* ES_101_110                          */, 0x09020001u /* rd    */, 0x002Au, {{0x0014u, (void *)&cy_ble_attValuesLen[31]}} },
    { 0x002Bu, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x002Cu, {{0x0010u, (void *)&cy_ble_attValuesLen[32]}} },
    { 0x002Cu, 0xDFE2u /* ES_111_120                          */, 0x09020001u /* rd    */, 0x002Cu, {{0x0014u, (void *)&cy_ble_attValuesLen[33]}} },
    { 0x002Du, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x002Eu, {{0x0010u, (void *)&cy_ble_attValuesLen[34]}} },
    { 0x002Eu, 0xD181u /* ES_121_130                          */, 0x09020001u /* rd    */, 0x002Eu, {{0x0014u, (void *)&cy_ble_attValuesLen[35]}} },
    { 0x002Fu, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0030u, {{0x0010u, (void *)&cy_ble_attValuesLen[36]}} },
    { 0x0030u, 0x634Eu /* ES_131_140                          */, 0x09020001u /* rd    */, 0x0030u, {{0x0014u, (void *)&cy_ble_attValuesLen[37]}} },
    { 0x0031u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x0032u, {{0x0010u, (void *)&cy_ble_attValuesLen[38]}} },
    { 0x0032u, 0xCA57u /* ES_141_144                          */, 0x09020001u /* rd    */, 0x0032u, {{0x0014u, (void *)&cy_ble_attValuesLen[39]}} },
    { 0x0033u, 0x2800u /* Primary service                     */, 0x00000001u /*       */, 0x003Fu, {{0x5805u, NULL}}                           },
    { 0x0034u, 0x2803u /* Characteristic                      */, 0x00080001u /* wr    */, 0x0035u, {{0x0010u, (void *)&cy_ble_attValuesLen[40]}} },
    { 0x0035u, 0x164Du /* Trigger                             */, 0x09080100u /* wr    */, 0x0035u, {{0x0001u, (void *)&cy_ble_attValuesLen[41]}} },
    { 0x0036u, 0x2803u /* Characteristic                      */, 0x000A0001u /* rd,wr */, 0x0037u, {{0x0010u, (void *)&cy_ble_attValuesLen[42]}} },
    { 0x0037u, 0xAB94u /* Event Number                        */, 0x090A0101u /* rd,wr */, 0x0037u, {{0x0001u, (void *)&cy_ble_attValuesLen[43]}} },
    { 0x0038u, 0x2803u /* Characteristic                      */, 0x000A0001u /* rd,wr */, 0x0039u, {{0x0010u, (void *)&cy_ble_attValuesLen[44]}} },
    { 0x0039u, 0x1FA9u /* Upper Threshold                     */, 0x090A0101u /* rd,wr */, 0x0039u, {{0x0002u, (void *)&cy_ble_attValuesLen[45]}} },
    { 0x003Au, 0x2803u /* Characteristic                      */, 0x000A0001u /* rd,wr */, 0x003Bu, {{0x0010u, (void *)&cy_ble_attValuesLen[46]}} },
    { 0x003Bu, 0xBD22u /* Lower Threshold                     */, 0x090A0101u /* rd,wr */, 0x003Bu, {{0x0002u, (void *)&cy_ble_attValuesLen[47]}} },
    { 0x003Cu, 0x2803u /* Characteristic                      */, 0x00020001u /* rd    */, 0x003Du, {{0x0010u, (void *)&cy_ble_attValuesLen[48]}} },
    { 0x003Du, 0x475Eu /* Number of Events                    */, 0x09020001u /* rd    */, 0x003Du, {{0x0001u, (void *)&cy_ble_attValuesLen[49]}} },
    { 0x003Eu, 0x2803u /* Characteristic                      */, 0x000A0001u /* rd,wr */, 0x003Fu, {{0x0010u, (void *)&cy_ble_attValuesLen[50]}} },
    { 0x003Fu, 0x9E56u /* Enable                              */, 0x090A0101u /* rd,wr */, 0x003Fu, {{0x0001u, (void *)&cy_ble_attValuesLen[51]}} },
};

#endif /* (CY_BLE_GATT_ROLE_SERVER) */

/* Default device security */
#if (CY_BLE_MODE_PROFILE) 
    cy_stc_ble_gap_auth_info_t cy_ble_authInfo[0x01u] = {

    /* Security configuration 0 */
    {
        .security = (CY_BLE_GAP_SEC_MODE_1 | CY_BLE_GAP_SEC_LEVEL_1 ), 
        .bonding = CY_BLE_GAP_BONDING, 
        .ekeySize = 0x10u, 
        .authErr = CY_BLE_GAP_AUTH_ERROR_NONE, 
        .pairingProperties = 0x01u, 
    },
};

#endif /* CY_BLE_MODE_PROFILE */

#if(CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL)

/** Initialize BLE configuration parameters structure */
static const cy_stc_ble_params_t cy_ble_params =
{
        .txPowerLevelAdv                    = CY_BLE_LL_PWR_LVL_0_DBM,
        .txPowerLevelConn                   = CY_BLE_LL_PWR_LVL_0_DBM,

        .securityIoCapability               = CY_BLE_GAP_IOCAP_DISPLAY_ONLY,
        .securityPairingMethod              = 0x00u,
    
        .siliconDeviceAddressEnabled        = 0x01u,
    
        .gattDbIndexCount                   = 0x003Fu,
};
#endif  /* (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL) */

cy_stc_ble_gap_bd_addr_t cy_ble_deviceAddress = {{0x00u, 0x00u, 0x00u, 0x50u, 0xA0u, 0x00u}, 0x00u };

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for BLE */
cy_stc_ble_config_t cy_ble_config =
{
    /* Initialize the GAPP structures */
    /* Initialize the cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo structure */
    #if(CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER)
        .discoveryModeInfo = cy_ble_discoveryModeInfo,
        .gappAdvParams = cy_ble_gappAdvConfig,
    #else
        .discoveryModeInfo = NULL,
    #endif /* CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER */

    /* Initialize the cy_stc_ble_gapc_disc_info_t  cy_ble_discoveryInfo  structure */
    #if(CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER)
        .discoveryInfo = cy_ble_discoveryInfo,
        .gapcScanParams = cy_ble_gapcScanConfig,
    #else
        .discoveryInfo = NULL,
    #endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER */

    /* Initialize the GATT structures */
    #if((CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES))
        .flashStorage = &cy_ble_flashStorage,
    #else
        .flashStorage = NULL,
    #endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES */

    #if(CY_BLE_GATT_ROLE_SERVER)
        .gatts            = &cy_ble_gatts,
        .gaps             = &cy_ble_gaps,
        .attValuesCCCD    = cy_ble_attValuesCCCD,
        .gattDB           = cy_ble_gattDB,
    #else
        .gatts            = NULL,
        .attValuesCCCD    = NULL,
        .gattDB           = NULL,
    #endif /* CY_BLE_GATT_ROLE_SERVER */

    #if(CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL)
        /* Initialize the device security structure */
        .authInfo = cy_ble_authInfo,
    #else
        .authInfo = NULL,
    #endif /* (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL */

    #if(CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL)
        /* Initialize the BLE configuration parameters structure */
        .params   = &cy_ble_params,
    #else
        .params = NULL,
    #endif /* (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL */

    /* An application layer event callback function to receive service events from the BLE Component. */
    .callbackFunc   = NULL,

    .deviceAddress  = &cy_ble_deviceAddress,
};

/** @} group_globals */

#endif /* CY_BLE_MODE_PROFILE */

/* [] END OF FILE */
