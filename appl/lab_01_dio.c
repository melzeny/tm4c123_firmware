/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <tm4c123_firmware/mcal/PortDriver/port.h>
#include <tm4c123_firmware/mcal/SysCtr/SysCtr.h>
#include "../mcal/dio/dio.h"

void lab_00_dio(void)
{
    /*TODO: write simple code to test System control clock */

    SysCtr_init();
    PORT_init();

    Dio_WriteChannel(Dio_Channel_F0, STD_high);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}


