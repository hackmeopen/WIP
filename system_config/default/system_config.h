/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.
    
    Created with MPLAB Harmony Version 1.05
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

/* This is a temporary workaround for an issue with the peripheral library "Exists"
   functions that causes superfluous warnings.  It "nulls" out the definition of
   The PLIB function attribute that causes the warning.  Once that issue has been
   resolved, this definition should be removed. */
#define _PLIB_UNSUPPORTED


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/


// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "1.05"
#define SYS_VERSION               10500

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        96000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            96000000ul
#define SYS_CLK_BUS_REFERENCE_1             48000000ul
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       15999984ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       0ul
   
/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

/*** Ports System Service Configuration ***/



/*Memory SPI Definitions*/
#define SPI_MEM             SPI_ID_2
#define SPI_MEM_BAUD_RATE   10000000 

#define SPI2_SCK_PORT   PORT_CHANNEL_G
#define SPI2_SCK_PIN    PORTS_BIT_POS_6

#define SPI2_MOSI_PORT  PORT_CHANNEL_G
#define SPI2_MOSI_PIN   PORTS_BIT_POS_8

#define SPI2_MISO_PORT  PORT_CHANNEL_B
#define SPI2_MISO_PIN   PORTS_BIT_POS_3

#define RAM_SPI_EN_PORT PORT_CHANNEL_B
#define RAM_SPI_EN_PIN  PORTS_BIT_POS_8

#define FLASH_SPI_EN_PORT   PORT_CHANNEL_B
#define FLASH_SPI_EN_PIN    PORTS_BIT_POS_2

#define SET_RAM_SPI_EN  PLIB_PORTS_PinSet(PORTS_ID_0, RAM_SPI_EN_PORT,RAM_SPI_EN_PIN)
#define CLEAR_RAM_SPI_EN PLIB_PORTS_PinClear(PORTS_ID_0, RAM_SPI_EN_PORT,RAM_SPI_EN_PIN)
#define SET_FLASH_SPI_EN PLIB_PORTS_PinSet(PORTS_ID_0, FLASH_SPI_EN_PORT,FLASH_SPI_EN_PIN)
#define CLEAR_FLASH_SPI_EN PLIB_PORTS_PinClear(PORTS_ID_0, FLASH_SPI_EN_PORT,FLASH_SPI_EN_PIN)

#define CLEAR_SPI2_TX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);
#define ENABLE_SPI2_TX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);
#define DISABLE_SPI2_TX_INT PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);
#define CLEAR_SPI2_RX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);
#define ENABLE_SPI2_RX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);
#define DISABLE_SPI2_RX_INT  PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);

//SPI Memory DMA Configuration
#define SPI_MEM_TX_DMA_CHANNEL          DMA_CHANNEL_0
#define SPI_MEM_RX_DMA_CHANNEL          DMA_CHANNEL_1
#define SPI_MEM_TX_DESTINATION_ADDRESS  &SPI2BUF
#define SPI_MEM_RX_SOURCE_ADDRESS       &SPI2BUF
#define SPI_MEM_DMA_TX_START            PLIB_DMA_StartTransferSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL)
#define SPI_MEM_DMA_RX_START            PLIB_DMA_StartTransferSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL)


#define CLEAR_SPI_MEM_DMA_TX_INT        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_0)
#define ENABLE_SPI_MEM_DMA_TX_INT       PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_DMA_0)
#define DISABLE_SPI_MEM_DMA_TX_INT      PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_DMA_0)
#define CLEAR_SPI_MEM_DMA_RX_INT        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_1)
#define ENABLE_SPI_MEM_DMA_RX_INT       PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_DMA_1)
#define DISABLE_SPI_MEM_DMA_RX_INT      PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_DMA_1)

/*LEDs*/
#define SHIFT_REG_DATA_PORT  PORT_CHANNEL_B
#define SHIFT_REG_DATA_PIN   PORTS_BIT_POS_5

#define SHIFT_REG_CLK_PORT  PORT_CHANNEL_B
#define SHIFT_REG_CLK_PIN   PORTS_BIT_POS_4

#define LED_PWM_1_REMAP_PORT  OUTPUT_PIN_RPD1
#define LED_PWM_2_REMAP_PORT  OUTPUT_PIN_RPC14
#define LED_PWM_3_REMAP_PORT  OUTPUT_PIN_RPD3
#define LED_PWM_4_REMAP_PORT  OUTPUT_PIN_RPD4
#define LED_PWM_5_REMAP_PORT  OUTPUT_PIN_RPD5

#define RESET_SR_DATA   PLIB_PORTS_PinClear(PORTS_ID_0, SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN)
#define SET_SR_DATA     PLIB_PORTS_PinSet(PORTS_ID_0, SHIFT_REG_DATA_PORT, SHIFT_REG_DATA_PIN)
#define SET_SR_CLK      PLIB_PORTS_PinSet(PORTS_ID_0, SHIFT_REG_CLK_PORT, SHIFT_REG_CLK_PIN)
#define CLEAR_SR_CLK    PLIB_PORTS_PinClear(PORTS_ID_0, SHIFT_REG_CLK_PORT, SHIFT_REG_CLK_PIN)
#define TOGGLE_SR_CLK   PLIB_PORTS_PinToggle(PORTS_ID_0, SHIFT_REG_CLK_PORT, SHIFT_REG_CLK_PIN) 

/*** OSAL Configuration ***/
#define OSAL_USE_RTOS          1

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/

