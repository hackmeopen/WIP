/*codec.c
 * Contains code related to the operation of a WM8731 stereo 24 bit codec.
 * 
 */
#include "app.h"
#include "codec.h"

/*This function sets up all the hardware and software resources which will be used
 to interact with the WM8731 codec.*/
void codec_init(void){
    
    //Port direction settings
    PLIB_PORTS_RemapOutput(PORTS_ID_0, SPI1_MOSI_PPS_FUNC_MASK, SPI1_MOSI_PPS_PORT_MASK);
    PLIB_PORTS_RemapInput(PORTS_ID_0, SPI1_MISO_PPS_FUNC_MASK, SPI1_MISO_PPS_PORT_MASK);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, CODEC_MCLK_PPS_FUNC_MASK, CODEC_MCLK_PPS_PORT_MASK);
    
    //Port Pin Select Settings
    PLIB_PORTS_RemapOutput(PORTS_ID_0, OUTPUT_FUNC_SDO1, OUTPUT_PIN_RPG7);
    PLIB_PORTS_RemapInput(PORTS_ID_0, INPUT_FUNC_SDI1, INPUT_PIN_RPE5);
    PLIB_PORTS_RemapOutput(PORTS_ID_0, OUTPUT_FUNC_REFCLKO, OUTPUT_PIN_RPB9);
    
    //Set up the I2C bus and configure the codec.
    PLIB_I2C_BaudRateSet(CODEC_I2C_ID, SYS_CLK_BUS_PERIPHERAL_1, CODEC_I2C_BAUD_RATE);
    PLIB_I2C_Enable(CODEC_I2C_ID);
    
    PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_SPI_1_TRANSMIT);
    
    //Disable SPI
    PLIB_SPI_Disable(CODEC_SPI_ID);
    // Optional:  Clear SPI interrupts and status flag.
    //clear SPI buffer
    PLIB_SPI_BufferClear (CODEC_SPI_ID);
    // Configure General SPI Options
    PLIB_SPI_StopInIdleDisable(CODEC_SPI_ID);
    PLIB_SPI_PinEnable(CODEC_SPI_ID, SPI_PIN_DATA_IN|SPI_PIN_DATA_OUT);
    PLIB_SPI_CommunicationWidthSelect(CODEC_SPI_ID, SPI_COMMUNICATION_WIDTH_16BITS);
    PLIB_SPI_InputSamplePhaseSelect(CODEC_SPI_ID,SPI_INPUT_SAMPLING_PHASE_IN_MIDDLE);
    PLIB_SPI_ClockPolaritySelect(CODEC_SPI_ID, SPI_CLOCK_POLARITY_IDLE_HIGH);
    PLIB_SPI_OutputDataPhaseSelect(CODEC_SPI_ID, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    PLIB_SPI_BaudRateSet(CODEC_SPI_ID,SYS_CLK_BUS_PERIPHERAL_1,CODEC_SPI_BAUD_RATE);
    PLIB_SPI_MasterEnable(CODEC_SPI_ID);
    PLIB_SPI_AudioProtocolModeSelect(CODEC_SPI_ID,SPI_AUDIO_PROTOCOL_I2S );
    PLIB_SPI_FramedCommunicationDisable(CODEC_SPI_ID);
    PLIB_SPI_AudioProtocolEnable(CODEC_SPI_ID);
    
    //Enable the Master Clock to the codec.
    PLIB_OSC_ReferenceOscBaseClockSelect(OSC_ID_0, OSC_REFERENCE_1, OSC_REF_BASECLOCK_PBCLK);
    PLIB_OSC_ReferenceOscDivisorValueSet(OSC_ID_0, OSC_REFERENCE_1, 128);
    PLIB_OSC_ReferenceOscEnable(OSC_ID_0, OSC_REFERENCE_1);
    PLIB_OSC_ReferenceOscTrimSet(OSC_ID_0, OSC_REFERENCE_1, 50);
    
    PLIB_OSC_ReferenceOutputEnable(OSC_ID_0, OSC_REFERENCE_1);
    
}

/*The WM8731 codec requires some I2C register configuration to operate properly.
 This function takes care of that jazz.*/
void codec_config(void){
//    /*Check to see if the Send the start bit.*/
//    if(PLIB_I2C_BusIsIdle(CODEC_I2C_ID)){
//        PLIB_I2C_MasterStart(CODEC_I2C_ID);
//    }
//
//    xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Start transmitted
//    /*Send the slave address*/
//    if(PLIB_I2C_TransmitterIsReady(CODEC_I2C_ID)){
//        PLIB_I2C_TransmitterByteSend(CODEC_I2C_ID, MGC3130_ADDRESS_READ);
//    }
//
//    xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Address transmitted
//    /*Get the I2C module to clock out to receive a byte.*/
//    if(PLIB_I2C_TransmitterByteWasAcknowledged(CODEC_I2C_ID)){
//        PLIB_I2C_MasterReceiverClock1Byte(CODEC_I2C_ID);
//
//    }
//
//    xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Message Length Received.
//    /*The first byte from the MGC3130 is the length of the message*/
//    /*The first byte from the MGC3130 is the length of the message*/
//    u8ReceiveBuffer[0] = PLIB_I2C_ReceivedByteGet(CODEC_I2C_ID);
//    u8MessageLength = u8ReceiveBuffer[0];
//
//    if(u8MessageLength > 0 && u8MessageLength < 0xFF){
//        for(i = 1; i<u8MessageLength; i++){
//            PLIB_I2C_ReceivedByteAcknowledge(CODEC_I2C_ID, true);
//            xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Ack completed
//            PLIB_I2C_MasterReceiverClock1Byte(CODEC_I2C_ID);
//            xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Byte Received
//            u8ReceiveBuffer[i] = PLIB_I2C_ReceivedByteGet(CODEC_I2C_ID);
//        }
//        PLIB_I2C_ReceivedByteAcknowledge(CODEC_I2C_ID, false);
//    }
//    else{
//        PLIB_I2C_ReceivedByteAcknowledge(CODEC_I2C_ID, false);
//    }
//
//    xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);
//
//    PLIB_I2C_MasterStop(CODEC_I2C_ID);
//
//    xSemaphoreTake(xSemaphoreI2CHandler,portMAX_DELAY);//Stop bit complete
//    MGC3130_TS_PIN_HIGH;   
}
