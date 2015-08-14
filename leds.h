/* 
 * File:   leds.h
 * Author: matthewheins
 *
 * Created on August 11, 2015, 9:28 PM
 */

#ifndef LEDS_H
#define	LEDS_H

/*The LEDs use the same SPI bus as the flash memory. We only have to transmit 
 two bytes to write all the LEDs. All the initialization takes place over there.
 We will probably have to duplicate some names to use the same resource but know
 that the configuration happens in mem.h. 
 There will have be a mutex to keep the devices from fighting over the bus but
 there are only 16 LEDS. */

#define LED_SR_LOAD_PORT          PORT_CHANNEL_D
#define LED_SR_LOAD_PIN           PORTS_BIT_POS_1

#endif	/* LEDS_H */

