/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic.h"

void NVIC_init(void)
{
    NVIC_REG.EN0.B0 = GPIO_PORTA_NVIC;
    NVIC_REG.EN0.B1 = GPIO_PORTB_NVIC;
    NVIC_REG.EN0.B2 = GPIO_PORTC_NVIC;
    NVIC_REG.EN0.B3 = GPIO_PORTD_NVIC;
    NVIC_REG.EN0.B4 = GPIO_PORTE_NVIC;
    NVIC_REG.EN0.B30 = GPIO_PORTF_NVIC;

    NVIC_REG.EN0.B5 = UART0_NVIC;
    NVIC_REG.EN0.B6 = UART1_NVIC;
    NVIC_REG.EN1.B1 = UART2_NVIC;
    NVIC_REG.EN1.B27 = UART3_NVIC;
    NVIC_REG.EN1.B28 = UART4_NVIC;
    NVIC_REG.EN1.B29 = UART5_NVIC;
    NVIC_REG.EN1.B30 = UART6_NVIC;
    NVIC_REG.EN1.B31 = UART7_NVIC;

    NVIC_REG.EN0.B7 =   SPI0_NVIC;
    NVIC_REG.EN1.B2 =   SPI1_NVIC;
    NVIC_REG.EN1.B25 =  SPI2_NVIC;
    NVIC_REG.EN1.B26 =  SPI3_NVIC;

    NVIC_REG.EN0.B8 = I2C0_NVIC;
    NVIC_REG.EN1.B5 = I2C1_NVIC;
    NVIC_REG.EN3.B4 = I2C0_NVIC;
    NVIC_REG.EN4.B5 = I2C0_NVIC;



}



