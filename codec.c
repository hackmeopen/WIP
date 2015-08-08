/*codec.c
 * Contains code related to the operation of a WM8731 stereo 24 bit codec.
 * 
 */
#include "app.h"
#include "codec.h"

void codec_init(void){
    
    //Initialize the codec via I2C and set up the SPI bus.
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_1_TRANSMIT);
    
    //This was for framed mode. Need to set up for audio mode.
    PLIB_SPI_BufferClear (CODEC_SPI_ID);
    PLIB_SPI_StopInIdleDisable(CODEC_SPI_ID);
    PLIB_SPI_PinEnable(CODEC_SPI_ID, SPI_PIN_SLAVE_SELECT|SPI_PIN_DATA_OUT);
    PLIB_SPI_CommunicationWidthSelect(CODEC_SPI_ID, SPI_COMMUNICATION_WIDTH_16BITS);
    PLIB_SPI_InputSamplePhaseSelect(CODEC_SPI_ID,SPI_INPUT_SAMPLING_PHASE_IN_MIDDLE);
    PLIB_SPI_ClockPolaritySelect(CODEC_SPI_ID, SPI_CLOCK_POLARITY_IDLE_HIGH);
    PLIB_SPI_OutputDataPhaseSelect(CODEC_SPI_ID, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    PLIB_SPI_BaudRateSet(CODEC_SPI_ID,SYS_CLK_BUS_PERIPHERAL_1,CODEC_SPI_BAUD_RATE);
    PLIB_SPI_MasterEnable(CODEC_SPI_ID);
    PLIB_SPI_FramedCommunicationEnable(CODEC_SPI_ID);
    PLIB_SPI_FrameSyncPulseDirectionSelect(CODEC_SPI_ID, SPI_FRAME_PULSE_DIRECTION_INPUT);

    
}