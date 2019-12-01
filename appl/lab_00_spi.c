/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/global_interrupt.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/nvic/nvic.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/spi/spi.h"

void lab_00_spi(void)
{

    SysCtr_init();
    NVIC_init();
    PORT_init();
    Spi_init();

    while(1)
    {


    }


}


