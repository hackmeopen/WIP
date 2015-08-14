/*mem.c
 * Contains code related to the operation of a WM8731 stereo 24 bit codec.
 * 
 */

#include "app.h"
#include "mem.h"

/*Local Variables*/
uint8_t u8SPI_MEM_TX_Buffer[1024];
uint8_t u8SPI_MEM_RX_Buffer[1024];

/*memInit 
 * Initialize the hardware interface to the memory.
 */
void memInit(void){
    
    //Port direction settings
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_MISO_PORT, SPI2_MISO_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_MOSI_PORT, SPI2_MOSI_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_SCK_PORT, SPI2_SCK_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_FLASH_1_SEL_PORT, SPI2_FLASH_1_SEL_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_FLASH_2_SEL_PORT, SPI2_FLASH_2_SEL_PIN);
            
    //Port Pin Select Settings
    PLIB_PORTS_RemapOutput(PORTS_ID_0, SPI2_MOSI_PPS_FUNC_MASK, SPI2_MOSI_PPS_PORT_MASK);
    PLIB_PORTS_RemapInput(PORTS_ID_0, SPI2_MISO_PPS_FUNC_MASK, SPI2_MISO_PPS_PORT_MASK);
    
    PLIB_SPI_OutputDataPhaseSelect(SPI_MEM, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);

    PLIB_SPI_BufferClear(SPI_MEM);

    PLIB_SPI_BaudRateSet(SPI_MEM, SYS_CLK_BUS_PERIPHERAL_1, SPI_MEM_BAUD_RATE);

    PLIB_SPI_CommunicationWidthSelect(SPI_MEM, SPI_COMMUNICATION_WIDTH_8BITS);

    PLIB_SPI_MasterEnable(SPI_MEM);

    PLIB_SPI_Enable(SPI_MEM);

    //Configure the DMA for standard memory reads and writes
    //TX DMA
    PLIB_DMA_Enable(DMA_ID_0);
    PLIB_DMA_ChannelXDisable(DMA_ID_0,SPI_MEM_TX_DMA_CHANNEL);
    PLIB_DMA_ChannelXSourceStartAddressSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, (uint32_t) u8SPI_MEM_TX_Buffer);
    PLIB_DMA_ChannelXDestinationStartAddressSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, (volatile unsigned int) (SPI_MEM_TX_DESTINATION_ADDRESS));
    PLIB_DMA_ChannelXSourceSizeSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, LENGTH_OF_DMA_MESSAGE);
    PLIB_DMA_ChannelXDestinationSizeSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, 1);
    PLIB_DMA_ChannelXCellSizeSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, 1);
    PLIB_DMA_ChannelXTriggerEnable(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, DMA_CHANNEL_TRIGGER_TRANSFER_START);
    PLIB_DMA_ChannelXStartIRQSet(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, DMA_TRIGGER_SPI_2_TRANSMIT);
    PLIB_DMA_ChannelXINTSourceEnable(DMA_ID_0, SPI_MEM_TX_DMA_CHANNEL, DMA_INT_BLOCK_TRANSFER_COMPLETE);
    
    //RX DMA
    //Trigger the DMA when data is received
    PLIB_DMA_ChannelXDisable(DMA_ID_0,SPI_MEM_RX_DMA_CHANNEL);
    PLIB_DMA_ChannelXDestinationStartAddressSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, (uint32_t) u8SPI_MEM_RX_Buffer);
    PLIB_DMA_ChannelXSourceStartAddressSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, (volatile unsigned int) (SPI_MEM_RX_SOURCE_ADDRESS));
    PLIB_DMA_ChannelXSourceSizeSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, 1);
    PLIB_DMA_ChannelXDestinationSizeSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, LENGTH_OF_DMA_MESSAGE);
    PLIB_DMA_ChannelXCellSizeSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, 1);
    PLIB_DMA_ChannelXTriggerEnable(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, DMA_CHANNEL_TRIGGER_TRANSFER_START);
    PLIB_DMA_ChannelXStartIRQSet(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, DMA_TRIGGER_SPI_2_RECEIVE);
    PLIB_DMA_ChannelXINTSourceEnable(DMA_ID_0, SPI_MEM_RX_DMA_CHANNEL, DMA_INT_BLOCK_TRANSFER_COMPLETE);  
}