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
    uint16 arr[10] = {1,2,3,4,5,6,7,8,9,10};
    uint16 arr2[10] = {10,20,30,40,50,60,70,80,90,100};

    SysCtr_init();
    NVIC_init();
    PORT_init();
    Spi_init();

    Spi_WriteIB(Spi_Channel0, arr, 10);
    Spi_enInterrupt(Spi_Channel3);
    Spi_AsyncTransmit(Spi_Channel0);

    while(1)
    {


    }


}


