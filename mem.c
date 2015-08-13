/*mem.c
 * Contains code related to the operation of a WM8731 stereo 24 bit codec.
 * 
 */

#include "app.h"
#include "mem.h"

/*memInit 
 * Initialize the hardware interface to the memory.
 */
void memInit(void){
    
    //Port direction settings
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_MISO_PORT, SPI2_MISO_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_MOSI_PORT, SPI2_MOSI_PIN);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, SPI2_SCK_PORT, SPI2_SCK_PIN);
    
    //Port Pin Select Settings
    PLIB_PORTS_RemapOutput(PORTS_ID_0, SPI2_MOSI_PPS_FUNC_MASK, SPI2_MOSI_PPS_PORT_MASK);
    PLIB_PORTS_RemapInput(PORTS_ID_0, SPI2_MISO_PPS_FUNC_MASK, SPI2_MISO_PPS_PORT_MASK);
    
}