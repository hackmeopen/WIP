/* 
 * File:   encoders.h
 * Author: matthewheins
 *
 * Created on August 12, 2015, 9:30 PM
 */

#include app.h

#ifndef ENCODERS_H
#define	ENCODERS_H

//Define pin change interrupts for the encoders

#define ENCODER_1A_PORT          PORT_CHANNEL_E
#define ENCODER_1A_PIN           PORTS_BIT_POS_7

#define ENCODER_1B_PORT          PORT_CHANNEL_B
#define ENCODER_1B_PIN           PORTS_BIT_POS_14

#define ENCODER_2A_PORT          PORT_CHANNEL_E
#define ENCODER_2A_PIN           PORTS_BIT_POS_6

#define ENCODER_2B_PORT          PORT_CHANNEL_B
#define ENCODER_2B_PIN           PORTS_BIT_POS_15

#define ENCODER_3A_PORT          PORT_CHANNEL_C
#define ENCODER_3A_PIN           PORTS_BIT_POS_13

#define ENCODER_3B_PORT          PORT_CHANNEL_D
#define ENCODER_3B_PIN           PORTS_BIT_POS_11

#define ENCODER_4A_PORT          PORT_CHANNEL_E
#define ENCODER_4A_PIN           PORTS_BIT_POS_0

#define ENCODER_4B_PORT          PORT_CHANNEL_F
#define ENCODER_4B_PIN           PORTS_BIT_POS_1

//External interrupts for the switch inputs?

//MOVE THIS TO A PIN THAT HAS AN EXTERNAL INTERRUPT ASSOCIATED?
#define SWITCH_1_PORT          PORT_CHANNEL_B
#define SWITCH_1_PIN           PORTS_BIT_POS_6

//INT 2
#define SWITCH_2_PORT          PORT_CHANNEL_B
#define SWITCH_2_PIN           PORTS_BIT_POS_8
#define SWITCH2_EXTI_PPS_FUNC_MASK  PORTS_REMAP_FUNCTION_SDO1
#define SWITCH2_EXTI_PPS_PORT_MASK  OUTPUT_PIN_RPG7

//INT1
#define SWITCH_3_PORT          PORT_CHANNEL_D
#define SWITCH_3_PIN           PORTS_BIT_POS_0
#define SPI1_MOSI_PPS_FUNC_MASK  PORTS_REMAP_FUNCTION_SDO1
#define SPI1_MOSI_PPS_PORT_MASK  OUTPUT_PIN_RPG7

//INT4
#define SWITCH_4_PORT          PORT_CHANNEL_F
#define SWITCH_4_PIN           PORTS_BIT_POS_0
#define SPI1_MOSI_PPS_FUNC_MASK  PORTS_REMAP_FUNCTION_SDO1
#define SPI1_MOSI_PPS_PORT_MASK  OUTPUT_PIN_RPG7



#endif	/* ENCODERS_H */

