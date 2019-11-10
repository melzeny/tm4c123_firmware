/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/global_interrupt.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"

void lab_01_dio(void)
{
    SysCtr_init();
    PORT_init();

    Dio_WriteChannel(Dio_Channel_F0, STD_high);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}


