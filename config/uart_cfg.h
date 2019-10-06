/*
 * uart_cfg.h
 *
 *  Created on: May 21, 2019
 *      Author: Yasmin
 */

#ifndef SRC_DEVICE_DRIVER_UART_UART_CFG_H_
#define SRC_DEVICE_DRIVER_UART_UART_CFG_H_

#define RX_BUFFER_MAX_SIZE                      50
#define SYSCTR_CLOCK_Hz                        16000000


#define UART_PARITY_STICK                       STD_off
#define UART_PARITY_ENABLE                      STD_off
#define UART_PARITY_MODE                        UART_PARITY_MODE_EVEN


/*
* The bits indicate the number of data bits transmitted or received in a
* frame as follows:
* UART_WORD_LENGTH_5
* UART_WORD_LENGTH_6
* UART_WORD_LENGTH_7
* UART_WORD_LENGTH_8
 */
#define UART_WORD_LENGTH                        UART_WORD_LENGTH_8

#define UART_STOP_BITS                          UART_STOP_BITS_ONE
#define UART_FIFO_ENABLE                        STD_off

/*
 * control the baud clock source for the UART module.
 * choose from the follows;
 * UART_CLOCK_SOURCE_PIOSC : Internal Precision Oscillator
 * UART_CLOCK_SOURCE_SYS
 * */
#define UART_CLOCK_SOURCE                       UART_CLOCK_SOURCE_SYS

#define UART_DMA_RX_ENABLE                      STD_off
#define UART_DMA_TX_ENABLE                      STD_off
#define UART_DMA_DISABLE_ON_ERROR               STD_off

/*The following configuration for baud 115200
 * and UartClock 16 M _ ClockDiv = 16
 * */
#define UART_BAUD_RATE                          9600

/*Configure UART interrupts*/
#define UART_INTERRUPT_BREAKERROR               STD_off
#define UART_INTERRUPT_CLEARTOSEND              STD_off
#define UART_INTERRUPT_FRAMMINGERROR            STD_off
#define UART_INTERRUPT_OVERRUN                  STD_off
#define UART_INTERRUPT_PARITYERROR              STD_off
#define UART_INTERRUPT_RXTIMEOUT                STD_off
#define UART_INTERRUPT_RX                       STD_on
#define UART_INTERRUPT_TX                       STD_off
#define UART_INTERRUPT_9BIT                     STD_off

/* configure loop bach to connect Tx with Rx for debugging*/
#define UART_LOOP_BACK_ENABLE                   STD_off

#endif /* SRC_DEVICE_DRIVER_UART_UART_CFG_H_ */
