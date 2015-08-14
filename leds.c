/*LEDS.c
 * Contains functions related to the bicolor LEDs.
 */

#include "app.h"
#include "leds.h"

void leds_init(void){
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, LED_SR_LOAD_PORT, LED_SR_LOAD_PIN);
}

