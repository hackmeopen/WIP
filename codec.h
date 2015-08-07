/* 
 * File:   codec.h
 * Author: matthewheins
 *
 * Created on August 6, 2015, 8:47 PM
 */

#ifndef CODEC_H
#define	CODEC_H

void codec_init(void);

/*Port definitions*/
#define I2C_SDA_PORT  PORT_CHANNEL_E
#define I2C_SDA_PIN   PORTS_BIT_POS_2

#define I2C_SCL_PORT  PORT_CHANNEL_E
#define I2C_SCL_PIN   PORTS_BIT_POS_2

#define SPI1_MISO_PORT
#define SPI1_MISO_PIN

#define SPI1_MOSI_PORT
#define SPI1_MOSI_PIN

#define SPI1_SCK_PORT
#define SPI1_SCK_PIN



/*I2C Definitions*/
#define I2C_CODEC                 I2C_ID_1
#define I2C_CODEC_BAUD_RATE       100000
#define I2C_CODEC_SLAVE_ADDRESS   0x1A

/*CODEC Port Definitions*/
#define I2C_CODEC_INT_SOURCE  INT_SOURCE_I2C_1_MASTER
#define ENABLE_I2C_CODEC_INT  PLIB_INT_SourceEnable(INT_ID_0, I2C_CODEC_INT_SOURCE)
#define DISABLE_I2C_CODEC_INT  PLIB_INT_SourceDisable(INT_ID_0, I2C_CODEC_INT_SOURCE)

/*SPI Frequency*/
#define SPI_DAC             SPI_ID_1
#define SPI_DAC_BAUD_RATE    //1.6MHz - Max for the ADC.

/*SPI Port Definitions*/
#define DAC_SPI_EN_PORT PORT_CHANNEL_E
#define DAC_SPI_EN_PIN  PORTS_BIT_POS_7

#define DAC_LDAC_PORT   PORT_CHANNEL_E
#define DAC_LDAC_PIN    PORTS_BIT_POS_6

#define ADC_SPI_EN_PORT PORT_CHANNEL_B
#define ADC_SPI_EN_PIN  PORTS_BIT_POS_13

#define SPI1_SCK_PORT   PORT_CHANNEL_D
#define SPI1_SCK_PIN    PORTS_BIT_POS_2

#define SPI1_MOSI_PORT  PORT_CHANNEL_G
#define SPI1_MOSI_PIN   PORTS_BIT_POS_7

#define SPI1_MISO_PORT  PORT_CHANNEL_E
#define SPI1_MISO_PIN   PORTS_BIT_POS_5

#define CLEAR_SPI1_TX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_1_TRANSMIT);
#define ENABLE_SPI1_TX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_1_TRANSMIT);
#define DISABLE_SPI1_TX_INT PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_1_TRANSMIT);

#define CLEAR_SPI1_RX_INT   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_1_RECEIVE);
#define ENABLE_SPI1_RX_INT  PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_SPI_1_RECEIVE);
#define DISABLE_SPI1_RX_INT PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_SPI_1_RECEIVE);

/*SPI Macros*/
#define SET_DAC_SPI_EN  PLIB_PORTS_PinSet(PORTS_ID_0, DAC_SPI_EN_PORT,DAC_SPI_EN_PIN)
#define CLEAR_DAC_SPI_EN PLIB_PORTS_PinClear(PORTS_ID_0, DAC_SPI_EN_PORT,DAC_SPI_EN_PIN)
#define SET_ADC_SPI_EN PLIB_PORTS_PinSet(PORTS_ID_0, ADC_SPI_EN_PORT,ADC_SPI_EN_PIN)
#define CLEAR_ADC_SPI_EN PLIB_PORTS_PinClear(PORTS_ID_0, ADC_SPI_EN_PORT,ADC_SPI_EN_PIN)
#define SET_DAC_LDAC    PLIB_PORTS_PinSet(PORTS_ID_0, DAC_LDAC_PORT,DAC_LDAC_PIN)
#define CLEAR_DAC_LDAC  PLIB_PORTS_PinClear(PORTS_ID_0, DAC_LDAC_PORT,DAC_LDAC_PIN)

//SPI Memory DMA Configuration
#define SPI_DACADC_TX_DMA_CHANNEL          DMA_CHANNEL_2
#define SPI_DACADC_RX_DMA_CHANNEL          DMA_CHANNEL_3
#define SPI_DACADC_TX_DESTINATION_ADDRESS  &SPI1BUF
#define SPI_DACADC_RX_SOURCE_ADDRESS       &SPI1BUF
#define SPI_DACADC_DMA_TX_START            PLIB_DMA_StartTransferSet(DMA_ID_0, SPI_DACADC_TX_DMA_CHANNEL)
#define SPI_DACADC_DMA_RX_START            PLIB_DMA_StartTransferSet(DMA_ID_0, SPI_DACADC_RX_DMA_CHANNEL)

#define CLEAR_SPI_DACADC_DMA_TX_INT        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_2)
#define ENABLE_SPI_DACADC_DMA_TX_INT       PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_DMA_2)
#define DISABLE_SPI_DACADC_DMA_TX_INT      PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_DMA_2)
#define CLEAR_SPI_DACADC_DMA_RX_INT        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_DMA_3)
#define ENABLE_SPI_DACADC_DMA_RX_INT       PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_DMA_3)
#define DISABLE_SPI_DACADC_DMA_RX_INT      PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_DMA_3)

#endif	/* CODEC_H */

