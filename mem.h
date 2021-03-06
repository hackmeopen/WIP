/* 
 * File:   mem.h
 * Author: matthewheins
 *
 * Created on August 11, 2015, 9:10 PM
 */

#include "app.h"

#ifndef MEM_H
#define	MEM_H

#define SPI2_FLASH_1_SEL_PORT   PORT_CHANNEL_B
#define SPI2_FLASH_1_SEL_PIN    PORTS_BIT_POS_2
#define ASSERT_FLASH_1_SEL      PLIB_PORTS_PinSet(PORTS_ID_0, SPI2_FLASH_1_SEL_PORT, SPI2_FLASH_1_SEL_PIN)
#define RELEASE_FLASH_1_SEL     PLIB_PORTS_PinClear(PORTS_ID_0, SPI2_FLASH_1_SEL_PORT, SPI2_FLASH_1_SEL_PIN)

#define SPI2_FLASH_2_SEL_PORT   PORT_CHANNEL_B
#define SPI2_FLASH_2_SEL_PIN    PORTS_BIT_POS_4
#define ASSERT_FLASH_2_SEL      PLIB_PORTS_PinSet(PORTS_ID_0, SPI2_FLASH_2_SEL_PORT, SPI2_FLASH_2_SEL_PIN)
#define RELEASE_FLASH_2_SEL     PLIB_PORTS_PinClear(PORTS_ID_0, SPI2_FLASH_2_SEL_PORT, SPI2_FLASH_2_SEL_PIN)

#define SPI2_MISO_PORT          PORT_CHANNEL_B
#define SPI2_MISO_PIN           PORTS_BIT_POS_3
#define SPI2_MISO_PPS_FUNC_MASK INPUT_FUNC_SDI2
#define SPI2_MISO_PPS_PORT_MASK INPUT_PIN_RPB3

#define SPI2_MOSI_PORT           PORT_CHANNEL_G
#define SPI2_MOSI_PIN            PORTS_BIT_POS_8
#define SPI2_MOSI_PPS_FUNC_MASK  OUTPUT_FUNC_SDO2
#define SPI2_MOSI_PPS_PORT_MASK  OUTPUT_PIN_RPG8

#define SPI2_SCK_PORT   PORT_CHANNEL_G
#define SPI2_SCK_PIN    PORTS_BIT_POS_6

#define CLEAR_SPI2_TX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);
#define ENABLE_SPI2_TX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);
#define DISABLE_SPI2_TX_INT PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_2_TRANSMIT);

#define CLEAR_SPI2_RX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);
#define ENABLE_SPI2_RX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);
#define DISABLE_SPI2_RX_INT PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_2_RECEIVE);

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

#define SPI_MEM             SPI_ID_2
#define SPI_MEM_BAUD_RATE   20000000 //20MHz
#define LENGTH_OF_RAM_ADDRESS   3 //BYTES
#define LENGTH_OF_DMA_MESSAGE   15
#define HIGHEST_RAM_ADDRESS 0x7D0000//1Mbit/8

/*Status Register Bits*/
#define FLASH_STATUS_BUSY               0
#define FLASH_STATUS_WRITE_EN           1
#define FLASH_STATUS_BLOCK_PROT_0       2
#define FLASH_STATUS_BLOCK_PROT_1       3
#define FLASH_STATUS_AUTO_INCREMENT     6
#define FLASH_STATUS_BLOCK_PROT_LOCK    7

#define FLASH_CMD_EN_WRITE_STATUS_REG   0x50
#define FLASH_CMD_WRITE_STATUS_REG      0x01
#define FLASH_CMD_WRITE_ENABLE          0x06
#define FLASH_CMD_CHIP_ERASE            0x60
#define FLASH_CMD_BLOCK_ERASE           0x52
#define FLASH_CMD_SECTOR_ERASE          0x20
#define FLASH_CMD_WRITE_DISABLE         0x04
#define FLASH_CMD_AUTO_INCREMENT_WR     0xAF
#define FLASH_CMD_BYTE_PROGRAM          0x02
#define FLASH_CMD_READ                  0x03
#define FLASH_CMD_READ_STATUS_REG       0x05

void memInit(void);
void vDMA0InterruptHandler(void);
void vDMA1InterruptHandler(void);
void vTaskSPIMemory(void * pvParameters);


#endif	/* MEM_H */

